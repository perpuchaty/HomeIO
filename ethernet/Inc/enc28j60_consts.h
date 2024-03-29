/**
 * @addtogroup enc28j60
 * @{
 * @addtogroup enc28j60-consts ENC28J60 constants
 * @{
 */
#define ENC28J60_USE_PBUF
#define ENC_RAMSIZE (8 * 1024)
#define ETH_RST_GPIO_Port
typedef enum {
	/* the top 3 bits are used to indicate the bank. lowest bit means
	 * explicit bank, 110 means "present in all banks", 100 mean "don't
	 * know". thus, right-shifting by 6 gives bank number. */
	ENC_BANKMASK = 0xe0,

	ENC_BANKALL = 0xc0,
	ENC_BANK0 = 0x20,
	ENC_BANK1 = 0x60,
	ENC_BANK2 = 0xa0,
	ENC_BANK3 = 0xe0,
	/* initial value used when optimizing away bank changes */
	ENC_BANK_INDETERMINATE = 0x80,

	ENC_REGISTERMASK = 0x1f,

	/* actual registers start here */

	ENC_EIE = 0x1b | ENC_BANKALL,
	ENC_EIR = 0x1c | ENC_BANKALL,
	ENC_ESTAT = 0x1d | ENC_BANKALL,
#define ENC_ESTAT_CLKRDY 0x01
	ENC_ECON2 = 0x1e | ENC_BANKALL,
#define ENC_ECON2_PKTDEC (1<<6)
#define ENC_ECON2_AUTOINC (1<<7)
	ENC_ECON1 = 0x1f | ENC_BANKALL,
#define ENC_ECON1_RXEN (1<<2)
#define ENC_ECON1_TXRTS (1<<3)
#define ENC_ECON1_CSUMEN (1<<4)
#define ENC_ECON1_DMAST (1<<5)
#define ENC_ECON1_RXRST (1<<6)
#define ENC_ECON1_TXRST (1<<7)

	ENC_ERDPTL = 0x00 | ENC_BANK0,
	ENC_ERDPTH = 0x01 | ENC_BANK0,
	ENC_EWRPTL = 0x02 | ENC_BANK0,
	ENC_EWRPTH = 0x03 | ENC_BANK0,
	ENC_ETXSTL = 0x04 | ENC_BANK0,
	ENC_ETXSTH = 0x05 | ENC_BANK0,
	ENC_ETXNDL = 0x06 | ENC_BANK0,
	ENC_ETXNDH = 0x07 | ENC_BANK0,
	ENC_ERXSTL = 0x08 | ENC_BANK0,
	ENC_ERXSTH = 0x09 | ENC_BANK0,
	ENC_ERXNDL = 0x0a | ENC_BANK0,
	ENC_ERXNDH = 0x0b | ENC_BANK0,
	ENC_ERXRDPTL = 0x0c | ENC_BANK0,
	ENC_ERXRDPTH = 0x0d | ENC_BANK0,
	ENC_EDMASTL = 0x10 | ENC_BANK0,
	ENC_EDMASTH = 0x11 | ENC_BANK0,
	ENC_EDMANDL = 0x12 | ENC_BANK0,
	ENC_EDMANDH = 0x13 | ENC_BANK0,
	ENC_EDMACSL = 0x16 | ENC_BANK0,
	ENC_EDMACSH = 0x17 | ENC_BANK0,

	ENC_EPKTCNT = 0x19 | ENC_BANK1,

	ENC_MACON1 = 0x00 | ENC_BANK2,
#define ENC_MACON1_MARXEN 0x01
#define ENC_MACON1_PASSALL 0x02
#define ENC_MACON1_RXPAUS 0x04
#define ENC_MACON1_TXPAUS 0x08
	ENC_MACON2 = 0x01 | ENC_BANK2,
#define ENC_MACON2_MARST 0x80
	ENC_MACON3 = 0x02 | ENC_BANK2,
#define ENC_MACON3_FULLDUPLEX 0x01
#define ENC_MACON3_FRMLEN 0x02
#define ENC_MACON3_TXCRCEN 0x10
#define ENC_MACON3_FULLPADDING 0xe0
	ENC_MAIPGL = 0x06 | ENC_BANK2,
	ENC_MAIPGH = 0x07 | ENC_BANK2,
	ENC_MICMD = 0x12 | ENC_BANK2,
#define ENC_MICMD_MIIRD 1
	ENC_MIREGADR = 0x14 | ENC_BANK2,
	ENC_MIWRL = 0x16 | ENC_BANK2,
	ENC_MIWRH = 0x17 | ENC_BANK2,
	ENC_MIRDL = 0x18 | ENC_BANK2,
	ENC_MIRDH = 0x19 | ENC_BANK2,

	ENC_MAADR5 = 0x00 | ENC_BANK3,
	ENC_MAADR6 = 0x01 | ENC_BANK3,
	ENC_MAADR3 = 0x02 | ENC_BANK3,
	ENC_MAADR4 = 0x03 | ENC_BANK3,
	ENC_MAADR1 = 0x04 | ENC_BANK3,
	ENC_MAADR2 = 0x05 | ENC_BANK3,
	ENC_EBSTSD = 0x06 | ENC_BANK3,
	ENC_EBSTCON = 0x07 | ENC_BANK3,
#define ENC_EBSTCON_PSEL 0x10
#define ENC_EBSTCON_PATTERNSHIFTFILL 0x08
#define ENC_EBSTCON_ADDRESSFILL 0x04
#define ENC_EBSTCON_RANDOMFILL 0x00
#define ENC_EBSTCON_TME 2
#define ENC_EBSTCON_BISTST 1
	ENC_EBSTCSL = 0x08 | ENC_BANK3,
	ENC_EBSTCSH = 0x09 | ENC_BANK3,
	ENC_MISTAT = 0x0a | ENC_BANK3,
	ENC_EREVID = 0x12 | ENC_BANK3,
#define ENC_MISTAT_BUSY 1
} enc_register_t;


/* mii registers */
typedef enum {
	ENC_PHCON1 = 0x00,
	ENC_PHSTAT1 = 0x01,
	ENC_PHID1 = 0x02,
	ENC_PHID2 = 0x03,
	ENC_PHCON2 = 0x10,
	ENC_PHSTAT2 = 0x11,
	ENC_PHIE = 0x12,
	ENC_PHIR = 0x13,
	ENC_PHLCON = 0x14,
} enc_phreg_t;

typedef enum {
	ENC_LCFG_ON = 0x8,
	ENC_LCFG_OFF = 0x9,
	ENC_LCFG_BLINKFAST = 0xa,
	ENC_LCFG_BLINKSLOW = 0xb,

	ENC_LCFG_MASK = 0xf,
} enc_lcfg_t;

typedef enum {
	/* these are the offsets of ENC_LCFG */
	ENC_LEDA = 8,
	ENC_LEDB = 4,
} enc_led_t;

#define ENC_READLOCATION_ANY (uint16_t)(~0)

/** @} @} */
