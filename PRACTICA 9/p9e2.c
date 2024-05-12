/*Escribir la función recursiva sumDigits que reciba un único parámetro de entrada de tipo integer 
y devuelva en su nombre la sumDigits de sus dígitos.
Por ejemplo,  sumDigits( 3498 ) devuelve 24*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sumDigits(int n){
    int sum = 0;
    if( n < 0)      // esto lo deberia hacer una wrapper, pero me da paja.
        n *= -1;
    if(n == 0)
        return 0;
    sum = n%10;
    return sum + sumDigits(n/10);
}
