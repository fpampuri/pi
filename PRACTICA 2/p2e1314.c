#include <stdio.h>
#include "getnum.h"

int main()
{
int a, b;
float prom;
char rta, rta1, menor, mayor;
a = getint("Escriba un primer numero entero\n");
b = getint("Escriba un segundo numero entero\n");
rta = (b % a) == 0 ? 'S' : 'N';
prom = (a + b)/2.0;
a > b ? (mayor = a, menor = b) : (mayor = b, menor = a);
rta1 = a == b ? 'S' : 'N';

printf("%d %c es multiplo de %d\n", b, rta, a);
printf("El promedio es %f\n", prom);
printf("La suma es %d\n", a + b);
printf("El menor es %d\n", menor);
printf("El mayor es %d\n", mayor);
printf("Los numeros %c son iguales\n", rta1);
return 0;
}