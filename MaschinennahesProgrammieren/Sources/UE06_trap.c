/************************************
 * Filename		 : UE07_trap.c	    *
 * Created on	 : Nov 14, 2018		*
 * Author		 : Christian Zahner	*
 ************************************/

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"
#include "Intro.h"
#include <stdio.h>

#include "UE07_Trap.h"

void trap(){
	
	asm{
		
		  bra start
		
	start:
			
	}
	
}

void IntroUe07(){
	TERM_WriteString("\n########################################################################\r\n");
	TERM_WriteString("\nUebung07: Trap-Befehl\r\n");
	TERM_WriteString("Simulieren sie einen \"Betriebssystemaufruf\" mit dem Trap-Befehl\r\n");
	TERM_WriteString("verwenden Sie eine einfache Stringausgabe als Ersatz fuer die\r\n");
	TERM_WriteString("Betriebssystemfunktion, uebergeben Sie die Stringadresse \r\n");
	TERM_WriteString("als Parameter \"Betriebssystem\"\r\n");
	TERM_WriteString("\n########################################################################\r\n");
}
