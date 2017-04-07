#include <stdio.h>

int main(void){

	int n, d, nApagados, tamanhoNumero, topo, i;
	char number[100001], temp;

	scanf("%d %d", &n, &d);

	while(n != 0 || d != 0){
		
		nApagados = 0;
		topo = -1;
		tamanhoNumero = n - d;

		for(i = 0; i < n; i++){

			scanf(" %c", &temp);
			
			while(nApagados < d && topo > -1 && temp > number[topo]){
				nApagados++;
				topo--;
			}

			if(tamanhoNumero > topo+1){
				topo++;
				number[topo] = temp;
			}
		}

		number[topo+1] = '\0';

		printf("%s\n", number);
		scanf("%d %d", &n, &d);
	}

	return 0;
}