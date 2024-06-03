#include "squirrelsCensusADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct row{
    size_t * squirrels;
    size_t dimCols;
} TRow;
typedef struct squirrelCensusCDT{
    TRow * rows;
    size_t dimBlock;
    size_t dimRows;
} squirrelCensusCDT;

squirrelCensusADT newSquirrelCensus(size_t blockSizeMeters){
    if(blockSizeMeters == 0)
        return NULL;
    squirrelCensusADT sq = calloc(1, sizeof(squirrelCensusCDT));
    sq->dimBlock = blockSizeMeters;
    return sq;
}

#define BLOCKS_DISTANCE(squirrelADT, d) ((d) / squirrelADT->dimBlock)

size_t countSquirrel(squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance){
    int i;
    int col = BLOCKS_DISTANCE(squirrelAdt, xDistance), row = BLOCKS_DISTANCE(squirrelAdt, yDistance);
    if(row >= squirrelAdt->dimRows){
        squirrelAdt->rows = realloc(squirrelAdt->rows, (row+1)*sizeof(TRow));
        for(i = squirrelAdt->dimRows; i < row; i++){
            squirrelAdt->rows[i].dimCols = 0;
            squirrelAdt->rows[i].squirrels = NULL;
        }
        squirrelAdt->dimRows = row  + 1;
    }
    if(col >= squirrelAdt->rows[row].dimCols){
        squirrelAdt->rows[row].squirrels = realloc(squirrelAdt->rows[row].squirrels, (col + 1)*sizeof(size_t));
        for(i = squirrelAdt->rows[row].dimCols; i < col; i++){
            squirrelAdt->rows[row].squirrels[i] = 0;
        }
        squirrelAdt->rows[row].dimCols = col + 1;
    }
    return ++(squirrelAdt->rows[row].squirrels[col]);
}

size_t squirrelsInBlock(const squirrelCensusADT squirrelAdt, size_t yDist, size_t xDist){
    int col = BLOCKS_DISTANCE(squirrelAdt, xDist), row = BLOCKS_DISTANCE(squirrelAdt, yDist);
    if(row >= squirrelAdt->dimRows || col >= squirrelAdt->rows[row].dimCols)
        return 0;
    return squirrelAdt->rows[row].squirrels[col];
}

void freeSquirrelCensus(squirrelCensusADT squirrelAdt){
    for(int i = 0; i < squirrelAdt->dimRows; i++)
        free(squirrelAdt->rows[i].squirrels);
    free(squirrelAdt->rows);
    free(squirrelAdt);
}

int
main(void) {
    // Reserva los recursos para contabilizar las ardillas del parque
    // agrupando las cantidades en bloques (manzanas) de 100 metros x 100 metros.
    // Por ejemplo:
    // - El bloque 0,0 comprende de [0, 100) metros en vertical y de [0, 100) metros en horizontal
    // - El bloque 0,1 comprende de [0, 100) metros en vertical y de [100, 200) metros en horizontal
    // - El bloque 1,0 comprende de [100, 200) metros en vertical y de [0, 100) metros en horizontal
    squirrelCensusADT centralPark = newSquirrelCensus(100);

    // Se registra a una ardilla a
    // - 299 metros en línea vertical del extremo superior izquierdo del parque
    // - 120 metros en línea horizontal del extremo superior izquierdo del parque
    // de forma que se contabilizará a la ardilla en el bloque 2,1
    assert(countSquirrel(centralPark, 299, 120) == 1);
    // Se registra a otra ardilla en el mismo bloque que la invocación anterior
    assert(countSquirrel(centralPark, 201, 140) == 2);

    // Se registra a una ardilla en el bloque 0,0
    assert(countSquirrel(centralPark, 15, 98) == 1);

    // Se consulta la cantidad de ardillas del bloque de las primeras dos invocaciones a countSquirrel
    assert(squirrelsInBlock(centralPark, 250, 150) == 2);
    // Se consulta la cantidad de ardillas del bloque de la tercera invocación a countSquirrel
    assert(squirrelsInBlock(centralPark, 0, 0) == 1);
    // Se consulta la cantidad de ardillas en un bloque distinto a los dos anteriores, el bloque 29,15
    assert(squirrelsInBlock(centralPark, 2965, 1540) == 0);

    // Libera los recursos utilizados para contabilizar las ardillas del parque
    freeSquirrelCensus(centralPark);

    puts("OK!");
    return 0;
}