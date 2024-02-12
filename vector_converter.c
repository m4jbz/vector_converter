#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979

int main()
{
	short option;
	int numVectors = 0;
	double coordsX, coordsY;
	double vecX, vecY, totalX = 0, totalY = 0;

	system("clear");
	printf("¿Cuántos vectores vas a sumar? => ");
	scanf("%d", &numVectors);

	if (numVectors == 0)
		return 1;

	printf("1) Rectangular a polar\n2) Polar a rectangular\n:");
	scanf("%hd", &option);

	switch (option) 
	{
		case 1:
			
			for (int i = 1; i <= numVectors; i++)
			{
				printf("\n");
				printf("X del Vector(%d): ", i);
				scanf("%lf", &coordsX);

				printf("Y del Vector(%d): ", i);
				scanf("%lf", &coordsY);

				if (numVectors == 1)
				{
					vecX = sqrt(pow(coordsX, 2) + pow(coordsY, 2));
					vecY = atan(coordsY/coordsX) * 180/PI;
					printf("\n");
					printf("Polares: (%lf, %lf°)\n", vecX, vecY);
					return 0;
				}

				totalX += coordsX;
				totalY += coordsY;
			}
			printf("\n");
			vecX = sqrt(pow(totalX, 2) + pow(totalY, 2));
			vecY = atan(totalY/totalX) * 180/PI;
			printf("Polares: (%lf, %lf°)\n", vecX, vecY);
			break;
		case 2:
			for (int i = 1; i <= numVectors; i++)
			{
				printf("\n");
				printf("Fuerza del Vector(%d): ", i);
				scanf("%lf", &coordsX);

				printf("Ángulo del Vector(%d): ", i);
				scanf("%lf", &coordsY);

				vecX = coordsX * cos(coordsY * PI/180);
				vecY = coordsX * sin(coordsY * PI/180);

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
			printf("Opción no existe.");
			break;
	}

	return 0;
}
