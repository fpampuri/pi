#include <stdio.h>
#include <stdlib.h>
int isInVec(int numero, const int vec[], int dimVec);
int esAscendente(int fils, int cols, const int m[][cols], int resp[cols]){
	int i,j, dimResp=0;
	for(i=0;i<fils;i++){
		j=1;

		if( !isInVec(m[i][0], resp, dimResp))
			resp[dimResp++]=m[i][0];
		while(j<cols){
			if(m[i][j] < m[i][j-1])
				return 0;
			if( !isInVec(m[i][j], resp, dimResp))
				resp[dimResp++]=m[i][j];
			j++;
		}
	}
	for(j=0;j<cols;j++){
		i=1;
		if( !isInVec(m[0][j], resp, dimResp))
			resp[dimResp++]=m[0][j];
		while(i<fils){
			if(m[i][j] < m[i-1][j])
				return 0;
			if( !isInVec(m[i][j], resp, dimResp))
				resp[dimResp++]=m[i][j];
			i++;
        }
    }
    return 1;
}

int isInVec(int numero, const int vec[], int dimVec){
	int i;
	for(i=0; i<dimVec; i++)
		if(vec[i] == numero)
			return 1;
	return 0;
}

int main(){
    int matriz[5][4]={{1,2,3,3},{2,3,4,5},{3,4,5,6},{2,5,6,7},{5,6,7,8}};
    int respuesta[20];
    int filas=5;
    int colum=4;
    int i;
    int n=esAscendente(filas, colum, matriz, respuesta);
    if(n==0)
        printf("La matriz no esta ordenada\n");
    else
        for(i=0; i<20; i++)
            printf("%d ",respuesta[i]);
    puts("\n");
    return 0;
}