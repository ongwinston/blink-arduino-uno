// Includes
#include <avr/io.h>
#include <util/delay.h>

void init_port_led_reg(void){
    DDRB = DDRB | (1 << DDB5);
}

void toggle_board_led(void) {
        // Light LED
        PORTB = PORTB | (1 << PORTB5);

        // WAIT
        _delay_ms(100);

        // Turn off LED
        PORTB = PORTB & ~(1 << PORTB5);

        // WAIT
        _delay_ms(100);

}

void port_d_init(void){
    DDRD = DDRD | 0x1;
}

void toggle_d0(void){
    // Turn on D0
    PORTD = PORTD | 0x1;

    _delay_ms(1000);
    PORTD = 0;

    _delay_ms(1000);
}

// Main
int main(void) {
    // Enable output port on LED register
    init_port_led_reg();
    port_d_init();

    while(1) {
        toggle_board_led();
        toggle_d0();
    }

    // End
    return 0;
}