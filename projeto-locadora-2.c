#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> //somente para uso da função setlocale()
#include <ctype.h> //somente para uso da função isdigit()
#include <unistd.h> //somente para uso da função access()

struct cliente {
    char cpf[15];
    char nome[100];
    char endereco[500];
    char dataNasc[11];
    char telefone[15];
    char celular[16];
};

struct veiculo {
    int codigo;
    char descricao[1000];
    char categoria[50];
    char modelo[50];
    float capacidade;
    float combustivel;
    int ano;
};

struct aluguel {
    char dataretirada[11];
    char datadevolucao[11];
    char cpfcli[15];
    int codveic;
};

//funções de base
void data_extrai (char data[], char Ndata[]) {
    strcpy(Ndata, "    /  /  ");
    Ndata[0] = data[6];
    Ndata[1] = data[7];
    Ndata[2] = data[8];
    Ndata[3] = data[9];

    Ndata[5] = data[3];
    Ndata[6] = data[4];

    Ndata[8] = data[0];
    Ndata[9] = data[1];
}

int verifica_cpf (char cpf[]) {
    int i, j = 10, soma = 0;
    for (i=0;i<12;i++) {
        if (isdigit(cpf[i]))
            soma = soma + ((int) cpf[i] - 48)*j--;
    }
    soma = soma%11;
    if (soma == 0 || soma == 1)
        soma = 0;
    else
        soma = 11 - soma;
    if (((int) cpf[12]) - 48 != soma)
        return 0;
    soma = 0, j = 11;
    for (i=0;i<13;i++) {
        if (isdigit(cpf[i]) == 1)
            soma = soma + ((int) cpf[i] - 48)*j--;
    }
    soma = soma%11;
    if (soma == 0 || soma == 1)
        soma = 0;
    else
        soma = 11 - soma;
    if (((int) cpf[13]) - 48 != soma)
        return 0;
    return 1;
}

int verifica_data (char data[]) {
    char dia[3] = {'\0'}, mes[3] = {'\0'}, ano[5] = {'\0'};
    strncpy(dia, &data[0], 2);
    strncpy(mes, &data[3], 2);
    strncpy(ano, &data[6], 4);
    if (strcmp(dia, "01") < 0 || strcmp(dia, "31") > 0)
        return 0;
    else if (strcmp(mes, "01") < 0 || strcmp(mes, "12") > 0)
        return 0;
    else if (strcmp(ano, "1800") < 0)
        return 0;
    else if (!strcmp(mes, "01") && strcmp(dia, "31") > 0)
        return 0; 
    else if (!strcmp(mes, "02") && strcmp(dia, "28") > 0 && atoi(ano)%4 != 0)
        return 0;
    else if (!strcmp(mes, "02") && strcmp(dia, "29") > 0 && atoi(ano)%4 == 0)
        return 0;
    else if (!strcmp(mes, "03") && strcmp(dia, "31") > 0)
        return 0;
    else if (!strcmp(mes, "04") && strcmp(dia, "30") > 0)
        return 0;
    else if (!strcmp(mes, "05") && strcmp(dia, "31") > 0)
        return 0;
    else if (!strcmp(mes, "06") && strcmp(dia, "30") > 0)
        return 0;
    else if (!strcmp(mes, "07") && strcmp(dia, "31") > 0)
        return 0;
    else if (!strcmp(mes, "08") && strcmp(dia, "31") > 0)
        return 0;
    else if (!strcmp(mes, "09") && strcmp(dia, "30") > 0)
        return 0;
    else if (!strcmp(mes, "10") && strcmp(dia, "31") > 0)
        return 0;
    else if (!strcmp(mes, "11") && strcmp(dia, "30") > 0)
        return 0;
    else if (!strcmp(mes, "12") && strcmp(dia, "31") > 0)
        return 0;
    return 1;
}


void cpf_regex (char cpf[]) {
    fflush(stdin);
    int contnum = 0, i, j;
    char Ncpf[15] = {' ', ' ', ' ', '.', ' ', ' ', ' ', '.', ' ', ' ', ' ', '-', ' ', ' ', '\0'};
    gets(cpf);
    while (contnum != 11) {
        for (i=0;i<strlen(cpf);i++) {
            if (isdigit(cpf[i]))
                contnum++;
        }
        if (contnum == 11) {
            j=0;
            for (i=0;i<strlen(cpf);i++) {
                if (j == 3 || j == 7 || j == 11)
                    j++;
                if (isdigit(cpf[i]))
                    Ncpf[j++] = cpf[i];
            }
            if (verifica_cpf(Ncpf))
                strcpy(cpf, Ncpf);
            else {
                printf("Schweinhunds!\n");
                gets(cpf);
                contnum = 0;
            }
        } else {
            printf("You are trying my patience!\n");
            gets(cpf);
            contnum = 0;
        }
    }
}

void data_regex (char data[]) {
    fflush(stdin);
    int contnum = 0, i, j;
    char Ndata[11] = {' ', ' ', '\\', ' ', ' ', '\\', ' ', ' ', ' ', ' ', '\0'};
    gets(data);
    while (contnum != 8) {
        for (i=0;i<strlen(data);i++) {
            if (isdigit(data[i]))
                contnum++;
        }
        if (contnum == 8) {
            j=0;
            for (i=0;i<strlen(data);i++) {
                if (j == 2 || j == 5)
                    j++;
                if (isdigit(data[i]))
                    Ndata[j++] = data[i];
            }
            if (verifica_data(Ndata))
                strcpy(data, Ndata);
            else {
                printf("Schweinhunds!\n");
                gets(data);
                contnum = 0;
            }
        } else {
            printf("You are trying my patience!\n");
            gets(data);
            contnum = 0;
        }
    }
}

