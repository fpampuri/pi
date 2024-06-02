#include "phrasesADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct node{
    size_t key;
    struct node * tail;
} TNode;
typedef TNode * TList;

typedef struct SPhrase{
    char * phrase;
    size_t len;
} TPhrase;

typedef struct phrasesCDT{
    TPhrase * vec;
    size_t minKey;
    size_t maxKey;
    size_t count;
    TList list;
} phrasesCDT;

phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo){
    if(keyFrom < 0 || keyFrom > keyTo)
        return NULL;
    phrasesADT ph = malloc(sizeof(phrasesCDT));
    ph->count = 0;
    ph->vec = calloc(keyTo-keyFrom,sizeof(TPhrase));
    ph->list = NULL;
    ph->minKey = keyFrom;
    ph->maxKey = keyTo;
    return ph;
}

static int isKeyValid(phrasesADT ph, size_t key){
    return (key >= ph->minKey && key <= ph->maxKey);
}

static TList putInList(TList list, size_t key){
    if(list == NULL || key < list->key ){
        TList aux = malloc(sizeof(TNode));
        aux->key = key;
        aux->tail = list;
        return aux;
    }
    else if(key > list->key)
        list->tail = putInList(list->tail, key);
    return list;
}

static void freeListRec(TList l){
    if(l == NULL)
        return;
    freeListRec(l->tail);
    free(l);
}
void freePhrases(phrasesADT ph){
    TList aux = ph->list;
    while(aux != NULL){
        free(ph->vec[aux->key - ph->minKey].phrase);
        aux = aux->tail;
    }
    free(ph->vec);
    freeListRec(ph->list);
    free(ph);
}

int put(phrasesADT ph, size_t key, const char * phrase){
    int idx = key - ph->minKey;
    if(!isKeyValid(ph, key))
        return 0;
    if(ph->vec[idx].phrase == NULL)
        ph->count++;
    ph->vec[idx].len = strlen(phrase);
    ph->vec[idx].phrase = realloc(ph->vec[idx].phrase, (ph->vec[idx].len+1)*sizeof(char));
    ph->list = putInList(ph->list, key);
    strcpy(ph->vec[idx].phrase, phrase);
    return 1;
}

/*
* Retorna una copia de la frase asociada a la clave key. Si no hay frase asociada
* a la clave key retorna NULL, lo mismo si la clave es inválida.
*/
char * get(const phrasesADT ph, size_t key){
    int idx = key - ph->minKey;
    if(!isKeyValid(ph, key) || ph->vec[idx].phrase == NULL)
        return NULL;
    char * aux = malloc((ph->vec[idx].len+1)*sizeof(char));
    strcpy(aux, ph->vec[idx].phrase);
    return aux;
}

size_t size(const phrasesADT ph){
    return ph->count;
}

/*
* Retorna un string con todas las frases concatenadas 
* Si no hay frases retorna un string vacío
*/
char * concatAll(const phrasesADT ph){
    char * resp = calloc(1, sizeof(char));
    TList aux = ph->list;
    size_t sizeResp = 1; // para tener espacio para el 0 final siempre
    size_t key, idx;
    while(aux != NULL){
        key = aux->key;
        idx = key - ph->minKey;
        resp = realloc(resp, (sizeResp+ph->vec[idx].len)*sizeof(char));
        sizeResp += ph->vec[idx].len;
        strcat(resp, ph->vec[idx].phrase);
        aux = aux->tail;
    }
    return resp;
}

/*
* Retorna un string con todas las frases concatenadas cuyas claves estén entre
* from y to inclusive.
* Si no hay frases en ese rango, retorna un string vacío
*/
char * concat(const phrasesADT ph, size_t from, size_t to){
    if(from < 0 || from > to)
        return NULL;
    TList aux = ph->list;
    char * resp = calloc(1, sizeof(char));
    size_t sizeResp = 1;
    while(aux != NULL && aux->key < from)
        aux = aux->tail;

    // aux terminó o alcanzó a la primer key
    size_t idx;
    while(aux != NULL && aux->key <= to){
        idx = aux->key - ph->minKey;
        resp = realloc(resp, (sizeResp + ph->vec[idx].len)*sizeof(char));
        sizeResp += ph->vec[idx].len;
        strcat(resp, ph->vec[idx].phrase);
        aux = aux->tail;
    }
    return resp;
}




