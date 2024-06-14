#include "landmarksADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define INDEX(m) ((m)/100)
#define FALSE 0
#define TRUE !FALSE

typedef struct landmark{
    landmarkType site;
    char occupied;
} TLandmark;

typedef struct landmarkCDT{
    TLandmark * path;
    size_t count, size;
    compare cmp;
} landmarkCDT;



landmarkADT newLandmark(compare cmp){
    landmarkADT lm = malloc(sizeof(landmarkCDT));
    lm->path = NULL;
    lm->count = 0;
    lm->size = 0;
    lm->cmp = cmp;
    return lm;
}

size_t landmarkCount(const landmarkADT landmark){
    return landmark->count;
}
/**
 * Agrega un punto de interés #site a #meters metros del origen. Si ya había
 * un sitio, sólo queda #site (ver programa de testeo)
 */
void addLandmark(landmarkADT lm, size_t meters, landmarkType site){
    int idx = INDEX(meters);
    if(lm == NULL || idx >= lm->size){
        lm->path = realloc(lm->path, (idx+1)*sizeof(TLandmark));
        for(int i = lm->size; i <= idx ; i++)
            lm->path[i].occupied = FALSE;
        lm->size = idx + 1;
    }
    lm->path[idx].site = site;
    if(!lm->path[idx].occupied){
        lm->count++;
        lm->path[idx].occupied = TRUE;
    }
}

/*
 * Retorna un vector con los sitios de interés, en orden ascendente por distancia
 * al origen. Si no hubiera sitios de interés retorna NULL
 */
landmarkType * landmarks(const landmarkADT lm){
    landmarkType * landmarks = NULL;
    if(lm->count > 0)
        landmarks = realloc(landmarks, lm->count*sizeof(landmarkType));
    int i,j=0;
    for(i = 0; i<lm->size; i++){
        if(lm->path[i].occupied)
            landmarks[j++] = lm->path[i].site;
    }
    return landmarks;
}

int 
main(void) {
    landmarkADT lm = newLandmark(strcmp);

    assert(landmarkCount(lm)==0);

    landmarkType * v = landmarks(lm);
    assert(v==NULL);

    addLandmark(lm, 50, "Atalaya");
    addLandmark(lm, 70, "YPF abandonada");
    addLandmark(lm, 99, "El estadio del Chelsea");
    assert(landmarkCount(lm)==1);

    addLandmark(lm, 650, "Restos de un OVNI");

    addLandmark(lm, 350, "Pulpería de 1800");

    addLandmark(lm, 200, "Otra pulperia");


    // El siguiente ciclo imprime:
    //     El estadio del Chelsea
    //     Otra pulpería
    //     Pulpería de 1800
    //     Restos de un OVNI
    v = landmarks(lm);
    for(int i=0; i < landmarkCount(lm); i++) {
        puts(v[i]);
    }
    free(v);
    puts("OK!");
    return 0;
}
