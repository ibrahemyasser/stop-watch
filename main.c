/*
 * sevenSegment.c
 *
 * Created: 3/26/2022 9:25:01 PM
 * Author : ibrahim yasser
 */ 
#define  F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void timer1_init();
ISR (TIMER1_COMPA_vect){
	PORTC ^= 0x07;	
}
int main(void)
{
    /* Replace with your application code */
	DDRC |= (1<<0) | (1<<1) | (1<<2);
	PORTC = 0x00;
	timer1_init();
    while (1) 
    {

    }
}
void timer1_init(){
	// enables OCF1A (output compare match flag)
	TIFR |= (1<<4);
	//enables OCIE1A (output compare match interrupt enable)
	TIMSK |= (1<<4);
	// enable global interrupt
	sei();
	// CTC mode with prescaler 256
	TCCR1A = 0x00;
	TCCR1B |=  (1<<2) | (1<<3);
	// output compare value for a delay of .5 seconds
	OCR1A = 31249;
}

