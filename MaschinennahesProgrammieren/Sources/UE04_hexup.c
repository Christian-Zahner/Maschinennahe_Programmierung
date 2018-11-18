/***********************************
 * Filename		 : UE04_hexup.c    *
 * Created on	 : Nov 17, 2018    *
 * Author		 : Christian Zahner*
 ***********************************/

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"
#include <stdio.h>

#include "UE04_HexUp.h"

void hexUP(int zahl){

	
  	asm{

  		           bra     start

  		     hexup:  // Unterprogramm Hex Ausgabe    
  		              
  		           link    a6,#0           //Stackframe aufbauen, 0 lokale Varaiablen

  		           adda   #-16, sp         //Platz auf Stack schaffen zum Sichern der 
  		                                   //Register (4x Long)
  		           movem.l d2-d5,(sp)      //Register sichern

  		           move.w  8(a6),d5        //Parameter holen => d5       
  		           move.l  #12,d4          //Schleifenzähler in d4

  		     loop:   
  		     
  		           move.w  d5,d3           //kopieren nach d3
  		           lsr.l   d4,d3           //12/8/4/0 Bit nach rechts schieben  

  		           andi.l  #0x000f,d3      //Nibble ermitteln
  		           addi.l  #'0',d3         //in ASCII umwandeln
  		           cmpi.l  #'9',d3
  		           ble.b   kein_buchstabe
  		           addi.l  #'A'-'0'-10,d3  //Hex-Ziffern A - F
  		           
  		     kein_buchstabe: 
  		     
  		           move.b  d3,-(sp)        //Parameter auf den Stack (Byte)
  		           jsr     TERM_Write      //Nibble-Ziffer ausgeben
  		           adda   #1, sp           //Stack freigeben

  		           subi.l   #4,d4          //Shift-Register um 4 erniedrigen
  		           bge     loop            //insgesamt 4 mal wiederholen

  		           jsr     TERM_WriteLn    //neuZeile

  		           movem.l (sp),d2-d5      //gesicherte Register restaurieren
  		           adda   #16, sp          //Platz auf Stack wieder freigeben (4x Long)
  		                  
  		           unlk    a6              //Stackframe abbauen
  		           rts                     //Return from Subroutine Rücksprung
  		                  

  		     start:                        //"Hauptprogramm" 
  		     
  		     	   //pea zahl				   //Push effective address auf Stack
  		     	   //jsr TERM_WriteString	   // jsr TERM_WriteString
  		     	   adda #4,sp	 		   //Stackbereinigen
  		     	   jsr     TERM_WriteLn    //neuZeile
  		     	   
  		           move.w  zahl,-(sp)      //Parameter auf den Stack (Word=16 Bit)
  		           jsr     hexup           //Aufruf des Unterprogramms hexup
  		           adda   #2,sp            //Clear Stack (Word=16 Bit)
  		           
  		     }

	TERM_WriteLn();
	
	}

void IntroUe04(int zahl){
	TERM_WriteString("\n########################################################################\r\n");
	TERM_WriteString("\nUebung04: Ausgeben eines Speicherwortes als Heaxdezimal Unterprogramm\r\n");
	TERM_WriteString("Umgestalten von Ue03 zu einem Unterprogramm gemaess Aufrufkonvention\r\n");
	TERM_WriteString("unseres Compilers und Aufruf des Unterprogramms aus Assembler\r\n");
	TERM_WriteString("\n########################################################################\r\n\n");
	INOUT_WriteInt(zahl);
	TERM_WriteLn();
}
