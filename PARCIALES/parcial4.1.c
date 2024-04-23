#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE !FALSE
#define COLS 5

int onlyBin(char m[][COLS], int filas);

int main(){
    int i,j;
    char m[][COLS]={{1,0,0,1,1},{'a',1,0,0,'x'},{1,2,6,1,1},{1,0,0,0,0}};
    int filas=4;
    int n=onlyBin(m, filas);
    for(i=0;i<filas;i++){
        for(j=0;j<COLS;j++)
            printf("%d ",m[i][j]);
        puts("\n");
    }
    printf("FILAS BINARIAS: %d",n);
    return 0;
}
int onlyBin(char m[][COLS], int filas){
	int i,j,k;
	int esBinaria;
	int filasBin=0;
	for(i=0;i<filas;i++){
		esBinaria=TRUE;
		for(j=0;(j<COLS) && esBinaria;j++){
			if(m[i][j] != 0 && m[i][j] != 1)
				esBinaria=FALSE;
		}
		if(esBinaria){
			for(k=0;k<COLS;k++)
				m[filasBin][k]=m[i][k];
			filasBin++;
		}
	}
	return filasBin;
}