#include <stdio.h>
#include <stdlib.h>

void buscaProfundidade(int v, int n, char (*grafo)[2001], char *cor){
	
	int i;
	
	if(cor[v] == '1')
		return;

	cor[v] = '1';

	for(i = 0; i < n; i++){
		
		if(grafo[v][i] == '1'){
			if(cor[i] == '0')
				buscaProfundidade(i, n, grafo, cor);
		}	
	}
}

int main(void){

	int n, m, i, j, v, w, p, resposta;
	char grafo[2001][2001];
	char cor[2001];

	scanf("%d %d", &n, &m);
	
	while(n != 0 || m != 0){

		resposta = 1;


		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				grafo[i][j] = '0';

		for(i = 0; i < m; i++){
			
			scanf("%d %d %d", &v, &w, &p);
			grafo[v-1][w-1] = '1';
			
			if(p == 2)
				grafo[w-1][v-1] = '1';
		}
		

		for(j = 0; j < n; j++)
			cor[j] = '0';

		buscaProfundidade(1, n, grafo, cor);
			
		for(j = 0; j < n; j++){
			if(cor[j] == '0'){
				resposta = 0;
				break;
			}
		}

		if(resposta == 1){

			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					if(grafo[i][j] == '0')
						grafo[i][j] = '1';
					else
						grafo[i][j] = '0';
				}
			}

			for(j = 0; j < n; j++)
				cor[j] = '0';

			buscaProfundidade(1, n, grafo, cor);
			
			for(j = 0; j < n; j++){
				if(cor[j] == '0'){
					resposta = 0;
					break;
				}
			}
		}

		printf("%d\n", resposta);
		scanf("%d %d", &n, &m);
	}

	return 0;
}