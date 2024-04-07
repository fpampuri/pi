#include <stdio.h>

int main(void){
    int c;
    while ( (c=getchar()) != EOF )
    {
        if ( c == '\t' || c == '\b' || c == '\\') {
            if ( c == '\t' || c == '\b' ) 
            {
                if (c == '\t')
                printf("\t");
                else
                printf("\b");
            }
            else printf("\\");
        }
        else putchar(c);
    }
    return 0;
}
