#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define FILS 6
#define COLS 7
#define CANT_DIRS 8
#define FALSE 0
#define TRUE !FALSE
#define DIM 2
#define BLOQUE 5
#define ERROR -1

typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB } Tdireccion;

typedef struct posicion{
	char * palabra;
	int fila;
	int columna;
	Tdireccion direccion;
} pos;

struct posicion * resolverSopa(const char sopa[FILS][COLS], char * diccionario[]);
struct posicion * buscarPalabra(const char sopa[FILS][COLS], char * pal, struct posicion * resp, int * PDimResp);
struct posicion * guardarPalabra(char * pal, int fil, int col, Tdireccion dir, struct posicion * resp, int * dimResp);
int buscarPalabraEnDir(const char sopa[FILS][COLS], char * pal, int fil, int col, Tdireccion dir);
int isInGrid(int fil, int col);

struct posicion * resolverSopa(const char sopa[FILS][COLS], char * diccionario[]){
    int i;
    struct posicion * resp = malloc(BLOQUE*sizeof(struct posicion));
    int dimResp = 0;
    for(i = 0; *diccionario[i] != 0; i++){
        resp = buscarPalabra(sopa, diccionario[i], resp, &dimResp);
    }
    resp[dimResp++].palabra = NULL;
    resp = realloc(resp, dimResp*sizeof(struct posicion));
    return resp;
}

struct posicion * buscarPalabra(const char sopa[FILS][COLS], char * pal, struct posicion * resp, int * PDimResp){
    int i,j,dir;
    for(i = 0; i<FILS; i++){
        for(j = 0; j<COLS; j++){
            if(sopa[i][j] == pal[0])
                for(dir=DER; dir<CANT_DIRS; dir++){
                    if(buscarPalabraEnDir(sopa, pal, i, j, dir))
                        resp = guardarPalabra(pal, i, j, dir, resp, PDimResp);
                }
        }
    }
    return resp;
}

struct posicion * guardarPalabra(char * pal, int fil, int col, Tdireccion dir, struct posicion * resp, int * dimResp){
    if(*dimResp % BLOQUE == 0){
        resp = realloc(resp, (*dimResp + BLOQUE)*sizeof(struct posicion));
        if( resp == NULL )  // si no hubo espacio, que corte.
            return ERROR;
    }
    resp[*dimResp].fila = fil;
    resp[*dimResp].columna = col;
    resp[*dimResp].direccion = dir;
    resp[*dimResp].palabra = pal;
    (*dimResp)++;
    return resp;
}
int buscarPalabraEnDir(const char sopa[FILS][COLS], char * pal, int fil, int col, Tdireccion dir){
    signed char dirs[CANT_DIRS][DIM] = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,-1},{-1,1},{1,1}};
    int i=1;
    char sonIguales = TRUE;
    int dx = dirs[dir][0], dy = dirs[dir][1];
    while(isInGrid(fil += dx, col += dy) && sonIguales && pal[i]){
        if(sopa[fil][col] != pal[i++])
            sonIguales = FALSE;
    }
    if(sonIguales && i == strlen(pal)){
        return TRUE;
    }
    return FALSE;
}

int isInGrid(int fil, int col){
    if(fil >= 0 && fil < FILS && col >= 0 && col < COLS)
        return TRUE;
    return FALSE;
}

// NOTA: depende del orden en que realizan la busqueda, el testeo puede dar diferente
//       en esta prueba asumimos que se recorre el diccionario, y cada palabra se busca en la sopa de 
//       letras.
//.      Si en vez de hacerlo así recorren la matriz y por cada letra buscan si hay una palabra en el diccionario
//       que empiece con esa letra, tienen que cambiar el testeo para que coincida con el orden en que se encuentran.


int main(void) {
  char * diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};
   
  char sopa[FILS][COLS] =
     {{'X','X','X','O','X','X','X'},
      {'A','P','A','C','Y','Y','O'},
      {'Z','E','Z','R','Z','C','X'},
      {'E','R','R','O','R','X','X'},
      {'X','R','I','O','I','E','X'},
      {'X','O','X','X','O','X','X'}};
  
  struct posicion * res = resolverSopa(sopa, diccionario);
  // La cantidad de palabras encontradas debe ser 9
  int expected = 9;
  int count = 0;
  while ( res[count].palabra != NULL)
     printf("%s\n", res[count++].palabra);
  assert(count == expected);

  assert(strcmp(res[0].palabra,"ARRE")==0);
  assert(res[0].fila==1);
  assert(res[0].columna==2);
  assert(res[0].direccion==D_AB);

  assert(strcmp(res[3].palabra,"ORCO")==0);
  assert(res[3].fila==3);
  assert(res[3].columna==3);
  printf("%d\n", res[3].direccion);
  assert(res[3].direccion==ARR);
  
  assert(strcmp(res[4].palabra,"ORCO")==0);
  assert(res[4].fila==4);
  assert(res[4].columna==3);
  assert(res[4].direccion==D_AR);

  assert(strcmp(res[6].palabra,"REA")==0);
  assert(res[6].fila==3);
  assert(res[6].columna==2);
  assert(res[6].direccion==I_AR);
  free(res);
  puts("OK primera parte");
  
  char * diccionario2[] = {""};
  res = resolverSopa(sopa, diccionario2);
  // La cantidad de palabras encontradas debe ser 0
  expected = 0;
  count = 0;
  while ( res[count].palabra != NULL)
     printf("%s\n", res[count++].palabra);
  assert(count == expected);
  free(res); 
  puts("OK sin palabras encontradas");
  return 0;
}