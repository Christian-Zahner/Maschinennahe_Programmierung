/************************************
 * Filename		 : Klausur.c	    *
 * Created on	 : Jan 06, 2019		*
 * Author		 : Christian Zahner	*
 ************************************/

 #pragma compact_abi 
 

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"
#include <stdio.h>


// Include der Uebungsheader

#include "Klausur.h"


void mul(void){
	
	int i,x;
	x = 1;
	
	if (x < 7){
		for (i = 10; i >= 0; i--){
			x = x*2;
		}
	x = x*5;
	}
	
	switch (i){
	 
	case 1: 
		x = 1;
		break;
	
	case 2: 
		x = 2; 
		break;
	
	case 3: 
		x = 3; 
		break;
	
	default: x = 99;
	
	do{
		x = x + 1;
	}while(x < 100);
	
	}
}
