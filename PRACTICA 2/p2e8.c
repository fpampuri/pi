#include <stdio.h>
#include "getnum.h"

int main() {
   float v;
   v = getfloat("");
   v = v * 3.6;
   printf("Son %.2f km/h",v);
   return 0;
}