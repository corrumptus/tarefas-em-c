//Ex. 1
/*
    Pergunta:
        Explique a diferença entre: p++; (*p)++; *(p++);
    Resposta:
        p++;:
            p pode ser uma variável assim como pode ser uma variável ponteiro.
            Caso uma variável normal, a linha de comando irá fazer com que o valor seja incrementado em 1.
            Caso um ponteiro, a linha de comando irá fazer com que o ponteiro avance um tamanho de seu tipo.
        (*p)++;:
            incrementa em 1 o valor do endereço apontado.
        *(p++);:
            indica o valor do próximo bloco de bytes do tipo de p e faz p apontar para o mesmo.
*/

//Ex. 2
/*
    Pergunta:
        O que quer dizer a instrução *(p+10);?
    Resposta:
        indica o valor do bloco de bytes que está a frente de p em 10 vezes o tipo de p.
*/

//Ex. 3
/*
    Pergunta:
        Considere o seguinte trecho de programa:
            int i=3, j=5;
            int *p, *q;
            p = &i;
            q = &j;
        Qual é o valor das seguintes expressões?
        a) p == &i;
        b) *p - *q
        c) **&p
        d) 3* - *p/(*q)+7
    Resposta:
        a) 1
        b) -2
        c) 3
        d) (3* - *p/(*q)+7 -> 3* - 3/5+7 -> -9/5+7 -> -1+7 -> 6) 6
    p.s.: se não possui parenteses, o programa segue a ordem.
    Como i, j, p e q são do tipo int, logo int sobre int resulta apenas no inteiro da conta.
*/

//Ex. 4
/*
    Pergunta:
        Qual será a saída do programa a seguir supondo que i ocupa o endereço 4094 na
        memória?
        main() {
            int i=5, *p;
            p = &i;
            printf(“%x %d %d %d %d \n”, p,*p+2,**&p,3**p,**&p+4);
        }
    Resposta:
        4094 7 5 15 9 

*/

//Ex. 5
/*
    Pergunta:
        Se i e j são variáveis inteiras e p e q ponteiros para int, quais das seguintes
        expressões de atribuição são ilegais?
        a) p = &i;
        b) *q = &j;
        c) p = &*&i;
        d) i = (*&)j;
        e) i = *&j;
        f) i = *&*&j;
        g) q = *p;
        h) i = (*p)++ + *q
    Resposta:
        b, d, g.
        p.s.: aparentemente não foi intensional, mas h estaria errada pois faltaria o ponto e virgula ao final da linha.
*/

//Ex. 6
/*
    Pergunta:
        Quais serão as saídas do seguinte programa?
        #include <stdio.h>
        int main() {
            int valor;
            int *p1;
            float temp;
            float *p2;
            char aux;
            char *nome = "Algoritmos";
            char *p3;
            int idade;
            int vetor[3];
            int *p4;
            int *p5;
            // (a)
            valor = 10;
            p1 = &valor;
            *p1 = 20;
            printf("(a) %d \n", valor);
            // (b)
            temp = 26.5;
            p2 = &temp;
            *p2 = 29.0;
            printf("(b) %.1f \n", temp);
            // (c)
            p3 = &nome[0];
            aux = *p3;
            printf("(c) %c \n", aux);
            // (d)
            p3 = &nome[4];
            aux = *p3;
            printf("(d) %c \n", aux);
            // (e)
            p3 = nome;
            printf("(e) %c \n", *p3);
            // (f)
            p3 = p3 + 4;
            printf("(f) %c \n", *p3);
            // (g)
            p3--;
            printf("(g) %c \n", *p3);
            // (h)
            vetor[0] = 31;
            vetor[1] = 45;
            vetor[2] = 27;
            p4 = vetor;
            idade = *p4;
            printf("(h) %d \n", idade);
            // (i)
            p5 = p4 + 1;
            idade = *p5;
            printf("(i) %d \n", idade);
            // (j)
            p4 = p5 + 1;
            idade = *p4;
            printf("(j) %d \n", idade);
            // (l)
            p4 = p4 - 2;
            idade = *p4;
            printf("(l) %d \n", idade);
            // (m)
            p5 = &vetor[2] - 1;
            printf("(m) %d \n", *p5);
            // (n)
            p5++;
            printf("(n) %d \n", *p5);
            return(0);
        }
    Resposta:
        (a) 20
        (b) 29.0
        (c) A
        (d) r
        (e) A
        (f) r
        (g) o
        (h) 31
        (i) 45
        (j) 27
        (l) 31
        (m) 45
        (n) 27
*/

