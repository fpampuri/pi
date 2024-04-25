#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

void deleteChars(char * s1, char * s2);
void completaString(char * s, int pos, int posNueva);

int main(void) {
    
  char s3[] = "abc";
  char s4[] = "axc123456789012345678901234567890";
  deleteChars(s3,s4);
  assert(strcmp(s3, "b")==0);
  assert(strcmp(s4, "x123456789012345678901234567890")==0);

  char s1[] = "Hola, soy un string";
  char s2[] = "Yo soy otro string";

  deleteChars(s1, s2);
  assert(strcmp(s1, "Hla, sy un string")==0);
  assert(strcmp(s2, "Y soy tro string")==0);

  char empty[] = "";
  deleteChars(s1, empty);
  assert(strcmp(s1, "Hla, sy un string")==0);
  assert(strcmp(empty, "")==0);

  strcpy(s1, "ABCDE");
  strcpy(s2, "abcde");
  deleteChars(s1, s2);
  assert(strcmp(s1, "ABCDE")==0);
  assert(strcmp(s2, "abcde")==0);

  deleteChars(s1,s1);
  assert(strcmp(s1, "")==0);
  


  puts("OK!");
  return 0;
}

void deleteChars(char * s1, char * s2){
    int i, j=0;
    for( i=0; s1[i] && s2[i]; i++){
        if(!(s1[i] == s2[i])){
            s1[j]=s1[i];
            s2[j]=s2[i];
            j++;
        }
    }
    completaString(s1, i, j);
    completaString(s2, i, j);
}

void completaString(char * s, int pos, int posNueva){
    for(int i=pos; s[i]; i++){
        s[posNueva++]=s[i];
    }
    s[posNueva]=0;
}