#ifndef _PI2C_H_
#define _PI2C_H_

#include "project.h"

typedef struct pi2c_device
{
	uint8_t addr;
	uint8_t* data;
	uint8_t data_length;
}pi2c_device;


pi2c_init(void);

pi2c_init_device(pi2c_device* dev);


#endif
