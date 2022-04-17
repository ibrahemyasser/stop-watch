/*
 * StopWatch.c
 *
 * Created: 3/26/2022 9:25:01 PM
 * Author : ibrahim yasser
 */ 
#define  F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define SET_BIT(reg, bit)	(reg|= 1<<bit)
#define CLR_BIT(reg, bit)	(reg&= ~(1<<bit))

#define Falling		0
#define Rising		1

#define I0	Falling
#define I1	Rising
#define I2	Falling

void interrupt0_Init();
void interrupt1_Init();
void interrupt2_Init();

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

void interrupt0_Init()
{
	if(I0 == Falling)
	{
	SET_BIT(MCUCR , 1); //ISC01
	CLR_BIT(MCUCR, 0);	//ISC00	
	}
	else if (I0 == Rising)	
	{	
		SET_BIT(MCUCR, 1);//ISC01
		SET_BIT(MCUCR, 0);//ISC00
	}

}

void interrupt1_Init()
{
	if(I1 == Falling)
	{
		SET_BIT(MCUCR , 3);//ISC11
		CLR_BIT(MCUCR, 2);//ISC10
	}
	else if (I1 == Rising)
	{
		SET_BIT(MCUCR, 2);
		SET_BIT(MCUCR, 3);
	}
}

void interrupt2_Init()
{
	if (I2 == Falling)
	{
	CLR_BIT(MCUCSR, 6);	//ISC2
	}
	else if (I2 == Rising)
	{
		SET_BIT(MCUCSR, 6)
	}
	
}