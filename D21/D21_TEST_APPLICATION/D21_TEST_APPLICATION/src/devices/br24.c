/*
 * br24.c
 *
 * Created: 1/29/2019 11:24:52 PM
 *  Author: Penguin
 */ 

#include "br24.h"
uint8_t br24_buffer[256];


void br24g1m_init(void)
{
	br24.addr = 0x50;
	br24.buffer = br24_buffer;
	br24.buffer_size = 256;
	
	//writing a byte to address 0x0004
	//address
	br24_buffer[0] = 0x00;
	br24_buffer[1] = 0x09;
	//data
	br24_buffer[2] = 3;
	
	
	////Clear R/~W bit to signify a write
	br24.addr &= ~0x01;
	//test write
	i2c_write_bytes(&br24, 3, true);
	
	
	//Now let's read that data back
	
	//Same address as before
	//br24_buffer[0] = 0x1;
	//br24_buffer[1] = 0x00;
	//i2c_write_bytes(&br24, 2, false);
	////Or 0x01 with 0x50 to signify a read
	//br24.addr |= 0x01;
	//i2c_read(&br24, 1, true);
	//uint8_t result = br24_buffer[0];
	#ifdef NODE_POWER_DEV_MODE

	char charArrCol[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	
	
	//Let's read the entire first page of eeprom, which is 256 bytes for us
	br24.addr &= ~0x01;
	br24_buffer[0] = 0x0;
	br24_buffer[1] = 0x0;
	i2c_write_bytes(&br24, 2, true);
	br24.addr |= 0x01;
	i2c_read(&br24, 256, true);
	int zctr = 0;
	DEBUG("%5s", " ");
	for(int x = 0; x < 16; x++)
	{
		DEBUG("0%c ", charArrCol[x]);
	}
	DEBUG("\n");
	for(int row = 0; row < 16; row++)
	{
		DEBUG("%c0:  ", charArrCol[row]);
		for(int col = 0; col < 16; col++)
		{
			DEBUG("%2x ", br24_buffer[zctr++]);
		}
		DEBUG("\n");
	}
	
	#endif
	
	
	
}
