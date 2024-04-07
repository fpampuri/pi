#include <stdio.h>
#define EPSILON 0.00001
// buscamos aproximar e utilizando el polinomio: 1 + 1/1! + 1/2! + 1/3! + ...
// corto el programa cuando la aproximación es lo suficientemente buena
// definido con el EPSILON.
int main(void) {
    printf("\t\tN\t\te\n");
    double e = 1, eAnterior = 0;
    int i, fact = 1;
    for(i=1; (e-eAnterior) > EPSILON;i++) {
        fact *= i;
        eAnterior = e;
        e += (1.0/fact);
        printf("\t\t%d\t\t%.10f\n", i, e);
    }
    return 0;
}