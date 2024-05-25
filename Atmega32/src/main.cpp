#include <util/delay.h>
#include <avr/io.h>
#include "uart.hpp"

UART uart;

int main()
{
    uart.init(115200);

    char msg[] = "Fuck You Atmega!";

    while (1)
    {
        uart.writeLine(msg);
        _delay_ms(1000);
    }

    return 0;
}
