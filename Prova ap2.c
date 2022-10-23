/* PROVA PR�TICA DE AP2S2 - II SEM DE 2022 - 17/10/2022

	Lucas Lazarini - SC3030121
	
	ATEN��O: VOC�S	 N�O DEVE MODIFICAR OS PROT�TIPOS DAS FUN��ES.
	N�o ser� permitido o uso de vari�veis globais dentro das fun��es.
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

/*QUEST�O 1 (2.0): Implemente a fun��o inserir_contato() que recebe por par�metro um ponteiro para um vetor
com capacidade para at� 200 registros de pessoas e um ponteiro para a posi��o do vetor na qual o registro 
ser� inserido pela fun��o. A fun��o dever� retornar 1, caso o contato tenha sido incluído com sucesso e -1,
caso contr�rio. A mensagem informando se o contato foi inclu�do com sucesso
ou n�o ser� impressa na fun��o submenu_agenda_contatos().*/
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

/*QUEST�O 2 (1.0): Implemente a fun��o buscar_contato() que receba por par�metro um ponteiro para um vetor
com registros de pessoas, o nome do contato e o contador indicando a quantidade de contatos armazenados
no vetor. A fun��o dever� retornar a posi��o (�ndice) do primeiro registro encontrado com aquele nome, 
caso ele exista e -1, caso ele n�o seja encontrado. A mensagem informando que o nome n�o foi encontrado 
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

/*QUEST�O 3 (1.0): Implemente a fun��o imprimir_contato() que receba por par�metro um ponteiro para um vetor
com registros de pessoas e o contador de contatos cadastrados. A fun��o dever� solicitar o nome do contato
como entrada e dever� transferir esse nome, juntamente com o vetor de contatos, por par�metros para a fun��o 
buscar_contato(), que verificar� se esse nome est� cadastrado. Se o retorno da fun��o buscar_contato() 
for maior ou igual a zero (ou seja, um �ndice v�lido), a fun��o imprimir_contato() dever� imprimir o telefone fixo,
o celular e a cidade daquele contato. Caso o retorno seja -1, deve apresentar uma mensagem 
informando que o nome n�o foi localizado na agenda de contatos.*/
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
		printf("Contato n�o encontrado, tente novamente\n");
}			    		

/*QUEST�O 4 (2.0): Implemente a fun��o excluir_contato() que recebe por par�metro um ponteiro para um vetor
de pessoas e um ponteiro para o contador de contatos cadastrados. A fun��o dever� retornar 1, caso o contato 
tenha sido exclu�do com sucesso e -1, caso o contato n�o tenha sido encontrado. A mensagem informando se o 
contato foi exclu�do ou n�o deve ser impressa pela fun��o submenu_agenda_contatos().
OBS: utilize a fun��o buscar_contato() para verificar se o contato existe na agenda. */
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

/*QUEST�O 5 (2.0): Desenvolva o c�digo da fun��o imprimir_vetor() que receber� por par�metro um 
ponteiro para um vetor com 100 elementos inteiros e percorrer� esse vetor imprimindo os seus 
elementos. Para percorrer o vetor, a fun��o dever� usar 4 ponteiros (p,q,r,s) de forma SIMULTÂNEA 
posicionados conforme seguem:
p: deve iniciar na posi��o 0
q: deve iniciar na posi��o 25
r: deve iniciar na posi��o 50
s: deve iniciar na posi��o 75
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

/*QUEST�O 6 (0.75): Desenvolva o c�digo da fun��o preencher_vetor() que receber� um ponteiro para 
um vetor vazio por par�metro e o preencher� automaticamente com 100 valores inteiros.*/
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

//Fun��o menu(): fun��o que apresenta o menu de op��es para o usu�rio
void menu() {
	printf("**************Menu de Op��es:****************\n\n");
	printf("\t1. Acessar submenu Agenda de Contatos\n");
	printf("\t2. Imprimir vetor usando 4 ponteiros\n ");
	printf("\t3. Sair\n");
	printf("\nEscolha uma op��o entre 1 e 2 ou digite 3 para encerrar o programa\n");
}

//Chamada das fun��es: (0.75)
void submenu_agenda_contatos(struct Pessoa contatos[], int *cont){
	int op, flag;
	
	do {	
		printf("\n**************Submenu Agenda:****************\n\n");
		printf("\t1. Inserir contato na agenda\n ");
		printf("\t2. Imprimir dados de um contato\n");
		printf("\t3. Excluir um contato\n");
		printf("\t4. Voltar ao menu principal\n");
		printf("\nEscolha uma op��o entre 1 e 3 ou digite 4 para voltar ao menu principal\n");
		scanf("%d",&op);
	
		switch (op) {
			case 1:
				if (inserir_contato(contatos, &(*cont)) == 1) {
					printf("Contato inserido com sucesso\n");
				} else {
					printf("Contato n�o inserido, tente novamente\n");
				}
				break;							
			case 2:
				imprimir_contato(contatos, *cont);
				break;			
			case 3:
				if (excluir_contato(contatos, &(*cont)) == 1)
					printf("Exclus�o concluida com sucesso\n");
				else
					printf("contato n�o encontrado, tente novamente\n");
				break;
			case 4:
				printf("Voltando para o menu principal\n");
				system("cls");
				break;
			default: printf("Op��o incorreta!\n");		
		}	
	} while(op >= 1 && op < 4);
}

//Chamada das fun��es: (0.5)
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
				printf("Op��o incorreta!\n");
		}	
	} while (op >= 1 && op < 3);	
}
