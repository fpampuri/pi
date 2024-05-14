#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sumMatch(int v[]){
    if(*v == -1)
        return 0;
    int resp = sumMatch(v+1);
    if(resp < 0 )
        return resp;
    else if(resp > 0)
        return resp - *v;
    return *v;
}
