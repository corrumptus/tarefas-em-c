/* PROVA PRÁTICA DE AP2S2 - II SEM DE 2022 - 17/10/2022
	Coloque aqui seu nome completo e prontuário
	
	ATENÇÃO: VOCÊ NÃO DEVE MODIFICAR OS PROTÓTIPOS DAS FUNÇÕES. 
	Não será permitido o uso de variáveis globais dentro das funções. 
*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

struct Pessoa {
	char nome[40];
	char tel_fixo[15], cel[15], cidade [40]; 	
};

/*QUESTÃO 1 (2.0): Implemente a função inserir_contato() que recebe por parámetro um ponteiro para um vetor
com capacidade para até 200 registros de pessoas e um ponteiro para a posição do vetor na qual o registro 
será inserido pela função. A função deverá retornar 1, caso o contato tenha sido incluído com sucesso e -1, 
caso contrário. A mensagem informando se o contato foi incluído com sucesso
ou não será impressa na função submenu_agenda_contatos().*/
int inserir_contato(struct Pessoa *agenda, int *pos) 
{   
	printf("\nInserindo um novo contato na agenda:\n");

}

/*QUESTÃO 2 (1.0): Implemente a função buscar_contato() que receba por parámetro um ponteiro para um vetor
com registros de pessoas, o nome do contato e o contador indicando a quantidade de contatos armazenados
no vetor. A função deverá retornar a posição (índice) do primeiro registro encontrado com aquele nome, 
caso ele exista e -1, caso ele não seja encontrado. A mensagem informando que o nome não foi encontrado 
(quando acontecer) deve ser impressa em imprimir_contato().*/
int buscar_contato(struct Pessoa *contatos, char nome[], int cont)
{	
	printf("\nBuscando um contato na agenda:\n");


}
/*QUESTÃO 3 (1.0): Implemente a função imprimir_contato() que receba por parámetro um ponteiro para um vetor
com registros de pessoas e o contador de contatos cadastrados. A função deverá solicitar o nome do contato
como entrada e deverá transferir esse nome, juntamente com o vetor de contatos, por parámetros para a função 
buscar_contato(), que verificará se esse nome está cadastrado. Se o retorno da função buscar_contato() 
for maior ou igual a zero (ou seja, um índice válido), a função imprimir_contato() deverá imprimir o telefone fixo,
o celular e a cidade daquele contato. Caso o retorno seja -1, deve apresentar uma mensagem 
informando que o nome não foi localizado na agenda de contatos.*/
void imprimir_contato(struct Pessoa contatos[], int cont)
{	
	printf("\nImprimindo um contato da agenda:\n");

}			    		

/*QUESTÃO 4 (2.0): Implemente a função excluir_contato() que recebe por parámetro um ponteiro para um vetor
de pessoas e um ponteiro para o contador de contatos cadastrados. A função deverá retornar 1, caso o contato 
tenha sido excluído com sucesso e -1, caso o contato não tenha sido encontrado. A mensagem informando se o 
contato foi excluído ou não deve ser impressa pela função submenu_agenda_contatos().
OBS: utilize a função buscar_contato() para verificar se o contato existe na agenda. */
int excluir_contato(struct Pessoa agenda[], int *pos) 
{   
	printf("\nExcluindo um contato da agenda:\n");


}

/*QUESTÃO 5 (2.0): Desenvolva o código da função imprimir_vetor() que receberá por parámetro um 
ponteiro para um vetor com 100 elementos inteiros e percorrerá esse vetor imprimindo os seus 
elementos. Para percorrer o vetor, a função deverá usar 4 ponteiros (p,q,r,s) de forma SIMULTÂNEA 
posicionados conforme seguem:
p: deve iniciar na posição 0
q: deve iniciar na posição 25
r: deve iniciar na posição 50
s: deve iniciar na posição 75
*/
void imprimir_vetor(int *vet)
{	
	printf("\nImprimindo o vetor de inteiros usando quatros ponteiros\n");

}

/*QUESTÃO 6 (0.75): Desenvolva o código da função preencher_vetor() que receberá um ponteiro para 
um vetor vazio por parámetro e o preencherá automaticamente com 100 valores inteiros.*/
void preencher_vetor(int vet[])
{	
	printf("\nPreenchendo automaticamente o vetor de inteiros\n");


}

//função menu(): função que apresenta o menu de opções para o usuário
void menu(){
	printf("**************Menu de Opções:****************\n\n");
	printf("\t1. Acessar submenu Agenda de Contatos\n");
	printf("\t2. Imprimir vetor usando 4 ponteiros\n ");
	printf("\t3. Sair\n");
	printf("\nEscolha uma opção entre 1 e 2 ou digite 3 para encerrar o programa\n");
}
//Chamada das funções: (0.75)
void submenu_agenda_contatos(struct Pessoa contatos[], int *cont){
	int op, flag;

	do
	{		
		printf("**************Submenu Agenda:****************\n\n");
		printf("\t1. Inserir contato na agenda\n ");
		printf("\t2. Imprimir dados de um contato\n");
		printf("\t3. Excluir um contato\n");
		printf("\t4. Voltar ao menu principal\n");
		printf("\nEscolha uma opção entre 1 e 3 ou digite 4 para voltar ao menu principal\n");
		scanf("%d",&op);

		switch (op){
			case 1:
			/*INSIRA AQUI A CHAMADA DA função inserir_contato_agenda(), RESPEITANDO OS 
			PARÁMETROS CONFORME O PROTÓTIPO DA função*/			

			case 2:
			/*INSIRA AQUI A CHAMADA DA função imprimir_contato(), RESPEITANDO OS 
			PARÁMETROS CONFORME O PROTÓTIPO DA função*/

			case 3:
			/*INSIRA AQUI A CHAMADA DA função excluir_contato(), RESPEITANDO OS 
			PARÁMETROS CONFORME O PROTÓTIPO DA função*/

			case 4:
				printf("Voltando para o menu principal\n");
				break;
			default: printf("opção incorreta!\n");		
		}	
	} while(op >= 1 && op <4);
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
			case 1: system("cls");
				//CHAMANDO O SUBMENU AGENDA
				submenu_agenda_contatos(Agenda, &cont);			
				break;
			case 2: system("cls");
			   int vetor[100];
			   /*INSIRA AQUI AS CHAMADAS DAS FUNÇÕES preencher_vetor() e imprimir_vetor(), RESPEITANDO OS 
			   PARÁMETROS E O VALOR DE RETORNO (QUANDO HOUVER), CONFORME O PROTÓTIPO DE CADA função*/
			   break;			
			case 3: system("cls");
			   printf("\nEncerrando o programa...\n"); 
			   break;
			default: printf("opção incorreta!\n");
		}	
	} while (op >= 1 && op <3);	
}