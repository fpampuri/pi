#include <stdio.h>
int main(void)
{
int edad = 25;
float longitud = 185.654;
char  letra = 'Z';
printf("%-5i\n", edad);
printf("%10d\n", edad);
printf("%-10.2f\n", longitud);
printf("%8d\n", letra);
return 0;
}
