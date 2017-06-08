  /*    Ekahau-SiteSurvey-Client [[::Xcalibus::]]
   *
   *    Copyright (C) 2007,2008-2015 Gregorio Ortiz
   *    goyo2600@gmail.com
   */


#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netdb.h>
#include <net/if.h>
#include <netinet/in.h>
#include <time.h>
#include <sys/time.h>
#include "apinfo.h"
#include "cabecera.h"

// ISO VT100/220 definitions
#define VT_COL_TEXT_BLACK    "30"
#define VT_COL_TEXT_RED      "31"
#define VT_COL_TEXT_GREEN    "32"
#define VT_COL_TEXT_YELLOW   "33"
#define VT_COL_TEXT_BLUE     "34"
#define VT_COL_TEXT_MAGENTA  "35"
#define VT_COL_TEXT_CYAN     "36"
#define VT_COL_TEXT_WHITE    "37"
#define VT_COL_BACK_BLACK    "40"
#define VT_COL_BACK_RED      "41"
#define VT_COL_BACK_GREEN    "42"
#define VT_COL_BACK_YELLOW   "43"
#define VT_COL_BACK_BLUE     "44"
#define VT_COL_BACK_MAGENTA  "45"
#define VT_COL_BACK_CYAN     "46"
#define VT_COL_BACK_WHITE    "47"
//
#define VT_GOTOXY(X,Y)  "\33["Y";"X"f"
#define VT_COLOR(C)     "\33["C"m"
#define VT_RESET        "\33[m"
#define VT_REVERSE      "\33[7m"
#define VT_UNREVERSE    "\33[27m"
#define VT_BOLD         "\33[1m"
#define VT_UNBOLD       "\33[22m"
#define VT_BLINK        "\33[5m"
#define VT_UNBLINK      "\33[25m"
//
#define VT_CLREOL       "\33[K"
#define VT_CLRSOL       "\33[1K"
#define VT_CLRLIN       "\33[2K"
#define VT_CLREOS       "\33[J"
#define VT_CLRSOS       "\33[1J"
#define VT_CLRSCR       "\33[2J"

#define LittleEndian		// para intel
#define WITH_UDP_RESPONSE

extern int posix_com_open (char *, int, char, int, int, int);
extern int posix_com_write_string (int, char *);

unsigned long
ByteSwap32 (unsigned long nLongNumber)
{
#ifdef LittleEndian
  return (((nLongNumber & 0x000000FF) << 24) +
	  ((nLongNumber & 0x0000FF00) << 8) +
	  ((nLongNumber & 0x00FF0000) >> 8) +
	  ((nLongNumber & 0xFF000000) >> 24));
#endif

#ifdef BigEndian
  return nLongNumber;
#endif
}

unsigned short
ByteSwap16 (unsigned short nValue)
{
#ifdef LittleEndian
  return (((nValue >> 8)) | (nValue << 8));
#endif

#ifdef  BigEndian
  return nValue;
#endif

}

int
SustitucionPorTruq (struct globals *G, T_war * truq, int linea)
{

  int i;
  struct AP_info *ap_cur;

  ap_cur = &G->ap[0];		// Punto de acceso con mayor rssi


  for (i = 0; i < truq[linea].lines_churro; i++)
    {
      memcpy (ap_cur[i].bssid, truq[linea].churro[i].AP_mac, 6);
      ap_cur[i].channel = truq[linea].churro[i].channel;
      ap_cur[i].avg_power = truq[linea].churro[i].dBm;
      ap_cur[i].power_index = 0;
    }
  G->numregs = i - 1;

  printf ("%s%sVALOR NORMALIZADO.%s\n", VT_BOLD, VT_COLOR (VT_COL_TEXT_WHITE),
	  VT_RESET);
  return 0;


}


void
PrintBuffer (unsigned const char *buf, int longitud)
{

  unsigned const char *p = buf;
  while (longitud--)
    {
      printf ("%02X,", *p++);
    }
  printf ("\n\n");
}

