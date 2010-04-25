/*
 * generator.h
 *
 *  Created on: 2009/08/09
 *      Author: Account01
 */

#ifndef GENERATOR_H_
#define GENERATOR_H_
#include "vector.h"
typedef struct GENERATOR{
	Vector pt;
	int angle;
}GENERATOR;

void initGenerator();
void moveGenerator();

#endif /* GENERATOR_H_ */
