#include <stdio.h>
#include <stdlib.h>
#define M 6

void bordes(const int mat[M][M], int sumas[M/2]);

void bordes(const int mat[M][M], int sumas[M/2]){
    int i,j, borde;
    for(borde=0;borde<M/2;borde++){
        sumas[borde]=0;
        for(i=borde;i<(M-(borde));i++){
            sumas[borde]+=(mat[i][borde]+mat[i][M-(borde+1)]);
        }
        for(j=borde+1;j<(M-(borde+1));j++)
            sumas[borde]+=(mat[borde][j]+mat[M-(borde+1)][j]);
    }
}
