#pragma once
#include <avr/io.h>

class UART
{

    void sendChar(char ch);

public:
    UART();
    void init(uint32_t baudrate);
    void writeLine(char *buffer);
};

UART::UART(){};

void UART::init(uint32_t baudrate)
{
    uint32_t BRC = (uint32_t)((16000000UL / 16) / baudrate);
    UBRRH = (BRC >> 8);
    UBRRL = BRC;

    UCSRB |= (1 << TXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
}

void UART::sendChar(char ch)
{
    while (!(UCSRA & (1 << UDRE)))
        ;
    UDR = ch;
}

void UART::writeLine(char *buffer)
{
    while (*buffer)
    {
        sendChar(*buffer++);
    };
    sendChar('\r');
    sendChar('\n');
}
