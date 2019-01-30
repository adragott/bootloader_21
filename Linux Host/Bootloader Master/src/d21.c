#include "d21.h"
#include <string.h>
uint8_t d21_buffer[256];

void d21_init(void)
{
	d21.data = d21_buffer;
	d21.data_length = 1;
	d21.max_data_length = 256;
	d21.addr = 0x60;

	pi2c_init_device(&d21);
}

void send_firmware_size()
{
	FILE* p_file;
	p_file = fopen(D21_FIRMWARE_FILE, "r+");
	fseek(p_file, 0L, SEEK_END);
	u64to8 sizeFile;
	sizeFile.value = (uint64_t)(ftell(p_file));
	printf("%llu\n", sizeFile.value);
	uint8_t sendBuffer[9];
	sendBuffer[0] = D21_FIRMWARE_SIZE;
	memcpy(&sendBuffer[1], sizeFile.buffer, 8);
	//void pi2c_write_bytes(pi2c_device* dev, uint8_t* data, uint16_t data_length)

	pi2c_write_bytes(&d21, sendBuffer, 9);

}
