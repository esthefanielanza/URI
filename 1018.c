#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, i;
	int notas[7];
	int notasValor[7] = {100, 50, 20, 10, 5, 2, 1};

	for(i = 0; i < 7; i++)
		notas[i] = 0;

	scanf("%d", &n);
	
	printf("%d\n", n);
	
	for(i = 0; i < 7; i++){
		
		while(n >= notasValor[i]){
			notas[i]++;
			n -= notasValor[i];
		}
	}

	for(i = 0; i < 7; i++)
		printf("%d nota(s) de R$ %d,00\n", notas[i], notasValor[i]);

	return 1;
}