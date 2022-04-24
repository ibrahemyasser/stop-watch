/*
 * header.h
 *
 * Created: 4/24/2022 2:21:16 PM
 *  Author: Administrator
 */ 


#ifndef HEADER_H_
#define HEADER_H_

#define SET_BIT(reg, bit)	(reg|= 1<<bit)
#define CLR_BIT(reg, bit)	(reg&= ~(1<<bit))

#endif /* HEADER_H_ */