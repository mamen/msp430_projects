#include <msp430.h>
#include "led.h"

volatile int numSeconds = 0;

#pragma vector = TIMER0_A1_VECTOR
__interrupt void TimerA1_ISR (void) {
    numSeconds++;

    if(numSeconds >= 10) {
        led_toggleLED(LED_RED, LED_MODE_TOGGLE);

        numSeconds = 0;
    }
    TA1CCTL1 &= ~CCIFG;
}




void led_init() {
    P1DIR |= BIT0;
    P9DIR |= BIT7;

    // timer
    TA1CCR0 = 10000; // 10 ms @ 1MHz

    TA1CCTL1 |= CCIE;
    TA1CTL = TASSEL_2 | MC_2 | ID_1;


}


void led_toggleLED(int ledNum, int mode) {
    switch(mode) {
        // off
        case 0:
            if(ledNum == 1)
                P1OUT &= ~LED_RED;
            else
                P9OUT &= ~LED_GREEN;
            break;
        // on
        case 1:
            if(ledNum == 1)
                P1OUT |= LED_RED;
            else
                P9OUT |= LED_GREEN;
            break;
        // toggle
        case 2:
            if(ledNum == 1)
                P1OUT ^= LED_RED;
            else
                P9OUT ^= LED_GREEN;
            break;
        // blink
        case 3:
            if(ledNum == 1)
                P1OUT ^= LED_RED;
            else
                P9OUT ^= LED_GREEN;
            break;

    }
}