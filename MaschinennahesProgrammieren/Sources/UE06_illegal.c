/************************************
 * Filename		 : UE06_illegal.c	*
 * Created on	 : Nov 14, 2018		*
 * Author		 : Christian Zahner	*
 ************************************/

#pragma compact_abi

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"

#include "UE06_Illegal.h"

#define MEMOFFSET 0x20000000

/****************************************************************
 * Uebung6: Illegal instruction, testen Sie den Befehl 			*
 * 			einschlie�lich Verbiegen des zugeh�rigen Vektors.	*
 ****************************************************************/

void illegal(){
	
	char strt[] 	= "\nProgramm starten!!!\n\r";
	char exptn[] 	= "\nDas war Illegal du Schlingel!!!\r\nAnzeige!!!\n\r";
	char end[] 		= "\nProgramm beendet!!!\n\r";
	
	asm{
		bra     start

		        //Dies ist der "Exception Handler"
		        
		        Exception_Handler:
		        
		              pea     exptn				 // push effective Address auf Stack    
		              jsr     TERM_WriteString   // Jump Subroutine
		              adda    #4, sp			 // Stack freigeben
		              
		              add.l  #2, 4(sp)		     // Den auf dem Stack gespeicherten 
		              // +2 illegal 32 bit		 // PC auf den n�chsten Befehl setzen.
		                                         // WICHTIGER HINWEIS:
		                                         // Das ist i.A. keine sinnvolle Behandlung
		              	  	  	  	  	  	  	 // der Exception!!!
		              rte               		 // Return from Exception


		        start: 
		        
		              lea Exception_Handler, a1  // Adresse des Exception Handlers einh�ngen in a1
		              move.l  a1, MEMOFFSET+0x10 // Vektor Nr. 4 (Illegaler Opcode), Offset 0x10


		              pea     strt         		 // Ausgabe am Programmanfang
		              jsr     TERM_WriteString
		              adda    #4, sp             // Stack freigeben


		              illegal                    // Illegaler Opcode  = 0x4afc
		              //dc.w 0x4afc                // ginge ebenfalls


		              pea     end                // Ausgabe am Programmende    
		              jsr     TERM_WriteString
		              adda    #4, sp             // Stack freigeben


		              //jsr TERM_Read              // Warten auf Tastendruck
		     }
	
	
}

void IntroUe06(){
	TERM_WriteString("\n########################################################################\r\n");
	TERM_WriteString("\nUebung06: Illegale Instruction\r\n");
	TERM_WriteString("Testen Sie diesen \"Befehl\" (einschl. Verbiegen des zugehoerigen Vektors)\r\n");
	TERM_WriteString("\n########################################################################\r\n");
}