void celular_regex (char celular[]) {
    fflush(stdin);
    int contnum = 0, i, j;
    char Ncel[16] = {'(', ' ', ' ', ')', ' ', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ', ' ', '\0'};
    gets(celular);
    while (contnum != 11) {
        for (i=0;i<strlen(celular);i++) {
            if (isdigit(celular[i]))
                contnum++;
        }
        if (contnum == 11) {
            j=1;
            for (i=0;i<strlen(celular);i++) {
                if (j == 10)
                    j++;
                else if (j == 3)
                    j = 5;
                if (isdigit(celular[i]))
                    Ncel[j++] = celular[i];
            }
            strcpy(celular, Ncel);
        } else {
            printf("You are trying my patience!\n");
            gets(celular);
            contnum = 0;
        }
    }
}

void telefone_regex (char telefone[]) {
    fflush(stdin);
    int contnum = 0, i, j;
    char Ntel[15] = {'(', ' ', ' ', ')', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ', ' ', '\0'};
    gets(telefone);
    while (contnum != 10) {
        for (i=0;i<strlen(telefone);i++) {
            if (isdigit(telefone[i]))
                contnum++;
        }
        if (contnum == 10) {
            j=1;
            for (i=0;i<strlen(telefone);i++) {
                if (j == 9)
                    j++;
                else if (j == 3)
                    j = 5;
                if (isdigit(telefone[i]))
                    Ntel[j++] = telefone[i];
            }
            strcpy(telefone, Ntel);
        } else {
            printf("You are trying my patience!\n");
            gets(telefone);
            contnum = 0;
        }
    }
}

int veiculo_alugavel (struct aluguel *alu, int count, struct aluguel alu_teste, int indice) {
    int i;
    char Rdatapega[11], Rdatadevol[11], Rdataretirada[11], Rdatadevolucao[11];
    data_extrai(alu_teste.dataretirada, Rdatapega);
    data_extrai(alu_teste.datadevolucao, Rdatadevol);
    if (strcmp(Rdatapega, Rdatadevol) < 1) {
        for (i=0;i<count;i++) {
            if ((alu+i)->codveic == alu_teste.codveic && i != indice) {
                data_extrai((alu+i)->dataretirada, Rdataretirada);
                data_extrai((alu+i)->datadevolucao, Rdatadevolucao);
                if (strcmp(Rdatapega, Rdataretirada) < 0 && strcmp(Rdataretirada, Rdatadevol) < 0) {
                    return 0;
                }
                else if (!strcmp(Rdatapega, Rdataretirada) || !strcmp(Rdatadevol, Rdatadevolucao) || !strcmp(Rdatapega, Rdatadevolucao) || !strcmp(Rdatadevol, Rdataretirada)) {
                    return 0;
                }
                else if (strcmp(Rdatapega, Rdataretirada) > 0 && strcmp(Rdatadevol, Rdatadevolucao) < 0) {
                    return 0;
                }
                else if (strcmp(Rdatapega, Rdataretirada) > 0 && strcmp(Rdatadevol, Rdatadevolucao) > 0 && strcmp(Rdatapega, Rdatadevolucao) < 0) {
                    return 0;
                }
            }
        }
    } else
        return 0;
    return 1;
}

void mata_arquivo(char nome[]) {
    FILE *p;
    p = fopen(nome, "wb");
    fclose(p);
}

//funções de cliente
void extrai_cli(struct cliente *cli, int *max, int *count) {
    FILE *p;
    int n, i = 100, k = 10;
    *count = 0;
    struct cliente *aux;
    if (!access("clientes.txt", F_OK) && !access("clientes.txt", R_OK)) {
        p = fopen("clientes.txt" , "rb");
        if (p != NULL) {
            while (!feof(p)) {
                n = fread(cli+*count, sizeof(struct cliente), k, p);
                *count = *count + n;
                if (*count == *max && i > 0) {
                    aux = (struct cliente *) realloc (cli, (*max) + i);
                    if (aux)
                        cli = aux;
                    else
                        printf("The cart(Clientes) has almost reached the final terminus! %d left\n", (100-i));
                        i = i - 5;
                } else if (i == 0) {
                    printf("Jarate for everyone! I'm so, so SORRY!\n");
                    return;
                } else if (n < k)
                    k = 10 - n;
            }
        } else
            printf("I should have asked one of the other guys\n");
    } else
        p = fopen("clientes.txt", "wb");
    fclose(p);
}

void realloca_cli(struct cliente *cli, int *max) {
    struct cliente *aux = NULL;
    int i = 100;
    while (!aux) {
        aux = (struct cliente *) realloc (cli, (*max) + i);
        if (!aux)
            i = i - 5;
        else if (!aux && !i) {
            printf("Jarate for everyone! I'm so, so SORRY!\n");
            return;
        }
    }
}

int procura_cli(struct cliente *cli, int count, char cpf[]) {
    int i;
    for (i=0;i<count;i++) {
        if (!strcmp(cpf, (cli+i)->cpf))
            return i;
    }
    return -1;
}

void ordena_cli(struct cliente *cli, int count) {
    int i, j, trocou;
    struct cliente aux;
    for (i=count-1;i>0 && trocou;i--) { 
        trocou = 0;
        for (j=0;j<i;j++) {
            if (strcmp((cli+j)->cpf, (cli+j+1)->cpf) > 0) {
                strcpy(aux.cpf, (cli+j)->cpf);
                strcpy(aux.nome, (cli+j)->nome);
                strcpy(aux.endereco, (cli+j)->endereco);
                strcpy(aux.dataNasc, (cli+j)->dataNasc);
                strcpy(aux.telefone, (cli+j)->telefone);
                strcpy(aux.celular, (cli+j)->celular);

                strcpy((cli+j)->cpf, (cli+j+1)->cpf);
                strcpy((cli+j)->nome, (cli+j+1)->nome);
                strcpy((cli+j)->endereco, (cli+j+1)->endereco);
                strcpy((cli+j)->dataNasc, (cli+j+1)->dataNasc);
                strcpy((cli+j)->telefone, (cli+j+1)->telefone);
                strcpy((cli+j)->celular, (cli+j+1)->celular);

                strcpy((cli+j+1)->cpf, aux.cpf);
                strcpy((cli+j+1)->nome, aux.nome);
                strcpy((cli+j+1)->endereco, aux.endereco);
                strcpy((cli+j+1)->dataNasc, aux.dataNasc);
                strcpy((cli+j+1)->telefone, aux.telefone);
                strcpy((cli+j+1)->celular, aux.celular);

                trocou = 1;
            }
        }
    }
}

int adiciona_cli(struct cliente *cli, int *max, int *count) {
    char cpfteste[15];
    if (*count != *max) {
        printf("All aboard! It's collectin' time!\n\n");
        printf("Digite o CPF do cliente\n");
        cpf_regex(cpfteste);
        if (procura_cli(cli, *count, cpfteste) < 0) {
            strcpy((cli+*count)->cpf, cpfteste);
            printf("Digite o nome\n");
            gets((cli+*count)->nome);
            printf("Digite o endereço\n");
            gets((cli+*count)->endereco);
            printf("Digite a data de nascimento(dd/mm/aaaa)\n");
            data_regex((cli+*count)->dataNasc);
            printf("Digite o telefone\n");
            telefone_regex((cli+*count)->telefone);
            printf("Digite o celular\n");
            celular_regex((cli+*count)->celular);
            (*count)++;
            printf("\nFlawless victory, now do it again!\n\n");
            return 1;
        } else
            printf("\nHmm. Well maybe next time\n\n");
    } else {
        printf("\nWell, you can't win them all\n\n");
        realloca_cli(cli, max);
    }
    return 0;
}

void lista_clis(struct cliente *cli, int count) {
    int i;
    printf("\t\tEmergis Exmortis!\n\n");
    for (i=0;i<count;i++) {
        printf("Nome: %s\nCPF: %s\nEndereço: %s\n", (cli+i)->nome, (cli+i)->cpf, (cli+i)->endereco);
        printf("Data de nascimento: %s\nCelular: %s\nTelefone: %s\n", (cli+i)->dataNasc, (cli+i)->celular, (cli+i)->telefone);
        printf("---------------------------------------------\n");
    }
    printf("\n");
}

void mostra_cli(struct cliente *cli, int count) {
    int indice;
    char cpfteste[15];
    printf("Digite o CPF do cliente procurado\n");
    cpf_regex(cpfteste);
    indice = procura_cli(cli, count, cpfteste);
    if (indice == -1) 
        printf("Fools! You'll never find me!\n");
    else {
        printf("\nEmergis Exmortis!\n\n");
        printf("Nome: %s\nCPF: %s\nEndereço: %s\n", (cli+indice)->nome, (cli+indice)->cpf, (cli+indice)->endereco);
        printf("Data de nascimento: %s\nCelular: %s\nTelefone: %s\n\n", (cli+indice)->dataNasc, (cli+indice)->celular, (cli+indice)->telefone);
    }
}

int altera_cli(struct cliente *cli, int count, struct aluguel *alu, int count_alu) {
    char cpfteste[15];
    int i, j, indice, quantidade, escolha;
    printf("Digite o CPF do cliente\n");
    cpf_regex(cpfteste);
    indice = procura_cli(cli, count, cpfteste);
    if (indice != -1) {
        printf("\nEmergis Exmortis!\n\n");
        printf("Nome(1): %s\nCPF(2): %s\nEndereço(3): %s\n", (cli+indice)->nome, (cli+indice)->cpf, (cli+indice)->endereco);
        printf("Data de nascimento(4): %s\nCelular(5): %s\nTelefone(6): %s\n", (cli+indice)->dataNasc, (cli+indice)->celular, (cli+indice)->telefone);
        printf("\nDigite quantos campos serão alterados\n");
        scanf("%d", &quantidade);
        if (quantidade) {
            for (i=0;i<quantidade;i++) {
                printf("Digite o número do campo que será alterado\n");
                scanf("%d", &escolha);
                printf("Digite um novo valor\n");
                fflush(stdin);
                switch (escolha) {
                    case 1:
                        gets((cli+indice)->nome);
                        break;
                    case 2:
                        cpf_regex(cpfteste);
                        if (procura_cli(cli, count, cpfteste) == -1) {
                            strcpy((cli+indice)->cpf, cpfteste);
                            for (j=0;j<count_alu;j++) {
                                if (strcmp((alu+j)->cpfcli, cpfteste) == 0)
                                    strcpy((alu+j)->cpfcli, (cli+indice)->cpf);
                            }
                        } else
                            printf("You did it! Wait, you didn't do it\n");
                        
                        break;
                    case 3:
                        gets((cli+indice)->endereco);
                        break;
                    case 4:
                        data_regex((cli+indice)->dataNasc);
                        break;
                    case 5:
                        celular_regex((cli+indice)->celular);
                        break;
                    case 6:
                        telefone_regex((cli+indice)->telefone);
                        break;
                    default:
                        printf("\nIs that all you got, moron?\n");
                }
            }
            printf("Flawless victory, now do it again!\n\n");
            return 1;
        } else
            printf("Humiliating defeat!\n\n");
    } else
        printf("Fools! You'll never find me!\n");
    return 0;
}

int exclui_cli(struct cliente *cli, int *count, struct aluguel *alu, int *count_alu) {
    int i, j, n = 0, indice, confirma;
    char cpfteste[15];
    printf("Digite o CPF do cliente a ser excluido\n");
    cpf_regex(cpfteste);
    indice = procura_cli(cli, *count, cpfteste);
    if (indice != -1) {
        printf("\nEmergis Exmortis!\n\n");
        printf("Nome: %s\nCPF: %s\nEndereço: %s\n", (cli+indice)->nome, (cli+indice)->cpf, (cli+indice)->endereco);
        printf("Data de nascimento: %s\nCelular: %s\nTelefone: %s\n", (cli+indice)->dataNasc, (cli+indice)->celular, (cli+indice)->telefone);
        printf("Deseja mesmo excluir este cliente? (1/0)\n");
        scanf("%d", &confirma);
        if (confirma) {
            for (i=indice;i<(*count)-1;i++) {
                strcpy((cli+i)->cpf, (cli+i+1)->cpf);
                strcpy((cli+i)->nome, (cli+i+1)->nome);
                strcpy((cli+i)->endereco, (cli+i+1)->endereco);
                strcpy((cli+i)->dataNasc, (cli+i+1)->dataNasc);
                strcpy((cli+i)->telefone, (cli+i+1)->telefone);
                strcpy((cli+i)->celular, (cli+i+1)->celular);
            }
            (*count)--;
            for (i=0;i<(*count_alu);i++) {
                if(strcmp((alu+i)->cpfcli, cpfteste) == 0) {
                    for (j=i;j<(*count_alu)-1;j++) {
                        strcpy((alu+j)->cpfcli, (alu+j+1)->cpfcli);
                        (alu+j)->codveic = (alu+j+1)->codveic;
                        strcpy((alu+j)->dataretirada, (alu+j+1)->dataretirada);
                        strcpy((alu+j)->datadevolucao, (alu+j+1)->datadevolucao);
                    }
                    (*count_alu)--;
                }
            }
            printf("\nContract complete\n\n");
            return 1;
        } else
            printf("\nContract incomplete\n\n");
    } else
        printf("\nFools! You'll never find me!\n\n");
    return 0;
}

int descarrega_clis(struct cliente *cli, int count) {
    FILE *p;
    int n;
    if (!access("clientes.txt", W_OK)) {
        ordena_cli(cli, count);
        p = fopen("clientes.txt", "wb");
        n = fwrite(cli, sizeof(struct cliente), count, p);
        fclose(p);
        if (n == count){
            printf("Contract complete\n\n");
            return 1;
        } else 
            printf("Contract incomplete\n\n");
    } else
        printf("The Administrator will have to be notified. Sorry\n\n");
    return 0;
}



//funções de veículo
void extrai_vei(struct veiculo *vei, int *max, int *count) {
    FILE *p;
    int n, i = 100, k = 10;
    *count = 0;
    struct veiculo *aux;
    if (!access("veiculos.txt", F_OK) && !access("veiculos.txt", R_OK)) {
        p = fopen("veiculos.txt" , "rb");
        if (p != NULL) {
            while (!feof(p)) {
                n = fread(vei+*count, sizeof(struct veiculo), k, p);
                *count = *count + n;
                if (*count == *max && i > 0) {
                    aux = (struct veiculo *) realloc (vei, (*max) + i);
                    if (aux)
                        vei = aux;
                    else
                        printf("The cart(Veículos) has almost reached the final terminus! %d left\n", (100-i));
                        i = i - 5;
                } else if (i == 0) {
                    printf("Jarate for everyone! I'm so, so SORRY!\n");
                    return;
                } else if (n < k)
                    k = 10 - n;
            }
        } else
            printf("I should have asked one of the other guys\n");
    } else
        p = fopen("veiculos.txt", "wb");
    fclose(p);
}

void realloca_vei(struct veiculo *vei, int *max) {
    struct veiculo *aux = NULL;
    int i = 100;
    while (!aux) {
        aux = (struct veiculo *) realloc (vei, (*max) + i);
        if (!aux)
            i = i - 5;
        else if (!aux && !i) {
            printf("Jarate for everyone! I'm so, so SORRY!\n");
            return;
        }
    }
}

int procura_vei(struct veiculo *vei, int count, int cod) {
    int i;
    for (i=0;i<count;i++) {
        if (cod == (vei+i)->codigo)
            return i;
    }
    return -1;
}

void ordena_vei(struct veiculo *vei, int count) {
    int i, j, trocou;
    struct veiculo aux;
    for (i=count-1;i>0 && trocou;i--) { 
        trocou = 0;
        for (j=0;j<i;j++) {
            if ((vei+j)->codigo > (vei+j+1)->codigo) {
                aux.codigo = (vei+j)->codigo;
                strcpy(aux.descricao, (vei+j)->descricao);
                strcpy(aux.categoria, (vei+j)->categoria);
                strcpy(aux.modelo, (vei+j)->modelo);
                aux.capacidade = (vei+j)->capacidade;
                aux.combustivel = (vei+j)->combustivel;
                aux.ano = (vei+j)->ano;

                (vei+j)->codigo = (vei+j+1)->codigo;
                strcpy((vei+j)->descricao, (vei+j+1)->descricao);
                strcpy((vei+j)->categoria, (vei+j+1)->categoria);
                strcpy((vei+j)->modelo, (vei+j+1)->modelo);
                (vei+j)->capacidade = (vei+j+1)->capacidade;
                (vei+j)->combustivel = (vei+j+1)->combustivel;
                (vei+j)->ano = (vei+j+1)->ano;

                (vei+j+1)->codigo = aux.codigo;
                strcpy((vei+j+1)->descricao, aux.descricao);
                strcpy((vei+j+1)->categoria, aux.categoria);
                strcpy((vei+j+1)->modelo, aux.modelo);
                (vei+j+1)->capacidade = aux.capacidade;
                (vei+j+1)->combustivel = aux.combustivel;
                (vei+j+1)->ano = aux.ano;

                trocou = 1;
            }
        }
    }
}

int adiciona_vei(struct veiculo *vei, int *max, int *count) {
    int codteste;
    if (*count != *max) {
        printf("All aboard! It's collectin' time!\n\n");
        printf("Digite o código do veículo\n");
        scanf("%d", &codteste);
        if (procura_vei(vei, *count, codteste) == -1) {
            (vei+*count)->codigo = codteste;
            fflush(stdin);
            printf("Digite a descricao\n");
            gets((vei+*count)->descricao);
            printf("Digite a categoria\n");
            gets((vei+*count)->categoria);
            printf("Digite o modelo\n");
            gets((vei+*count)->modelo);
            printf("Digite a capacidade\n");
            scanf("%f", &(vei+*count)->capacidade);
            printf("Digite o combustivel\n");
            scanf("%f", &(vei+*count)->combustivel);
            printf("Digite o ano\n");
            scanf("%d", &(vei+*count)->ano);
            (*count)++;
            printf("Flawless victory, now do it again!\n\n");
            return 1;
        } else
            printf("\nHmm. Well maybe next time\n\n");
    } else {
        printf("\nWell, you can't win them all\n\n");
        realloca_vei(vei, max);
    }
    return 0;
}

void lista_veis(struct veiculo *vei, int count) {
    int i;
    printf("\t\tEmergis Exmortis!\n\n");
    for (i=0;i<count;i++) {
        printf("Modelo: %s\nCódigo: %d\nCategoria: %s\n", (vei+i)->modelo, (vei+i)->codigo, (vei+i)->categoria);
        printf("Ano: %d\nCapacidade: %.2f\nCombustível: %.2f\n", (vei+i)->ano, (vei+i)->capacidade, (vei+i)->combustivel);
        printf("descrição: %s\n", (vei+i)->descricao);
        printf("---------------------------------------------\n");
    }
    printf("\n");
}

void mostra_vei(struct veiculo *vei, int count) {
    int indice;
    int codteste;
    printf("Digite o código do veículo procurado\n");
    scanf("%d", &codteste);
    indice = procura_vei(vei, count, codteste);
    if (indice == -1) 
        printf("Fools! You'll never find me!\n");
    else {
        printf("cadastro encontrado:\n");
        printf("Modelo: %s\nCódigo: %d\nCategoria: %s\n", (vei+indice)->modelo, (vei+indice)->codigo, (vei+indice)->categoria);
        printf("Ano: %d\nCapacidade: %.2f\nCombustível: %.2f\n", (vei+indice)->ano, (vei+indice)->capacidade, (vei+indice)->combustivel);
        printf("descrição: %s\n", (vei+indice)->descricao);
    }
}

int altera_vei(struct veiculo *vei, int count, struct aluguel *alu, int count_alu) {
    int codteste;
    int i, j, indice, quantidade, escolha;
    printf("Digite o código do carro\n");
    scanf("%d", &codteste);
    indice = procura_vei(vei, count, codteste);
    if (indice != -1) {
        printf("Modelo(1): %s\nCódigo(2): %d\nCategoria(3): %s\n", (vei+indice)->modelo, (vei+indice)->codigo, (vei+indice)->categoria);
        printf("Ano(4): %d\nCapacidade(5): %.2f\nCombustível(6): %.2f\n", (vei+indice)->ano, (vei+indice)->capacidade, (vei+indice)->combustivel);
        printf("descrição(7): %s\n", (vei+indice)->descricao);
        printf("\nDigite quantos campos serão alterados\n");
        scanf("%d", &quantidade);
        if (quantidade) {
            for (i=0;i<quantidade;i++) {
                printf("Digite o número do campo que será alterado\n");
                scanf("%d", &escolha);
                printf("Digite o novo valor\n");
                fflush(stdin);
                switch (escolha) {
                    case 1:
                        gets((vei+indice)->modelo);
                        break;
                    case 2:
                        scanf("%d", &codteste);
                        if (procura_vei(vei, count, codteste) == -1) {
                            (vei+indice)->codigo = codteste;
                            for (j=0;j<count_alu;j++) {
                                if ((alu+j)->codveic == codteste)
                                    (alu+j)->codveic = (vei+indice)->codigo;
                            }
                        } else
                            printf("You did it! Wait, you didn't do it\n");                        
                        break;
                    case 3:
                        gets((vei+indice)->categoria);
                        break;
                    case 4:
                        scanf("%d", &(vei+indice)->ano);
                        break;
                    case 5:
                        scanf("%f", &(vei+indice)->capacidade);
                        break;
                    case 6:
                        scanf("%f", &(vei+indice)->combustivel);
                        break;
                    case 7:
                        gets((vei+indice)->descricao);
                        break;
                    default:
                        printf("\nIs that all you got, moron?\n");
                }
            }
            printf("Flawless victory, now do it again!\n\n");
            return 1;
        } else
            printf("Humiliating defeat!\n\n");        
    } else
        printf("Fools! You'll never find me!\n\n");
    return 0;
}

int exclui_vei(struct veiculo *vei, int *count, struct aluguel *alu, int *count_alu) {
    int i, j, n = 0, indice, confirma;
    int codteste;
    printf("Digite o código do veículo a ser excluido\n");
    scanf("%d", &codteste);
    indice = procura_vei(vei, *count, codteste);
    if (indice != -1) {
        printf("\nEmergis Exmortis!\n\n");
        printf("Modelo: %s\nCódigo: %d\nCategoria: %s\n", (vei+indice)->modelo, (vei+indice)->codigo, (vei+indice)->categoria);
        printf("Ano: %d\nCapacidade: %.2f\nCombustível: %.2f\n", (vei+indice)->ano, (vei+indice)->capacidade, (vei+indice)->combustivel);
        printf("descrição: %s\n", (vei+indice)->descricao);
        printf("Deseja mesmo excluir este veiculo? (1/0)\n");
        scanf("%d", &confirma);
        if (confirma) {
            for (i=indice;i<(*count)-1;i++) {
                (vei+i)->codigo = (vei+i+1)->codigo;
                strcpy((vei+i)->modelo, (vei+i+1)->modelo);
                strcpy((vei+i)->categoria, (vei+i+1)->categoria);
                strcpy((vei+i)->descricao, (vei+i+1)->descricao);
                (vei+i)->capacidade = (vei+i+1)->capacidade;
                (vei+i)->combustivel = (vei+i+1)->combustivel;
                (vei+i)->ano = (vei+i+1)->ano;
            }
            (*count)--;
            for (i=0;i<(*count_alu);i++) {
                if(codteste == (alu+i)->codveic) {
                    for (j=i;j<(*count_alu)-1;j++) {
                        strcpy((alu+j)->cpfcli, (alu+j+1)->cpfcli);
                        (alu+j)->codveic = (alu+j+1)->codveic;
                        strcpy((alu+j)->dataretirada, (alu+j+1)->dataretirada);
                        strcpy((alu+j)->datadevolucao, (alu+j+1)->datadevolucao);
                    }
                    (*count_alu)--;
                }
            }
            printf("Contract complete\n\n");
            return 1;
        } else
            printf("Contract incomplete\n\n");
    } else
        printf("Fools! You'll never find me!\n\n");
    return 0;
}

int descarrega_veis(struct veiculo *vei, int count) {
    FILE *p;
    int n;
    if (!access("veiculos.txt", W_OK)) {
        ordena_vei(vei, count);
        p = fopen("veiculos.txt", "wb");
        n = fwrite(vei, sizeof(struct veiculo), count, p);
        fclose(p);
        if (n == count){
            printf("\nContract complete\n\n");
            return 1;
        } else 
            printf("\nContract incomplete\n\n");
    } else
        printf("\nThe Administrator will have to be notified. Sorry\n\n");
    return 0;
}

//funções de aluguel
void extrai_alu(struct aluguel *alu, int *max, int *count) {
    FILE *p;
    int n, i = 100, k = 10;
    *count = 0;
    struct aluguel *aux;
    if (!access("alugueis.txt", F_OK) && !access("alugueis.txt", R_OK)) {
        p = fopen("alugueis.txt" , "rb");
        if (p != NULL) {
            while (!feof(p)) {
                n = fread(alu+*count, sizeof(struct aluguel), k, p);
                *count = *count + n;
                if (*count == *max && i > 0) {
                    aux = (struct aluguel *) realloc (alu, (*max) + i);
                    if (aux)
                        alu = aux;
                    else
                        printf("The cart(Alugueis) has almost reached the final terminus! %d left\n", (100-i));
                        i = i - 5;
                } else if (i == 0) {
                    printf("Jarate for everyone! I'm so, so SORRY!\n");
                    return;
                } else if (n < k)
                    k = 10 - n;
            }
        } else
            printf("I should have asked one of the other guys\n");
    } else {
        p = fopen("alugueis.txt", "wb");
    }
    fclose(p);
}

void realloca_alu(struct aluguel *alu, int *max) {
    struct aluguel *aux = NULL;
    int i = 100;
    while (!aux) {
        aux = (struct aluguel *) realloc (alu, (*max) + i);
        if (!aux)
            i = i - 5;
        else if (!aux && !i) {
            printf("Jarate for everyone! I'm so, so SORRY!\n");
            return;
        }
    }
}

int procura_alu(struct aluguel *alu, int count, struct aluguel alu_teste) {
    int i;
    for (i=0;i<count;i++) {
        if(!strcmp((alu+i)->dataretirada, alu_teste.dataretirada) && !strcmp((alu+i)->datadevolucao, alu_teste.datadevolucao))
            if (!strcmp((alu+i)->cpfcli, alu_teste.cpfcli) && (alu+i)->codveic == alu_teste.codveic)
                return i;
    }
    return -1;
}

void ordena_alu(struct aluguel *alu, int count) {
    int i, j, trocou = 1;
    struct aluguel aux;
    char Rdatainicio[11], Rdatafim[11];
    for (i=count-1;i>0 && trocou;i--) { 
        trocou = 0;
        for (j=0;j<i;j++) {
            if (strcmp((alu+j)->cpfcli, (alu+j+1)->cpfcli) > 0) {
                strcpy(aux.cpfcli, (alu+j)->cpfcli);
                aux.codveic = (alu+j)->codveic;
                strcpy(aux.dataretirada, (alu+j)->dataretirada);
                strcpy(aux.datadevolucao, (alu+j)->datadevolucao);
                
                strcpy((alu+j)->cpfcli, (alu+j+1)->cpfcli);
                (alu+j)->codveic = (alu+j+1)->codveic;
                strcpy((alu+j)->dataretirada, (alu+j+1)->dataretirada);
                strcpy((alu+j)->datadevolucao, (alu+j+1)->datadevolucao);

                strcpy((alu+j+1)->cpfcli, aux.cpfcli);
                (alu+j+1)->codveic = aux.codveic;
                strcpy((alu+j+1)->dataretirada, aux.dataretirada);
                strcpy((alu+j+1)->datadevolucao, aux.datadevolucao);

                trocou = 1;
            }
        }
    }
    for (i=count-1;i>0 && trocou;i--) { 
        trocou = 0;
        for (j=0;j<i;j++) {
            if (!strcmp((alu+j)->cpfcli, (alu+j+1)->cpfcli) && (alu+j)->codveic > (alu+j+1)->codveic) {
                strcpy(aux.cpfcli, (alu+j)->cpfcli);
                aux.codveic = (alu+j)->codveic;
                strcpy(aux.dataretirada, (alu+j)->dataretirada);
                strcpy(aux.datadevolucao, (alu+j)->datadevolucao);
                
                strcpy((alu+j)->cpfcli, (alu+j+1)->cpfcli);
                (alu+j)->codveic = (alu+j+1)->codveic;
                strcpy((alu+j)->dataretirada, (alu+j+1)->dataretirada);
                strcpy((alu+j)->datadevolucao, (alu+j+1)->datadevolucao);

                strcpy((alu+j+1)->cpfcli, aux.cpfcli);
                (alu+j+1)->codveic = aux.codveic;
                strcpy((alu+j+1)->dataretirada, aux.dataretirada);
                strcpy((alu+j+1)->datadevolucao, aux.datadevolucao);

                trocou = 1;
            }
        }
    }
    for (i=count-1;i>0 && trocou;i--) { 
        trocou = 0;
        for (j=0;j<i;j++) {
            data_extrai((alu+j)->dataretirada, Rdatainicio);
            data_extrai((alu+j+1)->dataretirada, Rdatafim);
            if (!strcmp((alu+j)->cpfcli, (alu+j+1)->cpfcli) && (alu+j)->codveic == (alu+j+1)->codveic && strcmp(Rdatainicio, Rdatafim) > 0) {
                strcpy(aux.cpfcli, (alu+j)->cpfcli);
                aux.codveic = (alu+j)->codveic;
                strcpy(aux.dataretirada, (alu+j)->dataretirada);
                strcpy(aux.datadevolucao, (alu+j)->datadevolucao);

                strcpy((alu+j)->cpfcli, (alu+j+1)->cpfcli);
                (alu+j)->codveic = (alu+j+1)->codveic;
                strcpy((alu+j)->dataretirada, (alu+j+1)->dataretirada);
                strcpy((alu+j)->datadevolucao, (alu+j+1)->datadevolucao);

                strcpy((alu+j+1)->cpfcli, aux.cpfcli);
                (alu+j+1)->codveic = aux.codveic;
                strcpy((alu+j+1)->dataretirada, aux.dataretirada);
                strcpy((alu+j+1)->datadevolucao, aux.datadevolucao);

                trocou = 1;
            }
        }
    }
}

int adiciona_alu(struct aluguel *alu, int *max, int *count, struct cliente *cli, int count_cli, struct veiculo *vei, int count_vei) {
    struct aluguel alu_teste;
    if (*count != *max) {
        printf("Digite o CPF do cliente\n");
        cpf_regex(alu_teste.cpfcli);
        if (procura_cli(cli, count_cli, alu_teste.cpfcli) != -1) {
            printf("Digite o código do carro\n");
            scanf("%d", &alu_teste.codveic);
            if (procura_vei(vei, count_vei, alu_teste.codveic) != -1) {
                printf("Digite a data de retirada\n");
                data_regex(alu_teste.dataretirada);
                printf("Digite a data de devolução\n");
                data_regex(alu_teste.datadevolucao);
                if (veiculo_alugavel(alu, *count, alu_teste, -1))
                    if (procura_alu(alu, *count, alu_teste) == -1) {
                        strcpy((alu+*count)->cpfcli, alu_teste.cpfcli);
                        (alu+*count)->codveic = alu_teste.codveic;
                        strcpy((alu+*count)->dataretirada, alu_teste.dataretirada);
                        strcpy((alu+*count)->datadevolucao, alu_teste.datadevolucao);
                        (*count)++;
                        printf("Flawless victory, now do it again!\n\n");
                        return 1;
                    } else
                        printf("\nHmm. Well maybe next time\n\n");
                else
                    printf("\nToo slow mortal! The Gargoyle, is gone!\n\n");
            } else
                printf("\nFools! You'll never find me!\n\n");
        } else
            printf("\nFools! You'll never find me!\n\n");
    } else {
        printf("\nWell, you can't win them all\n\n");
        realloca_alu(alu, max);
    }
    return 0;
}

void lista_alus(struct aluguel *alu, int count) {
    int i;
    printf("\t\tEmergis Exmortis!\n\n");
    for (i=0;i<count;i++) {
        printf("CPF: %s\nCódigo: %d\n", (alu+i)->cpfcli, (alu+i)->codveic);
        printf("Data de retirada: %s\nData de devolução: %s\n", (alu+i)->dataretirada, (alu+i)->datadevolucao);
        printf("---------------------------------------------\n");
    }
    printf("\n");
}

void mostra_alu(struct aluguel *alu, int count, struct cliente *cli, int count_cli, struct veiculo *vei, int count_vei) {
    struct aluguel alu_teste;
    printf("Digite o cpf do cliente no aluguel procurado\n");
    cpf_regex(alu_teste.cpfcli);
    if (procura_cli(cli, count_cli, alu_teste.cpfcli) != -1) {
        printf("Digite o código do veículo no aluguel procurado\n");
        scanf("%d", &alu_teste.codveic);
        if (procura_vei(vei, count_vei, alu_teste.codveic) != -1) {
            printf("Digite a data de retirada do veículo no aluguel procurado\n");
            data_regex(alu_teste.dataretirada);
            printf("Digite a data de devolução do veículo no aluguel procurado\n");
            data_regex(alu_teste.datadevolucao);
            if (procura_alu(alu, count, alu_teste) != -1) {
                printf("\t\tEmergis Exmortis!\n\n");
                printf("CPF: %s\nCódigo do veículo: %d\n", alu_teste.cpfcli, alu_teste.codveic);
                printf("Data de retirada: %s\nData de devolução: %s\n", alu_teste.dataretirada, alu_teste.datadevolucao);
            } else
                printf("\nFools! You'll never find me!\n\n");
        } else
            printf("\nFools! You'll never find me!\n\n");
    } else
        printf("\nFools! You'll never find me!\n\n");
}

int altera_alu(struct aluguel *alu, int count, struct cliente *cli, int count_cli, struct veiculo *vei, int count_vei) {
    struct aluguel alu_teste;
    int i, indice, quantidade, escolha;
    printf("Digite o cpf do cliente\n");
    cpf_regex(alu_teste.cpfcli);
    if (procura_cli(cli, count_cli, alu_teste.cpfcli) != -1) {
        printf("Digite o código do veículo\n");
        scanf("%d", &alu_teste.codveic);
        if (procura_vei(vei, count_vei, alu_teste.codveic) != -1) {
            printf("Digite a data de retirada do veículo\n");
            data_regex(alu_teste.dataretirada);
            printf("Digite a data de devolução do veículo\n");
            data_regex(alu_teste.datadevolucao);
            indice = procura_alu(alu, count, alu_teste);
            if (indice != -1) {
                printf("\t\tEmergis Exmortis!\n\n");
                printf("CPF(1): %s\nCódigo do veículo(2): %d\n", alu_teste.cpfcli, alu_teste.codveic);
                printf("Data de retirada(3): %s\nData de devolução(4): %s\n", alu_teste.dataretirada, alu_teste.datadevolucao);
                printf("\nDigite quantos campos serão alterados\n");
                scanf("%d", &quantidade);
                for (i=0;i<quantidade;i++) {
                    printf("Digite o número do campo que será alterado\n");
                    scanf("%d", &escolha);
                    printf("Digite o novo valor\n");
                    fflush(stdin);
                    switch (escolha) {
                        case 1:
                            cpf_regex(alu_teste.cpfcli);
                            if (procura_cli(cli, count_cli, alu_teste.cpfcli) != -1 && procura_alu(alu, count, alu_teste) == -1)
                                strcpy((alu+indice)->cpfcli, alu_teste.cpfcli);
                            else
                                printf("\nYou did it! Wait, you didn't do it\n\n");
                            break;
                        case 2:
                            scanf("%d", &alu_teste.codveic);
                            if (procura_vei(vei, count_vei, alu_teste.codveic) != -1 && procura_alu(alu, count, alu_teste) == -1)
                                (alu+indice)->codveic = alu_teste.codveic;
                            else
                                printf("\nYou did it! Wait, you didn't do it\n\n");
                            break;
                        case 3:
                            data_regex(alu_teste.dataretirada);
                            if (veiculo_alugavel(alu, count, alu_teste, indice))
                                strcpy((alu+indice)->dataretirada, alu_teste.dataretirada);
                            else
                                printf("\nToo slow mortal! The Gargoyle, is gone!\n\n");
                            break;
                        case 4:
                            data_regex(alu_teste.datadevolucao);
                            if (veiculo_alugavel(alu, count, alu_teste, indice))
                                strcpy((alu+indice)->datadevolucao, alu_teste.datadevolucao);
                            else
                                printf("\nToo slow mortal! The Gargoyle, is gone!\n\n");
                            break;
                        default:
                            printf("\nIs that all you got, moron?\n");
                    }
                }
                printf("Flawless victory, now do it again!\n\n");
                return 1;
            } else
                printf("\nFools! You'll never find me!\n\n");
        } else
            printf("\nFools! You'll never find me!\n\n");
    } else
        printf("\nFools! You'll never find me!\n\n");
    return 0;
}

int exclui_alu(struct aluguel *alu, int *count, struct cliente *cli, int count_cli, struct veiculo *vei, int count_vei) {
    struct aluguel alu_teste;
    int i, indice, confirma;
    printf("Digite o cpf do cliente\n");
    cpf_regex(alu_teste.cpfcli);
    if (procura_cli(cli, count_cli, alu_teste.cpfcli) != -1) {
        printf("Digite o código do veículo\n");
        scanf("%d", &alu_teste.codveic);
        if (procura_vei(vei, count_vei, alu_teste.codveic) != -1) {
            printf("Digite a data de retirada do veículo\n");
            data_regex(alu_teste.dataretirada);
            printf("Digite a data de devolução do veículo\n");
            data_regex(alu_teste.datadevolucao);
            indice = procura_alu(alu, *count, alu_teste);
            if (indice != -1) {
                printf("CPF(1): %s\nCódigo do veículo(2): %d\n", alu_teste.cpfcli, alu_teste.codveic);
                printf("Data de retirada(3): %s\nData de devolução(4): %s\n", alu_teste.dataretirada, alu_teste.datadevolucao);
                printf("Deseja mesmo excluir este aluguel? (1/0)\n");
                scanf("%d", &confirma);
                if (confirma) {
                    for (i=indice;i<(*count)-1;i++) {
                        strcpy((alu+i)->cpfcli, (alu+i+1)->cpfcli);
                        (alu+i)->codveic = (alu+i+1)->codveic;
                        strcpy((alu+i)->dataretirada, (alu+i+1)->dataretirada);
                        strcpy((alu+i)->datadevolucao, (alu+i+1)->datadevolucao);
                    }
                    (*count)--;
                    printf("\nContract complete\n\n");
                    return 1;
                } else
                    printf("\nContract incomplete\n\n");
            } else
                printf("\nFools! You'll never find me!\n\n");
        } else
            printf("\nFools! You'll never find me!\n\n");
    } else
        printf("\nFools! You'll never find me!\n\n");
    return 0;
}

int descarrega_alus(struct aluguel *alu, int count) {
    FILE *p;
    int n;
    if (!access("alugueis.txt", W_OK)) {
        ordena_alu(alu, count);
        p = fopen("alugueis.txt", "wb");
        n = fwrite(alu, sizeof(struct aluguel), count, p);
        fclose(p);
        if (n == count){
            printf("\nContract complete\n\n");
            return 1;
        } else 
            printf("\nContract incomplete\n\n");
    } else
        printf("\nThe Administrator will have to be notified. Sorry\n\n");
    return 0;
}

//funções de relatório
void F_relatorio(struct cliente *cli, int count_cli, struct aluguel *alu, int count_alu) {
    FILE *p;
    char cpfteste[15];
    int i, alugou = 0;
    p = fopen("relatorio.txt", "wb");
    if (p != NULL) {
        printf("Digite o CPF do cliente\n");
        cpf_regex(cpfteste);
        if (procura_cli(cli, count_cli, cpfteste) != -1) {
            printf("-------------------Alugueis-------------------\n\n");
            fwrite("-------------------Alugueis-------------------\n\n", sizeof(char), 49, p);
            for (i=0;i<count_alu;i++) {
                if (!strcmp((alu+i)->cpfcli, cpfteste)) {
                    printf("CPF: %s\nCódigo: %d\n", (alu+i)->cpfcli, (alu+i)->codveic);
                    fwrite("CPF: ", sizeof(char), 6, p);
                    fwrite((alu+i)->cpfcli, sizeof(char), 15, p);
                    fwrite("\nCódigo: ", sizeof(char), 11, p);
                    fwrite(&(alu+i)->codveic, sizeof(int), 1, p);
                    printf("Data de retirada: %s\nData de devolução: %s\n", (alu+i)->dataretirada, (alu+i)->datadevolucao);
                    fwrite("\nData de retirada: ", sizeof(char), 20, p);
                    fwrite((alu+i)->dataretirada, sizeof(char), 11, p);
                    fwrite("\nData de devolução: ", sizeof(char), 23, p);
                    fwrite((alu+i)->datadevolucao, sizeof(char), 11, p);
                    printf("---------------------------------------------\n");
                    fwrite("\n---------------------------------------------\n", sizeof(char), 48, p);
                    alugou++;
                }
            }
            if (!alugou) {
                printf("Is that all you got, moron?\n");
                fwrite("Is that all you got, moron?\n", sizeof(char), 29, p);
            }
        } else
            printf("\nFools! You'll never find me!\n\n");
    } else
        printf("\nThe Administrator will have to be notified. Sorry\n\n");
    fclose(p);
}

void S_relatorio(struct veiculo *vei, int count_vei, struct aluguel *alu, int count_alu) {
    FILE *p;
    int codteste;
    int i, alugou = 0;
    p = fopen("relatorio.txt", "wb");
    if (p != NULL) {
        printf("Digite o codigo do veículo\n");
        scanf("%d", &codteste);
        if (procura_vei(vei, count_vei, codteste) != -1) {
            printf("-------------------Alugueis-------------------\n\n");
            fwrite("-------------------Alugueis-------------------\n\n", sizeof(char), 49, p);
            for (i=0;i<count_alu;i++) {
                if ((alu+i)->codveic == codteste) {
                    printf("CPF: %s\nCódigo: %d\n", (alu+i)->cpfcli, (alu+i)->codveic);
                    fwrite("CPF: ", sizeof(char), 6, p);
                    fwrite((alu+i)->cpfcli, sizeof(char), 15, p);
                    fwrite("\nCódigo: ", sizeof(char), 11, p);
                    fwrite(&(alu+i)->codveic, sizeof(int), 1, p);
                    printf("Data de retirada: %s\nData de devolução: %s\n", (alu+i)->dataretirada, (alu+i)->datadevolucao);
                    fwrite("\nData de retirada: ", sizeof(char), 20, p);
                    fwrite((alu+i)->dataretirada, sizeof(char), 11, p);
                    fwrite("\nData de devolução: ", sizeof(char), 23, p);
                    fwrite((alu+i)->datadevolucao, sizeof(char), 11, p);
                    printf("---------------------------------------------\n");
                    fwrite("\n---------------------------------------------\n", sizeof(char), 48, p);
                    alugou++;
                }
            }
            if (!alugou) {
                printf("Is that all you got, moron?\n");
                fwrite("Is that all you got, moron?\n", sizeof(char), 29, p);
            }
        } else
            printf("\nFools! You'll never find me!\n\n");
    } else
        printf("\nThe Administrator will have to be notified. Sorry\n\n");
    fclose(p);
}

void T_relatorio(struct cliente *cli, int count_cli, struct veiculo *vei, int count_vei, struct aluguel *alu, int count_alu) {
    FILE *p;
    char dataini[11], datafim[11], Rdataini[11], Rdatafim[11];
    struct veiculo Sveiculo;
    struct cliente Scliente;
    int i, j, dados = 0;
    p = fopen("relatorio.txt", "wb");
    if (p != NULL) {
        printf("Digite a data de inicio\n");
        data_regex(dataini);
        printf("Digite a data de fim\n");
        data_regex(datafim);
        data_extrai(dataini, Rdataini);
        data_extrai(datafim, Rdatafim);
        for (i=0;i<count_alu;i++) {
            if (strcmp((alu+i)->dataretirada, Rdataini) > -1 && strcmp((alu+i)->datadevolucao, Rdatafim) < 1) {
                for (j=0;j<count_cli;j++) {
                    if (!strcmp((cli+j)->cpf, (alu+i)->cpfcli)) {
                        strcpy(Scliente.cpf, (cli+j)->cpf);
                        strcpy(Scliente.nome, (cli+j)->nome);
                    }
                }
                for (j=0;j<count_vei;j++) {
                    if ((vei+j)->codigo == (alu+i)->codveic) {
                        Sveiculo.codigo = (vei+j)->codigo;
                        strcpy(Sveiculo.modelo, (vei+j)->modelo);
                        strcpy(Sveiculo.descricao, (vei+j)->descricao);
                        strcpy(Sveiculo.categoria, (vei+j)->categoria);
                        Sveiculo.capacidade = (vei+j)->capacidade;
                        Sveiculo.combustivel = (vei+j)->combustivel;
                        Sveiculo.ano = (vei+j)->ano;
                    }
                }
                printf("-------------------Dados-----------------\n\n");
                fwrite("-------------------Dados-----------------\n\n", sizeof(char), 44, p);
                printf("Modelo: %s\nCódigo: %d\nCategoria: %s\n", Sveiculo.modelo, Sveiculo.codigo, Sveiculo.categoria);
                printf("Ano: %d\nCapacidade: %.2f\nCombustível: %.2f\n", Sveiculo.ano, Sveiculo.capacidade, Sveiculo.combustivel);
                printf("descrição: %s\n", Sveiculo.descricao);
                printf("Nome: %s\nCPF: %s\n", Scliente.nome, Scliente.cpf);
                fwrite("Modelo: ", sizeof(char), 9, p);
                fwrite(Sveiculo.modelo, sizeof(char), strlen(Sveiculo.modelo), p);
                fwrite("\nCódigo: ", sizeof(char), 11, p);
                fwrite(&Sveiculo.codigo, sizeof(int), 1, p);
                fwrite("\nCategoria: ", sizeof(char),13 , p);
                fwrite(Sveiculo.categoria, sizeof(char), strlen(Sveiculo.categoria), p);
                fwrite("\nAno: ", sizeof(char), 7, p);
                fwrite(&Sveiculo.ano, sizeof(int), 1, p);
                fwrite("\nCapacidade: ", sizeof(char), 14, p);
                fwrite(&Sveiculo.capacidade, sizeof(float), 1, p);
                fwrite("\nCombustível: ", sizeof(char), 16, p);
                fwrite(&Sveiculo.combustivel, sizeof(float), 1, p);
                fwrite("\ndescrição: ", sizeof(char), 15, p);
                fwrite(Sveiculo.descricao, sizeof(char), strlen(Sveiculo.descricao), p);
                fwrite("Nome: ", sizeof(char), 7, p);
                fwrite(Scliente.nome, sizeof(char), strlen(Scliente.nome), p);
                fwrite("CPF: ", sizeof(char), 6, p);
                fwrite(Scliente.cpf, sizeof(char), 15, p);
                fwrite("\n---------------------------------------------\n", sizeof(char), 48, p);
                dados++;
            }
            if (!dados) {
                printf("Is that all you got, moron?\n");
                fwrite("Is that all you got, moron?\n", sizeof(char), 29, p);
            }
        }
    } else
        printf("\nThe Administrator will have to be notified. Sorry\n\n");
    fclose(p);
}

//funções de menu
void subcli(struct cliente *cli, int *max, int *count, int *aux, int *auxM, struct aluguel *alu, int *count_alu) {
    int opcao = 1;
    while (opcao) {
        if (*aux == 5) {
            descarrega_clis(cli, *count);
            *auxM = (*auxM) - (*aux);
            *aux = 0;
        }
        printf("Submenu Clientes\n");
        printf("1 - Adicionar um cliente novo\n");
        printf("2 - Listar todos os clientes cadastrados\n");
        printf("3 - Mostrar um cliente específico\n");
        printf("4 - Alterar um cadastro de cliente específico\n");
        printf("5 - Excluir um cadastro de cliente específico\n");
        printf("6 - Descarregar as atualizações para a memória(%d)\n", *aux);
        printf("7 - Descartar todas as atualizações(%d)\n", *aux);
        printf("8 - Recarregar os cadastros para memória\n");
        printf("9 - DELETE, mas sem WHERE\n");
        printf("0 - sair\n");
        scanf("%d", &opcao);
        system("cls");
        switch (opcao) {
            case 0:
                printf("\nOh, not the pocket\n\n");
                break;
            case 1:
                if (adiciona_cli(cli, max, count)) {
                    (*aux)++;
                    (*auxM)++;
                }
                break;
            case 2:
                lista_clis(cli, *count);
                break;
            case 3:
                mostra_cli(cli, *count);
                break;
            case 4:
                if (altera_cli(cli, *count, alu, *count_alu)) {
                    (*aux)++;
                    (*auxM)++;
                }
                break;
            case 5:
                if (exclui_cli(cli, count, alu, count_alu)) {
                    (*aux)++;
                    (*auxM)++;
                }
                break;
            case 6:
                if (descarrega_clis(cli, *count)) {
                    (*auxM) = (*auxM) - (*aux);
                    (*aux) = 0;
                }
                break;
            case 7:
                extrai_cli(cli, max, count);
                (*auxM) = (*auxM) - (*aux);
                (*aux) = 0;
                break;
            case 8:
                extrai_cli(cli, max, count);
                (*auxM) = (*auxM) - (*aux);
                (*aux) = 0;
                break;
            case 9:
                mata_arquivo("clientes.txt");
                break;
            default:
                printf("\nIs that all you got, moron?\n");
        }
    }
}

void subvei(struct veiculo *vei, int *max, int *count, int *aux, int *auxM, struct aluguel *alu, int *count_alu) {
    int opcao = 1;
    while (opcao) {
        if (*aux == 5) {
            descarrega_veis(vei, *count);
            *auxM = (*auxM) - (*aux);
            *aux = 0;
        }
        printf("Submenu Veículos\n");
        printf("1 - Adicionar um veículo novo\n");
        printf("2 - Listar todos os veículos cadastrados\n");
        printf("3 - Mostrar um veículo específico\n");
        printf("4 - Alterar um cadastro de veículo específico\n");
        printf("5 - Excluir um cadastro de veículo específico\n");
        printf("6 - Descarregar as atualizações para a memória(%d)\n", *aux);
        printf("7 - Descartar todas as atualizações(%d)\n", *aux);
        printf("8 - Recarregar os cadastros para memória\n");
        printf("9 - DELETE, mas sem WHERE\n");
        printf("0 - sair\n");
        scanf("%d", &opcao);
        system("cls");
        switch (opcao) {
            case 0:
                printf("\nOh, not the pocket\n\n");
                break;
            case 1:
                if (adiciona_vei(vei, max, count)) {
                    (*aux)++;
                    (*auxM)++;
                }
                break;
            case 2:
                lista_veis(vei, *count);
                break;
            case 3:
                mostra_vei(vei, *count);
                break;
            case 4:
                if (altera_vei(vei, *count, alu, *count_alu)) {
                    (*aux)++;
                    (*auxM)++;
                }
                break;
            case 5:
                if (exclui_vei(vei, count, alu, count_alu)) {
                    (*aux)++;
                    (*auxM)++;
                }
                break;
            case 6:
                if (descarrega_veis(vei, *count)) {
                    (*auxM) = (*auxM) - (*aux);
                    (*aux) = 0;
                }
                break;
            case 7:
                extrai_vei(vei, max, count);
                (*auxM) = (*auxM) - (*aux);
                (*aux) = 0;
                break;
            case 8:
                extrai_vei(vei, max, count);
                (*auxM) = (*auxM) - (*aux);
                (*aux) = 0;
                break;
            case 9:
                mata_arquivo("veiculos.txt");
                break;
            default:
                printf("\nIs that all you got, moron?\n");
        }
    }
}

void subalu(struct aluguel *alu, int *max, int *count, int *aux, int *auxM, struct cliente *cli, int count_cli, struct veiculo *vei, int count_vei) {
    int opcao = 1;
    while (opcao) {
        if (*aux == 5) {
            descarrega_alus(alu, *count);
            *auxM = (*auxM) - (*aux);
            *aux = 0;
        }
        printf("Submenu Alugueis\n");
        printf("1 - Adicionar um aluguel novo\n");
        printf("2 - Listar todos os alugueis cadastrados\n");
        printf("3 - Mostrar um aluguel específico\n");
        printf("4 - Alterar um cadastro de aluguel específico\n");
        printf("5 - Excluir um cadastro de aluguel específico\n");
        printf("6 - Descarregar as atualizações para a memória(%d)\n", *aux);
        printf("7 - Descartar todas as atualizações(%d)\n", *aux);
        printf("8 - Recarregar os cadastros para memória\n");
        printf("9 - DELETE, mas sem WHERE\n");
        printf("0 - sair\n");
        scanf("%d", &opcao);
        system("cls");
        switch (opcao) {
            case 0:
                printf("\nOh, not the pocket\n\n");
                break;
            case 1:
                if (adiciona_alu(alu, max, count, cli, count_cli, vei, count_vei)) {
                    (*aux)++;
                    (*auxM)++;
                }
                break;
            case 2:
                lista_alus(alu, *count);
                break;
            case 3:
                mostra_alu(alu, *count, cli, count_cli, vei, count_vei);
                break;
            case 4:
                if (altera_alu(alu, *count, cli, count_cli, vei, count_vei)) {
                    (*aux)++;
                    (*auxM)++;
                }
                break;
            case 5:
                if (exclui_alu(alu, count, cli, count_cli, vei, count_vei)) {
                    (*aux)++;
                    (*auxM)++;
                }
                break;
            case 6:
                if (descarrega_alus(alu, *count)) {
                    (*auxM) = (*auxM) - (*aux);
                    (*aux) = 0;
                }
                break;
            case 7:
                extrai_alu(alu, max, count);
                (*auxM) = (*auxM) - (*aux);
                (*aux) = 0;
                break;
            case 8:
                extrai_alu(alu, max, count);
                (*auxM) = (*auxM) - (*aux);
                (*aux) = 0;
                break;
            case 9:
                mata_arquivo("alugueis.txt");
                break;
            default:
                printf("\nIs that all you got, moron?\n");
        }
    }
}

void gerar_relatorios (struct cliente *cli, int count_cli, struct veiculo *vei, int count_vei, struct aluguel *alu, int count_alu) {
    int opcao = 1;
    while (opcao) {
        printf("Submenu Relatórios\n");
        printf("1 - Mostrar todas as reservas de um cliente\n");
        printf("2 - Mostrar todas as reservas de um veículo\n");
        printf("3 - Mostrar os dados de cada carro, o nome e o CPF de cada cliente que fizeram reservas em determinado período\n");
        printf("0 - sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                printf("\nOh, not the pocket\n\n");
                break;
            case 1:
                F_relatorio(cli, count_cli, alu, count_alu);
                break;
            case 2:
                S_relatorio(vei, count_vei, alu, count_alu);
                break;
            case 3:
                T_relatorio(cli, count_cli, vei, count_vei, alu, count_alu);
                break;
            default:
                printf("\nIs that all you got, moron?\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao = 1;
    struct cliente *clientes;
    struct veiculo *veiculos;
    struct aluguel *alugueis;
    int c, v, a;
    int Mc = 100, Mv = 100, Ma = 100;
    int AUXc = 0, AUXv = 0, AUXa = 0;
    int AUXt = 0;
    clientes = (struct cliente *) malloc (100 * sizeof(struct cliente));
    veiculos = (struct veiculo *) malloc (100 * sizeof(struct veiculo));
    alugueis = (struct aluguel *) malloc (100 * sizeof(struct aluguel));
    extrai_cli(clientes, &Mc, &c);
    extrai_vei(veiculos, &Mv, &v);
    extrai_alu(alugueis, &Ma, &a);
    while (opcao) {
        if (AUXt == 10) {
            descarrega_clis(clientes, c);
            descarrega_veis(veiculos, v);
            descarrega_alus(alugueis, a);
            AUXc = AUXv = AUXa = AUXt = 0;
        }
        printf("Menu Locadora de carros\n");
        printf("1 - Submenu clientes(%d)\n", AUXc);
        printf("2 - Submenu veículos(%d)\n", AUXv);
        printf("3 - Submenu alugueis(%d)\n", AUXa);
        printf("4 - Submenu relatórios\n");
        printf("5 - Descarregar todas as atualizações(%d)\n", AUXt);
        printf("6 - Descartar todas as atualizações(%d)\n", AUXt);
        printf("7 - Recarregar todos os cadastros para a memória\n");
        printf("7 - DELETE, mas sem WHERE (todos os arquivos)\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        system("cls");
        switch (opcao) {
            case 0:
                printf("Oh, not the pocket\n");
                break;
            case 1:
                subcli(clientes, &Mc, &c, &AUXc, &AUXt, alugueis, &a);
                break;
            case 2:
                subvei(veiculos, &Mv, &v, &AUXv, &AUXt, alugueis, &a);
                break;
            case 3:
                subalu(alugueis, &Ma, &a, &AUXa, &AUXt, clientes, c, veiculos, v);
                break;
            case 4:
                gerar_relatorios(clientes, c, veiculos, v, alugueis, a);
                break;
            case 5:
                descarrega_clis(clientes, c);
                descarrega_veis(veiculos, v);
                descarrega_alus(alugueis, a);
                AUXc = AUXv = AUXa = AUXt = 0;
                break;
            case 6:
                extrai_cli(clientes, &Mc, &c);
                extrai_vei(veiculos, &Mv, &v);
                extrai_alu(alugueis, &Ma, &a);
                descarrega_clis(clientes, c);
                descarrega_veis(veiculos, v);
                descarrega_alus(alugueis, a);
                AUXc = AUXv = AUXa = AUXt = 0;
                break;
            case 7:
                mata_arquivo("clientes.txt");
                mata_arquivo("veiculos.txt");
                mata_arquivo("alugueis.txt");
                AUXt++;
                break;
            default:
                printf("Is that all you got, moron?\n");
        }
    }
}

/*
    comentários:
	para este projeto, foi feito toda uma reestruturação do código para que este ficasse mais fácil e também mais semântico que sua versão
    parte 1. Para tais reformulações optou-se por separar uma função para cada submenu, sendo eles de cliente, de veículo, de aluguel e de
    relatório. Tiveram varias refatorações e varios reparos, tendo em vista que algumas técnicas foram percebidas e erros SGBD foram
    corrigidos, tais como falta de atomicidade perante um registro, verificações de periodos de aluguel, entre outros. um pequeno adendo:
    embora talvez a eloize não tenha dito em aula, em seu material ela ainda mostra que para poonteiros de struct existe o operador "->",
    o qual pega o endereço da struct apontada e acessa o campo desejado (não se esqueça de que strings são endereços já (vetores homogêneos
    de caractéres), mas interios e flutuantes não).

    funções de base:
	data_extrai:
	    a data_extrai possui uma funcionalidade parecidade com sua primeira versão mas para este projeto, cujo qual extinguiu a função
        data_valor, não modifica o conteúdo de 3 strings que apontavam a fragmentação de cada data, mas sim modifica uma string na qual
        recebe a data invertida no formato AAAA/MM/DD. Está técnica permite a comparação entre as strings sem a necessidade de atribuir
        um valor a cada uma delas. Ou seja, data_extrai é, atualmente, uma mistura das funções data_extrai e data_valor antigas.
	
	verifica_cpf:
	    não possui nenhuma mudança em seu comportamento, portanto, continua usando os passos que se devem ser seguidos para verificar um cpf.

	verifica_data:
	    a parte da função data_extrai que foi perdida teve que vir para função de verificar datas, pois seu funcionamento continua dependendo
        da fragmentação das datas para que se compare manualmente cada requisito de data. 

	cpf_regex, data_regex, telefone_regex, celular_regex:
	    agora, essas funções contam com uma leitura própria das variaveis.

	veiculo_alugavel:
	    com a mudança da função data_extrai, a função veiculo_alugavel se adequou às formas de se comparar datas, agora em seus formatos vetor
        homogêneo de caractéres , ou seja, agora usam as funções strcmp. nessa versão da veiculo_alugavel, foi necessário que se fizesse mais
        uma passagem de parâmetros, tendo em vista que quando tenta-se verificar se um veiculo pode ou não ser alugado após a alteração de uma
        de suas datas nós iriamos acolidir o novo periodo com o antigo causando um veiculo não alugavel, portanto foi impressindível o uso do
        índice do aluguel em questão para eliminar esse problema.

	mata_arquivo:
	    uma função nova, que apenas abre um arquivo em forma de escrita (ou seja, apaga tudo), não escreve nada dentro dele e o fecha.

    funções de cadastro(cliente, veículo, aluguel):
	extrai_cli, extrai_vei, extrai_alu:
	    as funções de carregamento de dados de um arquivo para a memória contam com sistemas de verificação de possibilidade de existência e
        de leitura, tal que se possível inicia-se as tentativas de carregar os dados para a memória, se não for possível carregar tudo,
        tenta-se carregar 5 posições a menos, até que não seja mais possível e então a função retorna ao usuário por meio de uma mensagem
        na tela, dizendo que não foi possível carregar tudo. se não for possível abrir em modo de leitura ou se o arquivo não existir,
        cria-se um arquivo novo.

	realloca_cli, reallocar_vei, realloca_alu:
	    a função irá tentar reallocar mais 100 posições para o vetor, caso não de certo, tenta-se reallocar 5 posições a menos, até que não
        seja possível reallocar mais posições e então a função retorna uma mensagem na tela para que o usuário saiba que não foi possível
        reallocar mais espaço.

	procura_cli, procura_vei, procura_alu:
	    a função irá iterar o vetor em questão atrás de um registro que seja compatível com as chaves requeridas.

	ordena_cli, ordena_vei, ordena_alu:
	    essas funções usam do método bubble de ordenação para ordenar os vetores de acordo com as chaves que cada 1 apresenta.
	    P.s. vide material de ordenação da Eloize.

	adiciona_cli, adiciona_vei, adiciona_alu:
	    para se adicionar um novo registro em uma relação é necessário que verifique se a chave primária não está igual a uma já existente.
	    para a minha modelagem as FKs de aluguel deveriam ser não nulas. caso tudo tenha sido obedecido continua para o resto do registro.

	lista_clis, lista_veis, lista_alus:
	    apenas itera sobre o vetor printando tudo o que tem dentro dele.
	
	mostra_cli, mostra_vei, mostra_alu:
	    faz-se o uso da chave primária para localizar o registro requerido e printa-lo.

	altera_cli, altera_vei, altera_alu:
	    procura-se o registro específico, printa o registro todo mostrando o número de cada campo, após isso
	    pergunta para o usuário quantas coisas ela quer modificar e vai perguntando o que ela quer modificar e
	    qual vai ser o novo valor. recebido o novo valor verifica se ele pode sobreescrever o valor antigo ou não.

	exclui_cli, exclui_vei, exclui_alu:
	    procura-se o registro específico, printa o registro todo e pergunta se o usuário realmente quer deletar
	    o registro. caso ele realmente queira e seja um registro de cliente ou de carro, o registro será deletado
	    logicamente e posteriormente será excluido todos os alugueis em que ele participa (famigerado on delete cascade),
	    caso seja de aluguel só irá excluir o registro.

	descarrega_clis, descarrega_veis, descarrega_alus:
	    irá abrir, se possível, o arquivo em modo de escrita e irá descarregar todo o vetor dentro dele, também se possível.

    funções de relatório:
	F_relatorio:
	    o primeiro relátório, cujo qual pede para informar todos os alugueis de um cliente, pergunta-se qual é o cliente e
	    printa tanto em tela quanto mostra em arquivo todos os registros.
	S_relatorio:
	    o segundo relatório, cujo qual pede para informar todos os alugueis de um veículo, pergunta-se qual é o veículo e 
	    printa tanto em tela quanto mostra em arquivo todos os registros.
	T_relatorio:
	    o terceiro relatório, cujo qual pede para informar todos os clientes e todos os carros que participaram de reservas
	    em determinado período, o qual deve ser informado por meio das datas de início e de fim do período. para printar na
	    tela e mostrar em arquivo, optou-se por mostrar o cliente e o veículo do aluguel cujo qual aconteceu dentro do período
	    exigido.

    funções de menu:
	subcli, subvei, subalu:
	    o menu começa sua rotina verificando se existem atualizações suficientes na memória para que sejam carregados para o arquivo
	    sendo esse número igual a 5, tendo em vista que foi dado para o usuário a liberdade de desconsiderar todas as 4 primeiras
	    atualizações feitas em memória e também que isso custaria menos recursos ao sistema, tendo em vista que reescrever o arquivo
	    toda vez que se fizesse uma atualização em memória poderia ser custoso. foram dadas as opções de adicinar, listar, mostrar,
	    alterar e excluir, como forma de manipular os registros em memória. como opções de gerenciamento de atualizações foram dadas
	    as opções de descarregar ou descartar tudo o que foi feito. como gerenciamento de arquivo foram dadas as opções de recarregar
	    os dados do arquivo e de deletar tudo o que ele continha. e por fim foi dada a opção de navegação entre menus sendo ela a de
	    voltar ao menu principal.

	gerar_relatorios:
	    da ao usuário a opção de gerar o relatório que desejar dentre os que o sistema disponibiliza.

	main:
	    a main inicia o sistema criando todos os recursos necessários para que ele funcionasse, sendo a memória, as variáveis de tamanho
	    as variáveis de tamanho máximo e as variáveis auxiliares para a manipulação de atualizações. aloca a memória de forma dinâmica e
	    carrega as informações do arquivo para a memória. para as atualizações do menu principal, foi decidido que para subir as atualizações
	    de backup seriam necessárias um total de 10 atualizações. ao usuário é dada a opção de navegar entre os menus, fazer manipulação
	    de todas as atualizações, recarregar todos os arquivos para a memória, manipular os arquivos(sempre todos) ou fechar o sistema.
*/