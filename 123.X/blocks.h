/* 
 * File:   blocks.h
 * Author: USER
 *
 * Created on 2021年1月11日, 下午 11:56
 */
#include <xc.h> 
#ifndef BLOCKS_H
#define	BLOCKS_H
void block7();
void block8();
void block9();

void block4();
void block5();
void block6(); 

void block1();
void block2();
void block3();
void block(int x);
void game1_init(int* state,int* scores,int* timer);
void timer1_init();
void game1_run(int* state,int* timer,int* game,int* scores);
void change(int* state);
void score(int x,int y,int z);
void animate_score(int x);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* BLOCKS_H */

