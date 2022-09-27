#include <stdio.h>
#include <math.h>

float delta_func (float a, float b, float c) {
    int delta = b*b - 4*a*c;
    return delta;
}

float raiz_func (float a, float b) {
    float x = -b/(2*a);
    return x;
}

void raizes_func (float a, float b, float delta, float raizes[]) {
    raizes[0] = (-b + sqrt(delta))/(2*a);
    raizes[1] = (-b - sqrt(delta))/(2*a);
}


void main () {
    float a, b, c, delta, raizes[2];
    printf("Tendo em mente a fórmula geral da equação quadrática ax²+bx+c, informe a, b e c\n");
    scanf("%f%f%f", &a, &b, &c);
    delta = delta_func(a, b, c);
    if (delta < 0) {
        printf("A equação quadrática não possui raizes reais");
    } else {
        if (delta == 0) {
            printf("A equação quadrática possui 2 raizes reais iguais a : %f", raiz_func(a, b));
        } else {
            raizes_func(a, b, delta, raizes);
            printf("A equação quadrática possui 2 raizes reais distintas e iguais a %f e %f", raizes[0], raizes[1]);
        }
    }
}







struct habitante {
    char sexo;
    int nf, idade;
    float sal;
}

main() {
    struct habitante habs[20];
    int i, maiorsal=0, menorsal=0;
    float mediasal=0, mediafil=0, mediamul=0;

    for (i=0;i<20;i++) {
        printf("Digite o o sexo(H/M)\n");
        scanf("%c", &habs[i].sexo);
        printf("Digite a idade\n");
        scanf("%d", &habs[i].idade);
        printf("Digite a salário\n");
        scanf("%f", &habs[i].sal);
        printf("Digite o número de filhos\n");
        scanf("%d", &habs[i].nf);

        mediasal = mediasal + habs[i].sal;
        mediafil = mediafil + habs[i].nf;
        if (habs[i].sexo == "M" && habs[i].sal > 1500) {
            mediamul++;
        }
        if (habs[i].sal > maiorsal) {
            maiorsal = habs[i].sal;
        }
        if (menorsal == 0) {
            menorsal = habs[i].sal;
        } else {
            if (habs[i].sal < menorsal) {
                menorsal = habs[i].sal;
            }
        }
    }
    mediasal = mediasal/20;
    mediafil = mediafil/20;
    mediamul = mediamul/100*5;
    printf("A média de salários da população: %f\nO número médio de filhos: %f\nO maior salário: %f\nO menor salário: %f\nO percentual de mulheres com salário superior a R$1.500,00: %f", mediasal, mediafil, maiorsal, menorsal, mediamul);
}