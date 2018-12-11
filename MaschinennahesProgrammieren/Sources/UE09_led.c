/***********************************
 * Filename		 : UE09_LED.h      *
 * Created on	 : Dec 11, 2018    *
 * Author		 : Christian Zahner*
 ***********************************/

/* ###################################################################
**     Filename    : main.c
**     Project     : test9a
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
**         Main module.
**         This module contains user's application code.
*/                  
/* MODULE main */ 
 
#pragma compact_abi 
 

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"

#include "UE09_LED.h"


// - Bitte darauf achten, dass am Coldfire-Serial Port ein  
//   Terminal (Putty o.�.) mit 19200kBaud angeschlossen ist.
// - Als Target muss   <projektname>_RAM_OSBDM   ausgew�hlt werden.







  /* Definitions for MCF_GPIO Port NQ */
  #define MNP_GPIO_PORTNQ        0x40100008

  //hier fehlt was


  /* Bit definitions for MCF_GPIO Port TC */
  #define MNP_GPIO_PORTTC        0x4010000F

  
  //hier fehlt was





  int ledOnOff(void)
  {
  	int counter = 0;
  	
    /***** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
    PE_low_level_init(); /********************************************************/
    /***** End of Processor Expert internal initialization. **********************/


  asm 
  {
  	/* MCF52259RM.pdf
  	- SW1 and SW2 are connected to PNQPAR5 and PNQPAR1 (Quad function pins!!)
  	- LED's 1-4 are connected to DDRTC0-DDRTC3
  	*/
  	
     /* Enable Switches to be pollable ====================================== */
     /* MCF52259RM.pdf
     - Pin Assignment must be set to GPIO function 
       (15.6.5.3 Port NQ Pin Assignment Register (PNQPAR))
     - Port Data Direction must be cleared for input function 
       (15.6.2 Port Data Direction Registers (DDRn))
     - Output Data Register must be cleared 
       (15.6.1 Port Output Data Registers (PORTn))
     */

     //hier fehlt was



     /* Enable LEDs as digital outputs ==================================== */
  	/* MCF52259RM.pdf
  	- Port Data Direction must be set for output function 
  	  (15.6.2 Port Data Direction Registers (DDRn))
  	- Pin Assignment must be set to GPIO function 
  	  (15.6.5.1 Dual-Function Pin Assignment Registers)
     - Output Data Register must be set/reset 
       (15.6.1 Port Output Data Registers (PORTn))
  	*/
  	
  	
     // hier fehlt was



     loop:


	 
	   /* hier fehlt was
		Taster abfragen
		LED setzen*/


     	bra	    loop	

     }

  }
  
  void ledLatched(){
	  
  }
  void ledCount(){
	  
  }
  void ledInterrupt(){
	  
  }

  void IntroUe09(){
   	TERM_WriteString("\n########################################################################\r\n");
   	TERM_WriteString("\nUebung09: Ansteuerung der Leuchtdioden bei Tastendruck\r\n\n");
   	TERM_WriteString("          Programmieren Sie den Mikrocontroller so, dass bei   \r\n");
   	TERM_WriteString("          Betaetigung der Tasten SW1 und/oder SW2 eine Anzeige an den \r\n");
   	TERM_WriteString("          Leuchtdioden erfolgt\r\n");
   	
  }
  
  void IntroUe09A(){
    TERM_WriteString("\n09a) LED leuchtet, solange der entsprechende Schalter betaetigt ist.\r\n");
    TERM_WriteString("\n########################################################################\r\n");
  }
  
  void IntroUe09B(){
    TERM_WriteString("\n09b) LED wechselt (ein -aus - ein usw.-) mit jeder Schalterbetaetigung.\r\n");
    TERM_WriteString("\n########################################################################\r\n");
  }
  
  void IntroUe09C(){
    TERM_WriteString("\n09c) Die vier LEDs zaehlen binaer mit jeder Schalterbetaetigung von SW1.\r\n");
    TERM_WriteString("\n########################################################################\r\n");
  }
  
  void IntroUe09D(){
    TERM_WriteString("\n09d) SW1 schaltet eine LED ein, SW2 schaltet sie wieder aus.\r\n");
    TERM_WriteString("     WOBEI AUF SW1 UND SW2 PER INTERRUPT REAGIERT WERDEN SOLL.\r\n");
    TERM_WriteString("\n########################################################################\r\n");
  }
