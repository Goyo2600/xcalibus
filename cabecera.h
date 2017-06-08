
//#define BigEndian
#define LittleEndian 	// deependiendo de la arquitectura del sistema embebido
								// si no se define esto, la comprobación se hará por medio del Link Quality
								
//#define CHECK_LICENSE	// comprueba la licencia


// tipos de datos ansi
typedef signed char     int8;
typedef unsigned short  uint16;
typedef short           int16;
typedef unsigned long	uint32;
typedef long           	int32;
typedef unsigned char   uchar;
typedef uchar           uint8;
typedef uint16          uchar16;

#define  kMAGIC 	"\x45\x4C\x50\x00" // ELP\0
#define  kTAM_ELP 	sizeof(T_header)+sizeof(T_device)+sizeof(T_data)
#define	 kMAX_CHURRO 	10
#define  kMAYOR		0
#define  kMENOR		1

#define	 SENDUDP	1
#define  CALIBRATE	2
#define  WARFILE	4
#define  PORT		8
#define  DELAY		16
#define	 VERBOSE	32
#define  APFOUNDS	64

//#define  kSYSRUTA "/sys/devices/pci0000:00/0000:00:12.0/net/ath0/statistics/tx_packets"
#define  kSYSRUTA 		"/sys/devices/pci0000:00/0000:00:1c.4/0000:03:00.0/net/eth0/statistics/tx_packets"
#define	kSYSRUTAESSID 		"/sys/module/ath9k/parameters/essid"
#define kSYSRUTASCANDELAY	"/sys/module/ath9k/parameters/scandelay"
#define kSYSRUTAAPTIME		"/sys/module/ath9k/parameters/aptime"

typedef struct {
	uchar		magic[4]; 	// 4 bytes 'ELP\0'
	uint16		version;	// 2 bytes	1	
	uint16		type;		// 2 bytes	1=RSSI data,2 ACK
	uint16		sequence;	// 2 bytes	0-65535
	uint32		timestamp;	// 4 bytes	36547
	uint16		length;		// 2 bytes	256
} T_header;						// total=16 bytes

typedef struct {
	int8		deviceMac[6] ;
	uint16		deviceType;
	uint16		batteryLevel;
	uint16		charging;
	uint16		scanReason;
	uint16		scannedChannels;
} T_device;

typedef struct {
	int8		AP_mac[6];
	uint16		dBm;
	uint16		channel;
	uint16		TxPower;
	uint32		TimeStamp;	
} T_data;


typedef struct {
	uint8		AP_mac[6];
	uint16		channel;
	int16		dBm;
}T_chur;


typedef struct {
	uint8		AP_mac_estudio[6];	// AP a estudiar
	int16		dBm_estudio;		// dBm
	uint16		lines_churro;		// lineas que tiene el churro para esa mac.
	T_chur 		churro[kMAX_CHURRO];	// cadena de AP's máximas.
}T_war;

