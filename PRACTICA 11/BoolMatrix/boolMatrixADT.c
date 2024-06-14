#include "boolMatrixADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct column{
    size_t col;
    struct column * nextCol;
} TCol;
typedef TCol * LCols;

typedef struct row{
    size_t row;
    LCols * firstCol;
    struct row * nextRow;
} TRow;
typedef TRow  * LRows;

typedef struct boolMatrixCDT{
    LRows firstRow;
    boolean defaultValue;
} boolMatrixCDT;

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

boolMatrixADT newBoolMatrix(boolean defaultV){
    boolMatrixADT new = malloc(sizeof(boolMatrixCDT));
    new->firstRow = NULL;
    new->defaultValue = defaultV;
    return new;
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

static LCols addCol(LCols cols, size_t col){
    if(cols == NULL || cols->col > col){
        LCols aux = malloc(sizeof(TCol));
        aux->col = col;
        aux->nextCol = cols;
        return aux;
    }
    if(cols->col < col)
        cols->nextCol = addCol(cols->nextCol, col);
    return cols;
}
static LRows addRow(LRows rows, size_t row, size_t col){
    if(rows == NULL || rows->row > row){
        LRows aux = malloc(sizeof(TRow));
        aux->row = row;
        aux->firstCol = addCol(NULL, col);
        aux->nextRow = rows;
        return aux;
    }
    if(rows->row < row){
        rows->nextRow = addRow(rows->nextRow, row, col);
        return rows;
    }
    rows->firstCol = addCol(rows->firstCol, col);
    return rows;
}

static LCols deleteCol(LCols cols, size_t col){
    if(cols == NULL || cols->col > col)
        return cols;
    if(cols->col < col){
        cols->nextCol = deleteCol(cols->nextCol, col);
        return cols;
    }
    LCols aux = cols->nextCol;
    free(cols);
    return aux;
    
}
static LRows deleteRow(LRows rows, size_t row, size_t col){
    if(rows == NULL || rows->row > row)
        return rows;
    if(rows->row < row){
        rows->nextRow = deleteRow(rows->nextRow, row, col);
        return rows;
    }
    // encontramos la fila
    rows->firstCol = deleteCol(rows->firstCol, col);
    return rows;
}
void setValue(boolMatrixADT m, size_t row, size_t col, boolean value){
    if(value != m->defaultValue)
        m->firstRow = addRow(m->firstRow, row, col);
    else
        m->firstRow = deleteRow(m->firstRow, row, col);
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

//  VERSION RECURSIVA

static belongsCol(LCols cols, size_t col){
    if(cols == NULL || cols->col > col)
        return false;
    if(cols->col < col)
        return belongsCol(cols->nextCol, col);
    return true;
}
static boolean belongsRec(LRows rows, size_t row, size_t col){
    if(rows == NULL || rows->row > row)
        return false;
    if(rows->row < row){
        return belongsRec(rows->nextRow, row, col);
    }
    return belongsCol(rows->firstCol, col);
}
boolean getValue(const boolMatrixADT m, size_t row, size_t col){
    return m->defaultValue != (m->firstRow, row, col);
}

// VERSION ITERATIVA

static boolean belongsIter(LRows rows, size_t row, size_t col){
    LRows aux = rows;
    while(aux != NULL && aux->row < row){
        if(aux->row == row){
            LCols auxC = aux->firstCol;
            while(auxC != NULL && auxC->col < col){
                if(auxC->col == col)
                    return true;
                auxC = auxC->nextCol;
            }
        }
        aux = aux->nextRow;
    }
    return false;
}
boolean getValue(const boolMatrixADT m, size_t row, size_t col){
    return m->defaultValue != (m->firstRow, row, col);
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

static void freeCols(LCols cols){
    if(cols == NULL)
        return;
    free(cols->nextCol);
    free(cols);
}
static void freeRows(LRows rows){
    if(rows == NULL)
        return;
    freeCols(rows->firstCol);
    free(rows->nextRow);
    free(rows);
}
void freeBoolMatrix(boolMatrixADT m){
    freeRows(m->firstRow);
    free(m);
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void negate(boolMatrixADT m){

}