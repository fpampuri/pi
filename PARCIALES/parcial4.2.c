#include <stdio.h>
#include <stdlib.h>
#define DIM 3
#define DIRECCIONES 8

int esTableroValido(const int tab[DIM][DIM]);
int esValido(int fil, int col, int numero, const int tablero[DIM][DIM]);

int main(){
    int tablero[DIM][DIM]={{0,2,-1},{1,3,2},{-1,2,-1}};
    int n=esTableroValido(tablero);
    printf("%d\n",n);
}
int esTableroValido(const int tab[DIM][DIM]){
	int i,j;
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			if( tab[i][j] != -1)
				if ( !esValido(i, j, tab[i][j], tab))
					return 0;
		}
	}
	return 1; 
}

int esValido(int fil, int col, int numero, const int tablero[DIM][DIM]){
	int cantMinas=0, i, dirx, diry;
	int direcciones[8][2]={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}}; // Vector de versores
		for(i=0;i<DIRECCIONES;i++){
			dirx=direcciones[i][0];
			diry=direcciones[i][1];
			if(fil+dirx >= 0 && fil+dirx < DIM && col+diry >= 0 && col+diry < DIM)
				if(tablero[fil+dirx][col+diry]==-1)
					cantMinas++;
        }		

	return (numero==cantMinas);
}	