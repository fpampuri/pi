#include <stdio.h>
#include "getnum.h"
 int main (void){
   int lim = getint("Ingrese límite:"), c;
   int i = 0;
   while( i<lim-1 )
      if ( (c=getchar()) != '\n' ) {
         if ( c != EOF )
            putchar(c);
			i++;
      }
      else return 1;
return 0;

}
