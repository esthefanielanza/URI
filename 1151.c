#include <stdio.h>
#include <stdlib.h>

int main(void){

	int n, x1 = 0, x2 = 1, aux, i;
	scanf("%d", &n);

	if(n > 1)
		printf("0 ");

	if(n > 2)
		printf("1 ");

	for(i = 2; i < n; i++){
		aux = x1 + x2;
		printf("%d", aux);
		if(i != n - 1)
			printf(" ");
		x1 = x2;
		x2 = aux;
	}
	printf("\n");
	return 1;
}