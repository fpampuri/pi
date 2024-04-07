#include <stdio.h>
#include "getnum.h"
#include <math.h>


int lugar (int num, int pos);
int cantDigitos (int num);


int
main(void)
{
	int boleto, esCapicua=1;
	int  j;
	
	do boleto = getint("Ingrese un número de 5 dígitos:");
    while( cantDigitos(boleto) != 5);
    for (j=1; j<=2; j++)
        if ( lugar(boleto, j) != lugar(boleto,5-j+1))
        {	
            esCapicua=0;
            break;
        }
    printf("El boleto %ses capicúa",(esCapicua)? "":"no ");
	return 0;
}


int 
lugar( int num, int pos )
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
