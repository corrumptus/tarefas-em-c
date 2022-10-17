/* PROVA PRÁTICA DE AP2S2 - II SEM DE 2022 - 17/10/2022

	Lucas Lazarini - SC3030121
	
	ATENÇÃO: VOCÊS	 NÃO DEVE MODIFICAR OS PROTÓTIPOS DAS FUNÇÕES. 
	Não será permitido o uso de variáveis globais dentro das funções. 
*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
	char nome[40];
	char tel_fixo[15];
	char cel[15];
	char cidade [40]; 	
};

/*QUESTÃO 1 (2.0): Implemente a função inserir_contato() que recebe por parâmetro um ponteiro para um vetor
com capacidade para até 200 registros de pessoas e um ponteiro para a posição do vetor na qual o registro 
será inserido pela função. A função deverá retornar 1, caso o contato tenha sido incluÃ­do com sucesso e -1, 
caso contrário. A mensagem informando se o contato foi incluído com sucesso
ou não será impressa na função submenu_agenda_contatos().*/
int inserir_contato(struct Pessoa *agenda, int *pos) {
	if (*pos <= 200) {
		fflush(stdin);
		printf("\nInserindo um novo contato na agenda:\n");
		printf("Digite o nome do contato:\n");
		gets(agenda[*pos].nome);
		printf("Digite o telefone do contato\n");
		gets(agenda[*pos].tel_fixo);
		printf("Digite o celular do contato\n");
		gets(agenda[*pos].cel);
		printf("Digite a cidade do contato\n");
		gets(agenda[*pos].cidade);
		(*pos)++;
		return 1;
	} else {
		printf("Agenda cheia, apague contatos e tente novamente\n");
		return -1;
	}
}

/*QUESTÃO 2 (1.0): Implemente a função buscar_contato() que receba por parâmetro um ponteiro para um vetor
com registros de pessoas, o nome do contato e o contador indicando a quantidade de contatos armazenados
no vetor. A função deverá retornar a posição (índice) do primeiro registro encontrado com aquele nome, 
caso ele exista e -1, caso ele não seja encontrado. A mensagem informando que o nome não foi encontrado 
(quando acontecer) deve ser impressa em imprimir_contato().*/
int buscar_contato(struct Pessoa *contatos, char nome[], int cont) {	
	int i;
	printf("\nBuscando um contato na agenda:\n");
	for (i=0;i<cont;i++) {
		if (strcmp(contatos[i].nome, nome) == 0)
			return i;
	}
	return -1;	
}

/*QUESTÃO 3 (1.0): Implemente a função imprimir_contato() que receba por parâmetro um ponteiro para um vetor
com registros de pessoas e o contador de contatos cadastrados. A função deverá solicitar o nome do contato
como entrada e deverá transferir esse nome, juntamente com o vetor de contatos, por parâmetros para a função 
buscar_contato(), que verificará se esse nome está cadastrado. Se o retorno da função buscar_contato() 
for maior ou igual a zero (ou seja, um índice válido), a função imprimir_contato() deverá imprimir o telefone fixo,
o celular e a cidade daquele contato. Caso o retorno seja -1, deve apresentar uma mensagem 
informando que o nome não foi localizado na agenda de contatos.*/
void imprimir_contato(struct Pessoa contatos[], int cont) {	
	char nome[40];
	int indice = 0;
	printf("\nImprimindo um contato da agenda:\n");
	printf("Digite o nome do contato:\n");
	fflush(stdin);
	gets(nome);
	indice = buscar_contato(contatos, nome, cont);
	if (indice != -1)
		printf("Telefone: %s\nCelular: %s\nCidade: %s\n", contatos[indice].tel_fixo, contatos[indice].cel, contatos[indice].cidade);
	else
		printf("Contato não encontrado, tente novamente\n");
}			    		

/*QUESTÃO 4 (2.0): Implemente a função excluir_contato() que recebe por parâmetro um ponteiro para um vetor
de pessoas e um ponteiro para o contador de contatos cadastrados. A função deverá retornar 1, caso o contato 
tenha sido excluído com sucesso e -1, caso o contato não tenha sido encontrado. A mensagem informando se o 
contato foi excluído ou não deve ser impressa pela função submenu_agenda_contatos().
OBS: utilize a função buscar_contato() para verificar se o contato existe na agenda. */
int excluir_contato(struct Pessoa agenda[], int *pos) {   
	char nome[40];
	int indice = 0, i, j;
	printf("\nExcluindo um contato da agenda:\n");
	printf("Informe o nome do contato a ser excluido\n");
	fflush(stdin);
	gets(nome);
	indice = buscar_contato(agenda, nome, *pos);
	if (indice != -1) {
		for (i=indice;i<(*pos)-1;i++) {
			strcpy(agenda[i].nome, agenda[i+1].nome);
			strcpy(agenda[i].tel_fixo, agenda[i+1].tel_fixo);
			strcpy(agenda[i].cel, agenda[i+1].cel);
			strcpy(agenda[i].cidade, agenda[i+1].cidade);
		}
		(*pos)--;
		return 1;
	} else
		return -1;
}

