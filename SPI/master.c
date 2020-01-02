#include <string.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define PORT_DIRECTION DDRB
#define PORT_VALUE PORTB

// Pin definitions (on Port B)
#define SCK  5
#define MISO 4
#define MOSI 3
#define SS   2

// Defines for the SS pin
#define SS_UNSELECT PORT_VALUE |= (1 << SS);
#define SS_SELECT PORT_VALUE &= ~(1 << SS);

void SPI_MasterInit(void) {
    // Set MOSI and SCK output, all others input
    PORT_DIRECTION |= (1 << MOSI) | (1 << SCK);
    // Enable SPI, Master, set clock rate fck/16
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0) | (1 << SPR1);
}


void SPI_MasterTransmit(char cData) {
    // Start transmission
    SPDR = cData;

    // Wait for transmission complete
    while (!(SPSR & (1 << SPIF)));
}

void uart_transmit(char character) {
    while (!(UCSR0A & (1 << 5)));
    UDR0 = (uint8_t) character;
}

void uart_transmit_string(char *string) {
    for (int i = 0; strcmp(string[i], '\0') != 0; i++) {
        uart_transmit(string[i]);
    }
}

char uart_receive() {
    while (!(UCSR0A & (1 << RXC0)));
    return (char) UDR0;
}

void uart_init(uint32_t baudrate) {
    // UBRR formula from datasheet
    // 8 as we use doublespeed
    uint16_t ubrr = (F_CPU / 8 / baudrate) - 1;
    // Set baud rate, use double speed
    UBRR0H = (uint8_t)(ubrr >> 8); // get higher 8 bits
    UBRR0L = (uint8_t)(ubrr & 0xff); // get lower 8 bits
    UCSR0A |= (1 << U2X0);
    // Enable receiver and transmitter
    UCSR0B = (1 << TXEN0 | 1 << RXEN0);
    // select character size, stop and parity bits: 8N1
    // UCSR0C = (1<<UCSZ01 | 1<<UCSZ00);
    // not necessary, because UCSR0C is initialised corretly !
    // for interrupts: enable receive complete interrupt
    // UCSR0B |= (1<<RXCIE0); we do not use interrupts by now..
}

char SPI_MasterReceive(void) {
    SPDR = 0x00;
    /* Wait for reception complete */
    while (!(SPSR & (1 << SPIF)));
    /* Return Data Register */
    return SPDR;
}


int main() {
    uart_init(115200);

    uart_transmit_string("I bims der Master\n\r");

    DDRB |= SS;
    SPI_MasterInit();

    while (1) {
        SS_SELECT
        _delay_ms(100);
        SPI_MasterTransmit('A');
        SS_UNSELECT
        uart_transmit_string("255 Gesendet\n\r");
        _delay_ms(100);


        SS_SELECT
        _delay_ms(100);
        SPI_MasterTransmit('Z');
        uart_transmit_string("0 Gesendet\n\r");
        SS_UNSELECT
        _delay_ms(100);
    }
}
