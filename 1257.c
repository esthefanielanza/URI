#include <stdio.h>
#include <stdlib.h>

#define PRIMEIRA_LETRA 'A'

int main(void){

	int nCasosTeste, nLinhas, hash = 0;
	int i, j, k;

	char string[51]; 

	scanf("%d[^\n]\n", &nCasosTeste);
	
	for(i = 0; i < nCasosTeste; i++){

		scanf("%d[^\n]", &nLinhas);

		
		for(j = 0; j < nLinhas; j++){
			
			scanf("%s[^\n]", string);

			for(k = 0; string[k] != '\0'; k++){
				hash += string[k] - PRIMEIRA_LETRA + j + k;
			}
		}

		printf("%d\n", hash);
		hash = 0;
	}

	return 1;
} 