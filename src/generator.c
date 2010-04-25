/*
 * generator.c
 *
 *  Created on: 2009/08/09
 *      Author: Account01
 */

#include "generator.h"
#include "screen.h"
#include "bullet.h"
#include "trigonometric.h"
#include <GL/gl.h>
#include <stdlib.h>

#define GENERATOR_MAX 3
GENERATOR Gen[GENERATOR_MAX];

void initGenerator(){
	Gen[0].pt.x = IntToFix(WIDTH / 2);
	Gen[0].pt.y = IntToFix(HEIGHT / 4);
	Gen[1].pt.x = IntToFix(WIDTH / 3);
	Gen[1].pt.y = IntToFix(HEIGHT / 2);
	Gen[2].pt.x = IntToFix(WIDTH*2 / 3);
	Gen[2].pt.y = IntToFix(HEIGHT / 2);
}
const static GLfloat GEN_COLOR[4]= {0.0f,0.6f,0.7f,1.0f};
void moveGenerator(){
	int i;
	int j;
	for(j=0;j<100;j++){
		for(i=0;i<GENERATOR_MAX;i++){
			FixedPoint angle = FloatToFix((float)(rand()) / RAND_MAX);
			FixedPoint speed = ((float)(rand()) / RAND_MAX)*4;
			if(makeBullet(Gen[i].pt.x, Gen[i].pt.y, (FixedPoint)INT_cos(angle)*speed, (FixedPoint)INT_sin(angle)*speed) < 0){
				return;
			}
			/*
			if(makeBullet(Gen[i].pt.x, Gen[i].pt.y, (FixedPoint)INT_cos(Gen[i].angle), (FixedPoint)INT_sin(Gen[i].angle)) < 0){
				return;
			}
			Gen[i].angle++;
			Gen[i].angle %= ANGLE_MAX;
			*/
			GLint vertex[8];
			GLint x = FixToInt(Gen[i].pt.x);
			GLint y = FixToInt(Gen[i].pt.y);
			glEnableClientState( GL_VERTEX_ARRAY );
			glVertexPointer( 2, GL_INT, 0, vertex );
			vertex[0] = x-3;		vertex[1] = y-3;
			vertex[2] = x-3;		vertex[3] = y+3;
			vertex[4] = x+3;		vertex[5] = y+3;
			vertex[6] = x+3;		vertex[7] = y-3;
			glColor4fv(GEN_COLOR);
			glDrawArrays( GL_QUADS, 0, 4 );
		}
	}
}
