#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int factoreo(int v[]){
    int producto=1;
    int i=0, aux=0;
    while(v[i] != -1){
        if(v[i]!=v[i+1])
            v[aux++]=v[i];
        producto*=v[i++];
    }
    v[aux]=-1;
    return producto;
}
int main(){
    int v[]={2,2,3,3,4,5,-1};
    int resultado=factoreo(v);
    int i=0;
        printf("%d\n",resultado);
    while(v[i] != -1){
        printf("%d\n",v[i]);
        i++;
    }
    return 0;
}