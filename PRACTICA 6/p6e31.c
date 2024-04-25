#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int strend(char * s, char * t){
    int lt=strlen(t);
    int ls=strlen(s);
    if(lt > ls)
        return 0;
    return strcmp(s+ls-lt, t)==0;
}

// FALTA HACER ESTAS 3 
void strncpy(char * s, char * t, int n);
void strncat(char * s, int n);
void strncmp(char * s, char * t, int n);

#include <stdio.h>
#include <assert.h>

int main(void) {
  assert(strend("","")==1);
  assert(strend("something","")==1);
  assert(strend("something","thing")==1);
  assert(strend("something","something")==1);
  assert(strend("something","plus something")==0);
  assert(strend("not at the eeeeeend"," end")==0);
  assert(strend("not at the eeeeeennnnnd","end")==0);
  assert(strend("","s")==0);
  assert(strend("ssss","sss")==1);
  assert(strend("ssss","sssss")==0);
  puts("OK!");
  return 0;
}