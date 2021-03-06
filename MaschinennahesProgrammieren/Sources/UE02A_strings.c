/************************************
 * Filename		 : UE02A_strings.c	*
 * Created on	 : Nov 23, 2018		*
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

#include "UE02A_Strings.h"


/* ueb2a */

/* R. Hager , Maschinennahe Programmierung, Inf7, WS 1995/96,  © 1994-2006

   Musterlösung zu Aufgabe 2a (Vergleich Strings - Zeiger)

*/

/*
M.Hayn 08/10/09
- Bitte darauf achten, dass an dem CF-Serial Port ein Terminal mit 
  19200kBaud angeschlossen ist
- Als Target sollte INTERNAL_RAM ausgewählt sein
*/

char  textg[] = "Array global !\r\n";     /* globaler String */
char  *ptextg = "Pointer global !\r\n";   /* globaler Zeiger auf String */

void strings(){

	int counter = 0;
    char  textl[] = "Array local !\r\n";      /* lokaler String */
    char  *ptextl = "Pointer local !\r\n";    /* lokaler Zeiger auf String */	

    TERM_WriteString(textg);        //ergibt Code wie unten
 	TERM_WriteString(ptextg);
 	TERM_WriteString(textl);
 	TERM_WriteString(ptextl);

asm {  

start:          pea     textg                   //Ausgabe der Zeichenketten
                jsr     TERM_WriteString
                adda.l  #4, sp
                move.l  ptextg,-(sp)
                jsr     TERM_WriteString
                adda.l  #4, sp
                
                pea     textl
                jsr     TERM_WriteString
                adda.l  #4, sp
                move.l  ptextl,-(sp)
                jsr     TERM_WriteString 
                adda.l  #4, sp
	}
	
	TERM_WriteLn();			         // Nächste Zeile im Terminal
}

void IntroUe02a(){
	
	TERM_WriteString("\n########################################################################\r\n");
	TERM_WriteString("\nUebung02a: Unterschied String / String als Array in C\r\n");
	TERM_WriteString("Geben sie zwei Strings aus (unterschiedlich Global in C definiert\r\n");
	TERM_WriteString("C definiert als char* oder char[]) Analysieren Sie den Code der,\r\n");
	TERM_WriteString("sich bei einer Programmierung in C ergibt\r\n");
	TERM_WriteString("\n########################################################################\r\n\n");
	
}
