#include <stdio.h>
//Secuencias: 3,8,13,18,23      20,14,8,2,-4,-10           19,27,35,43,51
//Patrones:   i+=5              i-=6                       i+=8

int main() {
    int i;
    for (i=3; i <= 23; i+=5)
        printf("%d ",i);
    for (i=20; i >= -10; i-=6)
        printf("%d ",i);
    for (i=19; i <= 51; i+=8)
        printf("%d ",i);
    return 0;
}