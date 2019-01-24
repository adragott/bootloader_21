#ifndef _D21_H_
#define _D21_H_

#include "project.h"
#include "pi2c.h"

#define D21_FIRMWARE_FILE "../firmware/test.txt"
pi2c_device d21;

void d21_init(void);

typedef union u64to8
{
	uint8_t buffer[8];
	uint64_t value;
}u64to8;

void send_firmware_size(void);
#endif
