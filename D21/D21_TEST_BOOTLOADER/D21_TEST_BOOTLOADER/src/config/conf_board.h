/**
 * \file
 *
 * \brief SAM D21 Xplained Pro board configuration.
 *
 * Copyright (c) 2013-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED


#define DEBUG_ENABLE 1

//USART Configuration Options
#define USART_DEBUG				(&debug_mod)
#define USART_DEBUG_SERCOM		SERCOM3
#define USART_DEBUG_BAUD		115200
#define USART_DEBUG_CH_SIZE		USART_CHARACTER_SIZE_8BIT
#define USART_DEBUG_STOP_BIT	USART_STOPBITS_1
#define USART_DEBUG_PIN0		PINMUX_PA22C_SERCOM3_PAD0
#define USART_DEBUG_PIN1		PINMUX_PA23C_SERCOM3_PAD1
#define USART_DEBUG_PIN2		PINMUX_UNUSED
#define USART_DEBUG_PIN3		PINMUX_UNUSED
#define USART_DEBUG_MUX			USART_RX_1_TX_0_XCK_1

#define MAX_PPRINT_BUFFER_SIZE		256
#define MAX_DEBUG_BUFFER_SIZE		256
#define DEBUG_RX_SIZE				1

#ifndef I2C_MASTER_BUS_CONFIGURATION
#define I2C_MASTER_BUS_CONFIGURATION

#define I_MASTER				(&i2c_mod)
#define I_MASTER_BAUD			I2C_MASTER_BAUD_RATE_400KHZ
#define I_MASTER_PIN0			PINMUX_PA16C_SERCOM1_PAD0
#define I_MASTER_PIN1			PINMUX_PA17C_SERCOM1_PAD1
#define I_MASTER_ADDR_MODE		false
#define I_MASTER_PKT			(&comms_pkt)
#define I_MASTER_SERCOM			SERCOM1



#endif
#endif /* CONF_BOARD_H_INCLUDED */
