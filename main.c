/*
 * main.c
 *
 *  Created on: Apr 28, 2021
 *      Author: MeGa
 */


#define master    0
#define slave     1


#include <SPI_OWN.h>

#if  master

void main(){
	master_init();
 char x=0;
	while(1){

		Master_send_letter(x);
		_delay_ms(1000);
	     x++;
	     if(x==10)
	     { x=0;  }
	}
}


#endif

#if slave

void main(){
	slave_init();
	LCD_init();

	char  ReceivedChar=0;

	while(1){

				ReceivedChar=Slave_receive_letter();
				LCD_go_to(1,1);
				 LCD_Send_data(ReceivedChar);


	}



}
#endif
