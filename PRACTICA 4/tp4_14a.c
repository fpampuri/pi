#include <stdio.h>
#include "getnum.h"
#include "tp4_14.h"
int
main (void)
{
	float x, y, z;
	x= getfloat("Ingrese un número real :");
	putchar('\n');

	y = f1(x);
	z = f2(x);

	printf("El doble absoluto de %g es %g\n",x, y);
	printf("El triple absoluto de %g es %g\n",x , z);
	return 0;
}
