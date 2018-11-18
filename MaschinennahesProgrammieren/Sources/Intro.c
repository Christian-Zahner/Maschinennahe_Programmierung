/************************************
 * Filename		 : UE06_Illegal.c	*
 * Created on	 : Nov 16, 2018		*
 * Author		 : Christian Zahner	*
 ************************************/

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"
#include "Intro.h"

void intro(){
  // Kleiner Joke
  TERM_WriteString("========================================================================\r\n");
  TERM_WriteString("Freescale ColdFire M52259DEMOMCU Online!!!\r\n");
  TERM_WriteString("Alle Systeme normal!!!\r\n");
  TERM_WriteString("Waffen einsatzbereit!!!\r\n");
  TERM_WriteString("Mission: Vernichtung aller Chinesischer Kommunisten!!!\r\n");
  TERM_WriteString("Demokoratie ist nicht verhandelbar!!!\r\n");
  TERM_WriteString("Gegenueber dem Kommunismus, ist der Tod eine willkommene Alternative!!!\r\n");
  TERM_WriteString("========================================================================\r\n");
  
}

void test(){
	// Funktioniert PuTTY auch richtig
	TERM_WriteString("\nIch bin bereit!!!\r\n\n");
}
