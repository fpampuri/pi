#include <stdio.h>


// Escribir un programa para determinar los rangos del char, short e int
// char = 1 byte ; short = 2 bytes ; int = 4 bytes 
// char depende signed o unsigned ; short signed ; int signed
// signed char min: 1111 1111 ; signed char max: 0111 1111 (basicamente charmin>>1)
int main() {

    printf("El rango de char es de %d hasta %d\n", -(char)((unsigned char)0xFF >> 1)-1, (char)((unsigned char)~0>>1));
    printf("El rango de short (signed) es de %d hasta %d\n", -(short)((unsigned short)~0 >> 1)-1, (short)((unsigned short)~0>>1)); 
    printf("El rango de int es de %d hasta %d\n", -(int)((unsigned int)~0 >> 1)-1, (int)((unsigned int)~0>>1));  
    return 0;
    // esto funciona porque interpretamos el FF como un unsigned, lo decalamos en uno (dividir por dos
    // y acto seguido lo pasamos a negativo y le restamos uno para que funcione.
}
