/*
 * bullet.h
 *
 *  Created on: 2009/08/09
 *      Author: Account01
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "vector.h"
#define BULLET_MAX (65536*10)

typedef struct BULLET{
	char is_exist;
	Vector pt;
	Vector speed;
	IntVector speed_int;
}BULLET;

int initBullets();
int makeBullet(FixedPoint x,FixedPoint y,FixedPoint sx,FixedPoint sy);
int moveBullets();
int freeBullets();

#endif /* BULLET_H_ */
