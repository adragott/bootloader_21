#include "pi2c.h"
#include <fcntl.h>
#include <linux/i2c-dev.h>

static int i2c_master_inst = 0;

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
	if(!dev->data)
	{
		printf("bad device buffer\n");
	}
	else if(dev->addr > 256 || dev->addr < 0)
	{
		printf("bad slave addr\n");
	}
}
