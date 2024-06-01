#include "socialADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define BLOCK 3
#define LARGO_MAX 20
typedef char TVecNombres[LARGO_MAX];


typedef struct related{
    TVecNombres nombre;
    struct related * tail;
} TRelNode;
typedef TRelNode * TRelated;


typedef struct TNombre{
    TVecNombres nombre;
    struct TNombre * tail;
    TRelated firstRel;
    size_t cantRelated;
} TNombre;
typedef TNombre * TPersonas;


// EL STRUCT POSTA
typedef struct socialCDT{
    TPersonas firstP;
    size_t cantPersonas;
} socialCDT;


socialADT newSocial(void){
    return calloc(1, sizeof(socialCDT));
}

static void freeRelatedRec(TRelated firstR){
    if(firstR == NULL)
        return;
    freeRelatedRec(firstR->tail);
    free(firstR);
}

static void freePersonasRec(TPersonas firstP){
    if(firstP == NULL)
        return;
    freePersonasRec(firstP->tail);
    freeRelatedRec(firstP->firstRel);
    free(firstP);
}
void freeSocial(socialADT soc){
    freePersonasRec(soc->firstP);
    free(soc);
}

// retorna -1 si el primero alfabeticamente es n1, 1 si es n2, 0 si son iguales
static int ordenAlfabetico(const char * n1, const char * n2){
    int i;
    for(i=0; n1[i] && n2[i]; i++){
        if(n1[i] > n2[i])
            return 1;
        if(n1[i] < n2[i])
            return -1;
    }
    if(n1[i])
        return 1;
    if(n2[i])
        return -1;
    return 0;   
}
static TPersonas addPersonRec(TPersonas personas, const char * nombre, int * flag){
    int comp;
    if(personas == NULL || (comp = ordenAlfabetico(personas->nombre, nombre)) == 1){
        TPersonas aux = calloc(1, sizeof(TNombre));
        strncpy(aux->nombre, nombre, LARGO_MAX);
        aux->nombre[LARGO_MAX] = 0;
        aux->tail = personas;
        *flag = 1;
        return aux;
    }
    else if(comp == -1)
        personas->tail = addPersonRec(personas->tail, nombre, flag);
    
    return personas;
}

void addPerson(socialADT soc, const char * nombre){
    int flag = 0;
    soc->firstP = addPersonRec(soc->firstP, nombre, &flag);
    if(flag)
        soc->cantPersonas++;
}




/* Si existe una persona con ese nombre, agrega la nueva relación
** Si la persona no existe, no hace nada
** Si related ya estaba relacionado, lo agrega repetido
** Almacena una copia de related, no simplemente el puntero
**
*/

static TRelated addRelatedRec(TRelated list, const char * nombre){
    int comp;
    if(list == NULL || (comp = ordenAlfabetico(list->nombre, nombre)) >= 0 ){
        TRelated aux = malloc(sizeof(TRelNode));
        strncpy(aux->nombre, nombre, LARGO_MAX);
        aux->nombre[LARGO_MAX] = 0;
        aux->tail = list;
        return aux;
    }
    else list->tail = addRelatedRec(list->tail, nombre);
    return list;
}

void addRelated(socialADT soc, const char * name, const char * related){
    TPersonas aux = soc->firstP;
    for(int i=0; i < soc->cantPersonas; i++){
        if(strcmp(aux->nombre, name) == 0){
            aux->firstRel = addRelatedRec(aux->firstRel, related);
            aux->cantRelated++;
        }
        else aux = aux->tail;
    }
}




/* Retorna una copia de los nombres relacionados con una persona
** en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si la persona no existe, retorna un vector que sólo tiene a NULL como
** elemento
*/
TPersonas findPerson(TPersonas listP, const char * person){
    TPersonas aux = listP;
    int comp;
    while(aux != NULL){
        if((comp = ordenAlfabetico(aux->nombre, person)) == 0)
            return aux;
        if(comp == 1)
            return NULL;
        aux = aux->tail;
    }
    return NULL;
}

