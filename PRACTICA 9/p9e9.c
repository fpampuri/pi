#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double raizCuadrada(double vAnt, int iter, double x){
    if(iter == 0)
        return vAnt;
    vAnt = (vAnt + x/vAnt)/2;
    return raizCuadrada(vAnt, --iter, x);
}

