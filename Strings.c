#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    //Ex. 1
    /*
    #define n 50
    char palavra[n], inversa[n]; int i = 0, igual = 1;
    printf("Digite uma palavra\n");
    gets(palavra);
    strcpy(inversa, strrev(palavra));
    if (strcmp(palavra, inversa)) {
        igual = 0;
    }
    switch (igual) {
        case 1:
            printf("A palavra %s é um palindromo", palavra);
            break;
        case 0:
            printf("A palavra %s não é um palindromo", palavra);
    }
    // ovo, ana, renner, mirim, maroram
    */
    
    
    //Ex. 2
    /*
    #define n 50
    char nome[n], copia[5];
    printf("Digite um nome\n");
    gets(nome);
    strncpy(copia, nome, 4);
    puts(copia);
    // lucas, victor, renan, gabriela
    */
    
    
    //Ex. 3
    /*
    #define n 10
    char nomes[n][40], inter[40]; int i, j;
    printf("Digite %d nomes", n);
    for (i=0;i<n;i++) {
        gets(nomes[i]);
    }
    for (i=0;i<n;i++) {
        for (j=0;j<n-1;j++) {
            if (strcmp(nomes[j],nomes[j+1]) >= 1) {
                strcpy(inter, nomes[j]);
                strcpy(nomes[j], nomes[j+1]);
                strcpy(nomes[j+1], inter);
            }
        }
    }
    for (i=0;i<n;i++) {
        printf("\n%s", nomes[i]);
    }
    /*
    lucas
    gabi
    renan
    victor
    gabriel
    julia
    vitor
    vitoria
    angela
    solange
    */
    
    
    //Ex. 4
    /*
    #define n 10
    char nomes[n][40], letra; int i;
    printf("Digite %d nomes\n", n);
    fflush(stdin);
    for (i=0;i<n;i++) {
        gets(nomes[i]);
    }
    printf("Digite uma letra\n");
    scanf("%c", &letra);
    for (i=0;i<n;i++) {
        if (strchr(nomes[i], letra)) {
        printf("%s\n", nomes[i]);
        }
    }
    /*
    lucas
    gabi
    renan
    victor
    gabriela
    julia
    vitor
    vitoria
    angela
    solange
    */
    
    
    //Ex. 5
    /*
    char nome[40];
    printf("Digite um nome\n");
    gets(nome);
    printf("O nome \"%s\" possui %d letras", nome, strlen(nome));
    // lucas
    */
    
    
    //Ex. 6
    /*
    #define n 10
    char nome[n], snome[n], cnome[2*n+1] = "";
    printf("Digite um nome e um sobrenome\n");
    scanf("%s", &nome);
    scanf("%s", &snome);
    strcat(cnome, nome);
    strcat(cnome, " ");
    strcat(cnome, snome);
    printf("%s\n%d\n%c\n%c", cnome, strlen(cnome), cnome[0], cnome[strlen(cnome)-1]);
    */
    
    
    //Ex. 7
    /*
    char nome[40];
    printf("Digite um nome\n");
    gets(nome);
    strlwr(nome);
    puts(nome);
    strupr(nome);
    puts(nome);
    */
}
