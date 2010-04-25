/*
 * input.c
 *
 *  Created on: 2009/08/09
 *      Author: Account01
 */
#include <SDL/SDL.h>
#include "input.h"

static unsigned int KeyboardState;
static unsigned int JoystickState;

void pollKeyboardEvent(SDL_KeyboardEvent *key){
	if( key->type == SDL_KEYUP ){
		switch(key->keysym.sym){
		case SDLK_UP:
			KeyboardState &= ~KEY_UP;
			break;
		case SDLK_DOWN:
			KeyboardState &= ~KEY_DOWN;
			break;
		case SDLK_RIGHT:
			KeyboardState &= ~KEY_RIGHT;
			break;
		case SDLK_LEFT:
			KeyboardState &= ~KEY_LEFT;
			break;
		case SDLK_SPACE:
			KeyboardState &= ~KEY_SPEED;
			break;
		case SDLK_ESCAPE:
			KeyboardState &= ~KEY_EXIT;
			break;
		default:
			break;
		}
	}else{
		switch(key->keysym.sym){
		case SDLK_UP:
			KeyboardState |= KEY_UP;
			break;
		case SDLK_DOWN:
			KeyboardState |= KEY_DOWN;
			break;
		case SDLK_RIGHT:
			KeyboardState |= KEY_RIGHT;
			break;
		case SDLK_LEFT:
			KeyboardState |= KEY_LEFT;
			break;
		case SDLK_SPACE:
			KeyboardState |= KEY_SPEED;
			break;
		case SDLK_ESCAPE:
			KeyboardState |= KEY_EXIT;
			break;
		default:
			break;
		}
	}
}

int getInputState(unsigned int state){
	return ((KeyboardState | JoystickState) & state) == state;
}
int getInputStateOr(unsigned int state){
	return ((KeyboardState | JoystickState) & state) != 0;
}