//Ex. 7
/*
    Pergunta:
        Qual é o resultado do seguinte programa?
        #include <stdio.h>
        int main() {
            float vet[5] = {1.1,2.2,3.3,4.4,5.5}, float *f;
            int i;
            f = vet;
            printf("contador/valor/valor/endereco/endereco");
            for (i = 0 ; i <= 4 ; i++) {
                printf("\ni = %d",i);
                printf(" vet[%d] = %.1f",i, vet[i]);
                printf(" *(f + %d) = %.1f",i, *(f+i));
                printf(" &vet[%d] = %X",i, &vet[i]);
                printf(" (f + %d) = %X",i, f+i);
            }
        }
    Resposta:
        contador/valor/valor/endereco/endereco
        i = 0 vet[0] = 1.1 *(f + 0) = 1.1 &vet[0] = 500 (f + 0) = 500
        i = 1 vet[1] = 2.2 *(f + 1) = 2.2 &vet[1] = 504 (f + 1) = 504
        i = 2 vet[2] = 3.3 *(f + 2) = 3.3 &vet[2] = 508 (f + 2) = 508
        i = 3 vet[3] = 4.4 *(f + 3) = 4.4 &vet[3] = 512 (f + 3) = 512
        i = 4 vet[4] = 5.5 *(f + 4) = 5.5 &vet[4] = 516 (f + 4) = 516
        p.s.: para a conclusão desse exercicio, é preciso supor uma posição inicial de memória para vet
        o qual, irei assumir 500.
*/

//Ex. 8
/*
    Pergunta:
        Assumindo que pulo[] é um vetor do tipo int, quais das seguintes expressões
        referenciam o valor do terceiro elemento do vetor?
        a) *(pulo + 2)
        b) *(pulo + 4)
        c) pulo + 4
        d) pulo + 2
    Resposta:
        a) pois pulo se refere, em posição de memória, ao 1º elemento(índice 0), portanto deveriamos somar mais 2 blocos para
        obtermos o 3º elemento. Por fim, para obtermos o valor usasse o operador de conteúdo (*).
*/

//Ex. 9
/*
    Pergunta:
        Suponha a seguinte declaração: int mat[4], *p, x; Quais expressões são
        válidas? Justifique:
        a) p = mat + 1;
        b) p = mat++;
        c) p = ++mat;
        d) x = (*mat)++;
    Resposta:
        a, d.
        b está errada pois mat é um ponteiro imutável, logo a posição de memória que ele armazena não pode ser modificada.
        c está errada pois mat é um ponteiro imutável, logo a posição de memória que ele armazena não pode ser modificada.
        p.s.: lembrando que o operador aritmético de incremento(++) atribui um novo valor.
*/

