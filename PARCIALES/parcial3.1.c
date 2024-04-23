#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define APARICIONES 26

int main(){
    char * letters[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	int v[APARICIONES]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int i, c, letras, mayus, minus, noletras, index;
	letras=0; mayus=0; minus=0; noletras=0;
	while((c=getchar()) != EOF){
		if(isalpha(c)){
			letras++;
			if(isupper(c)){
				mayus++;
				tolower(c);
			}
			else minus++;
            index=c-'a';
			v[index]++;
		}
		else noletras++;
	
	
	}
	printf("Letras: %d\nMayus: %d\nMinus: %d\nCaracteres no letras: %d\n",letras, mayus, minus, noletras);
	for(i=0; i<APARICIONES; i++){
	if(v[i] != 0)
		printf("Cantidad de %s: %d\n",letters[i],v[i]);
	}
	return 0;
}