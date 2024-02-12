#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAD 180/3.14159265358979

int main()
{
	short option;
	int numVectors = 0;
	double valueX, valueY;
	double vecX, vecY, totalX = 0, totalY = 0;

	system("clear");
	printf("¿Cuántos vectores vas a sumar? => ");
	scanf("%d", &numVectors);

	if (numVectors == 0)
		return 1;

	printf("1) Rectangular a polar\n2) Polar a rectangular\n=>");
	scanf("%hd", &option);

	switch (option) 
	{
		case 1:
			for (int i = 1; i <= numVectors; i++)
			{
				printf("\n");
				printf("X del Vector(%d): ", i);
				scanf("%lf", &valueX);

				printf("Y del Vector(%d): ", i);
				scanf("%lf", &valueY);

				if (numVectors == 1)
				{
					vecX = sqrt(pow(valueX, 2) + pow(valueY, 2));
					vecY = atan(valueY/valueX) * GRAD;
					printf("\n");
					printf("Polares: (%lf, %lf°)\n", vecX, vecY);
					return 0;
				}

				totalX += valueX;
				totalY += valueY;
			}
			printf("\n");
			vecX = sqrt(pow(totalX, 2) + pow(totalY, 2));
			vecY = atan(totalY/totalX) * GRAD;
			printf("Polares: (%lf, %lf°)\n", vecX, vecY);
			break;
		case 2:
			for (int i = 1; i <= numVectors; i++)
			{
				printf("\n");
				printf("Fuerza del Vector(%d): ", i);
				scanf("%lf", &valueX);

				printf("Ángulo del Vector(%d): ", i);
				scanf("%lf", &valueY);

				vecX = valueX * cos(valueY / (GRAD));
				vecY = valueX * sin(valueY / (GRAD));

				if (numVectors == 1)
				{
					printf("\n");
					printf("Cardinales: (%lf, %lf)\n", vecX, vecY);
					return 0;
				}
				totalX += vecX;
				totalY += vecY;
			}
				printf("\n");
				printf("Cardinales: (%lf, %lf)\n", totalX, totalY);
			break;
		default:
			printf("Opción no existe.\n");
			break;
	}

	return 0;
}