int
Tiempoenms ()
{

  struct timeval tv;
  static int msec_ini = 0;
  static unsigned long def = 0;
  int msec_fin = 0, temp;

  gettimeofday (&tv, NULL);

  if (msec_ini == 0)
    {
      msec_ini = tv.tv_sec * 1000 + tv.tv_usec / 1000;
      def = 0;
      return 0;
    }
  else
    {
      temp = msec_fin = tv.tv_sec * 1000 + tv.tv_usec / 1000;
      msec_fin -= msec_ini;
      msec_ini = temp;
      def += msec_fin;
      if (def > 50 * 1000)
	{			//al cabo de un minuto m�s menos reestblece contadores
	  msec_ini = 0;
	}
      return 0x0001;
    }
}

int
recvfromTimeOut (int socket, long sec, long usec)
{
  int res;
  // Setup timeval variable
  struct timeval timeout;
  timeout.tv_sec = sec;
  timeout.tv_usec = usec;
  // Setup fd_set structure
  fd_set fds;
  FD_ZERO (&fds);
  FD_SET (socket, &fds);
  // Return value:
  // -1: error occured
  // 0: timed out
  // >0: data ready to be read
  res = select (socket + 1, &fds, 0, 0, &timeout);
  FD_CLR (socket, &fds);
  return res;
}


// envia el buffer al servidor
int
SendBuffer (unsigned char *buffer, int longitud_buffer, char *server_ip,
	    char *server_port)
{
  int sock, n, length, r = -1;	//, res;
  unsigned long ts;
  struct sockaddr_in server;
  struct hostent *hp;
//  FILE *f;
//  char svalue[32];
//  unsigned long int value1, value2;

  sock = socket (AF_INET, SOCK_DGRAM, 0);
  if (sock < 0)
    {
      fprintf (stderr, "Socket error.\n");
      return -1;
    }
  server.sin_family = AF_INET;
  hp = gethostbyname (server_ip);
  if (hp == 0)
    {
      fprintf (stderr, "Unknown %s host.\n", server_ip);
      return -1;
    }

  bcopy ((char *) hp->h_addr, (char *) &server.sin_addr, hp->h_length);
  server.sin_port = htons (atoi (server_port));
  length = sizeof (struct sockaddr_in);
  // copia el timestamp;
  ts = ByteSwap32 (Tiempoenms ());
  memcpy ((buffer + 10), &ts, 4);


/*#ifndef WITH_UDP_RESPONSE
  //Leemos paquetes enviados vía wifi
  f = fopen (kSYSRUTA, "r");

  fgets (svalue, 32, f);
  value1 = atol (svalue);
#endif
*/
  n = sendto (sock, buffer,
	      longitud_buffer, MSG_DONTWAIT | MSG_DONTROUTE,
	      (struct sockaddr *) &server, length);
  if (n < 0)
    {
      close (sock);
      fprintf (stderr, "Sending error.\n");
      return -1;
    }
//  else
//    {
//#ifdef WITH_UDP_RESPONSE
/*
      res = recvfromTimeOut (sock, 1, 700000);
      switch (res)
	{
	case 0:
	  // Timed out, do whatever you want to handle this situation
	  r = -1;
	  break;
	case -1:
	  // Error occured, maybe we should display an error message?
	  r = -1;
	  break;
	default:
	  // Ok the data is ready, call recvfrom() to get it then
	  n =
	    recvfrom (sock, buffer, 65536, MSG_WAITALL,
		      (struct sockaddr *) &server, &length);
	  if (n < 0)
	    {
	      fprintf(stderr,"Answer from server not received.\n");
	      r = -1;
	    }
	  else
	    r = 0;
	}

#else
      do
	{
	  rewind (f);
	  fgets (svalue, 32, f);
	  value2 = atol (svalue);
	  usleep (5000);
	}
      while (value1 == value2);
*/
//      fclose (f);
  r = 0;

//#endif
//    }
  close (sock);
  return r;
}



