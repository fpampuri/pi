#include "airportADT.h"

typedef struct plane{
    char * registration;
    struct plane * next;
} TPlane;

typedef struct runway{
    TPlane * firstP;
    TPlane * lastP;
    char * occupied;
    size_t planesInList;
} TRunway;

typedef struct airportCDT{
    TRunway * runways;
    size_t dim;
} airportCDT;

airportADT newAirport(void){
    airportADT port = malloc(sizeof(airportCDT));
    port->dim = 0;
    port->runways = NULL;
    return port;
}

/* Elimina al avión que se encuentra al principio de la pista de
** despegue con el identificador runwayId
** y retorna la matrícula del avión eliminado o NULL si falla.
** Falla si la pista no existe.
** Falla si no hay aviones en la pista.
*/
char * takeOff(airportADT port, size_t runwayId){
    // Si no hay tal runway en el aeropuerto o no hay aviones, falla
    if(runwayId > port->dim || !port->runways[runwayId-1].occupied || !port->runways[runwayId-1].planesInList)
        return NULL;
    // copio la rta, hago strlen y strcpy pues  se q son string cortos
    char * resp = malloc((strlen(port->runways[runwayId-1].lastP->registration) + 1));
    strcpy(resp, port->runways[runwayId-1].lastP->registration);
    // borro el nodo
    TPlane * aux = NULL;
    free(port->runways[runwayId-1].lastP);
    port->runways[runwayId-1].lastP = aux;
    (port->runways[runwayId-1].planesInList)--;
    return resp;
}

/* Retorna un arreglo con las matrículas de los aviones que se
** encuentran en la pista de despegue con el identificador
** runwayId en orden inverso al orden de despegue (el último elemento
** del arreglo debe coincidir con el valor de retorno de una
** invocación a la función takeOff sobre esa pista).
** El arreglo debe ** contar con una cadena vacía "" como marca de fin.
** Si la pista no existe retorna NULL.
*/
char ** pendingFlights(airportADT port, size_t runwayId){
     // Si no hay tal runway en el aeropuerto falla
    if(runwayId > port->dim || !port->runways[runwayId-1].occupied)
        return NULL;
    TPlane * aux = port->runways[runwayId-1].firstP;
    size_t i = 0;
    char ** resp = malloc((port->runways[runwayId-1].planesInList + 1)*sizeof(char *));
    while(aux != NULL){
        resp[i] = malloc(strlen(aux->registration) + 1);
        strcpy(resp[i], aux->registration);
        i++;
        aux = aux->next;
    }
    resp[i] = calloc(1, sizeof(char));
    return resp;
}