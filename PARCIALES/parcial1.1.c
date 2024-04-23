#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//1) Contiene todos los números de 1 a N * N inclusive
//2) En cada fila contiene números consecutivos, no necesariamente ordenados
#define N 4
#define FALSE 0
#define TRUE !FALSE
int matrizN(const int mat[][N]);
int filaCumple(const int vec[N], int fila);

int main(){
    int matriz[][N]={{1,3,4,2},{6,8,7,5},{9,10,11,12},{14,15,16,13}};
    printf("%d\n",matrizN(matriz));
}

int matrizN(const int mat[][N]){
    int i;
    for(i=0; i<N; i++){
        if (!filaCumple(mat[i], i))
            return 0;
    }
    return 1;
}

int filaCumple(const int vec[N], int fila){   // Si devuelve 0 es porque no está alguno de los numeros consecutivos correspondientes
    int i, aux, encuentre = TRUE;
    aux=(fila*N)+1;
    while(aux<=N*(fila+1) && encuentre){
        encuentre=FALSE;
        for(i=0; i<N && !encuentre; i++){
            encuentre = (vec[i]==aux);
        }
            aux++;
    }
    return encuentre;
}