// Rellena datagrama: cabecera+device
void
FormaDatagrama (T_header * cabecera, T_device * device, struct globals *G)
{


  int sd;
  static unsigned int timestamp = 0;

  static uint16 num_seq = 0;
  static uint8 mac_ifaz[6];
  unsigned char *a;
  struct ifreq ifr;



  sd = socket (AF_INET, SOCK_DGRAM, IPPROTO_IP);
  if (sd < 0)
    {
      fprintf (stderr, "Socket Error.\n");
      exit (-1);
    }
  strncpy ((char *) &ifr.ifr_name, "eth0", IFNAMSIZ);

  if (ioctl (sd, SIOCGIFHWADDR, &ifr) < 0)
    {
      perror ("Error ioctl SIOCGIFHWADDR");
      close (sd);
      exit (-1);
    }

  a = (unsigned char *) &ifr.ifr_hwaddr.sa_data;

  mac_ifaz[0] = a[0];
  mac_ifaz[1] = a[1];
  mac_ifaz[2] = a[2];
  mac_ifaz[3] = a[3];
  mac_ifaz[4] = a[4];
  mac_ifaz[5] = a[5];

  close (sd);

  strcpy ((char *) cabecera->magic, kMAGIC);
  cabecera->version = ByteSwap16 (1);
  cabecera->type = ByteSwap16 (1);

  // numero de secuencia no es requerido si want_ack is not set
  //cabecera->sequence=ByteSwap16(0x0000);
  srand ((unsigned) time (NULL));

  if (num_seq == 0)
    num_seq = 1 + (int) (32768.0 * rand () / (RAND_MAX + 1.0));
  else
    num_seq++;

  cabecera->sequence = ByteSwap16 (num_seq);

  // TimeStamp en ms->> dejamos esto hasta el final...(ver sendbuffer)
  //cabecera->timestamp=ByteSwap32(Tiempoenms());


  // longitud del paquete - el header
  cabecera->length = ByteSwap16 ((G->numregs + 1) * 16);
  memcpy (device->deviceMac, mac_ifaz, sizeof (uint8) * 6);

  // es una atheros
  //device->deviceType=ByteSwap16(1002); 

  // es una T201
  device->deviceType = ByteSwap16 (999);
  //es una T301
  //device->deviceType=ByteSwap16(0x0001); 

  // alimentacion a tope
  device->batteryLevel = ByteSwap16 (100);

  // no hay bateria
  device->charging = ByteSwap16 (0);

  // escaneo periodico
  if (timestamp == 0)
    {				// en primera ejecución
      device->scanReason = ByteSwap16 (0x8003);
    }
  else
    {
      device->scanReason = ByteSwap16 (0x0003);
    }
  // escanea todos los canales
  //device->scannedChannels=ByteSwap16(0x1FF);
  // escanea los canales 1,6,11
  device->scannedChannels = ByteSwap16 (0x421);
}


// Rellena el buffer con el contenido de cabecera+device+data
int
FillBuffer (unsigned char *dest, T_header cabecera, T_device device,
	    struct globals *G, T_war * truq, int lines_war, int flag)
{

  int i, indice = 0, timestamp, txpower, avgpower, channel;
  unsigned char *ini = dest;
  struct AP_info *ap_cur;

  ap_cur = &G->ap[0];		// Punto de acceso con mayor rssi


  memcpy (dest, &cabecera.magic, sizeof (uchar) * 4);
  dest += sizeof (uchar) * 4;
  memcpy (dest, &cabecera.version, sizeof (uint16));
  dest += sizeof (uchar) * 2;
  memcpy (dest, &cabecera.type, sizeof (uint16));
  dest += sizeof (uchar) * 2;
  memcpy (dest, &cabecera.sequence, sizeof (uint16));
  dest += sizeof (uchar) * 2;

  memcpy (dest, &cabecera.timestamp, sizeof (uchar) * 4);
  dest += sizeof (uchar) * 4;
  memcpy (dest, &cabecera.length, sizeof (uint16));
  dest += sizeof (uchar) * 2;
  memcpy (dest, &device.deviceMac, sizeof (int8) * 6);
  dest += sizeof (int8) * 6;
  memcpy (dest, &device.deviceType, sizeof (uint16));
  dest += sizeof (uchar) * 2;
  memcpy (dest, &device.batteryLevel, sizeof (uint16));
  dest += sizeof (uchar) * 2;
  memcpy (dest, &device.charging, sizeof (uint16));
  dest += sizeof (uchar) * 2;
  memcpy (dest, &device.scanReason, sizeof (uint16));
  dest += sizeof (uchar) * 2;
  memcpy (dest, &device.scannedChannels, sizeof (uint16));
  dest += sizeof (uchar) * 2;

