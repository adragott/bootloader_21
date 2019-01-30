/*
 * conf_bootloader.h
 *
 * Created: 1/29/2019 11:57:31 PM
 *  Author: Penguin
 */ 
#ifndef _CONF_BOOTLOADER_H_
#define _CONF_BOOTLOADER_H_

#define FIRMWARE_CRC_CHECK DISABLE

#define APP_START_OFFSET		0x?6408?		//leaves 25.6kB for bootloader

#define APP_START_ADDRESS		(FLASH_ADDR + APP_START_OFFSET)
#define APP_MAX_SIZE			(FLASH_ADDR + FLASH_SIZE - APP_START_ADDRESS)



#endif