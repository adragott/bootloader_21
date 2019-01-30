#include "main21.h"
#include "pusart.h"

int main (void)
{
	system_init();
	system_interrupt_enable_global();
	pusart_init();
	
	while (1) {
		/* Is button pressed? */
		if (port_pin_get_input_level(BUTTON_0_PIN) == BUTTON_0_ACTIVE) {
			/* Yes, so turn LED on. */
			port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		} else {
			/* No, so turn LED off. */
			port_pin_set_output_level(LED_0_PIN, !LED_0_ACTIVE);
		}
		services_handler();
	}
}

void services_handler(void)
{
	pusart_service();
}
