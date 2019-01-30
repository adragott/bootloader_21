/*
 * br24.h
 *
 * Created: 1/29/2019 11:24:43 PM
 *  Author: Penguin
 */ 
#ifndef _BR24_H_
#define _BR24_H_

#include <asf.h>
#include "i2c_comms.h"
void br24_init(void);

struct i2c_device br24;
#endif