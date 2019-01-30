#include "main21.h"
#include "pusart.h"
#include "br24.h"
#include <string.h>
typedef union u64_u8
{
	uint64_t value;
	uint8_t data[8];
}u64_u8;

uint8_t page_data_buffer[EEPROM_PAGE_SIZE];
char gridChars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
static void configure_eeprom(void);
static void program_application_memory(void);
_Bool bShouldFlashNewFirmware = false;


int main (void)
{
	system_init();
	pusart_init();
	i2c_master_bus_init();
	br24_init();
	configure_eeprom();
	program_application_memory();
	
	
	eeprom_emulator_read_page(0, page_data_buffer);
	int tempctr = 0;
	DEBUG("%4s", " ");
	for(int ind = 0; ind < 16; ind++)
	{
		DEBUG("0%c ", gridChars[ind]);
	}
	DEBUG("\n");

	
	for(int row = 0; row < 4; row++)
	{
		int col = 0;
		if(row == 0)
		{
			DEBUG("0%c: ", gridChars[row]);
			DEBUG("%12s", " ");
			col = 4;
		}
		else
		{
			DEBUG("0%c: ", gridChars[row]);
		}
		
		for(; col < 16; col++)
		{
			DEBUG("%2x ", page_data_buffer[tempctr++]);
		}
		DEBUG("\n");
	}
	
	page_data_buffer[0] = bShouldFlashNewFirmware;
	eeprom_emulator_write_page(0, page_data_buffer);
	eeprom_emulator_commit_page_buffer();

	for(;;)
	{
		
	}
}

void configure_eeprom(void)
{
	enum status_code ret = eeprom_emulator_init();
	
	if(ret == STATUS_ERR_NO_MEMORY)
	{
		DEBUG("No memory set... Dummying\n");
	}
	else if(ret != STATUS_OK)
	{
		eeprom_emulator_erase_memory();
		eeprom_emulator_init();
	}
}

void program_application_memory(void)
{
	//read eeprom
	
	
	//get file size from first 8 bytes
	u64_u8 size_of_firmware;
	u64_u8 test_ret;
	test_ret.value = 0;
	size_of_firmware.value = 4727;
	br24.addr = 0x50;
	br24.buffer[0] = 0x0;
	br24.buffer[1] = 0x0;
	memcpy(&br24.buffer[2], size_of_firmware.data, 8);
	i2c_write_bytes(&br24, 10, true);
	
	br24.buffer[0] = 0x0;
	br24.buffer[1] = 0x0;
	i2c_write_bytes(&br24, 2, false);
	br24.addr = 0x51;
	i2c_read(&br24, 8, true);
	memcpy(test_ret.data, br24.buffer, 8);
	DEBUG("%llu\n", test_ret.value);
	
	uint32_t number_pages = test_ret.value / 256;
	uint16_t leftovers = test_ret % 256;
	
	
	
	
}

