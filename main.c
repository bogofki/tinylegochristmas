#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h>

#define LED0 PA0
#define LED1 PA1
#define LED2 PA2
#define LED3 PA3

int main(void)
{
    // Set LEDs as outputs
    DDRA |= _BV(LED0);
    DDRA |= _BV(LED1);
    DDRA |= _BV(LED2);
    DDRA |= _BV(LED3);

    // Set BUTTON as input (active low)
    DDRA &= ~_BV(PA7);

    _delay_ms(100);
    PORTA ^= 0xF;
    _delay_ms(100);
    PORTA ^= 0xF;
    _delay_ms(100);
    PORTA ^= 0xF;
    _delay_ms(100);
    PORTA ^= 0xF;

    uint8_t advent = 0;
    while (1) {
    PORTA &= ~0xF;
        _delay_ms(2);
        if(advent >= 0)
            PORTA |= _BV(LED0);
        if(advent >= 1)
            PORTA |= _BV(LED1);
        if(advent >= 2)
            PORTA |= _BV(LED2);
        if(advent >= 3)
            PORTA |= _BV(LED3);
        _delay_ms(1);

        if((PINA & _BV(PA7)) == 0)
        {
            PORTA |= 0xF;
            advent++;
            advent%=4;
            _delay_ms(100);
            PORTA &= ~0xF;
        }
    }
    return 0;
}
