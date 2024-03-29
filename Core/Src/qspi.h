/*
 * qspi.h
 *
 *  Created on: 22 sty 2024
 *      Author: Sowa
 */

#ifndef SRC_QSPI_H_
#define SRC_QSPI_H_

/* MX25R6435F Macronix memory */
/* Size of the flash */
#define QSPI_FLASH_SIZE                      22
#define QSPI_PAGE_SIZE                       256

/* Read Operations */
#define READ_CMD                             0x03
#define FAST_READ_CMD                        0x0B
#define DUAL_OUT_READ_CMD                    0x3B
#define DUAL_INOUT_READ_CMD                  0xBB
#define QUAD_OUT_READ_CMD                    0x6B
#define QUAD_INOUT_READ_CMD                  0xEB

/* Program Operations */
#define PAGE_PROG_CMD                        0x02
#define QUAD_PAGE_PROG_CMD                   0x38

/* Erase Operations */
#define SECTOR_ERASE_CMD                     0x20
#define SUBBLOCK_ERASE_CMD                   0x52
#define BLOCK_ERASE_CMD                      0xD8
#define CHIP_ERASE_CMD                       0x60
#define CHIP_ERASE_CMD_2                     0xC7

#define PROG_ERASE_RESUME_CMD                0x7A
#define PROG_ERASE_RESUME_CMD_2              0x30
#define PROG_ERASE_SUSPEND_CMD               0x75
#define PROG_ERASE_SUSPEND_CMD_2             0xB0

/* Identification Operations */
#define READ_ID_CMD                          0x9F
#define READ_ELECTRONIC_ID_CMD               0xAB
#define READ_ELEC_MANUFACTURER_DEVICE_ID_CMD 0x90
#define READ_SERIAL_FLASH_DISCO_PARAM_CMD    0x5A

/* Write Operations */
#define WRITE_ENABLE_CMD                     0x06
#define WRITE_DISABLE_CMD                    0x04

/* Register Operations */
#define READ_STATUS_REG_CMD                  0x05
#define READ_CFG_REG_CMD                     0x15
#define WRITE_STATUS_CFG_REG_CMD             0x01

#define READ_SEC_REG_CMD                     0x2B
#define WRITE_SEC_REG_CMD                    0x2F

/* Power Down Operations */
#define DEEP_POWER_DOWN_CMD                  0xB9

/* Burst Operations */
#define SET_BURST_LENGTH_CMD                 0xC0

/* One-Time Programmable Operations */
#define ENTER_SECURED_OTP_CMD                0xB1
#define EXIT_SECURED_OTP_CMD                 0xC1

/* No Operation */
#define NO_OPERATION_CMD                     0x00

/* Reset Operations */
#define RESET_ENABLE_CMD                     0x66
#define RESET_MEMORY_CMD                     0x99
#define RELEASE_READ_ENHANCED_CMD            0xFF

/* Default dummy clocks cycles */
#define DUMMY_CLOCK_CYCLES_READ              8
#define DUMMY_CLOCK_CYCLES_READ_QUAD         6

/* End address of the QSPI memory */
#define QSPI_END_ADDR              (1 << QSPI_FLASH_SIZE)

/* Size of buffers */
#define BUFFERSIZE                 (COUNTOF(aTxBuffer) - 1)

/* Exported macro ------------------------------------------------------------*/
#define COUNTOF(__BUFFER__)        (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))


#endif /* SRC_QSPI_H_ */
