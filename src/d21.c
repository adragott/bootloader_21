#include "d21.h"

uint8_t d21_buffer[256];

void d21_init(void)
{
	d21.data = d21_buffer;
	d21.data_length = 1;
	d21.max_data_length = 256;
	d21.addr = 0x60;
}
