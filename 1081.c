#include <stdio.h>

void visitaVertice(int v, int (*grafo)[20], int *vertices, int *antecessor, int nVertices, int *nivel, int *imprimiu){

	int i, j;

	vertices[v] = 1;
	
	for(i = 0; i < nVertices; i++){
		
		if(grafo[v][i] == 1){
			
			if(vertices[i] == 0){
				
				antecessor[i] = v;
				
				for(j = 0; j < *nivel * 2; j++){
					printf(" ");
				}

				if(*imprimiu == 0)
					*imprimiu = 1;

				printf("%d-%d pathR(G,%d)\n", v, i, i);
				*nivel = *nivel + 1;
				visitaVertice(i, grafo, vertices, antecessor, nVertices, nivel, imprimiu);
			}

			else{

				for(j = 0; j < *nivel * 2; j++){
					printf(" ");
				}
				
				printf("%d-%d\n", v, i);
				if(*imprimiu == 0)
					*imprimiu = 1;
			}
		}
	}

	vertices[v] = 2;
	*nivel = *nivel - 1;
}

void buscaEmProfundidade(int (*grafo)[20], int v){

	int i;
	int vertices[20];
	int antecessor[20];
	int nivel = 1, imprimiu = 0;

	for(i = 0; i < 20; i++){
		vertices[i] = 0;
		antecessor[i] = -1;
	}

	for(i = 0; i < v; i++){
		imprimiu = 0;
		if(vertices[i] == 0){
			nivel = 1;
			visitaVertice(i, grafo, vertices, antecessor, v, &nivel, &imprimiu);
			if(imprimiu == 1)
				printf("\n");
		}
	}
}

int main(void){

	int n, v, e, caso = 1;
	int i, j, k;

	int v1, v2;
	int grafo[20][20];

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		
		for(j = 0; j < 20; j++){
			for(k = 0; k < 20; k++){
				grafo[j][k] = 0;
			}
		}

		printf("Caso %d:\n", caso);
		caso++;

		scanf("%d %d", &v, &e);

		for(j = 0; j < e; j++){
			scanf("%d %d", &v1, &v2);
			grafo[v1][v2] = 1;
		}

		buscaEmProfundidade(grafo, v);
	}

	return 0;
}