  if (flag & WARFILE)
    {				// si existe fichero de War of the worlds
      for (i = 0; i < lines_war; i++)
	{
	  if (memcmp (ap_cur->bssid, truq[i].AP_mac_estudio, 6) == 0
	      && ap_cur->avg_power >= truq[i].dBm_estudio)
	    {			// encontrada linea, modifica datos

	      SustitucionPorTruq (G, truq, i);
	      break;		// sólo coge un valor del fichero
	    }
	}
    }


  while (indice < G->numregs)
    {
      memcpy (dest, ap_cur[indice].bssid, sizeof (int8) * 6);
      dest += sizeof (int8) * 6;

      avgpower = ByteSwap16 (ap_cur[indice].avg_power);
      memcpy (dest, &avgpower, sizeof (uint16));
      dest += sizeof (uint16);

      channel = ByteSwap16 (ap_cur[indice].channel);
      memcpy (dest, &channel, sizeof (uint16));
      dest += sizeof (uint16);

      txpower = 0;
      memcpy (dest, &txpower, sizeof (uint16));
      dest += sizeof (uint16);

      timestamp = ByteSwap32 (1);
      memcpy (dest, &timestamp, 4);
      dest += 4;


      printf
	("%s%02X:%02X:%02X:%02X:%02X:%02X : rssi = %02d [%2d] [%02d]%s%s\n",
	 VT_COLOR (VT_COL_TEXT_GREEN), ap_cur[indice].bssid[0],
	 ap_cur[indice].bssid[1], ap_cur[indice].bssid[2],
	 ap_cur[indice].bssid[3], ap_cur[indice].bssid[4],
	 ap_cur[indice].bssid[5], ap_cur[indice].avg_power,
	 ap_cur[indice].channel, ap_cur[indice].power_index, VT_CLREOL,
	 VT_RESET);



      indice++;
    }

  printf ("\n");
  return dest - ini;		// tamaño total del paquete
}



int
SendBufferToEkahau (struct globals *G, T_war * truq,
		    int flag, int lines_war, char *ip, char *port)
{
  T_header cabecera;
  T_device device;
  unsigned char buffer[8192];
  int size;

  FormaDatagrama (&cabecera, &device, G);
  size = FillBuffer (buffer, cabecera, device, G, truq, lines_war, flag);
  if (size > 16)
    {
      SendBuffer (buffer, size, ip, port);
    }

  return 0;
}

