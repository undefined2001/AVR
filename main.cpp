#include <avr/io.h>
#include <util/delay.h>

void writePin(volatile uint8_t *port, uint8_t pin, uint8_t state)
{
    if (state)
    {
        (*port) |= (1 << pin);
    }
    else
    {
        (*port) &= ~(1 << pin);
    }
}

int main()
{
    DDRB |= (1 << DDB5);

    while (1)
    {
        writePin(&PORTB, 5, 1);
        _delay_ms(1000);
        writePin(&PORTB, 5, 0);
        _delay_ms(1000);
    }

    return 0;
}
