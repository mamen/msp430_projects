#include "led.h"


void led_init() {

    P1DIR |= LED_PIN_RED;
    P9DIR |= LED_PIN_GREEN;

    led_setMode(LED_RED, LED_MODE_OFF);
    led_setMode(LED_GREEN, LED_MODE_OFF);

}

void led_setMode(LED_TYPE_t led, LED_STATE_t mode) {
    switch(mode) {
        // off
        case LED_MODE_OFF:
            if(led == LED_RED)
                P1OUT &= ~LED_PIN_RED;
            else
                P9OUT &= ~LED_PIN_GREEN;
            break;
        // on
        case LED_MODE_ON:
            if(led == LED_RED)
                P1OUT |= LED_PIN_RED;
            else
                P9OUT |= LED_PIN_GREEN;
            break;
        // toggle
        case LED_MODE_TOGGLE:
            if(led == LED_RED)
                P1OUT ^= LED_PIN_RED;
            else
                P9OUT ^= LED_PIN_GREEN;
            break;

    }
}