int
SendBufferToSerial (T_data * data, struct globals *G, T_war * truq,
		    char *device, int flag, int lines_war)
{

  static int myport = -1, state = 0;
  int count = 0, i, status = 0;
  T_data *cur = data;
  struct AP_info *ap_cur;
  struct timeval tv;
  static int msec_ini = 0;
  static unsigned long def = 0;	// valor inicial
  int msec_fin = 0, temp;
  int indice = 0;
  char info[] =
    "Ekahau L i n u x  TAG\r\nSerial Number         : 1111-2222-666666\r\nManufacturing date    : 2006-03-01\r\nKernel image          : Date 2006-03-27 10:11:01 UTC  size 1087464 bytes\r\nFilesystem image      : Date 2006-11-27 09:38:55 UTC  size 1720256 bytes\r\nSoftware version      : 1.0.7 (Nov 27 2006 11:38:50)\r\nPIC firmware          : 0.6a (20050622) B\r\nCPU                   : AT91RM9200\r\nWLAN chipset          : Hermes 2\r\nWLAN firmware version : 3.2.36 (ComponentID:0x001f)\r\nMAC address           : 00:10:c6:fd:bd:7b\r\n";
//   Neomedia WLAN TAG DLA
  char linea[256], buffer[512], TimeStamp[16];

  gettimeofday (&tv, NULL);
  if (msec_ini == 0)
    {
      msec_ini = tv.tv_sec * 1000 + tv.tv_usec / 1000;
      def = 6315;		// por poner un valor inicial
    }
  else
    {
      temp = msec_fin = tv.tv_sec * 1000 + tv.tv_usec / 1000;
      msec_fin -= msec_ini;
      msec_ini = temp;
      def += msec_fin;
    }

  sprintf (TimeStamp, "T%05lu:", def);

  ap_cur = &G->ap[0];		// AP con mayot rssi
  if (ap_cur == NULL)
    return -1;


  if (ap_cur != NULL)
    {
      strcpy (buffer, TimeStamp);
      strcat (buffer, " START_SCAN_RESULTS\r\n");
    }

// si hay warfile se envia tb en el calibrado
  if (flag & WARFILE)
    {				// si existe fichero de War of the worlds
      for (i = 0; i < lines_war; i++)
	{
	  if (memcmp (ap_cur->bssid, truq[i].AP_mac_estudio, 6) == 0
	      && ap_cur->avg_power >= truq[i].dBm_estudio)
	    {			// encontrada linea, modifica datos

	      SustitucionPorTruq (G, truq, i);

	      break;		// sólo coge un valor del fichero
	    }
	}
    }

  while (count < G->numregs)
    {

      indice++;
      // copia la MAC del access point en la estructura
      memcpy (cur->AP_mac, ap_cur->bssid, sizeof (ap_cur->bssid));

      // copia el dBm en la estructura
      cur->dBm = ByteSwap16 (ap_cur->avg_power);


      printf
	("%s%02X:%02X:%02X:%02X:%02X:%02X : rssi = %02d [%2d] [%02d]%s%s\n",
	 VT_COLOR (VT_COL_TEXT_GREEN), ap_cur->bssid[0],
	 ap_cur->bssid[1], ap_cur->bssid[2], ap_cur->bssid[3],
	 ap_cur->bssid[4], ap_cur->bssid[5], ap_cur->avg_power,
	 ap_cur->channel, ap_cur->power_index, VT_CLREOL, VT_RESET);
      // copia el channel en la estructura
      cur->channel = ByteSwap16 (ap_cur->channel);
      // copia el TxPower en la estructura
      // de momento lo ponemos  a zero
      cur->TxPower = ByteSwap16 (0);
      // copia el TimeStamp (simulacion de 1ms) ???
      cur->TimeStamp = ByteSwap32 (0x0001);

      sprintf (linea,
	       " <-%d\t%d\t%02X:%02x:%02x:%02x:%02x:%02x\t%s->\r\n",
	       ap_cur->channel, ap_cur->avg_power, ap_cur->bssid[0],
	       ap_cur->bssid[1], ap_cur->bssid[2], ap_cur->bssid[3],
	       ap_cur->bssid[4], ap_cur->bssid[5], ap_cur->essid);
      strcat (buffer, TimeStamp);
      strcat (buffer, linea);

      cur = &cur[++count];


      ap_cur = &G->ap[count];
      if (ap_cur == NULL)
	break;

    }

  if (flag & CALIBRATE)
    {
      strcat (buffer, TimeStamp);
      strcat (buffer, " END_SCAN_RESULTS\xC2\xA4\r");

      if (myport == -1)
	{
	  myport = posix_com_open (device, 9600, 'N', 8, 1, 0);
	}
      if (myport != -1)
	{
	  if (state < 10)
	    {
	      posix_com_write_string (myport, info);
	      state++;
	    }
	  posix_com_write_string (myport, buffer);
	}
      else
	{
	  fprintf (stderr, "Serial port: Error\n");
	  status = -1;
	}
    }
  return status;
}

int
hex2bin (char c1, char c2)
{
  char hexchars[] = "0123456789abcdefABCDEF";
  char *p;
  int val, val2;

  p = strchr (hexchars, c1);
  val = p - hexchars;
  if (val > 15)
    val = val - 6;


  p = strchr (hexchars, c2);
  val2 = p - hexchars;
  if (val2 > 15)
    val2 = val2 - 6;

  return val * 16 + val2;
}

