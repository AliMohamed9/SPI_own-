/*
 * SPI_OWN.c
 *
 *  Created on: Apr 28, 2021
 *      Author: MeGa
 */
#include <avr/io.h>
#include <util/delay.h>
#include <SPI_OWN.h>

void master_init(){
	DDRB|=(1<<PB4);    /*    SET THE SLAVE SELECT TO 1 AS OUTPUT  */
	DDRB|=(1<<PB5);    /*    SET THE MOSI TO 1  AS OUTPUT      */
	DDRB&=~(1<<PB6);   /*    SET THE MISO TO 0  AS INPUT      */
	DDRB|=(1<<PB7);   /*     SET THE SCK TO 1    AS OUTPUT    */

	SPCR|=(1<<SPE);   /* ENABLE SPI  */
	SPCR|=(1<<MSTR);  /* ENABLE MASTER MODE   */

	// Bits 1, 0 – SPR1, SPR0: IS BY DEFAULT 0 >>> FOSC/4



}
void slave_init(){
	    DDRB&=~(1<<PB4);   /*    SET SLAVE SELECT TO 0 AS INPUT   */
		DDRB&=~(1<<PB5);   /*   SET MOSI TO 0 AS INPUT  AS INPUT  */
		DDRB|=(1<<PB6);    /*   SET MISO TO 1AS OUTPUT   */
		DDRB&=~(1<<PB7);  /*   SET THE SCK AS INPUT   */
		SPCR = (1<<SPE);  /*   ENABLE SLAVE  MODE   */
		SPCR|=(1<<SPE);  /*   ENABLE SPI MODE  */

		// Bits 1, 0 – SPR1, SPR0: IS BY DEFAULT 0 >>>  FOSC/4
}
void Master_send_letter(unsigned char letter ){

	SPDR = letter;

	while(!(SPSR & (1<<SPIF)));   /* Wait for transmission complete */
}
unsigned char Slave_receive_letter(){


	while(!(SPSR & (1<<SPIF)));   /* Wait for reception complete */


	return SPDR ;
}
void Master_send_string(char *sentence ){

	while(*sentence !='\0'){
		Master_send_letter(*sentence++);
	}
}
void  Slave_receive_string(char * receive_buffer){
	 unsigned int i=0;
         receive_buffer[i]=SPDR;
         while(receive_buffer[i]!='$'){
        	 i++;
        	 receive_buffer[i]=SPDR;
         }
         receive_buffer[i]='\0';
}

