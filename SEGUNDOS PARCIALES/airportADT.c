#include "airportADT.h"

typedef struct runway{
    
    char * occupied;
} TRunway;

typedef struct airportCDT{
    TRunway * runways;
    size_t dim;
} airportCDT;

airportADT newAirport(void){
    airportADT port = malloc(sizeof(airportCDT));
    port->dim = 0;
    port->runways = NULL;
}

/* Elimina al avión que se encuentra al principio de la pista de
** despegue con el identificador runwayId
** y retorna la matrícula del avión eliminado o NULL si falla.
** Falla si la pista no existe.
** Falla si no hay aviones en la pista.
*/
char * takeOff(airportADT airportAdt, size_t runwayId){

}

/* Retorna un arreglo con las matrículas de los aviones que se
** encuentran en la pista de despegue con el identificador
** runwayId en orden inverso al orden de despegue (el último elemento
** del arreglo debe coincidir con el valor de retorno de una
** invocación a la función takeOff sobre esa pista).
** El arreglo debe ** contar con una cadena vacía "" como marca de fin.
** Si la pista no existe retorna NULL.
*/
char ** pendingFlights(airportADT airportAdt, size_t runwayId){

}