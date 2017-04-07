#include <stdio.h>
#include <stdlib.h>

int main(void){

	int i, j, n;
	int **matriz;

	while(scanf("%d", &n) != EOF){

		matriz = malloc(sizeof(int*)*n);
		
		for(i = 0; i < n; i++)
			matriz[i] = malloc(sizeof(int)*n);

		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){

				if(i == n - 1 - j)
					matriz[i][j] = 2;

				else if(i == j)
					matriz[i][j] = 1;

				else
					matriz[i][j] = 3;

				printf("%d", matriz[i][j]);
			}
			printf("\n");
		}

		for(i = 0; i < n; i++)
			free(matriz[i]);

		free(matriz);
	}

	return 0;
}