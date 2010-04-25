/*
 * screen.h
 *
 *  Created on: 2009/08/09
 *      Author: Account01
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#define WIDTH 640
#define HEIGHT 480

#include "fp.h"
#define AdjustPoint(pt) \
	if((pt).x < 0){(pt).x += IntToFix(WIDTH);}else if((pt).x > IntToFix(WIDTH)){(pt).x -= IntToFix(WIDTH);}\
	if((pt).y < 0){(pt).y += IntToFix(HEIGHT);}else if((pt).y > IntToFix(HEIGHT)){(pt).y -= IntToFix(HEIGHT);}

#endif /* SCREEN_H_ */
