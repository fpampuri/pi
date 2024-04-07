/* Leer desde la entrada estándar una serie de caracteres, 
** hasta que uno de ellos no sea una letra ni un espacio.  
** Luego imprimir por salida estándar  el menor alfabéticamente de ellos  
** respetando si fue mayúscula o minúscula, 
** indicando además cuántas letras eran mayúsculas y cuántas minúsculas. 
** (En no más de 15 líneas). 
*/
#include <stdio.h>
#define DIFERENCIA ('a'-'A')
int main() {
    int c, menor, sumaMayus=0, sumaMinus=0, isMin, isMenorMin;
    menor = 'z';                //verifico que sea letra o espacio
    while (((c=getchar()) >= 'a' && c <= 'z' ) || ( 'A' <= c && c <= 'Z' ) || c == ' ') { 
        if (c != ' ') {
            if ((isMin=('A' < c && c < 'Z'))) {
                sumaMayus++;
                c+= DIFERENCIA;
            } 
            else 
                sumaMinus++;
            if ( c <= menor) {
                menor = c;
                isMenorMin = isMin;
            }
        }
    }
    printf("Cantidad de mayusculas: %d\nCantidad de minusculas: %d\n",sumaMayus,sumaMinus);
    printf("El caracter alfabeticamente menor es el %c\n", isMenorMin ? menor  - DIFERENCIA: menor);
    return 0;
}