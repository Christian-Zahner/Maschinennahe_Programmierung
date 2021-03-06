/***********************************
 * Headerfilename: UE07A_Bitrev.h  *
 * Created on	 : Nov 29, 2018    *
 * Author		 : Christian Zahner*
 ***********************************/

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"


#ifndef UE07A_BITREV_H_
#define UE07A_BITREV_H_

unsigned long bitrevUp(unsigned long quelle, unsigned long ziel);
void printbit(unsigned long zahl);
void IntroUe07A();

#endif /* UE07A_BITREV_H_ */
