/*
 * pusart.h
 *
 * Created: 1/5/2019 12:30:38 PM
 *  Author: Penguin
 */ 
#ifndef _PUSART_H_
#define _PUSART_H_
#include <asf.h>
void pusart_init(void);
void pprint(struct usart_module* mod, const char* str, ...);
void pusart_service(void);

struct usart_module debug_mod;
#define DEBUG(f_, ...) pprint(&debug_mod, f_, ##__VA_ARGS__)
//#if DEBUG_ENABLE == 1
//
//#else
//#define DEBUG(f_, ...) 
//#endif
#endif