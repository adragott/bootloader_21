/*
 * pusart.c
 *
 * Created: 1/5/2019 12:30:46 PM
 *  Author: Penguin
 */ 

#include "pusart.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
static void debug_rx_cb(struct usart_module* const mod);


volatile uint8_t debug_rx_buffer[DEBUG_RX_SIZE];
uint8_t pprint_buffer[MAX_PPRINT_BUFFER_SIZE];

void pusart_init(void)
{
	struct usart_config debug_conf;
	usart_get_config_defaults(&debug_conf);
	debug_conf.baudrate = USART_DEBUG_BAUD;
	debug_conf.pinmux_pad0 = USART_DEBUG_PIN0;
	debug_conf.pinmux_pad1 = USART_DEBUG_PIN1;
	debug_conf.pinmux_pad2 = USART_DEBUG_PIN2;
	debug_conf.pinmux_pad3 = USART_DEBUG_PIN3;
	debug_conf.mux_setting = USART_DEBUG_MUX;
	debug_conf.stopbits = USART_DEBUG_STOP_BIT;
	debug_conf.character_size = USART_DEBUG_CH_SIZE;
	usart_init(&debug_mod, USART_DEBUG_SERCOM, &debug_conf);
	usart_enable(&debug_mod);

	DEBUG("USART INITIALIZED DURING BOOTLOAD\n");
}

void pprint(struct usart_module* mod, const char* str, ...)
{
	memset(pprint_buffer, '\0', MAX_PPRINT_BUFFER_SIZE);
	va_list args;
	va_start(args, str);
	vsprintf((char*)pprint_buffer,str, args);
	va_end(args);
	usart_write_buffer_wait(&debug_mod, (uint8_t*)pprint_buffer, strlen((const char*)pprint_buffer));
}