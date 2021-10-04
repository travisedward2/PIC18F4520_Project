/* 
 * File:   pss.h
 * Author: USER
 *
 * Created on 2021年1月12日, 上午 12:50
 */
#include <xc.h> 
#ifndef PSS_H
#define	PSS_H

void paper();
void scissors();
void stone();
void guess(int* condition);
void ani_paper();
void ani_scissors();
void ani_stone();
void game2_run(int* hand,int* condition,int* game);
void game2_init(int* hand,int* condition);
void win();
void lose();
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PSS_H */

