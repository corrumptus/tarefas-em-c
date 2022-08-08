#include <stdio.h>

main() {
	//ex. 5
	/*
	float x, y, z;
	printf("Digite os valores dos lados de um triangulo:\n");
	scanf("%f%f%f", &x,&y,&z);
	if (x < y + z && y < x + z && z < x + y) {
		if (x == y && y == z && z == x) {
			printf("O triangulo é equilatero");
		}
		else {
			if (x == y || y == z || z == x) {
				printf("O triangulo é isoceles");
			}
			else {
				printf("O triangulo é escaleno");
			}
		}
	}
	else {
		printf("Os valores indicados(%f, %f, %f) não formam um triangulo", x, y, z);
	}
	*/
	
	//ex. 6
	/*
	#include <math.h>
	float a, b, c, x;
	printf("Sabendo que uma equação do 2º grau possui a forma ax²+bx+c = 0, digite os valores de a, b e c:\n");
	scanf("%f%f%f", &a, &b, &c);
	if (a != 0) {
		if ((b*b) - (4*a*c) < 0) {
			printf("A equação não possui raizes reais");
		}
		else {
			if (b*b - (4*a*c) == 0) {
				x = (-b)/(2*a);
				printf("A equação possui 2 raizes reais iguais a %f", x);
			}
			else {
				printf("A equação possui 2 raizes reais distintas: ");
				x = ((-b) + sqrt((b*b) - (4*a*c)))/(2*a);
				printf("%f ", x);
				x = ((-b) - sqrt((b*b) - (4*a*c)))/(2*a);
				printf("e %f", x);
			}
		}
	}
	else {
		printf("A equação precisa que a seja diferente de 0 para ser do segundo grau");
	}
	*/
	
	//ex. 7
	/*
	#include <math.h>
	int i; float n, m, nm;
	printf("Digite os 2 números:\n");
	scanf("%f%f", &n, &m);
	printf("Escolha uma das opções:\n1- potencia dos números\n2- Raiz quadrada de ambos\n3- Raiz cúbica de ambos\n4- produto dos números");
	scanf("%d", &i);
	switch (i) {
		case 1:
			nm = pow(n,m);
			printf("%f", nm);
			break;
		case 2:
			nm = sqrt(n);
			printf("%f", nm);
			nm = sqrt(m);
			printf("%f", nm);
			break;
		case 3:
			nm = cbrt(n);
			printf("%f", nm);
			nm = cbrt(m);
			printf("%f", nm);
			break;
		case 4:
			nm = n*m;
			printf("%f", nm);
			break;
		default:
			printf("Opção inválida");
	}
	*/
}
