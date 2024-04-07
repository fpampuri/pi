#include <stdio.h>
int main() {
    int i;
    printf("N\t10*N\t\t100*N\t\t1000*N\n\n");
for (i=1; i<=20; i++) {
    printf("%d\t%d\t\t%d\t\t%d\n", i, 10*i, 100*i, 1000*i); }
return 0; }