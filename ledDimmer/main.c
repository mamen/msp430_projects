#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5;

	// set Input/Output pins
    // P1
    // 0 .. OUT -> 1 | LED 1
    // 2 .. IN  -> 0 | S2
    // 1 .. IN  -> 0 | S1
    // P1DIR = 0000 0001 => 0x01
	// P9
	// 7 .. IN -> 0 | LED 2
	// P9DIR = 0000 0000 => (1<<7)

	P1SEL0 |= (1<<0);
    P1DIR |= (1<<0);

    P1OUT = 0x06;

    //pullup resistor for S1 & S2
    P1REN |= (1<<1);
    P1REN |= (1<<2);

	TA0CCR0 = 1000; // 1 ms @ 1MHz
	TA0CCR1 = TA0CCR0 / 4; // 25% duty cycle

	TA0CCTL1 = CM_0 | OUTMOD_7;
	// SMCLK, Divider /1, Up mode, clear counter
	TA0CTL = TASSEL_2 | ID_0 | MC_1 | TACLR;

	volatile unsigned int i = 0;
    volatile unsigned int j = 1;


	while (1) {
        do {
         i++;
        }while(i < 10000);

        i = 0;

        if((P1IN & (1<<1)) == 0) {
            if(TA0CCR1 > 100) {
                TA0CCR1 -= 100;
            }
        }

        if((P1IN & (1<<2)) == 0) {
            if(TA0CCR1 < 20000) {
                TA0CCR1 += 100;
            }
        }
	}

	return 0;
}
