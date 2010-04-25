/*
 * input.h
 *
 *  Created on: 2009/08/09
 *      Author: Account01
 */
#include <SDL/SDL.h>
#ifndef INPUT_H_
#define INPUT_H_

#define KEY_UP		(0x1)
#define KEY_DOWN	(0x2)
#define KEY_RIGHT	(0x4)
#define KEY_LEFT	(0x8)
#define KEY_SPEED	(0x10)
#define KEY_EXIT	(0x20)

void pollKeyboardEvent(SDL_KeyboardEvent *key);
int getInputState(unsigned int state);
int getInputStateOr(unsigned int state);

#endif /* INPUT_H_ */
