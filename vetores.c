#include <stdio.h>

main() {
    //Ex. 1
    /*
    int veti[8], vetj[8]={0,0,0,0,0,0,0,0}, vetk[8]={0,0,0,0,0,0,0,0}, i, j=0, k=0;
    printf("Digite todos os 8 números inteiros\n");
    for (i=0;i<8;i++) {
        scanf("%d", &veti[i]);
        if (veti[i] >= 0) {
            vetj[j] = veti[i];
            j++;
        }
        else {
            vetk[k] = veti[i];
            k++;
        }
    }
    printf("vetor\tposi\tnega\t\n");
    for (i=0;i<8;i++) {
        printf("\n%d\t\t%d\t\t%d\t", veti[i], vetj[i], vetk[i]);
    }
    */
    
    
    //Ex. 2
    /*
    #define n 10
    int veti[n], vetj[n], vetn[2*n], i;
    printf("Digite os %d números inteiros\n", 2*n);
    for (i=0;i<n;i++) {
        scanf("%d", &veti[i]);
    }
    for (i=0;i<n;i++) {
        scanf("%d", &vetj[i]);
    }
    printf("vetn = ");
    for (i=0;i<n;i++) {
        vetn[2*i] = veti[i];
        printf("%d ", vetn[2*i]);
        vetn[2*i+1] = vetj[i];
        printf("%d ", vetn[2*i+1]);
    }
    */
    
    
    //Ex. 4(3)
    /*
    int vet[3][3], i, j, yn = 1;
    printf("Digite 9 números para compor uma matriz 3x3\n");
    for (i=0;i<3;i++) {
        for (j=0;j<3;j++) {
            scanf("%d", &vet[i][j]);
        }
    }
    for (i=0;i<3;i++) {
        for (j=0;j<3;j++) {
            if (vet[i][j] != vet[j][i]) {
                yn = 0;
            }
        }
    }
    if (yn == 1) {
        printf("\nA matriz é simétrica :)");
    }
    else {
        printf("\nA matriz não é simétrica :(");
    }
    */
    
    
    //Ex. 5(4)
    /*
    int n;
    printf("Digite qual será o tamanho da matriz quadrada a ser analisada\n");
    scanf("%d", &n);
    int vet[n][n], i, j, yn = 1;
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            scanf("%d", &vet[i][j]);
            if (i == j) {
                if (vet[i][j] != 1) {
                    yn = 0;
                }
            }
            else {
                if (vet[i][j] != 0) {
                    yn = 0;
                }
            }
        }
    }
    if (yn == 1) {
        printf("A matriz de ordem %d é identidade :)", n);
    }
    else {
        printf("A matriz de ordem %d não é identidade :(", n);
    }
    */


    //Ex. 6(5)
    /*
    int i, j, k;
    printf("Digite o tamanho da primeira matriz: (digite 2 valores inteiros maiores que 0)\n");
    scanf("%d%d",&i,&j);
    printf("Agora digite quantas colunas terá a segunda matriz\n");
    scanf("%d", &k);
    int veti[i][j], vetk[j][k], vetj[i][k], n, a, b;
    for (a=0;a<i;a++) {
        for (b=0;b<j;b++) {
            scanf("%d", &veti[a][b]);
        }
    }
    for (a=0;a<j;a++) {
        for (b=0;b<k;b++) {
            scanf("%d", &vetk[a][b]);
        }
    }
    for (a=0;a<i;a++) {
        for (b=0;b<k;b++) {
            vetj[a][b] = 0;
            for (n=0;n<j;n++) {
                vetj[a][b] = vetj[a][b] + veti[a][n]*vetk[n][b];
            }
            printf("%d ", vetj[a][b]);
        }
        printf("\n");
    }
    */
}