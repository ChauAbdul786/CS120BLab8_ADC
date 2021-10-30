/*  Author: Abdullah Chaudhry
 *  Partner(s) Name: 
 *  Lab Section: 021
 *  Assignment: Lab #8  Exercise #4
 *  Exercise Description: Take the value read by the photoresistor and illuminate an LED connected to PORTB sequentially depending on the light level.
 *
 *  I acknowledge all content contained herein, excluding template or example
 *  code, is my own original work.
 *
 *  Demo Link: https://drive.google.com/file/d/1tE609z7fdJG0LKOs2Ep7fWe8vODcrHbE/view?usp=sharing
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

    /* Insert your solution below */
    ADC_init();
    unsigned char tmpB;
    while (1) {
        x = ADC;

        if(x < 64) {
            tmpB = 0x01;
        }else if(x < 128){
            tmpB = 0x03;
        }else if(x < 192){
            tmpB = 0x07;
        }else if(x < 256){
            tmpB = 0x0F;
        }else if(x < 320){
            tmpB = 0x1F;
        }else if(x < 384){
            tmpB = 0x3F;
        }else if(x < 448){
            tmpB = 0x7F;
        }else{
            tmpB = 0xFF;
        }

        PORTB = tmpB;
    }
    return 1;
}
