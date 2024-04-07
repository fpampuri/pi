#include <stdio.h>
#include "getnum.h"

int main() {
    int x;
    x = getint("");
    x = x>>1;
    printf("El número dividido 2 es %d",x);
    return 0;
}