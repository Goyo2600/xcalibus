#define NB_PWR 10      	/* size of signal power ring buffer */
#define NB_PRB 20       /* size of probed ESSID ring buffer */
#define NB_AP  20	/* size of max ap to send */


struct AP_info
{
    struct AP_info *prev;     /* prev. AP in list         */
    struct AP_info *next;     /* next  AP in list         */
    unsigned long tinit;      /* first time seen 	  */    
    int channel;              /* AP radio channel         */
    int avg_power;            /* averaged signal power    */
    int power_index;          /* index in power ring buf. */
    int power_lvl[NB_PWR];    /* signal power ring buffer */
    int preamble;             /* 0 = long, 1 = short      */
    int ssid_length;          /* length of ssid           */
    unsigned char bssid[6];   /* the access point's MAC   */
    unsigned char essid[256]; /* ascii network identifier */
};


struct globals
{
    struct AP_info *ap_1st, *ap_end, ap_copy[NB_AP];
    
};