int
LeerFicheroWarFile (char *filename, T_war * truq)
{
  FILE *war;
  char linea[512], *token;
  int indice = 0, indice2 = 0;

  war = fopen (filename, "r");

  if (war == NULL)
    {
      fprintf (stderr, "File %s not exists.\n", filename);
      return -1;
    }

  fgets (linea, 256, war);
  token = strtok (linea, " ");

  while (token != NULL)
    {

      // parsea la MAC  

      truq[indice].AP_mac_estudio[0] = hex2bin (token[0], token[1]);
      truq[indice].AP_mac_estudio[1] = hex2bin (token[3], token[4]);
      truq[indice].AP_mac_estudio[2] = hex2bin (token[6], token[7]);
      truq[indice].AP_mac_estudio[3] = hex2bin (token[9], token[10]);
      truq[indice].AP_mac_estudio[4] = hex2bin (token[12], token[13]);
      truq[indice].AP_mac_estudio[5] = hex2bin (token[15], token[16]);

      token = strtok (NULL, " ");
      //  parsea el dBm
      truq[indice].dBm_estudio = atoi (token);
      token = strtok (NULL, " ");

      for (indice2 = 0; indice2 < kMAX_CHURRO && token; indice2++)
	{
	  // parseamos el churro
	  // parseamos la mac del churro
	  truq[indice].churro[indice2].AP_mac[0] =
	    hex2bin (token[0], token[1]);
	  truq[indice].churro[indice2].AP_mac[1] =
	    hex2bin (token[3], token[4]);
	  truq[indice].churro[indice2].AP_mac[2] =
	    hex2bin (token[6], token[7]);
	  truq[indice].churro[indice2].AP_mac[3] =
	    hex2bin (token[9], token[10]);
	  truq[indice].churro[indice2].AP_mac[4] =
	    hex2bin (token[12], token[13]);
	  truq[indice].churro[indice2].AP_mac[5] =
	    hex2bin (token[15], token[16]);


	  // parsea el channel del churro
	  token = strtok (NULL, " ");

	  truq[indice].churro[indice2].channel = atoi (token);
	  // parsea el dBm del churro
	  token = strtok (NULL, " ");
	  truq[indice].churro[indice2].dBm = atoi (token);
	  if (indice2 < kMAX_CHURRO - 1)
	    token = strtok (NULL, " ");
	}
      truq[indice].lines_churro = indice2 + 1;
      if (fgets (linea, 256, war) != NULL)
	token = strtok (linea, " ");
      else
	token = NULL;
      indice++;
    }
  fclose (war);
  return indice;
}

int
LeerParametroScanDelay ()
{
  FILE *ksys;
  char scandelay[8];

  ksys = fopen (kSYSRUTASCANDELAY, "r");
  if (ksys == NULL)
    {
      fprintf (stderr, "Can not open:%s\n", kSYSRUTASCANDELAY);
      return -1;
    }
  fgets (scandelay, 8, ksys);
  fclose (ksys);
  return atoi (scandelay);
}

int
LeerParametroEssid (char *cad)
{
  size_t ln;
  FILE *ksys;

  ksys = fopen (kSYSRUTAESSID, "r");
  if (ksys == NULL)
    {
      fprintf (stderr, "Can not open:%s\n", kSYSRUTAESSID);
      return -1;
    }
  if (fgets (cad, 32, ksys) == NULL)
    strcpy (cad, "No Filter");
  else
    {
      ln = strlen (cad) - 1;
      if (cad[ln] == '\n')
	cad[ln] = '\0';
    }


  fclose (ksys);
  return 0;
}

int
LeerParametroAPTime ()
{
  FILE *ksys;
  char aptime[8];

  ksys = fopen (kSYSRUTAAPTIME, "r");
  if (ksys == NULL)
    {
      fprintf (stderr, "Can not open:%s\n", kSYSRUTAAPTIME);
      return -1;
    }
  fgets (aptime, 8, ksys);
  fclose (ksys);
  return atoi (aptime);

}

