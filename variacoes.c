#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	int nCasos, tamanhoPalavra, possibilidades = 1;
	int i, j;

	char palavra[17];

	scanf("%d", &nCasos);

	for(i = 0; i < nCasos; i++){

		scanf("%s", palavra);
		tamanhoPalavra = strlen(palavra);

		for(j = 0; j < tamanhoPalavra; j++){

			if(palavra[j] == 'A' || palavra[j] == 'a' ||  palavra[j] == '4')
				possibilidades *= 3;

			else if(palavra[j] == 'I' || palavra[j] == 'i' ||  palavra[j] == '1')
				possibilidades *= 3;

			else if(palavra[j] == 'E' || palavra[j] == 'e' ||  palavra[j] == '3')
				possibilidades *= 3;
			else if(palavra[j] == 'O' || palavra[j] == 'o' ||  palavra[j] == '0')
				possibilidades *= 3;

			else if(palavra[j] == 'S' || palavra[j] == 's' ||  palavra[j] == '5')
				possibilidades *= 3;

			else
				possibilidades *=2;
		}

		printf("%d\n", possibilidades);
		possibilidades = 1;
	}

	return 0;
}