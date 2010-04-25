/*
 * fp.h
 *
 *  Created on: 2009/08/09
 *      Author: Account01
 */

#ifndef FP_H_
#define FP_H_

#define	FP_BIT	(20)
#define	FP_NUM	(1<<20)

typedef int FixedPoint;
#define	FixToInt(x)	((x) >> FP_BIT)
#define	IntToFix(x)	((x) << FP_BIT)

#define	FixToFloat(x)	((float)(x) / FP_NUM)
#define	FloatToFix(x)	((FixedPoint)((x)*FP_NUM))

#define FixAdd(x,y) (x + y)
#define FixSub(x,y) (x - y)

#endif /* FP_H_ */
