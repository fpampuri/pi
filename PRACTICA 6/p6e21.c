#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "getnum.h"

#define LEER_DENOM(denom) {do { denom = getint(""); \
                                if (denom == 0) \
                                puts("El denominador debe ser distinto de cero\n");} \
                            while ( denom == 0);}

int simpFrac(int *num, int *den);

int mcd(int x, int y);

int main(void) {
    
    int num1, num2, den1, den2, numS, denS;

    printf("SIMPLIFICAR\n");
    num1 = 10; den1 = 15;
    simpFrac(&num1, &den1);
    assert(num1==2 && den1==3);
    simpFrac(&num1, &den1);
    assert(num1==2 && den1==3);

    num1 = 150; den1 = 15;
    simpFrac(&num1, &den1);
    assert(num1==10 && den1==1);
    simpFrac(&num1, &den1);
    assert(num1==10 && den1==1);
    simpFrac(&den1, &num1);
    assert(num1==10 && den1==1);
    num1 = 12*5; den1 = 36*7;
    simpFrac(&num1, &den1);
    assert(num1==5 && den1==21);
    num1 = 0; den1 = 36;
    simpFrac(&num1, &den1);
    assert(num1==0 && den1==1);

    printf("SUMAR\n");
  
    puts("OK!");
    return 0;
}

int mcd(int x, int y) {
    int auxi;
    auxi = x;
    while (auxi != 0)
    {
        x = y;
        y = auxi;
        auxi = x % y ;
    }
    return y;
}

int simpFrac(int *num1, int *den1) {
    int divcomun = mcd(*num1,*den1);
    *num1 /= divcomun;
    *den1 /= divcomun;
}
