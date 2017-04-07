#include <stdio.h>
#include <stdlib.h>

int main(void){

	int i = 0, resposta = 0, igual = 0, n1, n2, modulo; 
	char vetorAdjacencia[10];

	char numero1[5];

	while(scanf("%d", &n1) != EOF){

		scanf("%d", &n2);
		
		for(i = 0; i < 10; i++){
			vetorAdjacencia[i] = 0;
		}
		
		
		while(n1 <= n2){
			
			modulo = n1;

			for(i = 0; i < 5; i++){
			
				if(modulo < 1)
					numero1[i] = '\0';
			
				else{
					numero1[i] = modulo%10 + '0';
					modulo /= 10;
				}
			}

			for(i = 0; numero1[i] != '\0'; i++){

				if(vetorAdjacencia[(int)numero1[i] - '0'] == 0)
					vetorAdjacencia[(int)numero1[i] - '0'] = 1;

				else
					igual = 1;
			}
			
			if(!igual){
				resposta++;
			}

			n1++;

			igual = 0;

			for(i = 0; i < 10; i++)
				vetorAdjacencia[i] = 0;
		}		
		

		printf("%d\n", resposta);
		resposta = 0;

		for(i = 0; i < 10; i++)
				vetorAdjacencia[i] = 0;
	}

	return 1;
}