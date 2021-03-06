/***********************************
 * Headerfilename: UE05_Mymemcopy.h*
 * Created on	 : Nov 16, 2018    *
 * Author		 : Christian Zahner*
 ***********************************/

#include "UART0.h"
#include "support_common.h"  // include peripheral declarations and more; 
#include "uart_support.h"    // universal asynchronous receiver transmitter,
                             // (d.h. die serielle Schnittstelle)
#include "terminal_wrapper.h"
#include <stdio.h>

#ifndef UE05_MYMEMCOPY_H_
#define UE05_MYMEMCOPY_H_

void introUe5();
void* mymemcopy(void* ziel, const void* quelle, size_t anzahl);
void outro();

#endif /* UE05_MYMEMCOPY_H_ */
