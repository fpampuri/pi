#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define COLS 5
void difSim(const int m1[][COLS], const int m2[][COLS], int m3[][COLS], int filas){
	int i=0,j1=0, j2=0, aux=0;
	while(i<filas){
        j1=0; j2=0; aux=0;
		while(m1[i][j1] != -1 && m2[i][j2] != -1){
		if(m1[i][j1]==m2[i][j2]){
			j1++; j2++;
		}
		else if (m1[i][j1]<m2[i][j2]){
			m3[i][aux++]=m1[i][j1];
			j1++;
			}
			else if(m1[i][j1]>m2[i][j2]){
				m3[i][aux++]=m2[i][j2];
				j2++;
			}
		}
		if(j1==-1){
			while(j2!=-1)
				m3[i][aux++]=m2[i][j2++];
		} 
		else if(j2==-1){
			while(j1!=-1)
				m3[i][aux++]=m1[i][j1++];
		} 
		m3[i][aux]=-1;
        i++;	
	}
}

int main(){
    int m1[][COLS]={{1,4,5,6,-1},{1,2,3,4,-1}};
    int m2[][COLS]={{2,3,4,-1},{1,2,4,-1}};
    int m3[2][COLS];
    int i,j;
    difSim(m1, m2, m3, 2);
    for(i=0; i<2; i++){
        for(j=0; j<COLS; j++)
            printf("%d ",m3[i][j]);
        printf("\n");
    }
}