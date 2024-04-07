#include <stdio.h>
#include "getnum.h"

// Escribir un programa que cuente los espacios, tabs y enters

int main(){
    int c, suma = 0;
    while ( (c=getchar()) != EOF ) {
        if ( c == ' ' || c == '\t' || c == '\n' )
            suma++;
    }
    printf("La cantidad total de espacios, tabs y/o newlines es %d\n",suma);
    return 0;
}