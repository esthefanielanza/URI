#include <stdio.h>
#include <stdlib.h>

int main(void){

	int i, j;
	int jogadores, partidas, resultado = 0, gols;
	int bomJogador;

	scanf("%d %d", &jogadores, &partidas);

	for(i = 0; i < jogadores; i++){
		
		bomJogador = 1;

		for(j = 0; j < partidas; j++){

			scanf("%d", &gols);
			if(gols == 0)
				bomJogador = 0;
		}

		if(bomJogador)
			resultado++;
	}

	printf("%d\n", resultado);
	return 0;
}