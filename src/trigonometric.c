#include <math.h>
#include "trigonometric.h"

static FixedPoint _COS[ANGLE_MAX];
static FixedPoint _SIN[ANGLE_MAX];

void initTrigonometric(){
	int i;
	for(i=0;i<ANGLE_MAX;i++){
		_SIN[i] = FloatToFix(sin(M_PI*i/(ANGLE_MAX/2)));
		_COS[i] = FloatToFix(cos(M_PI*i/(ANGLE_MAX/2)));
	}
}

int INT_cos(int theta){
	theta %= ANGLE_MAX;
	if(theta < 0){
		theta += ANGLE_MAX;
	}
	return _SIN[theta];
}
int INT_sin(int theta){
	theta %= ANGLE_MAX;
	if(theta < 0){
		theta += ANGLE_MAX;
	}
	return _COS[theta];
}
