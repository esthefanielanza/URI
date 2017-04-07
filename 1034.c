#include <stdio.h>
#include <stdlib.h>

#define INFINITO 10000000

int min(int a, int b){
	if(a < b)
		return a;
	else
		return b;
}

int dinamica(int n, int m, int *vetor){

	int pd[n+1][m+1];
	int i, j;

	for(i = 0; i <= n; i++){
		pd[i][0] = 0;
	}

	for(i = 1; i < m+1; i++)
		pd[0][i] = INFINITO;


	for(i = 1; i <= n; i++){

		for(j = 1; j < m+1; j++){		
			
			if(vetor[i-1] > j) pd[i][j] = pd[i-1][j];
			
			else pd[i][j] = min(pd[i-1][j],pd[i][j-vetor[i-1]]+1);
		}
	}

	return pd[n][m];
}

int main(void){

	int t,n,m, blocos;
	int i, j;
	int tamanhosDisponiveis[26];

	scanf("%d", &t);


	for(i = 0; i < t; i++){

		blocos = 0;
		scanf("%d %d", &n, &m);

		for(j = 0; j < n; j++){
			scanf("%d", &tamanhosDisponiveis[j]);
		}

		/* Guloso 		
		for(j = 0; j < n; j++){
		
			while(m >= tamanhosDisponiveis[j]){
				m -= tamanhosDisponiveis[j];
				blocos++;
			}

			if(m == 0)
				break;
		}*/

		blocos = dinamica(n, m, tamanhosDisponiveis);

		printf("%d\n", blocos);
	}

	return 0;
}