#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct Funcionario {
	int cod, num_dep;
	char cargo[50], nome[50];
	float salario;
};


int procurar(struct Funcionario funcs[], int cod, int pos) {
	int i;
	for (i=0;i<pos;i++) {
		if (cod == funcs[i].cod) {
            return i;
		}
	}
	return -1;
}

void inserir(struct Funcionario funcs[], int *pos, int max) {
	if (*pos <= max) {
		printf("Digite o código do funcionário\n");
		scanf("%d", &funcs[*pos].cod);
		fflush(stdin);
		if (procurar(funcs, funcs[*pos].cod, *pos) == -1) {
			printf("Digite o nome\n");
			gets(funcs[*pos].nome);
			printf("Digite o cargo\n");
			gets(funcs[*pos].cargo);
			printf("Digite o número do departamento\n");
			scanf("%d", &funcs[*pos].num_dep);
			printf("Digite o salário\n");
			scanf("%f", &funcs[*pos].salario);
	    	(*pos)++; //correção
	    } else {
	        printf("Código já cadastrado, tente novamente\n");
    	}
	} 
}

void excluir(struct Funcionario funcs[], int i, int *pos) {
    int j;
    for (j=i; j<*pos-1; j++) {
        strcpy(funcs[j].nome, funcs[j+1].nome);
        strcpy(funcs[j].cargo, funcs[j+1].cargo);
        funcs[j].cod = funcs[j+1].cod;
        funcs[j].num_dep = funcs[j+1].num_dep;
        funcs[j].salario = funcs[j+1].salario;
    }
    (*pos)--;
    printf("Excluido\n");
}

int main() {
	#define max 5
	struct Funcionario funcs[max] = {};
	int i, pos=0, op=1, cod, codigo;
	setlocale(LC_ALL, "Portuguese");
	while (op > 0 && op < 4) {
		printf("Digite qual opção deseja\n1- Inserir funcionário\n2- Procurar um funcionário\n3- Remover um funcionário\n0- sair\n");
		scanf("%d", &op);
		fflush(stdin);
		switch (op) {
			case 1:
				if (pos<max) {
					inserir(funcs, &pos, max);
				} else {
					printf("Todas as vagas ja foram preenchidas\n");
				}					
				break;
			case 2:
				printf("Digite o codigo do funcionário desejado\n");
				scanf("%d", &cod);
				codigo = procurar(funcs, cod, pos);
				if (codigo == -1) {
					printf("Funcionário não encontrado\n");
				} else {
					printf("--infos--\nnome: %s\ncargo: %s\ncódigo: %d\nnúmero do departamento: %d\nsalário: %f\n", funcs[codigo].nome, funcs[codigo].cargo, funcs[codigo].cod, funcs[codigo].num_dep, funcs[codigo].salario);
				}
				break;
			case 3:
                printf("Digite o código do funcionário desejado\n");
                scanf("%d", &cod);
                codigo = procurar(funcs, cod, pos);
				if (codigo == -1) {
					printf("Funcionário não encontrado\n");
				} else {
					excluir(funcs, codigo, &pos);
				}
				break;
            default:
                printf("Opção inválida\n");
		}
	}
}
