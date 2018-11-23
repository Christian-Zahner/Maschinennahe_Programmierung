/************************************
 * Filename		 : UE08_liste.c	    *
 * Created on	 : Nov 23, 2018		*
 * Author		 : Christian Zahner	*
 ************************************/

// Nach Vorgabe von Dr. Prof. Tempelmeier 

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"
//#include "malloc_wrapper.h"

#include <stdlib.h>
#include <stdio.h>

#include "Intro.h"
#include "UE08_Liste.h"


char     msginput[]  = "\r\nZahl eingeben (0 fuer Ende): "; 
char     msgfehler[] = "\nFehler bei malloc() !\n";

void     *anker = NULL;


 void lstint(){
	     
  asm {

     schleife:  

             // Zahl einlesen (Ende vereinfachend mit Wert 0)
             //----------------------------------------------
 







 
             // Einzuh�ngendes Element aufbauen
             // -------------------------------
             // Mit malloc; malloc erwartet den Parameter im Register D0,
			 // weil daf�r "register_abi" gilt (nicht compact_abi)








  //                  ___________ 
  //          a0 -->  |zahl|  0 | 
  //                  �����������    
             

  // Organisation der Listeniteration
  //
  // a2 zeigt auf das aktuelle Element (oder 0 f�r Listenende)
  // a3 zeigt   a u f   d e n   Z e i g e r   im vorhergehenden Element
  //
  //                              a3         a2 
  //                                \         \
  //  anker:                         \         \
  //  ______     ___________     _____V_____    V___________     ___________
  //  |    | --> |zahl|next| --> |zahl|next| --> |zahl|next| --> |zahl|  0 |
  //  ������     �����������     �����������     �����������     �����������
  //
  //    Funtioniert 
  //       + auch am Listenende (a3 zeigt auf 0, a2 ist 0)
  //       + auch bei Einf�gen vor dem ersten Element 
  //                           (a3 zeigt auf Anker, a2 auf das erste Element
  //       + auch bei leerer Liste (a3 zeigt auf Anker, Anker und a2 sind 0)


  // suchen der Einf�gestelle
  //-------------------------

       // Iterator-P�rchen initialisieren

	   
	   
  naechstes:      

  
  
  
  
  
  
  
  
  
  
  // Einf�gestelle gefunden: Objekt einh�ngen
  //-----------------------------------------                
  gefunden:
  



  
       //bra     schleife         // naechste Zahl
                  
  // gesamte Liste ausgeben
  //-----------------------
  ausgabe: 









  
  ende:

  }

	TERM_WriteLn();			         // N�chste Zeile im Terminal
  
 }
 
 void IntroUe08(){
 	
 	TERM_WriteString("\n########################################################################\r\n");
 	TERM_WriteString("\nUebung08: Aufbau und Ausgabe einer einfach verkettetn\r\n");
 	TERM_WriteString("          und sortierteb Liste von Integerzahlen\r\n");
 	TERM_WriteString("Verwenden sie die Vorgabe UEB08_Vorgabe.c\r\n");
 	TERM_WriteString("\n########################################################################\r\n\n");
 	
 }

