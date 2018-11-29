/***********************************
 * Filename		 : UE03_hex.c 	   *
 * Created on	 : Nov 17, 2018    *
 * Author		 : Christian Zahner*
 ***********************************/

#pragma compact_abi

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"
#include <stdio.h>

#include "UE03_Hex.h"

void hex(int zahl){

		
	  	asm{
	  					bra start
	  					
	  		start:			
	  					move.l 	#12,    d5			// z�hler zum verschieben
	  					
	  		loop:
	  					move.w	zahl,   d3
	  					lsr.l	  d5,   d3
	  					
	  					andi.l	#0x000f,d3
	  					addi.l     #'0',d3           // in ASCII umwandeln
	  					cmpi.l     #'9',d3
	  					
	                    ble.b   kein_buchstabe
	                    addi.l  #'A'-'0'-10,d3       // Hex-Ziffern A - F
	                    
	    kein_buchstabe: 
	    
	                    move.b  	d3,-(sp)        // Zeichen auf den Stack
	                    jsr     TERM_Write           // Nibble-Ziffer ausgeben
	                    adda	  	#1,	sp			 // Stack in Ordnung bringen

	                    subi.l		#4,	d5
	                    bge     	loop             // 4 mal wiederholen

	  	}
		TERM_WriteLn();
	}

void IntroUe03(int zahl){
	TERM_WriteString("\n########################################################################\r\n");
	TERM_WriteString("\nUebung03: Ausgeben eines Speicherwortes als Heaxdezimalwert\r\n");
	TERM_WriteString("Ein vorgegebens Wort im Speicher als ASCII-String ausgeben\r\n");
	TERM_WriteString("\n########################################################################\r\n\n");
	INOUT_WriteInt(zahl);
	TERM_WriteLn();
}
