/*	Hacer un T.A.D. para conjuntos: elementos no repetidos, sin orden. 
Debe tener al menos las funciones de agregar o remover un elemento,
 unión, intersección y resta de conjuntos.*/

typedef struct conjuntoCDT * conjuntoADT;
typedef  char * elemType;
typedef int (*cmp)(elemType,  elemType);

conjuntoADT nuevoConjunto(cmp fnCompare);

// C1 U {elem}
int agregarElem(conjuntoADT c1, elemType elem);

// C1 - {elem}
void borrarElem(conjuntoADT c1, elemType elem);

// C1 U C2
conjuntoADT unionConj(conjuntoADT c1, conjuntoADT c2);

// C1 ∩ C2
conjuntoADT interseccionConj(conjuntoADT c1, conjuntoADT c2);

// C1 - C2
conjuntoADT restaConj(conjuntoADT c1, conjuntoADT c2);

void liberarConjunto(conjuntoADT c1);

int isEmptyConj(conjuntoADT c1);

int sizeConjunto(conjuntoADT c1);

int setContains(conjuntoADT c1, elemType elem);
