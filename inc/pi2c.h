#ifndef _PI2C_H_
#define _PI2C_H_

#include "project.h"

typedef struct pi2c_device
{
	uint8_t addr;
	uint8_t* data;
	uint8_t data_length;
	uint8_t max_data_length;
}pi2c_device;


void pi2c_init(void);

void pi2c_init_device(pi2c_device* dev);

void pi2c_quick_read(pi2c_device* dev, uint8_t reg);
void pi2c_quick_write(pi2c_device* dev, uint8_t reg, uint8_t data);

void pi2c_write_bytes(pi2c_device* dev, uint8_t* data, uint16_t data_length);
#endif
