#ifndef SRC_DRIVERS_BUTTONS_H_
#define SRC_DRIVERS_BUTTONS_H_

#include <msp430.h>
#include "../hal/gpio.h"

#define BUTTON_1 1
#define BUTTON_2 2

#define BUTTON_S1_PIN (1<<1)
#define BUTTON_S2_PIN (1<<2)


void buttons_init();
void buttons_enableButton(int btn);
int buttons_isButtonPressed(int btn);

#endif /* SRC_DRIVERS_BUTTONS_H_ */
