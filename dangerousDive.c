#include <stdio.h>
#include <stdlib.h>

int main (void){

	int wentM, returnedM, i, rDiver;
	int *divers;

	while(scanf("%d", &wentM) != EOF){

		scanf("%d", &returnedM);


		divers = malloc(wentM * sizeof(int));
			
		for(i = 0; i < wentM; i++)
			divers[i] = 0;

		for(i = 0; i < returnedM; i++){
			scanf("%d", &rDiver);
			divers[rDiver - 1] = 1;
		}

		if(wentM == returnedM)
			printf("*\n");

		else{

			for(i = 0; i < wentM; i++){				
				if(divers[i] == 0)
					printf("%d ", i + 1);
			}

			printf("\n");
		}
	}

	return 0;
}