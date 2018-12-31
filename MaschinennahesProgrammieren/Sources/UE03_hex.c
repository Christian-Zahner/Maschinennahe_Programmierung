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
	  					move.l 	#12,    d5			// zähler zum verschieben
	  					
	  		loop:
	  					move.w	zahl,   d3			// Zahl in d3 kopieren
	  					lsr.l	  d5,   d3			// logischer links Schift um d3
	  					
	  					andi.l	#0x000f,d3			 // Maske zum löschen 
	  												 // der linkesten 12 Bit
	  					addi.l     #'0',d3           // in ASCII umwandeln
	  					cmpi.l     #'9',d3			 // 9 Ascii ist 57
	  												 // Compare zieht 57 von d3 ab
	  												 // anschließend werde je nach 	
	  												 // Ergebnis das CCR gesetzt
	                    ble.b   kein_buchstabe		 // Sprung wenn Zahl
	                    addi.l  #'A'-'0'-10,d3       // Hex-Ziffern A - F ermitteln
	                    							 // ASCII Muster von A 
	                    							 // Von vorher Binär Muster 0 
	                    							 // ASCII abziehen. 
	                    							 // -10 da A = 10 ansonsten Buchstaben ab J
	                    
	    kein_buchstabe: 
	    
	                    move.b  	d3,-(sp)         // Zeichen auf den Stack
	                    jsr     TERM_Write           // Nibble-Ziffer ausgeben
	                    adda	  	#1,	sp			 // Stack in Ordnung bringen

	                    subi.l		#4,	d5			 // für shift Zähler kleiner machen
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
