#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

	float x1, y1, x2, y2;
	float distancia;

	scanf("%f %f", &x1, &y1);
	scanf("%f %f", &x2, &y2);

	distancia = sqrt(pow((x2-x1),2) + pow((y2-y1),2));

	printf("%0.4f\n", distancia);


	return 1;
}