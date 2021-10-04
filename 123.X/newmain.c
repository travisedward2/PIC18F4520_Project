

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pic18f4520.h>
#include "blocks.h"
#include "pss.h"

#pragma config OSC = INTIO67 // Oscillator Selection bits
#pragma config WDT = OFF     // Watchdog Timer Enable bit 
#pragma config PWRT = OFF    // Power-up Enable bit
#pragma config BOREN = ON   // Brown-out Reset Enable bit
#pragma config PBADEN = OFF     // Watchdog Timer Enable bit 
#pragma config LVP = OFF     // Low Voltage (single -supply) In-Circute Serial Pragramming Enable bit
#pragma config CPD = OFF     // Data EEPROM?Memory Code Protection bit (Data EEPROM code protection off)
#define _XTAL_FREQ 200000
int game=0;
int state[3]={0,0,0};
int hand=0;
int scores=0;

int condition=0;
int timer=0;

unsigned char W[145] = { 0xff, 0xc0, 0xbf, 0xcf, 0xcf, 0xbf, 0xc0,      //w
                       0xff, 0xc0, 0xb6, 0xb6, 0xb6,      //e
                       0xff, 0x80, 0xbf, 0xbf, 0xbf,       //l
                       0xff, 0xc1, 0xbe, 0xbe, 0xdd,      //c
                       0xff, 0xc1, 0xbe, 0xbe, 0xc1,      //o
                       0xff,  0x80, 0xfd, 0xf3, 0xfd, 0x80,    //m
                       0xff,0xc0, 0xb6, 0xb6, 0xb6, 0xff,0xff,0xff,      //e
                       0xff, 0xbb, 0xbd, 0x80, 0xbf, 0xbf, 0xff,0xbf, 0xff,      //1
                       0x80, 0xf7, 0xf7, 0x80, 0xff, 0x85, 0xff, 0xf7,      //Hi
                       0x81, 0xb7, 0xdf, 0xff,      //t
                       0xc1, 0xbe, 0xbe, 0xdd,      // C
                       0xff, 0xc3, 0xbf, 0xc3, 0xbf, 0xff,      //u
                       0x80, 0xb7, 0xb7, 0xcf, 0xff,    //b
                       0xc7, 0xab, 0xab, 0xe7,      //e
                        
                       0xff, 0xa0, 0xff, 0xff,0xff, 0x9d, 0xae,      //e(else) 驚嘆號   2(part) 
                       0xb6, 0xb9, 0xff,0xbf, 0xff, 0xc3, 0x81, 0x81, 0x81,      //2(else) rock(all)
                       0x81, 0xc3, 0xff, 0xfb, 0xf7, 0xcf, 0x81, 0x8f,      //scissors(all)
                       0xff, 0xef, 0xdf, 0x83, 0x81, 0x81, 0x83, 0xff, 0xff,     //paw(all)
                       0xff,0xdd, 0xb6, 0xb2, 0xcd, 0xff,0xbf,0xff, 0x80, 0xb6, 0xff,      //3(all) E(all)     17
                       0xbb, 0xd7, 0xef, 0xd7, 0xbb, 0xff, 0x85, 0xff,      //x i
                       0xf7, 0x81, 0xb7, 0xdf, 0xff, 0xff, 0xff, 0xff,     //t
                       0xff, 0xff, 0xff, 0xff};

void game1_interrupt(){
    
    if(PIR1bits.TMR1IF==1&&T1CONbits.TMR1ON==1){
        timer++;
        TMR1H=0x85;
        TMR1L=0xED;
        PIR1bits.TMR1IF=0;
        if(timer==60){
    T1CONbits.TMR1ON=0;
        }
    }
   
    INTCONbits.GIEH=0;
    
  
         if(INTCONbits.INT0IF==1){
        if(state[0]==1) {
            scores++;
            change(&state[0]);}
//        LATDbits.LATD0^=1;
        INTCONbits.INT0IF=0;
    }
        if(INTCON3bits.INT1IF==1){
          if(state[0]==2) {
              scores++;
              change(&state[0]);}  
//        LATDbits.LATD1^=1;
        INTCON3bits.INT1IF=0;
    }
        if(INTCON3bits.INT2IF==1){
            if(state[0]==3) {
                scores++;
                change(&state[0]); }
//        LATDbits.LATD2^=1;
        INTCON3bits.INT2IF=0;
    }
        __delay_ms(100);
   
  
    INTCONbits.GIEH=1;
}
void game2_interrupt(){

    INTCONbits.GIEH=0;
    
  
         if(INTCONbits.INT0IF==1){ //I paper
             hand=1;
             condition=1;
//        LATDbits.LATD0^=1;
        INTCONbits.INT0IF=0;
    }
        if(INTCON3bits.INT1IF==1){ //I scissors
            hand=2;
            condition=1;
//        LATDbits.LATD1^=1;
        INTCON3bits.INT1IF=0;
    }
        if(INTCON3bits.INT2IF==1){ //I stone
            hand=3;
            condition=1;
//        LATDbits.LATD2^=1;
        INTCON3bits.INT2IF=0;
    }
        __delay_ms(100);
   
  
    INTCONbits.GIEH=1;
}
void game3_interrupt(){

    INTCONbits.GIEH=0;
    
  
         if(INTCONbits.INT0IF==1){ //I paper
            
        INTCONbits.INT0IF=0;
    }
        if(INTCON3bits.INT1IF==1){ //I scissors
         
//        LATDbits.LATD1^=1;
        INTCON3bits.INT1IF=0;
    }
        if(INTCON3bits.INT2IF==1){ //I stone
            game=0;
//        LATDbits.LATD2^=1;
        INTCON3bits.INT2IF=0;
    }
        __delay_ms(100);
   
  
    INTCONbits.GIEH=1;
}
void __interrupt(high_priority) myIsr(void){  
    if(game==0){
         INTCONbits.GIEH=0;
         if(INTCONbits.INT0IF==1){ //I paper
             game=1;
//        LATDbits.LATD0^=1;
        INTCONbits.INT0IF=0;
    }
        if(INTCON3bits.INT1IF==1){ //I scissors
            game=2;
//        LATDbits.LATD1^=1;
        INTCON3bits.INT1IF=0;
    }
        if(INTCON3bits.INT2IF==1){ //I stone
           game=3;
//        LATDbits.LATD2^=1;
        INTCON3bits.INT2IF=0;
    }
        __delay_ms(100);
   
  
    INTCONbits.GIEH=1;

    }
    else if(game==1){
       game1_interrupt();
    }
    else if(game==2){
       game2_interrupt();
    }  
     else if(game==3){
       game3_interrupt();
     }
    }
    
    

