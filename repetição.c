#include <stdio.h>

main() {
    //Estruturas de repetição
     
    //Ex. 1
    /*
    int idade, Q_idade=0, t, j; float peso, altura, med_idade, med_altura=0, porce_mpeso=0;
    #define times 5
    #define jogadores 11
    for (t=0;t<times;t++) {
        med_idade = 0;
        for (j=0;j<jogadores; j++) {
            printf("Digite a idade, o peso, a altura do jogador:\n");
            scanf("%d%f%f",&idade,&peso,&altura);
            if (idade<18) Q_idade++;
            med_idade = med_idade + idade;
            med_altura = med_altura + altura;
            if (peso>80) porce_mpeso++;
        }
        med_idade = med_idade/jogadores;
        printf("A média das idades do %dº time é de %f", t,med_idade);
    }
    med_altura = med_altura/(times*jogadores);
    porce_mpeso= (porce_mpeso/(times*jogadores))*100;
    printf("A quantidade de jogaores que tem menos de 18 anos é de %d", Q_idade);
    printf("A altura média de todos os jogadores é de %f",med_altura);
    printf("A porcentagem de jogadores com peso acima de 80kg é de %f%",porce_mpeso);
    */
    
    //Ex. 2(for)
    /*
    int n, yn, i;
    printf("Digite um número para a verificação\n");
    scanf("%d",&n);
    if (n <= 1) {
        printf("O número não é primo");
    }
    else {
        yn = 1;
        for (i=2;i<n;i++) {
            if (n%i == 0) {
                yn = 0;
            }
        }
        if (yn == 1) {
            printf("O número é primo");
        }
        else {
            printf("O número não é primo");
        }
    }
    */
    
    //Ex. 2(while)
    /*
    int n, yn, i = 2; float result;
    printf("Digite um número para a verificação\n");
    scanf("%d",&n);
    if (n <= 1) {
        printf("O número não é um número primo");
    }
    else {
        yn = 1;
        while (i<n) {
            if (n%i == 0) {
                yn = 0;
            }
            i++;
        }
        if (yn == 1) {
            printf("O número é primo");
        }
        else {
            printf("O número não é primo");
        }
    }
    */
    
    //Ex. 2(do-while)
    /*
    int n, yn, i = 2;
    printf("Digite um número para a verificação\n");
    scanf("%d",&n);
    if (n <= 1) {
        printf("O número não é primo");
    }
    else {
        yn = 1;
        do {
            if (n%i == 0) {
                yn = 0;
            }
            i++;
        }
        while (i<n);
        if (yn == 1 || n == 2) {
            printf("O número é primo");
        }
        else {
            printf("O número não é primo");
        }
    }
    */
    
    //Ex. 3
    /*
    int n, i, n2;
    for (n=1;n<11;n++) {
        printf("\nTabuada do %d:",n);
        for (i=1;i<11;i++) {
            n2 = i*n;
            printf(" %d", n2);
        }
    }
    */
    
    //Ex. 4
    /*
    int n, i, n2;
    printf("Digite o número: ");
    scanf("%d",&n);
    if (n>0) {
        n2 = n;
        for (i=n-1;i>0;i--) {
            n2 = n2*i;
        }
        printf("O fatorial de %d é %d",n,n2);
    }
    else {
        if (n == 0) {
            printf("O fatorial de 0 é 1");
        }
        else {
            printf("O número não possui um fatorial");
        }
    }
    */
    
    //Ex. 5
    /*
    int notma=0, notmed=0, notme=-1, n=0;
    printf("Digite as nota do aluno(valores negativos param o censo)\n");
    while (n>=0) {
        scanf("%d", &n);
        if (n>=6) {
            notma++;
        }
        if (n<6 && n>=4) {
            notmed++;
        }
        if (n<4) {
            notme++;
        }
    }
    printf("O número de alunos que tiraram notas maiores ou iguais que 6 foram de %d\n", notma);
    printf("O número de alunos que tiraram notas entre 6 e 4 foram de %d\n", notmed);
    printf("O número de alunos que tiraram notas menores que 4 foram de %d", notme);
    */
    
    //Ex. 6
    /*
    int n, i; float sum=0, nabo, nbel;
    printf("Digite quantos termos terá a série\n");
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        nabo = i+1;
        nbel = 1+2*i;
        sum = sum + (nabo/nbel);
    }
    printf("O reultado da soma dos %d elementos da série S é de %f",n,sum);
    */
    
    //Ex. 7
    /*
    int n, ni=0, nm=1, nf, i;
    printf("Digite quantos números terá a sequência de Fibonacci\n");
    scanf("%d",&n);
    printf("A sequência, até o %dº, fica:",n);
    switch (n) {
        case 0:
            break;
        case 1:
            printf(" 0");
            break;
        case 2:
            printf(" 0 1");
            break;
        default:
            printf(" 0 1");
            for (i=0;i<n-2;i++) {
                nf= ni + nm;
                ni = nm;
                nm = nf;
                printf(" %d",nf);
            }
    }
    */
}