int main(void) {
    assert(newPhrasesADT(1200, 1100)==NULL);
    phrasesADT p = newPhrasesADT(1200, 1800);
    assert(p!=NULL);
    assert(put(p, 1199, "Hello" )==0);
    assert(size(p)==0);
    assert(put(p, 1200, "Hello" )==1);
    assert(put(p, 1210, ", " )==1);
    assert(put(p, 1220, "world" )==1);
    assert(size(p)==3);
    
    char * aux = get(p, 1100);
    assert(aux==NULL);
    aux= get(p, 1200);
    assert(strcmp(aux, "Hello")==0);
    free(aux);
    aux= get(p, 1210);
    assert(strcmp(aux, ", ")==0);
    free(aux);
    aux= get(p, 1220);
    assert(strcmp(aux, "world")==0);
    free(aux);
    
    aux = concatAll(p);
    assert(strcmp(aux, "Hello, world")==0);
    free(aux);
    
    aux = concat(p,1230, 1800);
    assert(strcmp(aux, "")==0);
    free(aux);
    
    aux = concat(p,1200, 1800);
    assert(strcmp(aux, "Hello, world")==0);
    free(aux);
    
    // reemplazamos "world" por otro texto
    assert(put(p, 1220, "mundo cruel." )==1);
    assert(size(p)==3);
    aux = concatAll(p);
    assert(strcmp(aux, "Hello, mundo cruel.")==0);
    free(aux);
    freePhrases(p);
 
    p = newPhrasesADT(1, 20);   
    put(p,1, "On the burning February morning Beatriz Viterbo died, after braving an agony that never for a single moment gave way to self-pity or fear, "
    "I noticed that the sidewalk billboards around Constitution Plaza were advertising some new brand or other of American cigarettes. "
    "The fact pained me, for I realised that the wide and ceaseless universe was already slipping away from her and that this slight change "
    "was the first of an endless series. The universe may change but not me, I thought with a certain sad vanity. "
    "I knew that at times my fruitless devotion had annoyed her; now that she was dead, I could devote myself to her memory, "
    "without hope but also without humiliation. I recalled that the thirtieth of April was her birthday; on that day to visit her house on Garay Street "
    "and pay my respects to her father and to Carlos Argentino Daneri, her first cousin, would be an irreproachable and perhaps unavoidable act of politeness. "
    "Once again I would wait in the twilight of the small, cluttered drawing room, once again I would study the details of her many photographs: "
    "Beatriz Viterbo in profile and in full colour; Beatriz wearing a mask, during the Carnival of 1921; "
    "Beatriz at her First Communion; Beatriz on the day of her wedding to Roberto Alessandri; "
    "Beatriz soon after her divorce, at a luncheon at the Turf Club; Beatriz at a seaside resort in Quilmes with Delia San Marco Porcel and Carlos Argentino; "
    "Beatriz with the Pekingese lapdog given her by Villegas Haedo; Beatriz, front and three-quarter views, smiling, hand on her chin... "
    "I would not be forced, as in the past, to justify my presence with modest offerings of books -- books whose pages I finally learned to cut beforehand, "
    "so as not to find out, months later, that they lay around unopened.");
    
    put(p,2, "Beatriz Viterbo died in 1929. From that time on, I never let a thirtieth of April go by without a visit to her house. "
    "I used to make my appearance at seven-fifteen sharp and stay on for some twenty-five minutes. "
    "Each year, I arrived a little later and stay a little longer. In 1933, a torrential downpour coming to my aid, "
    "they were obliged to ask me for dinner. Naturally, I took advantage of that lucky precedent. "
    "In 1934, I arrived, just after eight, with one of those large Santa Fe sugared cakes, and quite matter-of-factly I stayed to dinner. "
    "It was in this way, on these melancholy and vainly erotic anniversaries, that I came into the gradual confidences of Carlos Argentino Daneri." );
    
    put(p,3, "Be thou as chaste as ice, as pure as snow, thou shalt not escape calumny. Get thee to a nunnery, go.");
    assert(size(p)==3);
    
    put(p,10, "On the burning February morning Beatriz Viterbo died, after braving an agony that never for a single moment gave way to self-pity or fear, "
    "I noticed that the sidewalk billboards around Constitution Plaza were advertising some new brand or other of American cigarettes. "
    "The fact pained me, for I realised that the wide and ceaseless universe was already slipping away from her and that this slight change "
    "was the first of an endless series. The universe may change but not me, I thought with a certain sad vanity. "
    "I knew that at times my fruitless devotion had annoyed her; now that she was dead, I could devote myself to her memory, "
    "without hope but also without humiliation. I recalled that the thirtieth of April was her birthday; on that day to visit her house on Garay Street "
    "and pay my respects to her father and to Carlos Argentino Daneri, her first cousin, would be an irreproachable and perhaps unavoidable act of politeness. "
    "Once again I would wait in the twilight of the small, cluttered drawing room, once again I would study the details of her many photographs: "
    "Beatriz Viterbo in profile and in full colour; Beatriz wearing a mask, during the Carnival of 1921; "
    "Beatriz at her First Communion; Beatriz on the day of her wedding to Roberto Alessandri; "
    "Beatriz soon after her divorce, at a luncheon at the Turf Club; Beatriz at a seaside resort in Quilmes with Delia San Marco Porcel and Carlos Argentino; "
    "Beatriz with the Pekingese lapdog given her by Villegas Haedo; Beatriz, front and three-quarter views, smiling, hand on her chin... "
    "I would not be forced, as in the past, to justify my presence with modest offerings of books -- books whose pages I finally learned to cut beforehand, "
    "so as not to find out, months later, that they lay around unopened."
    "Beatriz Viterbo died in 1929. From that time on, I never let a thirtieth of April go by without a visit to her house. "
    "I used to make my appearance at seven-fifteen sharp and stay on for some twenty-five minutes. "
    "Each year, I arrived a little later and stay a little longer. In 1933, a torrential downpour coming to my aid, "
    "they were obliged to ask me for dinner. Naturally, I took advantage of that lucky precedent. "
    "In 1934, I arrived, just after eight, with one of those large Santa Fe sugared cakes, and quite matter-of-factly I stayed to dinner. "
    "It was in this way, on these melancholy and vainly erotic anniversaries, that I came into the gradual confidences of Carlos Argentino Daneri.");
    
    aux = get(p, 2);
    assert(strncmp(aux,"Beatriz Viterbo",15 )==0);
    
    assert(strlen(aux)==690);
    
    char *aux1 = get(p, 1);
    
    char aux12[strlen(aux1)+strlen(aux)+1];
    strcpy(aux12, aux1);
    strcat(aux12, aux);
    
    char * aux10 = get(p,10);
    assert(strcmp(aux12, aux10)==0);
    
    free(aux);
    free(aux1);
    free(aux10);
    
    freePhrases(p);
    puts("OK!");
    return 0;
}