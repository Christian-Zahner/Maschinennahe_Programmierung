/************************************
 * Filename		 : UE07A_bitrev.c	*
 * Created on	 : Nov 29, 2018		*
 * Author		 : Christian Zahner	*
 ************************************/

#pragma compact_abi 

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"
#include "Intro.h"
#include <stdio.h>

#include "UE07A_Bitrev.h"

char zer[] = "0";
char on[]  = "1";
char sep[] = " ";

unsigned long bitrevUp(unsigned long quelle){
	
	
  asm{
	  	  	  	bra			start
	  start:
				/*adda 		#-12, sp			// Platz f�r Register auf Stack machen
				movem.l 	d1-d3,(sp)*/			// Register sichern

				clr.l		d0		 			// Dazenregister mit 0 initialisieren
				clr.l		d1					
				clr.l		d2
				clr.l		d3					// Beginn am "0ten" Bit mit Bitset
				
				move.l      quelle,d1			// Inhalte Quelle in Datenregister 
			
				move.l		#31, d2				// Anzahl ist wieviele Bits sollen kopiert werden
				
				
				bra 		looptst
				
	looptst:
				btst.l		d2, d1				// Bit an position 1 oder 0
				bgt			bitset
				
				addi.l		#1, d3				// naechste Bit Stelle die gesetzt werden soll
				subi.l  	#1, d2				// naechste Bit Position die geteste wird
				tst.b		d2					// testen 0?
				blt			end
				
				bra 		looptst
	bitset:		
				bset.l		d3, d0				// Bit setzten in Dataregister
				subi.l  	#1, d2				// naechste Bit Position die geteste wird
				addi.l		#1, d3				// naechste Bit Stelle die gesetzt werden soll
				bra			looptst				
				
	end:		
				/*movem.l 	(sp), d1-d3			// Register restaurieren
				adda 		#12, sp				// Stack bere3inigen
				rts*/
				
	}
}

void printbit(unsigned long zahl){
	
	asm{
		
	 				//adda 		#-8,sp				// Platz f�r Register auf Stack machen 	
					//movem.l 	d3-d5,(sp)			// Register sichern
					
					clr.l		d5
					clr.l		d3
					clr.l		d4
					move.l		zahl, d4				// Bitmuster in Speicherschreiben
					move.l		#32, d3
					move.l		#4,  d5
					bra			outptloop				// Springe zur Marke out
					
		outptloop:	
					subi.l  	#1, d3				// wieder an Stelle 31 beginnend
					btst.l		d3, d4
					bgt			one
					bra			zero
					
		
		zero:		
		  	  	  	pea 		zer 			 	//  Adresse char zero auf Stack 	 
		  	  	  	jsr			TERM_WriteString	
		  	  	  	adda		#4, SP				// Stack bereinigen
		  	  	 
		  	  	  	tst.b		d3
		  	  	  	beq			end
		  	  	  	
		  	  	  	subi.l		#1, d5
		  	  	  	tst.b		d5
		  	  	  	beq			plchld
		  	  	  	
		  	  	  	bra 		outptloop
		  	  	  	
		one:		
					pea			on					// Adresse char one auf Stack
		  			jsr			TERM_WriteString	
		  			adda		#4, SP				// Stack bereinigen
		  			
		  			tst.b		d3
		  			beq			end
		  			
		  			subi.l		#1, d5
		  			tst.b		d5
		  			beq			plchld
		  			
		  			bra 		outptloop
		  			
		plchld:		
					pea			sep
					jsr			TERM_WriteString
					adda		#4, SP
					
					move.l		#4,	d5
					bra			outptloop

		end:		
		 	 	 	//movem.l 	(sp),d2-d3			// Register restaurieren
					//adda 		#8,sp				// Stack bereinigen
					
					jsr			TERM_WriteLn		//neue Zeile
	}
}

void IntroUe07A(){
 	TERM_WriteString("\n########################################################################\r\n");
 	TERM_WriteString("\nUebung7a: Schreiben sie ein Unterprogramm (keine Stackframes, Parameter-\r\n");
 	TERM_WriteString("          uebergabe nicht ueber den Stack sondern ueber Register), das \r\n");
 	TERM_WriteString("          den Befehl BITREV nachbildet.\r\n");
 	TERM_WriteString("\n########################################################################\r\n\n");
}
