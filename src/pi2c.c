#include "pi2c.h"
#include <fcntl.h>
#include <linux/i2c-dev.h>

static int i2c_master_inst = 0;

uint8_t tx_buffer[256];
void pi2c_init(void)
{
	i2c_master_inst = open("/dev/i2c-1", O_RDWR);
	if(i2c_master_inst < 0)
	{
		printf("Error opening i2c master\n");
	}
}

void pi2c_init_device(pi2c_device* dev)
{
	ioctl(i2c_master_inst, I2C_SLAVE, dev->addr);
	if(!dev->data)
	{
		printf("bad device buffer\n");
	}
	else if(dev->addr > 256 || dev->addr < 0)
	{
		printf("bad slave addr\n");
	}

}

void pi2c_quick_read(pi2c_device* dev, uint8_t reg)
{
	tx_buffer[0] = 0xFF;
	write(i2c_master_inst, tx_buffer, 1);
	tx_buffer[0] = reg;
	write(i2c_master_inst, tx_buffer, 1);
	read(i2c_master_inst, dev->data, 1);
	printf("%#x\n", dev->data[0]);

}

void pi2c_quick_write(pi2c_device* dev, uint8_t reg, uint8_t data)
{
	tx_buffer[0] = reg;
	write(i2c_master_inst, tx_buffer, 1);
	tx_buffer[0] = data;
	write(i2c_master_inst, tx_buffer, 1);
}

void pi2c_write_bytes(pi2c_device* dev, uint8_t* data, uint16_t data_length)
{
	memcpy(tx_buffer, data, data_length);
	for(int x = 0; x < 9; x++)
	{
		printf("%#x\n", data[x]);
	}
	write(i2c_master_inst, tx_buffer, 1);
	write(i2c_master_inst, &tx_buffer[1], 8);
}
