/*  Author: Abdullah Chaudhry
 *  Partner(s) Name: 
 *  Lab Section: 021
 *  Assignment: Lab #8  Exercise #3
 *  Exercise Description: Take the value read by the photoresistor and illuminate an LED connected to P0 if the value is greater than (max / 2)
 *
 *  I acknowledge all content contained herein, excluding template or example
 *  code, is my own original work.
 *
 *  Demo Link: https://drive.google.com/file/d/1hfEr4xsCvnpRrhygzGTexTeuEcuQfuSC/view?usp=sharing
 *
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short x;
unsigned short max = 999;

void ADC_init(){
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;

    /* Insert your solution below */
    ADC_init();
    while (1) {
        x = ADC;

        if(x >= max / 2) {
            PORTB = 0x01;
        } else {
            PORTB = 0x00;
        }
    }
    return 1;
}
