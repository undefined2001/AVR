#ifndef INC_GPIO_H
#define INC_GPIO_H
#include <stdint.h>

class GPIO
{
private:
    volatile uint8_t *_PORT;
public:
    GPIO(volatile uint8_t *port);
    ~GPIO();
    void writePin(uint8_t pin, uint8_t state);
};




void writePin(volatile uint8_t *port, uint8_t pin, uint8_t state);
#endif