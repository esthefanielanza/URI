#include <stdio.h>
#include <stdlib.h>

int main(void){

	int a, b;

	while(scanf("%u", &a) != EOF){

		scanf("%u", &b);

		printf("%u\n", a ^ b);
	}

	return 0;
}