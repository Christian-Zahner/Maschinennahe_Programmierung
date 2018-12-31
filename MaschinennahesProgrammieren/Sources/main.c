/* ###################################################################
**     Filename    : main.c
**     Project     : test8
**     Processor   : MCF52259CAG80
**     Version     : Driver 01.00
**     Compiler    : CodeWarrior MCF C Compiler
**     Date/Time   : 2014-10-11, 15:20, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**  Main module.
**  This module contains user's application code.
*/                  
/* MODULE main */ 
 
  #pragma compact_abi 
 

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"
#include "Intro.h"
#include <stdio.h>

// Include der Uebungsheader

#include "UE01_Strgout.h"
#include "UE02A_Strings.h"
#include "UE03_Hex.h"
#include "UE04_HexUp.h"
#include "UE05_Mymemcopy.h"
#include "UE06_Illegal.h"
#include "UE07_Trap.h"
#include "UE07A_Bitrev.h"
#include "UE08_Liste.h"
#include "HexDaten.h"
#include "UE09_LED.h"
#include "UE11_Echo.h"

// - Bitte darauf achten, dass am Coldfire-Serial Port ein  
//   Terminal (Putty o.�.) mit 19200kBaud angeschlossen ist.
// - Als Target muss   <projektname>_RAM_OSBDM   ausgew�hlt werden.

void main(void)
{
  // Variablen f�r die Uebungen
	
  int counter = 0;
  char strg1[20] 	= "String1";
  char strg2[20] 	= "leer";
  int zahl			= 0x12AF;
  
  unsigned long vorher  = 0x00000010;
  unsigned long nachher = 0x00000000;


  
  /***** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ********************/
  PE_low_level_init(); /*************************************************************************/
  /***** End of Processor Expert internal initialization. ***************************************/

  /* Nur kleiner Spass um zu Testem ob der Coldfire auch Funktioniert, PuTTY*********************
   * und Co, auch richtig eingestellt sind*******************************************************/
  
  	//intro();
  	test();
  
  /////////////////////////////// Starten der Uebungsprojekte \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
  
  
  /**** Uebung 01 ******************************************************************************/
  
  	/*IntroUe01();
  
  	strgout();
  	
  	outro();*/
  
  /**** Uebung 02 ******************************************************************************/ 
  
  	/*IntroUe02();
  	 
  	//strgoutrev();		     // Nach Musterl�sung
  	 
  	//strgoutrevalt();		 // Mittels Adressversatz
  	
  	strgoutRevWithoutCount(); // Ohne Counter	
  	
  	outro();*/
  	
  /**** Uebung 02a ******************************************************************************/ 
    
    /*IntroUe02a();
    	 
    strings();
    	
    outro();*/	
  
  /**** Uebung 03 ******************************************************************************/
  
  	/*IntroUe03(zahl);
  	
  	hex(zahl);
  	
  	outro();*/
  
  
  /**** Uebung 04 ******************************************************************************/
  
  	/*IntroUe04(zahl);
  	
  	hexUP(zahl);
  	
  	outro();*/
  
  
  /**** Uebung 05 Mymemcopy *******************************************************************/
  	
  	/*introUe5();
  	
	printf("\r\nString1 vorher:%s\r\n",strg1);
	printf("\r\nString2 vorher:%s\r\n",strg2);
	printf("\r\nString2 nachher:%s\r\n",mymemcopy(strg2, strg1, 20));
	
	outro();*/
  
	/**** Uebung 06 Illegal exception ********************************************************/
  
  	/*IntroUe06();
  	
  	illegal();
  	
  	outro();*/
  
  
	/**** Uebung 07 **************************************************************************/
  
  	/*IntroUe07();
  
	trap();
  
  	outro();*/
	
	/**** Uebung 07a **************************************************************************/
  
  	IntroUe07A();
  	
  	printf("\r\nZahl vorher  = 0x%08lX und als Integer = %lu\r\nBitmuster: ",vorher, vorher);
  	printbit(vorher);
  	
	nachher = bitrevUp(vorher, nachher);
	
	printf("\r\nZahl nachher = 0x%08lX und als Integer = %lu\r\nBitmuster: ",nachher, nachher);
	printbit(nachher);
	
  	outro();
	
	/**** Uebung 08 **************************************************************************/
  
  	/*IntroUe08();
  	
	lstint();
	
    outro();*/
  
	
	/**** Uebung 09 **************************************************************************/
  
  	/*IntroUe09();
  	
  	//Uebung 09a
  	
  	/*IntroUe09A();
  	
	ledOnOff();*/
  	
  	//Uebung 09b
  	
  	/*IntroUe09B();
  	
  	ledLatched();*/
  	
  	//Uebung 09c
  	
  	/*IntroUe09C();
  	
  	//ledCount();
  	
  	ledCountPlusMinus();*/
  	
  	//Uebung 09a
  	
  	/*IntroUe09D();
  	
  	ledInterrupt();*/
	
	/**** Uebung 10 **************************************************************************/
  
	//seriell();
  
	
	/**** Uebung 11 **************************************************************************/
  
  	/*IntroUe11();
  	
	echo();
  
	outro();*/
  	
	/**** Uebung 12 **************************************************************************/

	//lftdoor();
  
	
	
// Als Ende-Behandlung nachfolgend ein einfacher Leerlauf-Prozess 
// *******************************************************************************************/
 
 /* for(;;){
	  counter++;
  }*/
 
}  /* END main */


/*Donaudampfschifffahrtsgesellschaftskapitaensmuetzenabzeichen

Das ist ein ganz unglaublich langer Textstring, der vom DMA-
Controller in einem Zug ohne Zutun der CPU ausgegeben wird!!
Wenn Sie es richtig gemacht haben, funktioniert's wunderbar.
Und noch ein bisschen mehr Text, weil es gar so schoen geht.

Der String kann so lang sein, wie er will: Er wird in einem
Schwung per DMA ausgegeben, ohne das die CPU noch etwas tun
muss.


dma0 transfer done*/

