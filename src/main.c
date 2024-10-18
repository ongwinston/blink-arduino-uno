// Includes
#include <avr/io.h>
#include <util/delay.h>

// Main
int main(void) {
    // Enable output port on LED register
    DDRB = DDRB | (1 << DDB5);

    while(1) {
        // Light LED
        PORTB = PORTB | (1 << PORTB5);

        // WAIT
        _delay_ms(100);

        // Turn off LED
        PORTB = PORTB & ~(1 << PORTB5);

        // WAIT
        _delay_ms(100);
    }

    // End
    return 0;
}