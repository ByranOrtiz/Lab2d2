/*
 * File:   Pre1.c
 * Author: Bryan Ortiz
 *
 * Created on July 18, 2023, 2:37 PM
 * Contador 8 bits con 2 botones
 */

//Palabra de configuracion
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = ON        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

//Librerias
#include <xc.h>
#include <stdint.h>
#include "ADC.h"
#include "LCD.h"

#define _XTAL_FREQ 8000000
#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RB5
#define D6 RD6
#define D7 RD7


//Prototipos
void setup(void);
float map(float value, float fromLow, float fromHigh, float toLow, float toHigh);
//Variables globales


//Funcion principal
void main (void){
    setup();
    while(1){
        unsigned int adcV, temp;
        adcV = adc_read();
        temp = map(adcV,0,255,0,500);
        char voltaje[3];
        voltaje[0]=temp/100+48;
        voltaje[1]=(temp/10)%10+48;
        voltaje[2]=temp%10+48;
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("Potenciometro 1:");
        Lcd_Set_Cursor(2,1);
        Lcd_Write_Char(voltaje[0]);
        Lcd_Write_Char('.');
        Lcd_Write_Char(voltaje[1]);
        Lcd_Write_Char(voltaje[2]);
        Lcd_Write_Char('V');
        Lcd_Write_String(" Siuuu");
        __delay_ms(500);
    }
    return;
}
//Funciones
void setup(){
    ANSEL = 0;
    TRISD = 0;
    adc_init(0);
    Lcd_Init();
}

float map(float value, float fromLow, float fromHigh, float toLow, float toHigh){
    return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}