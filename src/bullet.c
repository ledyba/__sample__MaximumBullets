/*
 * bullet.c
 *
 *  Created on: 2009/08/09
 *      Author: Account01
 */
#include <GL/GL.h>
#include "bullet.h"
#include "ship.h"
#include "screen.h"
BULLET Bullet[BULLET_MAX];
BULLET* EmptyBullet[BULLET_MAX];
unsigned int EmptyBulletIdx = BULLET_MAX-1;

int initBullets(){
	int i;
	for(i=0;i<BULLET_MAX;i++){
		Bullet[i].is_exist = 0;
		EmptyBullet[i] = &Bullet[i];
	}
	return 0;
}
int makeBullet(FixedPoint x,FixedPoint y,FixedPoint sx,FixedPoint sy){
	if(EmptyBulletIdx <= 0){
		return -1;
	}
	BULLET* bul = EmptyBullet[EmptyBulletIdx];
	bul->is_exist = 1;
	bul->pt.x = x;
	bul->pt.y = y;
	bul->speed.x = sx;
	bul->speed.y = sy;
	bul->speed_int.x = FixToInt(sx);
	bul->speed_int.y = FixToInt(sy);
	EmptyBulletIdx--;
	return 0;
}
const static GLfloat BUL_LINE_COLOR[4]= {0.6f,0.0f,0.0f,1.0f};
const static GLfloat BUL_COLOR[4]= {1.0f,0.0f,0.0f,1.0f};
int moveBullets(){
	int i;
	for(i=0;i<BULLET_MAX;i++){
		if(!Bullet[i].is_exist){
			continue;
		}
		//移動
		VectorAdd(Bullet[i].pt,Bullet[i].speed);
		//消滅判定・・・はやめて、世界の果てから再度出現するようにしてみた。
		AdjustPoint(Bullet[i].pt);
		//自機とのあたり判定
		isShipHit(&Bullet[i].pt);
		//描画
		GLint x = FixToInt(Bullet[i].pt.x);
		GLint y = FixToInt(Bullet[i].pt.y);
		GLint vertex[8];
		glEnableClientState( GL_VERTEX_ARRAY );
		glVertexPointer( 2, GL_INT, 0, vertex );
		/*
		GLint sx = Bullet[i].speed_int.x;
		GLint sy = Bullet[i].speed_int.y;
		vertex[0] = x;		vertex[1] = y;
		vertex[2] = x-sx;	vertex[3] = y-sy;
		glColor4fv(BUL_LINE_COLOR);
		glDrawArrays( GL_LINES, 0, 2 );
		*/
		vertex[0] = x+1;		vertex[1] = y+1;
		vertex[2] = x+0;		vertex[3] = y+1;
		vertex[4] = x+0;		vertex[5] = y+0;
		vertex[6] = x+1;		vertex[7] = y+0;
		glColor4fv(BUL_COLOR);
		glDrawArrays( GL_QUADS, 0, 4 );
	}
	return 0;
}

int freeBullets(){
	return 0;
}