void init_interrupt(){
    RCONbits.IPEN = 1;      //enable Interrupt Priority mode
    INTCONbits.GIEH = 1;    //enable high priority interrupt
    INTCONbits.GIEL = 1;     //disable low priority interrupt
    
    TRISB=0xFF;
    PORTB=0;
    
    INTCONbits.INT0IE=1;
    INTCONbits.INT0IF=0;
    INTCON2bits.INTEDG0=1;
    
    INTCON3bits.INT1IE=1;
    INTCON3bits.INT1IF=0;
    INTCON3bits.INT1IP=1;
    INTCON2bits.INTEDG1=1;
    
    INTCON3bits.INT2IE=1;
    INTCON3bits.INT2IF=0;
    INTCON3bits.INT2IP=1;
    INTCON2bits.INTEDG2=1;
    
    TRISD=0;
    TRISC=0;
    LATD=0xff;
    LATC=0x00;
    
}
   void welcome(int pos){
     
    LATD=0b11111111;
    LATC=0b00000000;
    
    LATCbits.LC0=1;
    LATD=W[0+pos];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC1=1;
    
    LATD=W[1+pos];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    
    LATCbits.LC2=1;
    
    LATD=W[2+pos];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC3=1;
    
    LATD=W[3+pos];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC4=1;
    
    LATD=W[4+pos];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC5=1;
    
    LATD=W[5+pos];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC6=1;
    
    LATD=W[6+pos];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC7=1;
    
    LATD=W[7+pos];
    __delay_ms(10);
    
}
void animation(){
    int count=0;
    int pos = 0;
    while(1){   
        
        for (count = 0; count < 5; count ++){
            welcome(pos);
        }
        pos++;
        if( pos == 137){
            pos = 0;
        }
        if(game!=0)
            break;
//        count++;
//        if(count==100){
//            count=0;
//            pos = 0;
//            unsigned char tmp=W[0];
//            int i=0;
//            for(i=0;i<142;i++){
//
//                W[i]=W[i+1];
//            }
//            W[142]=tmp;
//        }
    }
}

void main(void) {
    //?? oscillator = 1 MHz
    OSCCONbits.IRCF=0b100;
       srand(time(NULL));
    //output pins


   
 

    
    //interrupt buttons setting
    init_interrupt();
   while(1){
    if(game==0){
        animation();
    }
    else if(game==1){
        game1_init(&state[0],&scores,&timer);
        game1_run(&state[0],&timer,&game,&scores);
    }
    else if(game==2){
          game2_init(&hand,&condition);
          game2_run(&hand,&condition,&game);
    }
    else if(game==3){
      LATD=0b11111111;
      LATC=0b00000000;
    }
   }
  //  game1_init(&state[0]);
         //Timer1 ??
//    game1_run(&state[0],&timer);
//   game2_run(&hand,&condition);
//    while(1){
//        if(condition==0)   
//    guess(&condition);
//    else if(condition==1){
//     opponent=(rand()%3)+1;
//     if(opponent==1){
//         ani_paper();
//     }
//     if(opponent==2){
//         ani_scissors();
//     }
//     if(opponent==3){
//         ani_stone();
//     }
//     if(hand==opponent){
//         condition=0;
//         hand=0;
//     }
//     if((hand==1&&opponent==3)||(hand==2&&opponent==1)||(hand==3&&opponent==2)){ 
//     condition=0;
//     hand=0;
//     }//win
//     if((hand==1&&opponent==2)||(hand==2&&opponent==3)||(hand==3&&opponent==1)){
//     condition=0;
//     hand=0;
//     }//lose
//     
// }   
//    }
            
 
    
    
    while(1);
    
    return;
}