#include <stdio.h>
#include <stdlib.h>

int main(void){

	int nGenes, nInversoes, nConsultas, a, b, genome = 1, i, j = 0, aux;

	int gene[50000];
	
	scanf("%d", &nGenes);

	while(nGenes != 0){

		for(i = 0; i < nGenes; i++)
			gene[i] = i + 1;
		

		scanf("%d", &nInversoes);

		for(i = 0; i < nInversoes; i++){

			scanf("%d %d", &a, &b);

			a--; b--;

			while(a < b){
				
				aux = gene[a];
				gene[a] = gene[b];
				gene[b] = aux;

				a++; b--;
			}
		}

		scanf("%d", &nConsultas);

		printf("Genome %d\n", genome);

		for(i = 0; i < nConsultas; i++){
			
			scanf("%d", &a);
			
			while(a != gene[j])
				j++;
			

			printf("%d\n", j+1);
			j = 0;
		}

		genome++;

		scanf("%d", &nGenes);
	}

	return 0;
}
	

	