#ifndef __BOOTLOADER_H__
#define __BOOTLOADER_H__
#include "stm32f4xx.h"
#include "usart.h"

//version 1.0
#define BL_VERSION 0x10

// our bootloader commands

//#define  <command name >	<command_code>

//This command is used to read the bootloader version from the MCU
#define BL_GET_VER				0x51

//This command is used to know what are the commands supported by the bootloader
#define BL_GET_HELP				0x52

//This command is used to read the MCU chip identification number
#define BL_GET_CID				0x53

//This command is used to read the FLASH Read Protection level.
#define BL_GET_RDP_STATUS		0x54

//This command is used to jump bootloader to specified address.
#define BL_GO_TO_ADDR			0x55

//This command is used to mass erase or sector erase of the user flash .
#define BL_FLASH_ERASE          0x56

//This command is used to write data in to different memories of the MCU
#define BL_MEM_WRITE			0x57

//This command is used to enable or disable read/write protect on different sectors of the user flash .
#define BL_EN_RW_PROTECT		0x58

//This command is used to read data from different memories of the microcontroller.
#define BL_MEM_READ				0x59

//This command is used to read all the sector protection status.
#define BL_READ_SECTOR_P_STATUS	0x5A


//This command is used to read the OTP contents.
#define BL_OTP_READ				0x5B


//This command is used disable all sector read/write protection
#define BL_DIS_R_W_PROTECT				0x5C

/* ACK and NACK bytes*/
#define BL_ACK   0XA5
#define BL_NACK  0X7F

#define ADDR_VALID 0x00
#define ADDR_INVALID 0x01

#define FLASH_SECTOR2_BASE_ADDRESS 0x08008000U

#define CRC_ENABLED 0
#define VERIFY_CRC_SUCCESS 1
#define VERIFY_CRC_FAIL    0


/*Some Start and End addresses of different memories of STM32F411xe MCU */
/*Change this according to your MCU */
#define SRAM1_SIZE            128*1024     // STM32F446RE has 128KB of SRAM1
#define SRAM1_END             (SRAM1_BASE + SRAM1_SIZE)
#define FLASH_SIZE             512*1024

void bootloader_uart_read_data(void);
void bootloader_jump_to_user_app(void);
void bootloader_handle_getver_cmd(uint8_t *bl_rx_buffer);
void bootloader_send_ack(uint8_t command_code, uint8_t follow_len);
void bootloader_uart_write_data(uint8_t *pBuffer,uint32_t len);
void bootloader_send_nack(void);
#if CRC_ENABED
uint8_t bootloader_verify_crc (uint8_t *pData, uint32_t len, uint32_t crc_host);
#endif

void bootloader_handle_getver_cmd(uint8_t *bl_rx_buffer);
void bootloader_handle_gethelp_cmd(uint8_t *pBuffer);
void bootloader_handle_getcid_cmd(uint8_t *pBuffer);
void bootloader_handle_getrdp_cmd(uint8_t *pBuffer);
void bootloader_handle_go_cmd(uint8_t *pBuffer);
void bootloader_handle_flash_erase_cmd(uint8_t *pBuffer);
void bootloader_handle_mem_write_cmd(uint8_t *pBuffer);
void bootloader_handle_en_rw_protect(uint8_t *pBuffer);
void bootloader_handle_mem_read (uint8_t *pBuffer);
void bootloader_handle_read_sector_protection_status(uint8_t *pBuffer);
void bootloader_handle_read_otp(uint8_t *pBuffer);
void bootloader_handle_dis_rw_protect(uint8_t *pBuffer);


uint8_t get_bootloader_version();
uint16_t get_mcu_chip_id();
uint8_t get_flash_rdp_level(void);
uint8_t verify_address(uint32_t go_address);
uint8_t execute_flash_erase(uint8_t sector_number , uint8_t number_of_sector);

#endif
