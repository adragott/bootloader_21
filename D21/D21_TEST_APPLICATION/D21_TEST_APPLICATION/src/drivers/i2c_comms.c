#include "i2c_comms.h"
#include "inttypes.h"
#include <stdio.h>
#include <string.h>

struct i2c_master_module i2c_mod;
struct i2c_master_packet comms_pkt;

volatile uint8_t i2c_master_buff[I_MASTER_MAX_BUFFER];

int ctr = 0;

void i2c_write_byte(i2c_device* dev, uint8_t byte, _Bool bShouldStop)
{
	I_MASTER_PKT->data[0] = 0x0;
	I_MASTER_PKT->data[0] = byte;
	I_MASTER_PKT->address = dev->addr;
	I_MASTER_PKT->data_length = 1;
	if(bShouldStop)
	{
		#warning timeout handling
		while(i2c_master_write_packet_wait(I_MASTER, I_MASTER_PKT) != STATUS_OK)
		{
			
		}

	}
	else
	{
		#warning add timeout handling
		while(i2c_master_write_packet_wait_no_stop(I_MASTER, I_MASTER_PKT) != STATUS_OK)
		{
			
		}
	}
}

void i2c_write_bytes(i2c_device* dev, uint16_t numBytes, _Bool bShouldStop)
{
	#warning need to optimize this
	memset(I_MASTER_PKT->data, '\0', numBytes);
	for(int x = 0; x < numBytes; x++)
	{
		I_MASTER_PKT->data[x] = dev->buffer[x];	
		//for debugging
	}
	#warning add timeout
	I_MASTER_PKT->address = dev->addr;
	I_MASTER_PKT->data_length = numBytes;
	enum status_code ret = STATUS_OK;
	if(bShouldStop)
	{
		while((ret = i2c_master_write_packet_wait(I_MASTER, I_MASTER_PKT)) != STATUS_OK)
		{

			if(ctr++ >= 2000)
			{
				
				break;
			}
		}
		ctr = 0;
	}
	else
	{
		while(i2c_master_write_packet_wait_no_stop(I_MASTER, I_MASTER_PKT) != STATUS_OK)
		{
			if(ctr++ >= 1000)
			{
				
				break;
			}
		}
		ctr = 0;
	}
}

void i2c_read(i2c_device* dev, uint16_t numBytes, _Bool bShouldStop)
{
	#warning add timeout
	//clear buffer just in case
	//weird things happen every now and then if I don't clear the buffer
	I_MASTER_PKT->data = i2c_master_buff;
	memset(I_MASTER_PKT->data, '\0', numBytes);
	I_MASTER_PKT->address = dev->addr;
	I_MASTER_PKT->data_length = numBytes;
	if(bShouldStop)
	{
		#warning add timeout handling
		while(i2c_master_read_packet_wait(I_MASTER, I_MASTER_PKT) != STATUS_OK);
	}
	else
	{
		#warning add timeout handling
		while(i2c_master_read_packet_wait_no_stop(I_MASTER, I_MASTER_PKT) != STATUS_OK);
	}
	
	//deliver the goods
	memcpy(dev->buffer, i2c_master_buff, numBytes);

}

void i2c_master_bus_init(void)
{
	struct i2c_master_config i2c_conf;
	i2c_master_get_config_defaults(&i2c_conf);
	i2c_conf.pinmux_pad0 = I_MASTER_PIN0;
	i2c_conf.pinmux_pad1 = I_MASTER_PIN1;
	i2c_conf.baud_rate = I_MASTER_BAUD;
	i2c_conf.baud_rate_high_speed = false;
	i2c_conf.run_in_standby = false;
	i2c_conf.generator_source = GCLK_GENERATOR_3;
	I_MASTER_PKT->address = 0x04;
	I_MASTER_PKT->data = i2c_master_buff;
	I_MASTER_PKT->data_length = 2;
	I_MASTER_PKT->ten_bit_address = I_MASTER_ADDR_MODE;
	while(i2c_master_init(I_MASTER, I_MASTER_SERCOM, &i2c_conf) != STATUS_OK);
	i2c_master_enable(&i2c_mod);
}

void i2c_write_bytes_no_ack(i2c_device* dev, uint8_t numBytes, uint16_t max_timeout)
{
	#warning need to optimize this
	memset(I_MASTER_PKT->data, '\0', numBytes);
	memcpy(I_MASTER_PKT->data, dev->buffer, numBytes);
	#warning add timeout
	I_MASTER_PKT->address = dev->addr;
	I_MASTER_PKT->data_length = numBytes;
	uint16_t timectr = 0;
	while(i2c_master_write_packet_wait_no_stop(I_MASTER, I_MASTER_PKT) != STATUS_OK)
	{
		if(timectr++ >= max_timeout)
		{
			
			break;
		}
		ctr = 0;
	}
}