int
PrintVerboseInfo (int numaps, int delay, int argc, char *argv[])
{
  int i;
  double elapsedTime;
  char essidfilter[32];
  static bool start = 0;
  struct timeval t2;
  static struct timeval t1;

  if (start == false)
    {
      gettimeofday (&t1, NULL);
      start = true;
    }
  else
    {
      gettimeofday (&t2, NULL);
      elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;	// sec to ms
      elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
      t1.tv_sec = t2.tv_sec;
      t1.tv_usec = t2.tv_usec;
    }

  LeerParametroEssid (essidfilter);
  printf
    ("[[:: Xcalibus ::]] version  : v20151021\nAccess Points  founds       : %d\nKernel scandelay (ms)       : %d\nKernel Essid Filter         : %s\nKernel APTime (ms)          : %d\nDelay between sendings (ms) : %d   (real:%.2f)\n",
     numaps, LeerParametroScanDelay (), essidfilter, LeerParametroAPTime (),
     delay, elapsedTime);
  printf ("Xcalibus Parameters         : ");
  for (i = 0; i < argc - 1; i++)
    {
      printf ("%s ", argv[i + 1]);
    }
  printf ("\n");
  return 0;
}

int
ReadMacAddress (char *macaddress)
{

  struct ifreq s;
  int fd = socket (PF_INET, SOCK_DGRAM, IPPROTO_IP);

  strcpy (s.ifr_name, "eth0");
  if (0 == ioctl (fd, SIOCGIFHWADDR, &s))
    {
      memcpy (macaddress, s.ifr_addr.sa_data, 6);
      return 0;
    }
  return 1;
}

//Fichero de 124 caracteres aleatorios donde:
// posicion 10 xor 12 == eth[0]
// posicion 60 xor 50 == eth[1]
// posicion 85 xor 20 == eth[2]
// posicion 93 xor 39 == eth[3]
// posicion 28 xor 82 == eth[4]
// posicion 43 xor 34 == eth[5]


char
LeerByteLicenseFile (FILE * f, int pos1, int pos2)
{
  unsigned char r;
  fseek (f, pos1, SEEK_SET);
  r = fgetc (f);

  fseek (f, pos2, SEEK_SET);
  r = r ^ fgetc (f);
  return r;
}

int
CheckCheckSum (FILE * f)
{
  unsigned int ck = 0, sum = 0, indice = 0, k;
  fseek (f, 0, SEEK_SET);
  while (indice++ < 122)
    {
      k = fgetc (f);
      ck += k;
    }
  sum = fgetc (f) + fgetc (f) * 256;
  if (sum != ck)
    return 1;
  return 0;
}

int
ReadLicenseFile ()
{
  unsigned int i;
  FILE *licFile;
  unsigned char lic[6];
  char mac[6], secret[] = "0sppu0ydbmjcvt0mjdfotf/mjd";

  // modificar texto license.lic"  
  for (i = 0; i < strlen (secret); i++)
    secret[i] = secret[i] - 1;
  if ((licFile = fopen (secret, "r")) == NULL)
    return 1;
  if (ReadMacAddress (mac))
    return 1;

  lic[0] = LeerByteLicenseFile (licFile, 10, 12);
  lic[1] = LeerByteLicenseFile (licFile, 60, 52);
  lic[2] = LeerByteLicenseFile (licFile, 85, 20);
  lic[3] = LeerByteLicenseFile (licFile, 93, 39);
  lic[4] = LeerByteLicenseFile (licFile, 28, 82);
  lic[5] = LeerByteLicenseFile (licFile, 43, 34);
  if (memcmp (mac, lic, 6))
    return 1;
  if (CheckCheckSum (licFile))
    return 1;
  fclose (licFile);
  return 0;
}

