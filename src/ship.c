/*
 * ship.c
 *
 *  Created on: 2009/08/09
 *      Author: Account01
 */
#include <GL/GL.h>
#include "fp.h"
#include "screen.h"
#include "vector.h"
#include "input.h"
typedef struct SHIP{
	Vector pt;
	int hit;
}SHIP;

static SHIP Ship;

int initShip(){
	Ship.pt.x = IntToFix(WIDTH / 2);
	Ship.pt.y = IntToFix((HEIGHT / 4) * 3);
	Ship.hit = 0;
	return 0;
}

const static GLfloat SHIP_COLOR[4]= {1.0f,1.0f,1.0f,1.0f};
const static GLfloat SHIP_HIT_COLOR[4]= {0.0f,1.0f,1.0f,1.0f};
int moveShip(){
	//移動処理
	int move = IntToFix(10);
	if(getInputState(KEY_SPEED)){
		move /= 3;
	}
	if(getInputState(KEY_UP)){
		Ship.pt.y -= move;
	}
	if(getInputState(KEY_DOWN)){
		Ship.pt.y += move;
	}
	if(getInputState(KEY_LEFT)){
		Ship.pt.x -= move;
	}
	if(getInputState(KEY_RIGHT)){
		Ship.pt.x += move;
	}
	//スクリーンとの判定
	AdjustPoint(Ship.pt);
	//描画処理
	GLint x = FixToInt(Ship.pt.x);
	GLint y = FixToInt(Ship.pt.y);
	GLint vertex[8];
	vertex[0] = x;		vertex[1] = y-30;
	vertex[2] = x-20;	vertex[3] = y+20;
	vertex[4] = x+20;	vertex[5] = y+20;
	glEnableClientState( GL_VERTEX_ARRAY );
	glColor4fv(Ship.hit ? SHIP_HIT_COLOR : SHIP_COLOR);
	glVertexPointer( 2, GL_INT, 0, vertex );
	glDrawArrays( GL_LINE_LOOP, 0, 3 );
	vertex[0] = x+1;		vertex[1] = y+1;
	vertex[2] = x+0;		vertex[3] = y+1;
	vertex[4] = x+0;		vertex[5] = y+0;
	vertex[6] = x+1;		vertex[7] = y+0;
	glDrawArrays( GL_QUADS, 0, 4 );
	Ship.hit = 0;
	return 0;
}

inline void isShipHit(Vector* pt){
	if(FixToInt(pt->x) == FixToInt(Ship.pt.x) && FixToInt(pt->y) == FixToInt(Ship.pt.y)){
		Ship.hit = 1;
	}
}

int freeShip(){
	return 0;
}
