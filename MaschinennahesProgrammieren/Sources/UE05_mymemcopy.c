/***********************************
 * Filename		 : UE05_mymemcopy.c*
 * Created on	 : Nov 15, 2018    *
 * Author		 : Christian Zahner*
 ***********************************/
#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"
#include <stdio.h>


#include "UE05_Mymemcopy.h"


/****************************************************************
 * Uebung5: mymemcopy											*
 * 			Erstellung und Test eines Unterprogramms mymemcopy.	*
 * 			Aufruf des Unterprogramms aus C.					*
 * 			Funktionskopf in C									*
 * 			Eingangs-, Ausgangs-, 								*
 * 			Frame- und Return-Code in Assembler					*
 ****************************************************************/


	void* mymemcopy(void* ziel, const void* quelle, size_t anzahl){
		
		
		asm{ naked						// selbst k�mmern um Stack
										// Nur Eingabeparameter 
										// liegen bereits darauf
				link 	a6,#0			//FP sichern
				adda 	#-12,sp			//Platz f�r Register auf Stack machen
				movem.l d2/a2-a3,(sp)	//Register sichern
				
				move.l  16(a6),d2		//Anzahl in d2
				move.l  12(a6),a2		//Quelle in a2
				move.l  8(a6),a3		//Ziel 	 in a3
			
		Loop:
				move.b  (a2)+, (a3)+	//Byteweise kopieren von a2 nach a3
				subi.l  #1, d2			//decrementieren d2(size_t anzahl)
				tst.b   d2				//testet d2 auf gleichheit mit Zero
				bne     Loop			//wenn nicht gleich Zero 
										//sprung auf Marke Loop
		
				move.l  8(a6),a0		//Ziel nach a0 (r�ckgabewert)
				
				movem.l (sp),d2/a2-a3	//Register holen vom Stack	
				adda 	#12,sp			//Speicherfreigeben von Register auf SP
				unlk 	a6				//FP vom Stack nehmen
				rts						//return from subroutine

		}
		
	}
	
	void introUe5(){
		TERM_WriteString("\r\n########################################################################\r\n");
		TERM_WriteString("\r\nUebung05: mymmemcopy\r\n");
		TERM_WriteString("Erstellung und Test eines Unterprogramms mymemcopy (analog zu memcopy)\r\n");
		TERM_WriteString("und Aufruf des Unterprogramms aus C\r\n");
		TERM_WriteString("\r\n########################################################################\r\n");
	}
	
	void outro(){
		TERM_WriteString("\r\n########################################################################\r\n\r\n");
	}
	
	
