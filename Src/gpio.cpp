#include "gpio.h"

GPIO::GPIO(volatile uint8_t *port) : _PORT{port} {}

void GPIO::writePin(uint8_t pin, uint8_t state)
{
    if (state == 1)
    {
        (*_PORT) |= (1 << pin);
    }
    else
    {
        (*_PORT) &= ~(1 << pin);
    }
}

GPIO::~GPIO()
{
}

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