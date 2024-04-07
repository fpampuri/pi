#include <stdio.h>

int main ()
{
    char letra;
    letra = getchar();
    letra = letra + 'A' - 'a';
    printf("La letra pasada a mayúscula es %c\n", letra);
    return 0;
}