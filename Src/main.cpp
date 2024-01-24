#include "gpio.h"
#include <avr/io.h>
#include <util/delay.h>


int main()
{
    DDRB |= (1 << DDB5);
    GPIO led(&PORTB);

    while (1)
    {
        led.writePin(5, 1);
        _delay_ms(1000);
        led.writePin(5, 0);
        _delay_ms(1000);
    }

    return 0;
}
