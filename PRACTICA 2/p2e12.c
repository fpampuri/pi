#include <stdio.h>
int main() {
    char letra;
    char rta;
    printf("Escriba un carácter\n");
    letra = getchar();
    rta = ( letra >= 'a' && letra <= 'z' ) | ( letra >= 'A' && letra <= 'Z' ) ? 'S' : 'N';
    printf("El carácter %c %c es un carácter\n", letra, rta);
    return 0;  
}