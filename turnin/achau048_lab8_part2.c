/*	Author: Abdullah Chaudhry
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #8  Exercise #2
 *	Exercise Description: Read the value in from the photoresistor and display it on 10 leds connected to PORTB through PORTD
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *  Demo Link: https://drive.google.com/file/d/1dRRSdG_PPn4jlvN1MZGUO2sV2MS1vZsn/view?usp=sharing
 *
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short x;
void ADC_init(){
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;

    /* Insert your solution below */
    unsigned char resB;
    unsigned char resD;
    ADC_init();
    while (1) {
        x = ADC;
        resB = (char)(x);
        resD = (char)(x >> 8);
  
        PORTB = resB;
        PORTD = resD;

    }

    return 1;
}
