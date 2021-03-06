#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

int kbport = -1;

int posix_com_close(int port)
{
  int rtnval = 0;
  if (port != -1)
  {
    rtnval = (int) close(port);
  }

  return(rtnval);
}

int posix_com_open(char *devicename,
                        int rate,
                        char parity,
                        int databits,
                        int stopbits,
                        int options)
{
  int rtnval = 0;
  struct termios t;

  int local_databits = 0, local_stopbits = 0, local_parity = 0, local_rate = 0;
  char upper_parity = 0;

  /* Check for valid values */

  upper_parity = toupper(parity);

  if (((databits == 5) || (databits == 6) || (databits == 7) || (databits == 8)) &&
      ((stopbits == 2) || (stopbits == 1)) &&
      ((upper_parity == 'N') || (upper_parity == 'O') || (upper_parity == 'E')) &&
      ((rate == 50) || (rate == 75) || (rate == 110) || (rate == 134) || (rate == 150) ||
       (rate == 200) || (rate == 300) || (rate == 600) || (rate == 1200) || (rate == 1800) ||
       (rate == 2400) || (rate == 4800) || (rate == 9600) || (rate == 19200) || (rate == 38400) ||
       (rate == 57600) || (rate == 115200)))
  {

    /* Open the com port for read/write access */

    rtnval = open(devicename,O_RDWR | O_NOCTTY | O_NONBLOCK);

    if (rtnval != -1)
    {
      /* Set the parity, data bits, and stop bits */

      switch(databits)
      {
        case 5 : local_databits = CS5; break;
        case 6 : local_databits = CS6; break;
        case 7 : local_databits = CS7; break;
        case 8 : local_databits = CS8; break;
      }

      if (stopbits == 2)
        local_stopbits = CSTOPB;
      else
        local_stopbits = 0;

      switch(upper_parity)
      {
        case 'E' : local_parity = PARENB; break;
        case 'O' : local_parity |= PARODD; break;
      }
    }

    t.c_iflag = IGNPAR;
    t.c_oflag = 0;
    t.c_cflag &= ~CSIZE; /* Zero out the CSIZE bits */
    t.c_cflag = CLOCAL | local_databits | local_stopbits | local_parity | options;
    t.c_lflag = IEXTEN;

    /* Set the data rate */

    switch(rate)
    {
      case 50     : local_rate = B50;     break;
      case 75     : local_rate = B75;     break;
      case 110    : local_rate = B110;    break;
      case 134    : local_rate = B134;    break;
      case 150    : local_rate = B150;    break;
      case 200    : local_rate = B200;    break;
      case 300    : local_rate = B300;    break;
      case 600    : local_rate = B600;    break;
      case 1200   : local_rate = B1200;   break;
      case 1800   : local_rate = B1800;   break;
      case 2400   : local_rate = B2400;   break;
      case 4800   : local_rate = B4800;   break;
      case 9600   : local_rate = B9600;   break;
      case 19200  : local_rate = B19200;  break;
      case 38400  : local_rate = B38400;  break;
#ifndef __OS_IRIX
      case 57600  : local_rate = B57600;  break;
      case 115200 : local_rate = B115200; break;
#endif
    }

    if ((cfsetispeed(&t,local_rate) != -1) && (cfsetospeed(&t,local_rate) != -1))
    {
      if (tcsetattr(rtnval,TCSANOW,&t) == -1)
        rtnval = -1;
    }
    else
      rtnval = -1;
  }
  else
    rtnval = -1;

  return(rtnval);
}

int posix_com_dataready(int port)
{
  struct timeval tvptr;
  fd_set rset;
  int status = -1;
  int rtnval = 0;

  if (port != -1)
  {
    /* Zero out the seconds and microseconds so we don't block */

    tvptr.tv_sec = 0;
    tvptr.tv_usec = 0;

    /* Initialize the read set to zero */

    FD_ZERO(&rset);

    /* And now turn on the read set */

    FD_SET(port,&rset);

    status = select(port + 1,&rset,NULL,NULL,&tvptr);

    if (status == -1) /* Error */
    {
      fprintf(stderr,"\nERROR:  dataready():  select() returned -1\n");
      rtnval = 0;
    }
    else if (status > 0)
    {
      if (FD_ISSET(port,&rset))
      {
        rtnval = 1;
      }
    }


  }

  return(rtnval);
}

char posix_com_read(int port, char *dst)
{

  if (port != -1)
    return(read(port,dst,1) == 1);
  else
    return(0);
}

char posix_com_write(int port, char src)
{
  if (port != -1)
    return(write(port,&src,1) == 1);
  else
    return(0);
}

int posix_com_write_string(int port, char *src)
{
  int rtnval = 0;

  if (src != (char *) NULL)
  {

    if (port != -1)
    {
      while (*src)
      {
        posix_com_write(port,*src++);
        rtnval++;
      }
    }
  }

  return(rtnval);

}

