#include <stdio.h>

int main () {
    int i;
    puts("Tabla del 10:");
    for (i=0; ;i+=10) {
        printf("%d ",i);
    }
    return 0;
}