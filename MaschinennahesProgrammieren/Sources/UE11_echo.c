/***********************************
 * Headerfilename: UE11_echo.c     *
 * Created on	 : Dec 11, 2018    *
 * Author		 : Christian Zahner*
 ***********************************/


  #pragma compact_abi 
 

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"


// Include der Uebungsheader

#include "UE11_Echo.h"

void echo(){
	
    asm{
    	
    	
    	
    }
	
}
            

void IntroUe11(){
	
	TERM_WriteString("\n########################################################################\r\n");
	TERM_WriteString("\nUebung11: Softwaregesteuerte Erzeugung eines \"Echos\" zu einem externen\r\n");
	TERM_WriteString("          Interruptsignal, Test, ab wann der Mikrocontroller mit den \r\n");
	TERM_WriteString("          Interrupts nicht mehr Schritt halten kann.\r\n");
	TERM_WriteString("\n########################################################################\r\n\n");
	
}