int posix_kbhit(void)
{
  int rtnval = 0;

  fd_set rset;
  static struct timeval tvptr;
  struct termios tty;

  int status = 0;

  if (kbport == -1)
  {

    /* Open the controlling terminal for read-only access */

    kbport = open(ctermid(NULL),O_RDONLY);

    if (kbport > -1)
    {
      /* Get the terminal attributes */

      if (tcgetattr(kbport,&tty) < 0)
      {
        fprintf(stderr,"\nERROR:  unable to get tty attributes for %s\n",ctermid(NULL));
        exit(-1);
      }
      else
      {
        tty.c_iflag = 0x0000; /* We don't need any input flags */
        tty.c_oflag = ONLCR | OPOST;
        tty.c_cflag = CREAD | CSIZE;
        tty.c_lflag = IEXTEN; /* Note - noncanonical mode, since no ICANON */

        tty.c_cc[VERASE] = 0x7F;   /* Since we're in noncanonical mode, we ignore
                                      backspace, and its value *should* be 127;
                                      to enable me to handle it, I make *sure* it's
                                      127, and then have a special case to map 127
                                      to 8 (^H) inside posix_getkey()               */

        if (tcsetattr(kbport,TCSANOW,&tty) < 0)
        {
          fprintf(stderr,"\nERROR:  unable to set tty attributes for %s\n",ctermid(NULL));
        }
      }

      /* Set up our "return immediately" structure for select */

      tvptr.tv_sec = 0;
      tvptr.tv_usec = 0;

    }
  }

  /* Initialize the read set to zero */

  FD_ZERO(&rset);

  /* And now turn on the read set */

  FD_SET(kbport,&rset);

  status = select(kbport + 1,&rset,NULL,NULL,&tvptr);

  if (status == -1) /* Error */
  {
    fprintf(stderr,"\nERROR:  posix_kbhit():  select() returned -1\n");
    exit(-1);
  }
  else if (status > 0)
  {
    if (FD_ISSET(kbport,&rset))
    {
      rtnval = 1;
    }
  }

  return(rtnval);

}

char posix_getkey(char *dst)
{
  char *extended_key = NULL;
  int extended_key_length = 0, numread = 0;
  char ch = 0;
  char rtnval = 0;

  if (kbport != -1)
  {
    read(kbport,&ch,1);

    if (ch == 27 && posix_kbhit())
    {
      read(kbport,&ch,1);

      if (ch == 91 && posix_kbhit())
      {
        do
        {
          numread = read(kbport,&ch,1);

          if ((numread == 1) && (ch != 126))
          {
            extended_key_length++;

            extended_key = (char *) realloc(extended_key,extended_key_length + 1);

            extended_key[extended_key_length - 1] = ch;

            /* Set the last element to zero */

            extended_key[extended_key_length] = 0;
          }
        }
        while ((numread == 1) && (ch != 126));

        ch = (char) atoi(extended_key);
        free(extended_key);

        *dst = ch;
        rtnval = 1; /* Extended key found */

      }
      else
      {
        *dst = ch;
        rtnval = 0;
      }
    }
    else if (ch == 127) /* Backspace */
    {
      *dst = 8;         /* Return ^H */
      rtnval = 0;
    }
    else
    {
      *dst = ch;
      rtnval = 0; /* Not a funckey */
    }
  }

  return(rtnval);
}

struct termios *posix_get_termsettings(char *devname)
{
  int port = 0;
  struct termios *rtnval = NULL;

  if (devname != (char *) NULL)
  {
    port = open(devname,O_RDONLY);

    if (port > -1)
    {

      rtnval = (struct termios *) malloc(sizeof(struct termios));

      if (rtnval != (struct termios *) NULL)
      {
        if (tcgetattr(port,rtnval) == -1)
        {
          free(rtnval);
          rtnval = (struct termios *) NULL;
        }
      }

      close(port);
    }
  }

  return(rtnval);
}

int posix_set_termsettings(char *devname, struct termios *termio)
{
  int port = 0;
  int rtnval = 0;

  if (devname != (char *) NULL)
  {
    port = open(devname,O_RDWR);

    if (port > -1)
    {

      if (tcsetattr(port,TCSANOW,termio) != -1)
      {
        rtnval = 1;
      }

      close(port);
    }
  }

  return(rtnval);
}

char *posix_console_name(void)
{
  return(ctermid(NULL));
}

void Sleep(int msec)
{
  usleep(msec*1000);

  return;
}
/*
int main(int argc, char **argv)
{
  int myport = 0;
  struct termios *settings = NULL;
  char key = 0, funckey = 0, done = 0, inchar = 0;

  if (argc > 1)
  {
    myport = posix_com_open(argv[1],9600,'N',8,1,0);

    settings = posix_get_termsettings(posix_console_name());

    if (myport != -1)
    {
      while (!done)
      {
        if (posix_com_dataready(myport))
        {
          if (posix_com_read(myport,&inchar))
          {
            if (isprint(inchar))
              printf("%c",inchar);
            else
              printf("<%03d>",inchar);
            fflush(stdout);
          }
        }

        if (posix_kbhit())
        {
          funckey = posix_getkey(&key);
          done = ((key == 27) && (!funckey));
          if (!done)
            posix_com_write(myport,key);
        }
      }

      posix_set_termsettings(posix_console_name(),settings);
    }
  }
  else
    printf("\nUsage: %s <port>\n\nWhere <port> has the format '/dev/com1'\n",argv[0]);
}

*/

