#include <stdio.h>
#include "getnum.h"

int main() {
    char c1, c2, max;
    printf("Escriba dos caracteres\n");
    c1 = getchar();
    c2 = getchar();
    max = c1 > c2 ? c1 : c2;
    printf("El carácter de ASCII más grande es %c\n", max);
    return 0;
}

//     c1 = getchar("Escriba el carácter uno:\n");
//  c2 = getchar("Escriba el carácter dos:\n");