int
main (int argc, char **argv)
{

  int index, c, flag, num, lines_war, numAPs = 5,delay = 500;
  char line[80], *warfile = NULL, *ip = NULL, *port = NULL, *device = NULL;
  double ExecutionTime;
  struct timeval t1, t2;

  FILE *proc_file;
  T_data data[32];
  T_war truq[64];
  struct globals G;

  while ((c = getopt (argc, argv, "s:p:c:f:d:n:v")) != -1)
    {
      switch (c)
	{
	case 's':
	  {
	    flag |= SENDUDP;
	    ip = optarg;
	    break;
	  }
	case 'p':
	  {
	    flag |= PORT;
	    port = optarg;
	    break;
	  }
	case 'n':
	  {
	    flag |= APFOUNDS;
	    numAPs = atoi(optarg);
	    break;
	  }
	  
	case 'c':
	  {
	    flag |= CALIBRATE;
	    device = optarg;
	    break;
	  }
	case 'f':
	  {
	    flag |= WARFILE;
	    warfile = optarg;
	    break;
	  }
	case 'd':
	  {
	    flag |= DELAY;
	    delay = atoi (optarg);
	    break;
	  }
	case 'v':
	  {
	    flag |= VERBOSE;
	    break;
	  }

	case '?':
	  {

	    return -1;
	  }
	default:
	  {
	    abort ();
	  }
	}
    }

  for (index = optind; index < argc; index++)
    printf ("Non-option arguments %s\n", argv[index]);

  /* calibrado y envio son excluyentes */
  if ((flag & CALIBRATE) && (flag & SENDUDP))
    {
      fprintf (stderr, "Options -c and -s are mutually exclusive.\n");
      return -1;
    }
  /* O calibrado O envio con puerto */
  if (!((flag & CALIBRATE) || ((flag & SENDUDP) && (flag & PORT))) || !flag)
    {
      fprintf (stderr,
	       "Syntax error: xcalibus [-s ip -p port | -c device] [-f configwarfile] [-n num] [-d delay] [-v]\n\
	        -s: Ekahau positioning engine IP\n\
	        -p: TCP port from Ekahau Positioning System\n\
	        -c: Calibrate with device\n\
	        -f: Especifies WarFile filename\n\
                -d: Delay in ms before sending, default 500ms\n\
                -n: APs founds as max, default 5\n\
                -v: print verbose information\n\n");
      return -1;
    }


  /* si no existe el modulo salimos */
  if ((proc_file = fopen ("/proc/ekahau-scan", "rt")) == NULL)
    {
      fprintf (stderr, "Error, scan module not loaded.\n");
      return -1;
    }
  /* hay warfile */
  if ((flag & WARFILE))
    {
      if ((lines_war = LeerFicheroWarFile (warfile, truq)) == -1)
	{
	  fprintf (stderr, "syntax error in warfile.\n");
	  return -1;
	}
    }
  if ((flag & APFOUNDS)) {
    if(numAPs <=0 || numAPs >= NB_AP-1) 
      numAPs=5;  
  }
  // no decimos nada ni hacemos nada
  if (ReadLicenseFile () != 0)
    return -1;
  setbuf (stdout, NULL);
  while (1)
    {
      gettimeofday (&t1, NULL);
      printf ("\033[2J\033[1;1H");
      num = 0;

      while (fgets (line, 80, proc_file) != NULL  && num < numAPs)
	{
	  sscanf (line, "%X:%X:%X:%X:%X:%X : rssi = %d [%d] [%d] %s",
		  (unsigned int *) &G.ap[num].bssid[0],
		  (unsigned int *) &G.ap[num].bssid[1],
		  (unsigned int *) &G.ap[num].bssid[2],
		  (unsigned int *) &G.ap[num].bssid[3],
		  (unsigned int *) &G.ap[num].bssid[4],
		  (unsigned int *) &G.ap[num].bssid[5], &G.ap[num].avg_power,
		  &G.ap[num].channel, &G.ap[num].power_index,
		  G.ap[num].essid);

      num++;

	}
      G.numregs = num;
      if (flag & VERBOSE)
	PrintVerboseInfo (num, delay, argc, argv);

      if (num)
	{
	  if (flag & CALIBRATE)
	    {
	      SendBufferToSerial (data, &G, truq, device, flag, lines_war);
	    }
	  if (flag & SENDUDP)
	    {
	      SendBufferToEkahau (&G, truq, flag, lines_war, ip, port);
	    }
	}

      fclose (proc_file);
      proc_file = fopen ("/proc/ekahau-scan", "rt");

      gettimeofday (&t2, NULL);
      ExecutionTime = (t2.tv_sec - t1.tv_sec) * 1000.0;	// sec to ms
      ExecutionTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
      t1.tv_sec = t2.tv_sec;
      t1.tv_usec = t2.tv_usec;
      if (delay - ExecutionTime > 0)
	usleep ((delay - ExecutionTime) * 1000);
    }

  return 0;
}
