#include <stdio.h>
#include <stdlib.h>
int particao(int *A, int esq, int dir){

	int i = esq, j = dir;
	int temp;

	int x;

	x = A[(i + j)/2]; //Obtém pivô
	
	do{
			
		while(A[i] < x){
			i++;
		}
		
		while(A[j] > x){
			j--;
		}

		if(i <= j){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
			j--;
		}

	} while(i <= j);

	return i;
}

void quickSort(int *A, int esq, int dir){
	
	int p = 0;

	p = particao(A, esq, dir);

	if(esq < p - 1)
		quickSort(A, esq, p - 1);
	if(dir > p)
		quickSort(A, p, dir);
}

int main(void){

	int nTestes, nAndares, capacidade, nPessoas, energia;
	int i, j, k;
	int andarDestino[50000];

	scanf("%d", &nTestes);

	for(i = 0; i < nTestes; i++){
		
		energia = 0;

		scanf("%d %d %d", &nAndares, &capacidade, &nPessoas);


		for(j = 0; j < nPessoas; j++){
			andarDestino[j] = 0;
		}

		for(j = 0; j < nPessoas; j++){
			//printf("loop");
			scanf("%d", &andarDestino[j]);
		}
	
		quickSort(andarDestino, 0, nPessoas-1);

		k = 0;

		while(k < nPessoas){
			energia += 2*andarDestino[nPessoas-1-k];
			k += capacidade;
		}

		printf("%d\n", energia);

	}

	return 0;
}