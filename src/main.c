/*
 * main.c
 *
 *  Created on: 2009/08/09
 *      Author: Account01
 */
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "bullet.h"
#include "ship.h"
#include "input.h"
#include "generator.h"
#include "trigonometric.h"

int initGL(int argc, char *argv[]){
	initTrigonometric();
	srand(2333);
	if(SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0){
		fprintf(stderr,"Failed to initialize SDL: %s\n", SDL_GetError());
		return -1;
	}
	if(SDL_SetVideoMode(WIDTH,HEIGHT,24, SDL_OPENGL) < 0){
		fprintf(stderr, "failed to set Video mode: %s\n", SDL_GetError() );
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1 );
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1 );
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8 );
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8 );
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8 );
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8 );
	SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, 8 );
	SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 8 );
	SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 8 );
	SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 8 );
	SDL_WM_SetCaption( "TamaTest" , NULL );
	glDisable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0,0,WIDTH,HEIGHT);
	/* 変換行列の初期化 */
	glLoadIdentity();
	/* スクリーン上の表示領域をビューポートの大きさに比例させる */
	glMatrixMode(GL_PROJECTION);
	glOrtho( 0, WIDTH, HEIGHT, 0, -1, 1);
	return 0;
}

int pollEvent(){
	int running = 1;
	SDL_Event event;
	while( SDL_PollEvent( &event ) ){
		switch( event.type ){
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			pollKeyboardEvent(&event.key);
			break;
		case SDL_QUIT:
			running = 0;
			break;
        }
	}
	return running;
}

int main(int argc,char *argv[]){
	initGL(argc,argv);
	initBullets();
	initShip();
	initGenerator();
	int running = 1;
	while(running){
		running &= running && pollEvent();
		glClear(GL_COLOR_BUFFER_BIT);
		moveBullets();
		moveGenerator();
		moveShip();
		SDL_GL_SwapBuffers();
		running = running && !getInputState(KEY_EXIT);
	}
	freeBullets();
	freeShip();
	SDL_Quit();
	return 0;
}
