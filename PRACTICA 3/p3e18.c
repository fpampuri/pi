#include <stdio.h>
#include "getnum.h"

int main(void){
    int i, num;
    long long factorial = 1;
    if ( (num = getint("Ingrese un entero no negativo: ")) >= 0 ) 
    {
        if (num != 0 && num != 1) {
            for (i=0; i != num; i++)
            factorial *= (num-i);
        }
        printf("El factorial de %d es %lld\n",num,factorial);
    }
    else puts("Dato invalido: debe proporcionar un entero no negativo");
    return 0;
}