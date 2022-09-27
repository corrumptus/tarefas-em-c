#include <stdio.h>

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