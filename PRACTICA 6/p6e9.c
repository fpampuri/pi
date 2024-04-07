#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

char izq(char num);
char der(char num);
double promedio(int cant, const unsigned char arreglo[]);
double sumatoria(int cant, double prom, const unsigned char arreglo[]);
double std_dev(const unsigned char arreglo[], int cant);

int main(void) {
    char arreglo2[] = { 0x33, 0x33, 0x33, 0x33, 0x33 };
    for(int i=0; i <= 10; i++)
    assert(std_dev(arreglo2, i)==0);
  

  char arreglo[] = { 0x37, 0xF2, 0x03, 0x4A, 0xFF };
  assert(std_dev(arreglo, 1)==0);
  assert(std_dev(arreglo, 2)==2.0);

  assert(std_dev(arreglo, 3) > 4.98 && std_dev(arreglo, 3) < 4.99);

  assert(std_dev(arreglo, 10) > 5.6071 && std_dev(arreglo, 3) < 5.6072);

  printf("OK!\n");
}

char izq( char num ){                       /*Calcula el valor izquierdo de un numero */
    return der ( num>>=4 ) ;
}

char der( char num ){                       /*Calcula el valor derecho de un numero */
    return num & 0x0F;
}

double promedio( int cant, const unsigned char arreglo[]){
    int i=0, cantNum;
    double suma=0;
    cantNum=cant;
    while (cantNum-- > 0){
        suma += izq(arreglo[i]);
        
        if (cantNum--)
            suma += der(arreglo[i]);
        i++;
    }
    return suma/cant;
}

double sumatoria(int cant, double prom, const unsigned char arreglo[]){
    int i=0;
    double acum=0;
    while (cant-- > 0){
        acum += pow( izq(arreglo[i]) - prom,2);
        
        if(cant--)
            acum += pow( der(arreglo[i]) - prom,2);
        i++;
    }
    return acum;
}

double std_dev(const unsigned char arreglo[], int cant){
    if (cant == 0)
        return 0;
    double deviacion;
    double prom=promedio(cant, arreglo);
    double suma=sumatoria(cant, prom, arreglo);
    deviacion=sqrt(suma/cant);
    return deviacion;
}