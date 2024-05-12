#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DIM_MAX 10
#define DIRS 4
int isInGrid(int matrix[][DIM_MAX], int dim, int fil, int col);
void negDirRec(int matrix[][DIM_MAX], int dim, int fil, int col, int dx, int dy);

void negDirs(int matrix[][DIM_MAX], int dim, int fil, int col){
    if(dim <= 0 || !isInGrid(matrix, dim, fil, col))
        return;
    int dir, dx, dy;
    int dirs[DIRS][2]={{-1,1},{-1,-1},{1,-1},{1,1}};
    matrix[fil][col] = !matrix[fil][col];
    for(dir=0; dir<DIRS; dir++){
        dx = dirs[dir][0];
        dy = dirs[dir][1];
        negDirRec(matrix, dim, fil, col, dx, dy);
    }
}

void negDirRec(int matrix[][DIM_MAX], int dim, int fil, int col, int dx, int dy){
    if(!isInGrid(matrix, dim, fil+dx, col+dy))
        return;
    matrix[fil+dx][col+dy]=!matrix[fil+dx][col+dy];
    negDirRec(matrix, dim, fil+dx, col+dy, dx, dy);
    return;
}

int isInGrid(int matrix[][DIM_MAX], int dim, int fil, int col){
    if(fil>=0 && fil<dim && col>=0 && col<dim)
        return 1;
    return 0;
}

int main(void) {

  int m[5][DIM_MAX] = { {1,0,1,0,1},
                    {0,1,1,1,1},
                    {1,0,0,1,0},
                    {1,1,1,0,1},
                    {0,0,0,0,0}};
  negDirs(m, 5, 1, 2);
  int m2[5][DIM_MAX] = { {1,1,1,1,1},
                    {0,1,0,1,1},
                    {1,1,0,0,0},
                    {0,1,1,0,0},
                    {0,0,0,0,0}};
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);
  negDirs(m, 5, 1, 2);
  negDirs(m, 5, 1, 2);
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);

  printf ("OK!\n");
  return 0;
}