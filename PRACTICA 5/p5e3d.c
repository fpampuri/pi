#include <stdio.h>
#include "getnum.h"
#include <math.h>


int lugar (int num, int pos);
int cantDigitos (int num);

int
main( void )
{
	int digitos, boleto, esCapicua=1;
	int  j;
	
	boleto = getint("Ingrese un número: ");
	digitos=cantDigitos(boleto);

	for (j=1; j<=(digitos)/2; j++)
		if ( lugar(boleto, j) != lugar(boleto,digitos-j+1))
		{	
 			esCapicua=0;
			break;
		}
	printf("El boleto %ses capicúa\n",(esCapicua)? "":"no ");
	return esCapicua;
}

int lugar( int num, int pos )
{	
return (num / (int)pow(10, pos-1)) % 10;
}

int cantDigitos (int num)
{
    int contador=0;
    while (num != 0) {
        num /= 10;
        contador++; }
    return contador;
}