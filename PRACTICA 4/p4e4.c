#include <stdio.h>

#define swap(t,x,y) {t aux=x; \
                    x=y; \
                    y=aux;}

int main(void){
    int x = 3, y = 7;
    printf("%d ; %d\n", x,y);
    swap(int,x,y);
    printf("%d ; %d\n", x,y);
    return 0;
}