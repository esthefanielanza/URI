#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INFINITO INT_MAX

typedef struct Celula *Apontador;

typedef struct Celula{
	int x;
	Apontador prox;
} Celula;

typedef struct Fila{
	Apontador frente, tras;
	int tamanho;
} Fila;

void criaFila(Fila *f){

	f->frente = (Celula*) malloc(sizeof(Celula));
	f->tras = f->frente;
	f->frente->prox = NULL;
	f->tamanho = 0;
}

void enfileira(Fila *f, int x){

	Apontador novaCelula;
	novaCelula = (Celula*) malloc(sizeof(Celula));
	
	novaCelula->x = x;
	novaCelula->prox = NULL;

	f->tras->prox = novaCelula;
	f->tras = novaCelula;
	f->tamanho++;
}


int filaVazia(Fila *f){
	return(f->frente == f->tras);
}

void desenfileira(Fila *f, int *x){

	if(filaVazia(f)){
		printf("Erro: Fila vazia");
		return;
	}

	Apontador q;
	q = f->frente;
	f->frente = f->frente->prox;
	*x = f->frente->x;
	free(q);
	f->tamanho--;
}

void destroiFila(Fila *f){
	
	Apontador aux, remover;
	aux = f->frente;
	
	while(aux->prox != NULL){
		remover = aux;
		aux = aux->prox;
		free(remover);
	}

	free(aux);
	free(f);
}

void djikstra(int c, int v, int **m){
	
	int i, x;
	int *distancia;
	char *cor;

	distancia = malloc(c * (sizeof(int)));
	cor = malloc(c * (sizeof(char)));


	Fila *f = malloc(sizeof(Fila));

	for(i = 0; i < c; i++){
		distancia[i] = INFINITO;
		cor[i] = '0';
	}

	criaFila(f);
	enfileira(f, 0);
	distancia[0] = 0;


	while(!filaVazia(f)){
		
		desenfileira(f, &x);
		cor[x] = '1';

		for(i = 0; i < c; i++){
			if(m[x][i] != -1 && cor[i] == '0'){
				
				if(distancia[i] > distancia[x] + m[x][i]){
					distancia[i] = distancia[x] + m[x][i];
				}
				enfileira(f, i);
			}
		}
	}

	if(distancia[c-1] == INFINITO)
		printf("-1\n");
	else 
		printf("%d\n", distancia[c-1]);

}

int main(void){

	int c, v, i, j, k, x, y, p;
	int **m, **m2;

	scanf("%d %d", &c, &v);
	
	m = malloc(c*sizeof(int*));
	m2 = malloc(c*sizeof(int*));

	for(i = 0; i < c; i++){
		m[i] = malloc(c*sizeof(int));
		m2[i] = malloc(c*sizeof(int));
	}

	for(i = 0; i < c; i++){
		for(j = 0; j < c; j++){
			m[i][j] = -1;
			m2[i][j] = -1;
		}
	}

	for(i = 0; i < v; i++){
		scanf("%d %d %d", &x, &y, &p);
		m[x-1][y-1] = p;
		m[y-1][x-1] = p;
	}

	for(i = 0; i < c; i++){
		for(j = 0; j < c; j++){
			if(m[i][j] != -1){
				for(k = 0; k < c; k++){
					if(m[j][k] != -1){
						if(i != k)
							if(m2[i][k] > m[i][j] + m[j][k] || m2[i][k] == -1)
								m2[i][k] = m[i][j] + m[j][k];
					}
				}
			}
		}
	}

	/*for(i = 0; i < c; i++){
		for(j = 0; j < c; j++){
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}*/
	
	djikstra(c, v, m2);

	return 0;
}