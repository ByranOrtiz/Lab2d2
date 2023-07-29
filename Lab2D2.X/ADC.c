/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
#include "ADC.h"
#define _XTAL_FREQ 4000000 //La frecencia que yo utlize para el delay

void adc_init(int channel){
    switch (channel){
        case 0:
            PORTAbits.RA0=0;
            TRISAbits.TRISA0=1;
            ANSELbits.ANS0=1;       //USAR ANSEL 0 EN ra0
            break;
        case 1:
            PORTAbits.RA1=0;
            TRISAbits.TRISA1=1;
            ANSELbits.ANS1=1;       //USAR ANSEL 0 EN ra1
            break;
        case 2:
            PORTAbits.RA2=0;
            TRISAbits.TRISA2=1;
            ANSELbits.ANS2=1;       //USAR ANSEL 0 EN ra2
            break;
        case 3:
            PORTAbits.RA3=0;
            TRISAbits.TRISA3=1;
            ANSELbits.ANS3=1;       //USAR ANSEL 0 EN ra3
            break;
        case 4:
            PORTAbits.RA5=0;
            TRISAbits.TRISA5=1;
            ANSELbits.ANS4=1;       //USAR ANSEL 0 EN ra5
            break;
        case 5:
            PORTEbits.RE0=0;
            TRISEbits.TRISE0=1;
            ANSELbits.ANS5=1;       //USAR ANSEL 0 EN ra5
            break;
        case 6:
            PORTEbits.RE1=0;
            TRISEbits.TRISE1=1;
            ANSELbits.ANS6=1;       //USAR ANSEL 0 EN ra5
            break;
        case 7:
            PORTEbits.RE2=0;
            TRISEbits.TRISE2=1;
            ANSELbits.ANS7=1;       //USAR ANSEL 0 EN ra5
            break;
        case 8:
            PORTBbits.RB2=0;
            TRISBbits.TRISB2=1;
            ANSELHbits.ANS8=1;       //USAR ANSEL 0 EN ra5
            break;
        case 9:
            PORTBbits.RB3=0;
            TRISBbits.TRISB3=1;
            ANSELHbits.ANS9=1;       //USAR ANSEL 0 EN ra5
            break;
        case 10:
            PORTBbits.RB1=0;
            TRISBbits.TRISB1=1;
            ANSELHbits.ANS10=1;       //USAR ANSEL 0 EN ra5
            break;
        case 11:
            PORTBbits.RB4=0;
            TRISBbits.TRISB4=1;
            ANSELHbits.ANS11=1;       //USAR ANSEL 0 EN ra5
            break;
        case 12:
            PORTBbits.RB0=0;
            TRISBbits.TRISB0=1;
            ANSELHbits.ANS12=1;       //USAR ANSEL 0 EN ra5
            break;
        case 13:
            PORTBbits.RB5=0;
            TRISBbits.TRISB5=1;
            ANSELHbits.ANS13=1;       //USAR ANSEL 0 EN ra5
            break;
    }
    
    ADCON0bits.ADCS1=0;
    ADCON0bits.ADCS0=1;     //fosc/8
    ADCON0bits.ADCS =01;
    ADCON1bits.VCFG1=0;     //VSS
    ADCON1bits.VCFG0=0;     //VDD
    
    ADCON1bits.ADFM=0;      //JUSTIFICADO IZQUIERDA
    ADCON0bits.ADON=1;      //habilitar convertidor ADC
    
    __delay_us(100);
}

int adc_read(){
    int adcValue;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO == 1);  //No hacer nada mientras hace la conversion]
    ADIF = 0;                   //Apagar bandera del ADC
    adcValue = ADRESH;//((ADRESH << 2) + (ADRESL >> 6));   //JUNTAR 10 BITS
    return adcValue;
}

void adc_change_channel(int channel){
    switch (channel){
        case 0:
            ADCON0bits.CHS = 0b0000;
            __delay_ms(5);  
            break;
        case 1:
            ADCON0bits.CHS = 0b0001;
            __delay_ms(5);  
            break;
        case 2:
            ADCON0bits.CHS = 0b0010;
            __delay_ms(5);  
            break;
        case 3:
            ADCON0bits.CHS = 0b0011;
            __delay_ms(5);  
            break;
        case 4:
            ADCON0bits.CHS = 0b0100;
            __delay_ms(5);  
            break;
        case 5:
            ADCON0bits.CHS = 0b0101;
            __delay_ms(5);  
            break;
        case 6:
            ADCON0bits.CHS = 0b0110;
            __delay_ms(5);  
            break;
        case 7:
            ADCON0bits.CHS = 0b0111;
            __delay_ms(5);  
            break;
        case 8:
            ADCON0bits.CHS = 0b1000;
            __delay_ms(5);  
            break;
        case 9:
            ADCON0bits.CHS = 0b1001;
            __delay_ms(5);  
            break;
        case 10:
            ADCON0bits.CHS = 0b1010;
            __delay_ms(5);  
            break;
        case 11:
            ADCON0bits.CHS = 0b1011;
            __delay_ms(5);  
            break;
        case 12:
            ADCON0bits.CHS = 0b1100;
            __delay_ms(5);  
            break;
        case 13:
            ADCON0bits.CHS = 0b1101;
            __delay_ms(5);  
            break;
        default:
            ADCON0bits.CHS = 0b000;
            __delay_ms(5);  
            break;
}
}

int adc_get_channel(){
    return ADCON0bits.CHS;
}
