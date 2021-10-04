/*
 * File:   newmain1.c
 * Author: USER
 *
 * Created on 2021年1月11日, 下午 11:59
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pic18f4520.h>
#include <xc.h>
#define _XTAL_FREQ 200000

void block7(void){
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD0=0;
    LATCbits.LC0=1;
    LATCbits.LC1=1;
    __delay_ms(10);
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD1=0;
    LATCbits.LC0=1;
    LATCbits.LC1=1;
    __delay_ms(10);
    }
void block8(void){
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD0=0;
    LATCbits.LC3=1;
    LATCbits.LC4=1;
    __delay_ms(10);
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD1=0;
    LATCbits.LC3=1;
    LATCbits.LC4=1;
    __delay_ms(10);
    }
void block9(void){
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD0=0;
    LATCbits.LC6=1;
    LATCbits.LC7=1;
    __delay_ms(10);
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD1=0;
    LATCbits.LC6=1;
    LATCbits.LC7=1;
    __delay_ms(10);    
    }

void block4(void){
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD3=0;
    LATCbits.LC0=1;
    LATCbits.LC1=1;
    __delay_ms(10);
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD4=0;
    LATCbits.LC0=1;
    LATCbits.LC1=1;
    __delay_ms(10);
    }
void block5(void){
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD3=0;
    LATCbits.LC3=1;
    LATCbits.LC4=1;
    __delay_ms(10);
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD4=0;
    LATCbits.LC3=1;
    LATCbits.LC4=1;
    __delay_ms(10);
    }
void block6(void){
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD3=0;
    LATCbits.LC6=1;
    LATCbits.LC7=1;
    __delay_ms(10);
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD4=0;
    LATCbits.LC6=1;
    LATCbits.LC7=1;
    __delay_ms(10);
    }    

void block1(void){
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD6=0;
    LATCbits.LC0=1;
    LATCbits.LC1=1;
    __delay_ms(10);
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD7=0;
    LATCbits.LC0=1;
    LATCbits.LC1=1;
    __delay_ms(10);
    }
void block2(void){
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD6=0;
    LATCbits.LC3=1;
    LATCbits.LC4=1;
    __delay_ms(10);
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD7=0;
    LATCbits.LC3=1;
    LATCbits.LC4=1;
    __delay_ms(10);
    }
void block3(void){
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD6=0;
    LATCbits.LC6=1;
    LATCbits.LC7=1;
    __delay_ms(10);
    LATD=0xff;
    LATC=0x00;
    LATDbits.LD7=0;
    LATCbits.LC6=1;
    LATCbits.LC7=1;
    __delay_ms(10);   
    }

void block(int x){
    switch(x){
        case 1:
            block1();
        break;
        case 2:
            block2();
        break;
        case 3:
            block3();
        break;
        case 4:
            block4();
        break;
        case 5:
            block5();
        break;
        case 6:
            block6();
        break;
        case 7:
            block7();
        break;
        case 8:
            block8();
        break;
        case 9:
            block9();
        break;
    }
}
void change(int* state){
    int temp[3]={0,0,0};
    temp[2]=(rand()%3)+1+6;
    temp[1]=state[2]-3;
    temp[0]=state[1]-3;
    state[0]=temp[0];
    state[1]=temp[1];
    state[2]=temp[2];
    
}
void animate_score(int x){
    switch(x){
        case 1:
//            unsigned char W[6]={
//        0xff,0xff,0xbd, 0x80, 0xbf,0xff
//    };
//       int count=0;
//    int pos = 0;
//    while(1){   
//        
//        for (count = 0; count < 5; count ++){
//            LATD=0b11111111;
//    LATC=0b00000000;
//    
//    LATCbits.LC0=1;
//    LATD=W[0+pos];
//    __delay_ms(10);
//    
//    LATD=0b11111111;
//    LATC=0b00000000;
//    LATCbits.LC1=1;
//    
//    LATD=W[1+pos];
//    __delay_ms(10);
//    
//    LATD=0b11111111;
//    LATC=0b00000000;
//    
//    LATCbits.LC2=1;
//    
//    LATD=W[2+pos];
//    __delay_ms(10);
//    
//    LATD=0b11111111;
//    LATC=0b00000000;
//    LATCbits.LC3=1;
//    
//    LATD=W[3+pos];
//    __delay_ms(10);
//    
//    LATD=0b11111111;
//    LATC=0b00000000;
//    LATCbits.LC4=1;
//    
//    LATD=W[4+pos];
//    __delay_ms(10);
//    
//    LATD=0b11111111;
//    LATC=0b00000000;
//    LATCbits.LC5=1;
//    
//    LATD=W[5+pos];
//    __delay_ms(10);
//    
//    LATD=0b11111111;
//    LATC=0b00000000;
//    LATCbits.LC6=1;
//    
//    LATD=W[6+pos];
//    __delay_ms(10);
//    
//    LATD=0b11111111;
//    LATC=0b00000000;
//    LATCbits.LC7=1;
//    
//    LATD=W[7+pos];
//    __delay_ms(10);
//    
//        }
//        pos++;
//        if( pos == 22){
//            break;
//        }
//    }
        break;
        case 2:
           
        break;
        case 3:
            
        break;
        case 4:
            
        break;
        case 5:
            
        break;
        case 6:
            
        break;
        case 7:
            
        break;
        case 8:
            
        break;
        case 9:
            
        break;
        case 0:
            
        break;
    }
}
void score(int x,int y,int z){

    unsigned char W[53]={
    0xdd, 0xba, 0xb6, 0xcd, 0xff,
    0xc1, 0xbe, 0xbe, 0xdd, 0xff,
    0xc1, 0xbe, 0xbe, 0xc1, 0xff,
    0x81, 0xe6, 0xd6, 0xb9, 0xff,
    0x80, 0xb6, 0xb6, 0xb6, 
    0xff, 0xd7, 0xd7, 0xd7, 0xff,
    0xff,0xff, 0xff, 0xff, 0xff, 0xff,//h
    0xff,0xff, 0xff, 0xff, 0xff, 0xff,//t
    0xff,0xff, 0xff, 0xff, 0xff, 0xff,//o
    0xff,0xff, 0xff, 0xff, 0xff, 0xff
    };
    switch(y){
        case 1:{
         W[35]=0xff;
         W[36]=0xff;
         W[37]=0xbd;
         W[38]=0x80;
         W[39]=0xbf;
         W[40]=0xff;
        break;}
        case 2:{
         W[35]=0xff;
         W[36]=0x90;
         W[37]=0xae;
         W[38]=0xb6;
         W[39]=0xb9;
         W[40]=0xff;         
        break;}
        case 3:{
         W[35]=0xff;
         W[36]=0xdd;
         W[37]=0xb6;
         W[38]=0xb6;
         W[39]=0xc9;
         W[40]=0xff;
        break;}
        case 4:{
         W[35]=0xff;
         W[36]=0xe1;
         W[37]=0xee;
         W[38]=0x80;
         W[39]=0xef;
         W[40]=0xff;     
        break;}
        case 5:{
         W[35]=0xff;
         W[36]=0xd0;
         W[37]=0xb6;
         W[38]=0xb6;
         W[39]=0xce;
         W[40]=0xff;   
        break;}
        case 6:{
         W[35]=0xff;
         W[36]=0xc3;
         W[37]=0xb5;
         W[38]=0xb6;
         W[39]=0xcf;
         W[40]=0xff;     
        break;}
        case 7:{
         W[35]=0xff;
         W[36]=0xf9;
         W[37]=0xfe;
         W[38]=0xfe;
         W[39]=0x81;
         W[40]=0xff;     
        break;}
        case 8:{
         W[35]=0xff;
         W[36]=0xc9;
         W[37]=0xb6;
         W[38]=0xb6;
         W[39]=0xc9;
         W[40]=0xff;      
        break;}
        case 9:{
         W[35]=0xff;
         W[36]=0xf9;
         W[37]=0xf6;
         W[38]=0xf6;
         W[39]=0x81;
         W[40]=0xff;     
        break;}
        case 0:{
         W[35]=0xff;
         W[36]=0xc1;
         W[37]=0xbe;
         W[38]=0xbe;
         W[39]=0xc1;
         W[40]=0xff;     
        break;}
    }
    switch(x){
        case 1:{
         W[29]=0xff;
         W[30]=0xff;
         W[31]=0xbd;
         W[32]=0x80;
         W[33]=0xbf;
         W[34]=0xff;
        break;}
        case 2:{
         W[29]=0xff;
         W[30]=0x90;
         W[31]=0xae;
         W[32]=0xb6;
         W[33]=0xb9;
         W[34]=0xff;         
        break;}
        case 3:{
         W[29]=0xff;
         W[30]=0xdd;
         W[31]=0xb6;
         W[32]=0xb6;
         W[33]=0xc9;
         W[34]=0xff;
        break;}
        case 4:{
         W[29]=0xff;
         W[30]=0xe1;
         W[31]=0xee;
         W[32]=0x80;
         W[33]=0xef;
         W[34]=0xff;     
        break;}
        case 5:{
         W[29]=0xff;
         W[30]=0xd0;
         W[31]=0xb6;
         W[32]=0xb6;
         W[33]=0xce;
         W[34]=0xff;   
        break;}
        case 6:{
         W[29]=0xff;
         W[30]=0xc3;
         W[31]=0xb5;
         W[32]=0xb6;
         W[33]=0xcf;
         W[34]=0xff;     
        break;}
        case 7:{
         W[29]=0xff;
         W[30]=0xf9;
         W[31]=0xfe;
         W[32]=0xfe;
         W[33]=0x81;
         W[34]=0xff;     
        break;}
        case 8:{
         W[29]=0xff;
         W[30]=0xc9;
         W[31]=0xb6;
         W[32]=0xb6;
         W[33]=0xc9;
         W[34]=0xff;      
        break;}
        case 9:{
         W[29]=0xff;
         W[30]=0xf9;
         W[31]=0xf6;
         W[32]=0xf6;
         W[33]=0x81;
         W[34]=0xff;     
        break;}
        case 0:{
         W[29]=0xff;
         W[30]=0xc1;
         W[31]=0xbe;
         W[32]=0xbe;
         W[33]=0xc1;
         W[34]=0xff;     
        break;}
    }
    switch(z){
        case 1:{
         W[41]=0xff;
         W[42]=0xff;
         W[43]=0xbd;
         W[44]=0x80;
         W[45]=0xbf;
         W[46]=0xff;
        break;}
        case 2:{
         W[41]=0xff;
         W[42]=0x90;
         W[43]=0xae;
         W[44]=0xb6;
         W[45]=0xb9;
         W[46]=0xff;         
        break;}
        case 3:{
         W[41]=0xff;
         W[42]=0xdd;
         W[43]=0xb6;
         W[44]=0xb6;
         W[45]=0xc9;
         W[46]=0xff;
        break;}
        case 4:{
         W[41]=0xff;
         W[42]=0xe1;
         W[43]=0xee;
         W[44]=0x80;
         W[45]=0xef;
         W[46]=0xff;     
        break;}
        case 5:{
         W[41]=0xff;
         W[42]=0xd0;
         W[43]=0xb6;
         W[44]=0xb6;
         W[45]=0xce;
         W[46]=0xff;   
        break;}
        case 6:{
         W[41]=0xff;
         W[42]=0xc3;
         W[43]=0xb5;
         W[44]=0xb6;
         W[45]=0xcf;
         W[46]=0xff;     
        break;}
        case 7:{
         W[41]=0xff;
         W[42]=0xf9;
         W[43]=0xfe;
         W[44]=0xfe;
         W[45]=0x81;
         W[46]=0xff;     
        break;}
        case 8:{
         W[41]=0xff;
         W[42]=0xc9;
         W[43]=0xb6;
         W[44]=0xb6;
         W[45]=0xc9;
         W[46]=0xff;      
        break;}
        case 9:{
         W[41]=0xff;
         W[42]=0xf9;
         W[43]=0xf6;
         W[44]=0xf6;
         W[45]=0x81;
         W[46]=0xff;     
        break;}
        case 0:{
         W[41]=0xff;
         W[42]=0xc1;
         W[43]=0xbe;
         W[44]=0xbe;
         W[45]=0xc1;
         W[46]=0xff;     
        break;}
    }
    int count=0;
    int pos = 0;
    while(1){   
        
        for (count = 0; count < 5; count ++){
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
        pos++;
        if( pos == 45){
            break;
        }
    }
}



void game1_run(int* state,int *timer,int* game,int* scores){
    int hundred;
    int ten;
    int one;
    while(1){
        if(*timer==60){
             LATD=0xff;
              LATC=0x00;
              hundred=*scores/100;
              ten=(*scores%100)/10;
              one=*scores%10;
              score(hundred,ten,one);
              *game=0;
            break;
        }
        block(state[0]);
        //line3
     LATD=0xff;
     LATC=0x00;
        LATDbits.LD2=0;
    __delay_ms(10);
        block(state[1]);
        //line6
        LATD=0xff;
     LATC=0x00;
        LATDbits.LD5=0;
    __delay_ms(10);
        block(state[2]);
    }
}
void timer1_init(){
    PIE1bits.TMR1IE=1;
    PIR1bits.TMR1IF=0;
    T1CONbits.T1CKPS=0b11;
    IPR1bits.TMR1IP=1;
    TMR1H=0x85;
    TMR1L=0xED;
    T1CONbits.TMR1ON=1;
}
void game1_init(int* state,int* scores,int *timer){
    *timer=0;
    timer1_init();
    *scores=0;
    state[2]=7;
    state[1]=6;
    state[0]=1;
}