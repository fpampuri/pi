#include "tp4_14.h"
float
f2(float x)
{
	return 3 * funAuxiliar(x);
}

float
funAuxiliar (float x)
{
	if ( x < 0 )
		x = -x;

	return x;
}

float
f1 ( float x)
{
	return 2 * funAuxiliar(x);
}
