 //PASAJE DE BINARIO A DECIMAL
#include <stdio.h>   
#include "getnum.h"
int main() {
   int factor = 1, decimal = 0, numBin;
   numBin = getint("Ingrese un numero binario: ");
    while( numBin != 0 ) {
        if ( (numBin%10) > 1 ) {                        //valido que sea binario
            puts("El numero ingresado no es binario");
            return 1;
        }
        decimal +=  ( numBin%2 ) * factor;
        factor *= 2; 
        numBin /= 10;
    }
    printf("La representacion en decimal del binario ingresado es: %d\n",decimal);
    return 0;
}