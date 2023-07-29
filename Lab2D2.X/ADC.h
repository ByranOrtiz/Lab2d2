/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC_H
#define	ADC_H

#include <xc.h> // include processor files - each processor file is guarded.  

void adc_init(int channel);
int adc_read();
void adc_change_channel(int channel);
int adc_get_channel();

#endif	/* ADC_H */