//Ex. 10
/*
    Pergunta:
        O que fazem os seguintes programas?
        #include <stdio.h>
        main() {
            int vet[] = {4,9,13};
            int i;
            for (i=0;i<3;i++) {
                printf("%d ",*(vet+i));
            }
        }

        #include <stdio.h>
        main() {
            int vet[] = {4,9,13};
            int i;
            for (i=0;i<3;i++) {
                printf("%X ",vet+i);
            }
        }

        #include <stdio.h>
        main() {
            int vet[] = {4,9,12};
            int i,*ptr;
            ptr = vet;
            for(i = 0 ; i < 3 ; i++) {
                printf("%d ",*ptr++);
            }
        }

        #include <stdio.h>
        main(){
            int vet[] = {4,9,12};
            int i,*ptr;
            ptr = vet;
            for(i = 0 ; i < 3 ; i++) {
                printf("%d ",(*ptr)++);
            }
        }
    Resposta:
        1º programa:
            - inicializa o vetor de inteiros vet e atribui a ele os valores 4, 9 e 13.
            - inicializa a variável i.
            - inicia um loop for controlado por i que ao rodar faz (ao final do processo, serão 3 execuções do loop):
                - imprime o valor do conteúdo da posição de memória de vet mais i vezes o tamanho de 1 inteiro e um espaço.

        2º programa:
            - inicializa o vetor de inteiros vet e atribui a ele os valores 4, 9 e 13.
            - inicializa a variável i.
            - inicia um loop for controlado por i que ao rodar faz (ao final do processo, serão 3 execuções do loop):
                - imprime o endereço de vet mais i vezes o tamanho de 1 inteiro e um espaço.
        
        3º programa:
            - inicializa o vetor de inteiros vet e atribui a ele os valores 4, 9 e 13.
            - inicializa a variável i e o ponteiro ptr.
            - atribui o endereço inicial do vetor vet para ptr.
            - inicia um loop for controlado por i que ao rodar faz (ao final do processo, serão 3 execuções do loop):
                - imprime o conteúdo do endereço de ptr e avança 1 bloco de bytes do tamanho de ptr no endereço que ele armazena e um espaço.
        
        4º programa:
            - inicializa o vetor de inteiros vet e atribui a ele os valores 4, 9 e 13.
            - inicializa a variável i e o ponteiro ptr.
            - atribui o endereço inicial do vetor vet para ptr.
            - inicia um loop for controlado por i que ao rodar faz (ao final do processo, serão 3 execuções do loop):
                - imprime o conteúdo do endereço referenciado por ptr e depois o incrementa em 1 e um espaço.
                p.s.: perceba que ele sempre vai mostrar a mesma posição do vetor e irá incrementar apenas o valor do índice 0.
*/

//Ex. 11
/*
    Pergunta:
        Qual a saída do programa a seguir?
        #include <stdio.h>
        main() {
            int t, i, M[3][4];
            for (t=0; t<3; ++t)
                for (i=0; i<4; ++i)
                    M[t][i] = (t*4)+i+1;
            for (t=0; t<3; ++t) {
                for (i=0; i<4; ++i)
                    printf ("%3d ", M[t][i]);
                printf ("\n");
            }
        }
    Resposta:
        1 2 3 4
        5 6 7 8
        9 10 11 12

*/

//Ex. 12
/*
    Pergunta:
        Qual o valor de y no final do programa?
        # include <stdio.h>
        main() {
            int y, *p, x;
            y = 0;
            p = &y;
            x = *p;
            x = 4;
            (*p)++;
            x;
            (*p) += x;
            printf ("y = %d\n", y);
        }
    Resposta:
        y = 5

*/

//Ex. 13
/*
    Pergunta:
        Reescreva o programa abaixo usando ponteiros para acessar cada posição da matriz.
        main () {
            float matrix [50][50];
            int i,j;
            for (i=0;i<50;i++)
                for (j=0;j<50;j++)
                    matrix[i][j]=0.0;
        }
    Resposta:
        main() {
            float matrix[50][50];
            int i, j;
            for (i=0;i<50;i++)
                for (j=0;j<50;j++)
                    **(matrix + j + i*50) = 0.0;
        }
*/

//Ex. 14
/*
    Pergunta:
        Diga quais expressões abaixo são válidas. Considere as declarações:
        int vetor[10];
        int *ponteiro;
        a) vetor = vetor + 2;
        b) vetor++;
        c) vetor = ponteiro;
        d) ponteiro = vetor;
        e) ponteiro = vetor+2;
    Resposta:
        d, e são as expressões corretas.
        a, b, c não são corretas pois vetor é um ponteiro fixo, portanto não pode receber atribuições.
*/