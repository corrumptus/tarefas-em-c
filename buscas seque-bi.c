#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
    #define n 500
    int vet[n], vet_pos[3] = {0, n/2, n-1}, i, j, inter, num, find = 0;

    for (i=0;i<n;i++) {
        vet[i] = rand() % 1000;
        //printf("%d ", vet[i]); //para fins de vizualização
    }
    printf("\nDigite um número\n");
    scanf("%d", &num);
    
    //resultado sequencial
    printf("resultado sequencial\n");
    for(i=0;i<n && find == 0;i++) {
        if (num == vet[i]) {
            printf("número encontrado na %dº posição", i+1);
            find = 1;
        }
    }
    if (find == 0) {
        printf("Número não encontrado");
    }
    
    //resultado binário
    find = 0;
    printf("\nresultado binário\n");
    for (i=0;i<n;i++) {
        for (j=0;j<n-1;j++) {
            if (vet[j] > vet[j+1]) {
                inter = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = inter;
            }
        }
    }
    inter = (int) floor(log(n)+4);
    for (i=0;i<inter && find == 0;i++) {
        if (num == vet[vet_pos[1]]) {
            find = 1;
            printf("Número encontrado na %dº posição", vet_pos[1]+1);
        }
        else {
            if (num > vet[vet_pos[1]]) {
                vet_pos[0] = vet_pos[1];
                vet_pos[1] = (vet_pos[0] + vet_pos[2])/2;
            }
            else {
                vet_pos[2] = vet_pos[1];
                vet_pos[1] = (vet_pos[0] + vet_pos[2])/2;
            }
        }
    }
    if (find == 0) {
        printf("Número não encontrado");
    }
}