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



  #define IPS 0x40000000

  /* Definitions for MCF_GPIO Port NQ */
  #define PORTNQ 			     0x40100008	// Output
  #define PNQPAR 			  	 0x40100068 // GPIO einstellen
  #define DDRNQ					 0x40100020	// Datenrichtung/Output
  #define PINDATANQ			     0x40100038	// Auslesen PIN
  #define CLRNQ				     0x40100068 // Schreiben an Port Taster

  #define PORTNQ1 			     0x00000002
  #define PORTNQ5   			 0x00000020


  /* Bit definitions for MCF_GPIO Port TC */
  #define PORTTC        		 0x4010000F // Output
  #define PTCPAR  				 0x4010006F	// GPIO einstellen 
  #define DDRTC					 0x40100027	// Datenrichtung/Input
  #define SETTC				 	 0x4010003F // Set Pin bzw. "LEDS" 
  #define CLRTC			 		 0x40100057	// Schreiben an "LEDS"

  #define PORTTC0				 0x00000001
  #define PORTTC1   			 0x00000002
  #define PORTTC2   			 0x00000004
  #define PORTTC3  				 0x00000008


  void ledOnOff(){

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
	  	  
		 // andi.w #0xF0F0, MNP_GPIO_PNQPAR  geht nicht, deshalb folgender Code
		 move.w   PNQPAR,d0 			//NQ5 and NQ1 l�schen f�r GPIO Funktion
		 and.l    #0xF0F0, d0
		 move.w   d0, PNQPAR
		 
		 // andi.b #0xDD, MNP_GPIO_DDRNQ  geht nicht, deshalb folgender Code
		 move.b   DDRNQ, d0				 //NQ5 and NQ1 l�schen f�r input Funktion
		 andi.l   #0xDD,d0
		 move.b   d0, DDRNQ
		  	

		 // andi.b #0xDD, MNP_GPIO_CLRNQ  geht nicht, deshalb folgender Code
		 move.b   CLRNQ,d0           	//NQ5+NQ1 l�schen
		 andi.l   #0xDD,d0	
		 move.b   d0, CLRNQ


	  /* Enable LEDs as digital outputs ==================================== */
	  /* MCF52259RM.pdf
	  - Port Data Direction must be set for output function 
	    15.6.2 Port Data Direction Registers (DDRn))
	  - Pin Assignment must be set to GPIO function 
	    (15.6.5.1 Dual-Function Pin Assignment Registers)
	   - Output Data Register must be set/reset 
	    (15.6.1 Port Output Data Registers (PORTn))
	  */
	  	
	  	
	     clr.b    PTCPAR      			//GPIO Funktion (=0)

	  	 move.b   #0xf, d0              //output Funktion (=1)
	  	 move.b   d0, DDRTC
	  	
	     clr.b    CLRTC        			//LEDS OFF, siehe Figure 15-3
     
     loop:

     ////////////////////////// Taster 1 schaltet LED 1
     
     	clr.l    d0                 // Reset D0
  	    move.b   PINDATANQ, d0 		// Taster via PINDATA_SETNQ abfragen
     	andi.l   #PORTNQ5, d0   	// Check NQ5 auf 0 (SW1 gedr�ckt)
     	bne      LED1_OFF           // falls nicht gedr�ckt: Sprung
  	
       	move.l   #PORTTC0,d1
     	move.b	 d1, SETTC         	// LED einschalten via set bit in GPIO_SETTC
     	bra      LED1_END
  	
     LED1_OFF:	
     
     	move.l   #~(PORTTC0),d1
     	move.b   d1, CLRTC         	// LED ausschalten via clear bit in GPIO_CLR

     LED1_END:	

     // Nochmal dasselbe f�r Nr. 2:
     ////////////////////////// Taster 2 schaltet LED 2
     
     	clr.l    d0
     	move.b   PINDATANQ, d0   	// Taster via PINDATA_SETNQ abfragen
     	andi.l   #PORTNQ1,  d0  	// Check NQ1 auf 0 (SW2 gedr�ckt)
     	bne      LED2_OFF
  	
     	move.l   #PORTTC1,  d1
     	move.b   d1, SETTC         // LED einschalten via set bit in GPIO_SET
     	bra      LED2_END
  	
     LED2_OFF:	
     
     	move.l   #~(PORTTC1),d1
     	move.b   d1, CLRTC         // LED ausschalten via clear bit in GPIO_CLR

  	
     LED2_END:	
     
     	bra	    loop

     }

  }
  
  void ledLatched(){
	  
	asm{
		
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
	
		// andi.w #0xF0F0, MNP_GPIO_PNQPAR  geht nicht, deshalb folgender Code
		move.w   PNQPAR,d0 		 //NQ5 and NQ1 l�schen f�r GPIO Funktion
		and.l    #0xF0F0, d0
		move.w   d0, PNQPAR
					 
		// andi.b #0xDD, MNP_GPIO_DDRNQ  geht nicht, deshalb folgender Code
		move.b   DDRNQ, d0			 //NQ5 and NQ1 l�schen f�r input Funktion
		andi.l   #0xDD,d0
		move.b   d0, DDRNQ
						
		// andi.b #0xDD, MNP_GPIO_CLRNQ  geht nicht, deshalb folgender Code
		move.b   CLRNQ,d0           //NQ5+NQ1 l�schen
		andi.l   #0xDD,d0	
		move.b   d0, CLRNQ


		 /* Enable LEDs as digital outputs ==================================== */
		 /* MCF52259RM.pdf
		 - Port Data Direction must be set for output function 
		   (15.6.2 Port Data Direction Registers (DDRn))
		 - Pin Assignment must be set to GPIO function 
		   (15.6.5.1 Dual-Function Pin Assignment Registers)
		 - Output Data Register must be set/reset 
		   (15.6.1 Port Output Data Registers (PORTn))
		  */
		  	  	
		  	  	
		clr.b    PTCPAR      		//GPIO Funktion (=0)

		move.b   #0xf, d0           //output Funktion (=1)
		move.b   d0, DDRTC
		  	  	
		clr.b    CLRTC        		//LEDS OFF, siehe Figure 15-3

	 loop:

	 	 // Schleife so lange Taste nicht gedr�ckt

	     wait_for_pressed:

	      clr.l    d0                         
	      move.b   PINDATANQ, d0         // Poll the switches via SETNQ
	      andi.l   #PORTNQ5, d0  		 // Check if NQ5 is unset (SW1 pressed)
	      bne      wait_for_pressed
	        

	     wait_for_released:
	     
	     // Schleife so lange Taste gedr�ckt

	      clr.l    d0                         
	      move.b   PINDATANQ, d0        // Poll the switches via SETNQ
	      andi.l   #PORTNQ5, d0   		// Check if NQ5 is set (SW1 released)
	      beq      wait_for_released

	      // LED ein

	      move.b   PORTTC, d0			// Inhalt in d0
	      bchg     #PORTTC0, d0   		// Toggle bit 
	      move.b   d0, PORTTC    		// PORTTC Lampe ein
	             
	      bra      loop	


	    }
	  
  }
  
  void ledCount(){
	  
	asm{
			
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
	
			// andi.w #0xF0F0, MNP_GPIO_PNQPAR  geht nicht, deshalb folgender Code
			move.w   PNQPAR,d0 			//NQ5 and NQ1 l�schen f�r GPIO Funktion
			and.l    #0xF0F0, d0
			move.w   d0, PNQPAR
						 
			// andi.b #0xDD, MNP_GPIO_DDRNQ  geht nicht, deshalb folgender Code
			move.b   DDRNQ, d0				 //NQ5 and NQ1 l�schen f�r input Funktion
			andi.l   #0xDD,d0
			move.b   d0, DDRNQ
							
			// andi.b #0xDD, MNP_GPIO_CLRNQ  geht nicht, deshalb folgender Code
			move.b   CLRNQ,d0           	//NQ5+NQ1 l�schen
			andi.l   #0xDD,d0	
			move.b   d0, CLRNQ
	
		/* Enable LEDs as digital outputs ==================================== */
		/* MCF52259RM.pdf
		- Port Data Direction must be set for output function 
		  (15.6.2 Port Data Direction Registers (DDRn))
		- Pin Assignment must be set to GPIO function 
		  (15.6.5.1 Dual-Function Pin Assignment Registers)
		- Output Data Register must be set/reset 
		  (15.6.1 Port Output Data Registers (PORTn))
		*/
						
						
			clr.b    PTCPAR      			//GPIO Funktion (=0)
	
			move.b   #0xf, d0              //output Funktion (=1)
			move.b   d0, DDRTC
						
			clr.b    CLRTC        		  //LEDS OFF, siehe Figure 15-3
	
		loop:
	
	
			wait_for_pressed:
	
			 clr.l    d0                         
			 move.b   PINDATANQ, d0         // Poll the switches via SETNQ
			 andi.l   #PORTNQ5, d0  		// Check if NQ5 is unset (SW1 pressed)
			 bne      wait_for_pressed
					
	
			wait_for_released:
	
			 clr.l    d0                         
			 move.b   PINDATANQ, d0        	// Poll the switches via SETNQ
			 andi.l   #PORTNQ5, d0   		// Check if NQ5 is set (SW1 released)
			 beq      wait_for_released
	
	
			 move.b   PORTTC, d0			// Auslesen des "LED Registers"
			 addq.l	  #1, d0	   			// erh�he aktuellen Inhalt um 1
			 move.b   d0, PORTTC			// �bertrage an "LED Register"
									 
			 bra      loop	
	
	
		  }
		  
  }
  
  void ledCountPlusMinus(){
	  
	asm{
			
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
	
			// andi.w #0xF0F0, MNP_GPIO_PNQPAR  geht nicht, deshalb folgender Code
			move.w   PNQPAR,d0 			//NQ5 and NQ1 l�schen f�r GPIO Funktion
			and.l    #0xF0F0, d0
			move.w   d0, PNQPAR
						 
			// andi.b #0xDD, MNP_GPIO_DDRNQ  geht nicht, deshalb folgender Code
			move.b   DDRNQ, d0				 //NQ5 and NQ1 l�schen f�r input Funktion
			andi.l   #0xDD,d0
			move.b   d0, DDRNQ
							
			// andi.b #0xDD, MNP_GPIO_CLRNQ  geht nicht, deshalb folgender Code
			move.b   CLRNQ,d0           	//NQ5+NQ1 l�schen
			andi.l   #0xDD,d0	
			move.b   d0, CLRNQ
	
		/* Enable LEDs as digital outputs ==================================== */
		/* MCF52259RM.pdf
		- Port Data Direction must be set for output function 
		  (15.6.2 Port Data Direction Registers (DDRn))
		- Pin Assignment must be set to GPIO function 
		  (15.6.5.1 Dual-Function Pin Assignment Registers)
		- Output Data Register must be set/reset 
		  (15.6.1 Port Output Data Registers (PORTn))
		*/
						
						
			clr.b    PTCPAR      			//GPIO Funktion (=0)
	
			move.b   #0xf, d0              //output Funktion (=1)
			move.b   d0, DDRTC
						
			clr.b    CLRTC        		  //LEDS OFF, siehe Figure 15-3
	
		loop:
	
	
			wait_for_pressed:
	
			 clr.l    d0                         
			 move.b   PINDATANQ, d0         // Poll the switches via SETNQ
			 andi.l   #PORTNQ5, d0  		// Check if NQ5 is unset (SW1 pressed)
			 beq	  wait_for_released1
			 
			 clr.l    d1                         
			 move.b   PINDATANQ, d1         // Poll the switches via SETNQ
			 andi.l   #PORTNQ1, d1  		// Check if NQ5 is unset (SW1 pressed)
			 beq	  wait_for_released2
			 
			 
			 bra      wait_for_pressed
					
	
			wait_for_released1:
	
			 clr.l    d0                         
			 move.b   PINDATANQ, d0        	// Poll the switches via SETNQ
			 andi.l   #PORTNQ5, d0   		// Check if NQ5 is set (SW1 released)
			 beq      wait_for_released1
	
	
			 move.b   PORTTC, d0			// Auslesen des "LED Registers"
			 addq.l	  #1, d0	   			// erh�he aktuellen Inhalt um 1
			 move.b   d0, PORTTC			// �bertrage an "LED Register"
									 
			 bra      loop	
			 
			wait_for_released2:
		
			 clr.l    d1                         
			 move.b   PINDATANQ, d1        	// Poll the switches via SETNQ
			 andi.l   #PORTNQ1, d1   		// Check if NQ5 is set (SW1 released)
			 beq      wait_for_released2
		
		
			 move.b   PORTTC, d1			// Auslesen des "LED Registers"
			 subq.l	  #1, d1	   			// erh�he aktuellen Inhalt um 1
			 move.b   d1, PORTTC			// �bertrage an "LED Register"
										 
			 bra      loop	
	
	
		  }
		  
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