char ** related(const socialADT soc, const char * person){
    TPersonas p = findPerson(soc->firstP, person);
    char ** aux;
    int i=0;
    if(p != NULL){
        int i;
        aux = malloc((p->cantRelated + 1)*sizeof(char *));
        TRelated auxR = p->firstRel;
        while(auxR != NULL){
            strcpy(aux[i++], auxR->nombre);
            auxR = auxR->tail;
        }
    }
    else aux = malloc(sizeof(char *));
    aux[i] = NULL;
    return aux;
}




/* Retorna una copia de los nombres de las personas en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si no hay personas, retorna un vector que sólo tiene a NULL como
** elemento
*/
char ** persons(const socialADT soc){
    char ** aux = malloc((soc->cantPersonas + 1)*sizeof(char *));
    TPersonas aux_nombres = soc->firstP;

    int i;
    for(i=0; i<soc->cantPersonas; i++){
        strcpy(aux[i], aux_nombres->nombre);
        aux_nombres = aux_nombres->tail;
    }
    aux[i] = NULL;
    return aux;
}

int main (void) {
	socialADT soc = newSocial();
	char ** rel;
	rel = persons(soc); // rel = {NULL}
	assert( rel[0] == 0 );
	free(rel);

	rel = related(soc, "carlitos"); // rel = {NULL};
	assert( rel[0] == NULL );
	free(rel);

	char aux[30] = "juan";
	addPerson(soc, aux); // soc contiene a "juan"
	strcpy(aux,"luisa");
	addPerson(soc, aux); // soc contiene a "juan" y "luisa"
	strcpy(aux,"ana");
	addRelated(soc, "juan", "pedro");
	addRelated(soc, "juan", aux);
	addRelated(soc, "juan", "juana");
	char ** juanFriends = related(soc, "juan"); // juanFriends es {"ana", "juana", "pedro", NULL};
	assert( !strcmp(juanFriends[0], "ana") && !strcmp(juanFriends[1], "juana"));
	assert( !strcmp(juanFriends[2], "pedro") && juanFriends[3] == NULL );
	for(int i=0; juanFriends[i] != NULL; i++)
		free(juanFriends[i]);
	free(juanFriends);

	addPerson(soc, "andres");
	addPerson(soc, "analia");
	char **p = persons(soc); // p={"analia","andres","juan","luisa",NULL}
	assert( !strcmp(p[0], "analia") && !strcmp(p[1], "andres"));
	assert( !strcmp(p[2], "juan") && !strcmp(p[3], "luisa") && p[4] == NULL );
	for(int i=0; p[i] != NULL; i++)
		free(p[i]);
	free(p);

	addRelated(soc, "juan", "john"); // Ahora los amigos de juan son "ana", "john", "juana" y "pedro"
	addRelated(soc, "juan", "john"); // Ahora los amigos de juan son "ana", "john", "john", juana" y "pedro"
	juanFriends = related( soc, "juan" );
	assert( !strcmp(juanFriends[0], "ana") && !strcmp(juanFriends[1], "john") && !strcmp(juanFriends[2], "john"));
	assert( !strcmp(juanFriends[3], "juana") && !strcmp(juanFriends[4], "pedro") && juanFriends[5] == NULL);
	for(int i=0; juanFriends[i] != NULL; i++)
		free(juanFriends[i]);
	free(juanFriends);

	freeSocial(soc);
	puts("OK!");
	
	// El enunciado decía que a lo sumo eran 20 chars lo que tenía cada nombre
	// Pero si el TAD aplica programación defensiva no debería causar problemas el pasarle un
	// nombre de mayor longitud, a lo sumo podría cortarlo.
    soc = newSocial();	
    addPerson(soc, "012345678901234567890123456789");
    p = persons(soc);
    assert(!strncmp(p[0],"01234567890123456789", 20 ));
    for(int i=0; p[i] != NULL; i++)
		free(p[i]);
	free(p);
    freeSocial(soc);

	puts("Great!");
	return 0;
}