#include "gpio.h"
#include <avr/io.h>
#include <util/delay.h>


int main()
{
    DDRB |= (1 << DDB5);

    while (1)
    {
        PORTB ^= _BV(PORTB5);
        _delay_ms(500);
    }

    return 0;
}
