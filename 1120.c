#include <stdio.h>
#include <stdlib.h>

int main(void){

	int x, i, imprimiu = 0;
	char y[102];

	scanf("%d %s", &x, y);

	while(x != 0 && y[0] != '0'){

		for(i = 0; y[i] != '\0'; i++){
			
			if(x != (int)y[i] - '0'){

				if(y[i] != '0' || imprimiu){
					printf("%c", y[i]);
					imprimiu = 1;
				}
			}
		}

		if(!imprimiu)
			printf("0");

		printf("\n");
		imprimiu = 0;

		scanf("%d %s", &x, y);
	}

	return 1;

}