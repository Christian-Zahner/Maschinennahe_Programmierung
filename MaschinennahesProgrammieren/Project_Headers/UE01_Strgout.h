/***********************************
 * Headerfilename: UE01_Strgout.h  *
 * Created on	 : Nov 17, 2018    *
 * Author		 : Christian Zahner*
 ***********************************/

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"
#include <stdio.h>

#ifndef UE01_STRGOUT_H_
#define UE01_STRGOUT_H_

void strgout();
void strgoutrev();
void strgoutrevalt();
void strgoutRevWithoutCount();
void IntroUe01();
void IntroUe02();

#endif /* UE01_STRGOUT_H_ */
