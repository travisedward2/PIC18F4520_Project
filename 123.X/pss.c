/*
 * File:   pss.c
 * Author: USER
 *
 * Created on 2021年1月12日, 上午 12:50
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pic18f4520.h>
#define _XTAL_FREQ 200000
void paper(){
    unsigned int x[8];
    x[0]=0xff;
    x[1]=0xef;
    x[2]=0xdf;
    x[3]=0x83;
    x[4]=0x81;
    x[5]=0x81;
    x[6]=0x83;
    x[7]=0xff;
    LATD=0b11111111;
    LATC=0b00000000;
    
    LATCbits.LC0=1;
    LATD=x[0];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC1=1;
    
    LATD=x[1];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    
    LATCbits.LC2=1;
    
    LATD=x[2];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC3=1;
    
    LATD=x[3];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC4=1;
    
    LATD=x[4];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC5=1;
    
    LATD=x[5];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC6=1;
    
    LATD=x[6];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
   LATCbits.LC7=1;
    
    LATD=x[7];
    __delay_ms(10);
}
void scissors(){
     unsigned int x[8];
    x[0]=0xff;
    x[1]=0xfb;
    x[2]=0xf7;
    x[3]=0xcf;
    x[4]=0x81;
    x[5]=0x8f;
    x[6]=0xff;
    x[7]=0xff;
    LATD=0b11111111;
    LATC=0b00000000;
    
    LATCbits.LC0=1;
    LATD=x[0];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC1=1;
    
    LATD=x[1];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    
    LATCbits.LC2=1;
    
    LATD=x[2];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC3=1;
    
    LATD=x[3];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC4=1;
    
    LATD=x[4];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC5=1;
    
    LATD=x[5];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC6=1;
    
    LATD=x[6];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
   LATCbits.LC7=1;
    
    LATD=x[7];
    __delay_ms(10);
}
void stone(){
     unsigned int x[8];
    x[0]=0xff;
    x[1]=0xc3;
    x[2]=0x81;
    x[3]=0x81;
    x[4]=0x81;
    x[5]=0x81;
    x[6]=0xc3;
    x[7]=0xff;
    LATD=0b11111111;
    LATC=0b00000000;
    
    LATCbits.LC0=1;
    LATD=x[0];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC1=1;
    
    LATD=x[1];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    
    LATCbits.LC2=1;
    
    LATD=x[2];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC3=1;
    
    LATD=x[3];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC4=1;
    
    LATD=x[4];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC5=1;
    
    LATD=x[5];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
    LATCbits.LC6=1;
    
    LATD=x[6];
    __delay_ms(10);
    
    LATD=0b11111111;
    LATC=0b00000000;
   LATCbits.LC7=1;
    
    LATD=x[7];
    __delay_ms(10);
}
void guess(int* condition ){
 int count=0;
    while(1){
        if(count==0){
            count++;
            int j=0;
            for(j=0;j<20;j++)
            paper();
        }
        else if(count==1){
            count++;
             int j=0;
            for(j=0;j<20;j++)
            scissors();
        }
        else if(count==2){
            count++;
             int j=0;
            for(j=0;j<20;j++)
            stone();
        }
        else if(count==3){
            count=0;
             int j=0;
            for(j=0;j<10;j++)
            paper();
        }
       __delay_ms(10);
       if(*condition==1)
           break;
    }
}
 void ani_paper(){
     int j=0;
         for(j=0;j<100;j++)
         paper();
     
 }
  void ani_scissors(){
     int j=0;
         for(j=0;j<100;j++)
         scissors();
     
 }
   void ani_stone(){
     int j=0;
         for(j=0;j<100;j++)
         stone();
 }
void win(){
    unsigned char W[40]={
    0xff,0x81,0xdf,0xef,0xef,0xdf,0x81,0xff, 
    0xff,0x85,0xff,0xff,0x83,0xf7,0xfb,0xfb,0x87,0xff,
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    };
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
        if( pos == 32){
            break;
        }
    }
}
void lose(){
    unsigned char W[40]={
    0xff,0xff,0x81,0xbf,0xbf,0xbf,0xbf,
    0xff,0xc3,0xbd,0xbd,0xbd,0xc3,
    0xff,0xb3,0xb5,0xb5,0xc5,0xff,0x81,0xb5,0xb5,0xb5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    };
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
        if( pos ==32){
            break;
        }
    }
}

void game2_run(int* hand,int* condition,int* game){
    int opponent=0;    
    while(1){
        if(*condition==0)   
    guess(condition);
    else if(*condition==1){
     opponent=(rand()%3)+1;
     if(opponent==1){
         ani_paper();
     }
     if(opponent==2){
         ani_scissors();
     }
     if(opponent==3){
         ani_stone();
     }
     if(*hand==opponent){
         *condition=0;
         *hand=0;
     }
     if((*hand==1&&opponent==3)||(*hand==2&&opponent==1)||(*hand==3&&opponent==2)){ 
    
     *hand=0;
     win();
     *game=0;
     }//win
     if((*hand==1&&opponent==2)||(*hand==2&&opponent==3)||(*hand==3&&opponent==1)){
     
     *hand=0;
     lose();
     *game=0;
     }//lose
     
 }   
       if(*game==0)
           break;
    }
}
void game2_init(int* hand,int* condition){
    *hand=0;
    *condition=0;
}
