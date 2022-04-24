/*
 * interrupt.h
 *
 * Created: 4/24/2022 2:22:37 PM
 *  Author: Administrator
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define Falling		0
#define Rising		1

#define I0	Falling
#define I1	Rising
#define I2	Falling

void interrupt0_Init();
void interrupt1_Init();
void interrupt2_Init();

void timer1_init();





#endif /* INTERRUPT_H_ */