/*QUESTÃO 5 (2.0): Desenvolva o código da função imprimir_vetor() que receberá por parâmetro um 
ponteiro para um vetor com 100 elementos inteiros e percorrerá esse vetor imprimindo os seus 
elementos. Para percorrer o vetor, a função deverá usar 4 ponteiros (p,q,r,s) de forma SIMULTÃ‚NEA 
posicionados conforme seguem:
p: deve iniciar na posição 0
q: deve iniciar na posição 25
r: deve iniciar na posição 50
s: deve iniciar na posição 75
*/
void imprimir_vetor(int *vet) {	
	printf("\nImprimindo o vetor de inteiros usando quatros ponteiros\n");
	int *p, *q, *r, *s;
	p = vet, q = (vet+25), r=(vet+50), s=(vet+75);
	while (p < (vet+25)) {
		printf("%d ", *(p++));
		printf("%d ", *(q++));
		printf("%d ", *(r++));
		printf("%d ", *(s++));
	}
	printf("\n");
}

/*QUESTÃO 6 (0.75): Desenvolva o código da função preencher_vetor() que receberá um ponteiro para 
um vetor vazio por parâmetro e o preencherá automaticamente com 100 valores inteiros.*/
void preencher_vetor(int vet[]) {	
	int  base[2] = {0, 1}, i;
	vet[0] = 0;
	vet[1] = 1;
	printf("\nPreenchendo automaticamente o vetor de inteiros\n");
	for (i=2;i<100;i++) {
		vet[i] = base[0]+base[1];
		base[0] = base[1];
		base[1] = vet[i];
	}
}

//Função menu(): função que apresenta o menu de opções para o usuário
void menu() {
	printf("**************Menu de Opções:****************\n\n");
	printf("\t1. Acessar submenu Agenda de Contatos\n");
	printf("\t2. Imprimir vetor usando 4 ponteiros\n ");
	printf("\t3. Sair\n");
	printf("\nEscolha uma opção entre 1 e 2 ou digite 3 para encerrar o programa\n");
}

//Chamada das funções: (0.75)
void submenu_agenda_contatos(struct Pessoa contatos[], int *cont){
	int op, flag;
	
	do {	
		printf("\n**************Submenu Agenda:****************\n\n");
		printf("\t1. Inserir contato na agenda\n ");
		printf("\t2. Imprimir dados de um contato\n");
		printf("\t3. Excluir um contato\n");
		printf("\t4. Voltar ao menu principal\n");
		printf("\nEscolha uma opção entre 1 e 3 ou digite 4 para voltar ao menu principal\n");
		scanf("%d",&op);
	
		switch (op) {
			case 1:
				if (inserir_contato(contatos, &(*cont)) == 1) {
					printf("Contato inserido com sucesso\n");
				} else {
					printf("Contato não inserido, tente novamente\n");
				}
				break;							
			case 2:
				imprimir_contato(contatos, *cont);
				break;			
			case 3:
				if (excluir_contato(contatos, &(*cont)) == 1)
					printf("Exclusão concluida com sucesso\n");
				else
					printf("contato não encontrado, tente novamente\n");
				break;
			case 4:
				printf("Voltando para o menu principal\n");
				system("cls");
				break;
			default: printf("Opção incorreta!\n");		
		}	
	} while(op >= 1 && op < 4);
}

//Chamada das funções: (0.5)
main()
{	int op, cont = 0;
	struct Pessoa Agenda[200];  
	setlocale(LC_ALL, "Portuguese");
		
	do
	{	
		menu();
		scanf("%d",&op);
		fflush(stdin);
		switch (op){
			case 1:
				system("cls");
				submenu_agenda_contatos(Agenda, &cont);			
				break;
			case 2:
				system("cls");
			    int vetor[100];
			    preencher_vetor(vetor);
			    imprimir_vetor(vetor);
			    break;			
			case 3:
				system("cls");
			    printf("\nEncerrando o programa...\n"); 
			    break;
			default:
				printf("Opção incorreta!\n");
		}	
	} while (op >= 1 && op < 3);	
}
