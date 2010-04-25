/*
 * vector.h
 *
 *  Created on: 2009/08/09
 *      Author: Account01
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include "fp.h"

typedef struct Vector{
	FixedPoint x;
	FixedPoint y;
}Vector;

typedef struct IntVector{
	int x;
	int y;
}IntVector;

#define VectorAdd_Pt(a,b) (a)->x += (b)->x;(a)->y += (b)->y;
#define VectorAdd(a,b) (a).x += (b).x;(a).y += (b).y;

#endif /* VECTOR_H_ */
