Ejercicio 3
¿Qué indican las siguientes expresiones?

int *(*p) (int (*a)[ ]); Puntero a función que recibe un puntero a un vector de ints y retorna puntero a int
int *p[10]; Vector de 10 punteros a int
int (*p)[10]; puntero a un arreglo de 10 ints
int *p(void); p es una función que recibe void y devuelve puntero a int
p (char *a); p es un puntero que recibe un string y devuelve ??? (int? void?)
int *p(char *a); p es una funcion que recibe un string y devuelve un puntero a int
int (*p) (char *a); p es un puntero a funcion que recibe string y devuelve int
int (*p(char *a))[10]; p es un puntero a funcion que recibe un string y devuelve un vector de 10 enteros
int p(char (*a)[ ]); p es una funcion que recibe un puntero a un vector de chars y devuelve int
int p(char *a[ ]); p es una funcion que recibe un vector de strings y devuelve int
int *p(char a[ ]); p es una funcion que recibe un vector de char y devuelve un puntero a int
int *p(char (*a)[ ]); p es una funcion que recibe un puntero a un arreglo de chars y devuelve un puntero a int
int *p(char *a[ ]); p es una funcion que recibe un vector de strings y devuelve un puntero a int
int (*p)(char(*a)[ ]); p es un puntero a funcion que recibe un puntero a un arreglo de chars y devuelve int
int *(*p)(char *a[ ]); p es un puntero a funcion que recibe un arreglo de strings y devuelve un puntero a int 
int (*p[10])(void); p es un vector de 10 punteros a funcion que reciben void y retornan int
int (*p[10])(char a); p es un vector de 10 punteros a funcion que reciben char y devuelven int
int *(*p[10])(char a); p es un vector de 10 punteros a funcion que reciben char y devuelven puntero a int
int *(*p[10])(char *a); p es un vector de 10 punteros a funcion que reciben un string y devuelven puntero a int
int (*p) (char *a[ ]); p es un puntero a funcion que recibe un vector de strings y devuelve un int

Ejercicio 4
a) double * (**p)(void) o double * (*p[])(void);

b) typedef int mat[3][5];
   *mat p(char *);

c) (int * (*p[N])(int)) * p;
