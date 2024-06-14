#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char head;
    struct node * tail;
} TNode;
typedef TNode * TList;

int contarGrupos(const char * s, char c){
    if(s == NULL || *s == NULL)
        return 0;
    return (*s == c && *(s+1) != c) + contarGrupos(s+1, c);
}

int countGroups(TList l, char c){
    if(l == NULL)
        return 0;
    return (l->head == c && (l->tail == NULL || l->tail->head != c)) + countGroups(l->tail, c);
}