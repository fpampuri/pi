#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void secuenciaAsc(int v[], int dim, int *com, int *len){
    int length=1;
    int i;
    *com=0;
    *len=1;
    for(i=1;i<dim;i++){
        if(v[i]>v[i-1]){
            length++;
        }
        else {if (length > *len){
            *len=length;
            *com=(i-length);
            length=1;
        }
        }
    }
}


int main(){
    int vector[]={1, 0, 2, 3, 4, 5, 7, 10, 90, 91};
    int dim=10;
    int comienzo, longitud;
    secuenciaAsc(vector, dim, &comienzo, &longitud);
    printf("Comienzo: %d\nLongitud: %d\n", comienzo, longitud);

}