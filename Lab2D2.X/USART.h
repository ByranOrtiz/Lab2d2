/* 
 * File:   
 * Author: Bryan
 * Comments: configuración usart
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef USART_H
#define	USART_H

#include <xc.h> // include processor files - each processor file is guarded.  

void UART_RX_CONFIG(uint16_t baudrate);
void UART_TX_CONFIG(uint16_t baudrate);
void UART_write_char(char *c);
char UART_read_char(void);

#endif	/* USART_H */