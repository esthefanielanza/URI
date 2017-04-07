#include <stdio.h>
#include <stdlib.h>

int main(void){

	int n, tamanhoAtual, i, j, iAtual, jAtual;
	int **matriz;

	scanf("%d", &n);

	while(n != 0){
		
		tamanhoAtual = n;

		matriz = malloc(n * sizeof(int*));
		for(i = 0; i < n; i++)
			matriz[i] = malloc(n * sizeof(int));

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				matriz[i][j] = 0;

		iAtual = 0;
		jAtual = 0;

		while(tamanhoAtual > 0){
			for(i = iAtual; i < tamanhoAtual; i++)
				for(j = jAtual; j < tamanhoAtual; j++)
					matriz[i][j]++;

			tamanhoAtual -= 1;
			iAtual += 1;
			jAtual += 1;
		}
		
		

		for(i = 0; i < n; i++){
			
			for(j = 0; j < n; j++){
				printf("%3d", matriz[i][j]);
				if(j != n - 1)
					printf(" ");
			}

			printf("\n");
		}
 
		printf("\n");
		scanf("%d", &n);
	}
	return 1;
}