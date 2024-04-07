#include <stdio.h>
#include "getnum.h"

int main() {
    char c1, c2, max, min;
    c1 = getchar();
    c2 = getchar();
    c1 > c2 ? (max = c1, min = c2) : (max = c2, min = c1);
    printf("El caracter %c es menor al caracter %c\n", min, max);
    return 0;
}