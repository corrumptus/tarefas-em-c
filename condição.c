#include <stdio.h>

main() {
	//ex. 5
	/*
	float x, y, z;
	printf("Digite os valores dos lados de um triangulo:\n");
	scanf("%f%f%f", &x,&y,&z);
	if (x < y + z && y < x + z && z < x + y) {
		if (x == y && y == z && z == x) {
			printf("O triangulo � equilatero");
		}
		else {
			if (x == y || y == z || z == x) {
				printf("O triangulo � isoceles");
			}
			else {
				printf("O triangulo � escaleno");
			}
		}
	}
	else {
		printf("Os valores indicados(%f, %f, %f) n�o formam um triangulo", x, y, z);
	}
	*/
	
	//ex. 6
	/*
	#include <math.h>
	float a, b, c, x;
	printf("Sabendo que uma equa��o do 2� grau possui a forma ax�+bx+c = 0, digite os valores de a, b e c:\n");
	scanf("%f%f%f", &a, &b, &c);
	if (a != 0) {
		if ((b*b) - (4*a*c) < 0) {
			printf("A equa��o n�o possui raizes reais");
		}
		else {
			if (b*b - (4*a*c) == 0) {
				x = (-b)/(2*a);
				printf("A equa��o possui 2 raizes reais iguais a %f", x);
			}
			else {
				printf("A equa��o possui 2 raizes reais distintas: ");
				x = ((-b) + sqrt((b*b) - (4*a*c)))/(2*a);
				printf("%f ", x);
				x = ((-b) - sqrt((b*b) - (4*a*c)))/(2*a);
				printf("e %f", x);
			}
		}
	}
	else {
		printf("A equa��o precisa que a seja diferente de 0 para ser do segundo grau");
	}
	*/
	
	//ex. 7
	/*
	#include <math.h>
	int i; float n, m, nm;
	printf("Digite os 2 n�meros:\n");
	scanf("%f%f", &n, &m);
	printf("Escolha uma das op��es:\n1- potencia dos n�meros\n2- Raiz quadrada de ambos\n3- Raiz c�bica de ambos\n4- produto dos n�meros");
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
			printf("Op��o inv�lida");
	}
	*/
}
