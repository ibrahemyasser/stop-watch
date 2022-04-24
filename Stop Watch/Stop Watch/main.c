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
#include "header.h"
#include "interrupt.h"


ISR (TIMER1_COMPA_vect){
	static uint16_t s1 = 0, s2 = 0, m1 = 0, m2 = 0;
	PORTC ^= 0x07;
	/*
	if(s1 < 9)
	{s1++;
		writeSeg1(s1);
	}
	else
	{
		s1 = 0;
		writeSeg1(s1);
		if(s2 < 6)
		{
			s2++;
			writeSeg2(s2);
		}
		else
		{
			s2 = 0;
			writeSeg2(s2);
			if(m1 < 9)
			{
				m1++;
				writeSeg3(m1);
			}
			else
			{
				m1 = 0;
				writeSeg3(m1);
				if(m2 < 6)
				{
					m2++;
					writeSeg4(m2);
				}
				else
				{
					m2 = 0;
					writeSeg4(m2);
				}
			}
			
		}
		
	}
*/	
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
