/*
 * SPI_OWN.h
 *
 *  Created on: Apr 28, 2021
 *      Author: MeGa
 */

#ifndef SPI_OWN_H_
#define SPI_OWN_H_
#include <avr/io.h>
#include <util/delay.h>
extern void master_init();
extern void slave_init();
extern void Master_send_letter(unsigned char letter);
extern unsigned char Slave_receive_letter();
extern void Master_send_string(char * sentence );
extern void Slave_receive_string(char* receive_buffer);


#endif /* SPI_OWN_H_ */
