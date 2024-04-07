#include <stdio.h>
#define isdigit(car) ('0'< (car) && (car)<'9')

int main(){
	int letra;
	letra = getchar();
	if ( isdigit(letra) )
		printf("Es un dígito\n");
    return 0;
}