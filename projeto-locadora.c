#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> //somente para setar a setlocale()
#include <ctype.h> //somente para uso da função isdigit()

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

void data_extrai (char data[], char dia[], char mes[], char ano[]) {
    dia[0] = data[0];
    dia[1] = data[1];
    dia[2] = '\0';
    mes[0] = data[3];
    mes[1] = data[4];
    mes[2] = '\0';
    ano[0] = data[6];
    ano[1] = data[7];
    ano[2] = data[8];
    ano[3] = data[9];
    ano[4] = '\0';
}

int data_valor (int dia, int mes, int ano) {
    int dias[] = {0, 31, 60, 91, 121, 152, 182, 216, 244, 275, 305, 335};
    return ano*1000 + dia + dias[mes-1] ;
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
    char dia[3], mes[3], ano[5];
    data_extrai(data, dia, mes, ano);
    if (strcmp(dia, "01") == -1 || strcmp(dia, "31") == 1)
        return 0;
    else if (strcmp(mes, "01") == -1 || strcmp(mes, "12") == 1)
        return 0;
    else if (strcmp(ano, "1800") == -1)
        return 0;
    else if (!strcmp(mes, "01") && strcmp(dia, "31") == 1)
        return 0; 
    else if (!strcmp(mes, "02") && strcmp(dia, "28") == 1 && atoi(ano)%4 != 0)
        return 0;
    else if (!strcmp(mes, "02") && strcmp(dia, "29") == 1 && atoi(ano)%4 == 0)
        return 0;
    else if (!strcmp(mes, "03") && strcmp(dia, "31") == 1)
        return 0;
    else if (!strcmp(mes, "04") && strcmp(dia, "30") == 1)
        return 0;
    else if (!strcmp(mes, "05") && strcmp(dia, "31") == 1)
        return 0;
    else if (!strcmp(mes, "06") && strcmp(dia, "30") == 1)
        return 0;
    else if (!strcmp(mes, "07") && strcmp(dia, "31") == 1)
        return 0;
    else if (!strcmp(mes, "08") && strcmp(dia, "31") == 1)
        return 0;
    else if (!strcmp(mes, "09") && strcmp(dia, "30") == 1)
        return 0;
    else if (!strcmp(mes, "10") && strcmp(dia, "31") == 1)
        return 0;
    else if (!strcmp(mes, "11") && strcmp(dia, "30") == 1)
        return 0;
    else if (!strcmp(mes, "12") && strcmp(dia, "31") == 1)
        return 0;
    return 1;
}

void cpf_regex (char cpf[]) {
    int contnum = 0, i, j;
    char Ncpf[15] = {' ', ' ', ' ', '.', ' ', ' ', ' ', '.', ' ', ' ', ' ', '-', ' ', ' ', '\0'};
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
            else
                contnum = 0;
        } else {
            printf("CPF incorreto, tente novamente\n");
            scanf("%s", cpf);
            contnum = 0;
        }
    }
}

void data_regex (char data[]) {
    int contnum = 0, i, j;
    char Ndata[11] = {' ', ' ', '\\', ' ', ' ', '\\', ' ', ' ', ' ', ' ', '\0'};
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
                printf("Data inválida, tente novamente\n");
                scanf("%s", data);
                contnum = 0;
            }
        } else {
            printf("Data inválida, tente novamente\n");
            scanf("%s", data);
            contnum = 0;
        }
    }
}

void celular_regex (char celular[]) {
    int contnum = 0, i, j;
    char Ncel[16] = {'(', ' ', ' ', ')', ' ', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ', ' ', '\0'};
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
            printf("Celular inválido, tente novamente\n");
            scanf("%s", celular);
            contnum = 0;
        }
    }
}

void telefone_regex (char telefone[]) {
    int contnum = 0, i, j;
    char Ntel[15] = {'(', ' ', ' ', ')', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ', ' ', '\0'};
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
            printf("Telefone inválido, tente novamente\n");
            scanf("%s", telefone);
            contnum = 0;
        }
    }
}

int procura_cliente (struct cliente clientes[], int c, char cpf[]) {
    int i;
    for (i=0; i<c; i++) {
        if (!strcmp(cpf, clientes[i].cpf)) 
            return i;
    }
    return -1;
}

int procura_veiculo (struct veiculo veiculos[], int v, int codigo) {
    int i;
    for (i=0; i<v; i++) {
        if (codigo == veiculos[i].codigo) 
            return i;
    }
    return -1;
}

int procura_aluguel (struct aluguel alugueis[], int a, char dataout[], char datain[], char cpfcli[], int codveic) {
    int i;
    for (i=0; i<a; i++) {
        if (!strcmp(alugueis[i].dataretirada, dataout) && !strcmp(alugueis[i].datadevolucao, datain))
            if (!strcmp(alugueis[i].cpfcli, cpfcli) && alugueis[i].codveic == codveic)
                return i;
    }
    return -1;
}

int veiculo_alugavel (struct aluguel alugueis[], int a, int codigo, char datapega[], char datadevol[]) {
    int i, valorpega, valordevolve, valorpegaA, valordevolveA;
    char ano[5], mes[3], dia[3], anoA[5], mesA[3], diaA[3];
    char anod[5], mesd[3], diad[3], anoAd[5], mesAd[3], diaAd[3];
    data_extrai(datapega, dia, mes, ano);
    valorpega = data_valor(atoi(dia), atoi(mes), atoi(ano));
    data_extrai(datadevol, diad, mesd, anod);
    valordevolve = data_valor(atoi(diad), atoi(mesd), atoi(anod));
    if (valorpega < valordevolve) {
        for (i=0; i<a; i++) {
            if (alugueis[i].codveic == codigo) {
                data_extrai(alugueis[i].dataretirada, diaA, mesA, anoA);
                valorpegaA = data_valor(atoi(diaA), atoi(mesA), atoi(anoA));
                data_extrai(alugueis[i].datadevolucao, diaAd, mesAd, anoAd);
                valordevolveA = data_valor(atoi(diaAd), atoi(mesAd), atoi(anoAd));
                if ((valorpega < valorpegaA) && (valorpegaA < valordevolve))
                    return 0;
                else if ((valorpega == valorpegaA) || (valordevolve == valordevolveA) || (valorpega == valordevolveA) || (valordevolve == valorpegaA))
                    return 0;
                else if ((valorpega > valorpegaA) && (valordevolve < valordevolveA))
                    return 0;
                else if ((valorpega > valorpegaA) && (valordevolve > valordevolveA) && (valorpega < valordevolveA))
                    return 0;
            }
        }
    } else
        return 0;
    return 1;
}

void ordena_registro(int n, struct cliente clientes[], struct veiculo veiculos[], struct aluguel alugueis[], int c, int v, int a) {
    int i, j;
    struct cliente intermediarioC;
    struct veiculo intermediarioV;
    struct aluguel intermediarioA;
    switch (n) {
        case 1:
            for (i=0;i<c;i++)
                for (j=0;j<c-1;j++) {
                    if (strcmp(clientes[j].cpf, clientes[j+1].cpf) == 1) {
                        strcpy(intermediarioC.cpf, clientes[j+1].cpf);
                        strcpy(intermediarioC.nome, clientes[j+1].nome);
                        strcpy(intermediarioC.endereco, clientes[j+1].endereco);
                        strcpy(intermediarioC.dataNasc, clientes[j+1].dataNasc);
                        strcpy(intermediarioC.telefone, clientes[j+1].telefone);
                        strcpy(intermediarioC.celular, clientes[j+1].celular);
                        strcpy(clientes[j+1].cpf, clientes[j].cpf);
                        strcpy(clientes[j+1].nome, clientes[j].nome);
                        strcpy(clientes[j+1].endereco, clientes[j].endereco);
                        strcpy(clientes[j+1].dataNasc, clientes[j].dataNasc);
                        strcpy(clientes[j+1].telefone, clientes[j].telefone);
                        strcpy(clientes[j+1].celular, clientes[j].celular);
                        strcpy(clientes[j].cpf, intermediarioC.cpf);
                        strcpy(clientes[j].nome, intermediarioC.nome);
                        strcpy(clientes[j].endereco, intermediarioC.endereco);
                        strcpy(clientes[j].dataNasc, intermediarioC.dataNasc);
                        strcpy(clientes[j].telefone, intermediarioC.telefone);
                        strcpy(clientes[j].celular, intermediarioC.celular);
                    }
                }
            break;
        case 2:
            for (i=0;i<v;i++)
                for (j=0;j<v-1;j++) {
                    if (veiculos[j].codigo > veiculos[j+1].codigo) {
                        intermediarioV.codigo = veiculos[j+1].codigo;
                        strcpy(intermediarioV.descricao, veiculos[j+1].descricao);
                        strcpy(intermediarioV.categoria, veiculos[j+1].categoria);
                        strcpy(intermediarioV.modelo, veiculos[j+1].modelo);
                        intermediarioV.capacidade = veiculos[j+1].capacidade;
                        intermediarioV.combustivel = veiculos[j+1].combustivel;
                        intermediarioV.ano = veiculos[j+1].ano;
                        veiculos[j+1].codigo = veiculos[j].codigo;
                        strcpy(veiculos[j+1].descricao, veiculos[j].descricao);
                        strcpy(veiculos[j+1].categoria, veiculos[j].categoria);
                        strcpy(veiculos[j+1].modelo, veiculos[j].modelo);
                        veiculos[j+1].capacidade = veiculos[j].capacidade;
                        veiculos[j+1].combustivel = veiculos[j].combustivel;
                        veiculos[j+1].ano = veiculos[j].ano;
                        veiculos[j].codigo = intermediarioV.codigo;
                        strcpy(veiculos[j].descricao, intermediarioV.descricao);
                        strcpy(veiculos[j].categoria, intermediarioV.categoria);
                        strcpy(veiculos[j].modelo, intermediarioV.modelo);
                        veiculos[j].capacidade = intermediarioV.capacidade;
                        veiculos[j].combustivel = intermediarioV.combustivel;
                        veiculos[j].ano = intermediarioV.ano;
                    }
                }
            break;
        case 3:
            for (i=0;i<a;i++)
                for (j=0;j<a-1;j++) {
                    if (strcmp(alugueis[j].cpfcli, alugueis[j+1].cpfcli) == 1 || alugueis[j].codveic > alugueis[j+1].codveic) {
                        strcpy(intermediarioA.cpfcli, alugueis[j+1].cpfcli);
                        strcpy(intermediarioA.dataretirada, alugueis[j+1].dataretirada);
                        strcpy(intermediarioA.datadevolucao, alugueis[j+1].datadevolucao);
                        intermediarioA.codveic = alugueis[j+1].codveic;
                        strcpy(alugueis[j+1].cpfcli, alugueis[j].cpfcli);
                        strcpy(alugueis[j+1].dataretirada, alugueis[j].dataretirada);
                        strcpy(alugueis[j+1].datadevolucao, alugueis[j].datadevolucao);
                        alugueis[j+1].codveic = alugueis[j].codveic;
                        strcpy(alugueis[j].cpfcli, intermediarioA.cpfcli);
                        strcpy(alugueis[j].dataretirada, intermediarioA.dataretirada);
                        strcpy(alugueis[j].datadevolucao, intermediarioA.datadevolucao);
                        alugueis[j].codveic = intermediarioA.codveic;
                    }
                }
    }
}

void adicionar(int n, struct cliente clientes[], struct veiculo veiculos[], struct aluguel alugueis[], int *c, int *v, int *a) {
    char cpfteste[15];
    int codteste;
    struct aluguel aluguelteste;
    switch (n) {
        case 1:
            fflush(stdin);
            if (*c < 100) {
                printf("Digite o CPF do cliente\n");
                gets(cpfteste);
				cpf_regex(cpfteste);
                if (procura_cliente(clientes, *c, cpfteste) == -1) {
                    strcpy(clientes[*c].cpf, cpfteste);
                    fflush(stdin);
                    printf("Digite o nome\n");
                    gets(clientes[*c].nome);
                    printf("Digite o endereço\n");
                    gets(clientes[*c].endereco);
                    printf("Digite a data de nascimento(dd/mm/aaaa)\n");
                    gets(clientes[*c].dataNasc);
                    data_regex(clientes[*c].dataNasc);
                    fflush(stdin);
                    printf("Digite o telefone\n");
                    gets(clientes[*c].telefone);
                    telefone_regex(clientes[*c].telefone);
                    fflush(stdin);
                    printf("Digite o celular\n");
                    gets(clientes[*c].celular);
                    celular_regex(clientes[*c].celular);
                    (*c)++;
                    printf("Cadastro efetuado com sucesso\n\n");
                    ordena_registro(1, clientes, veiculos, alugueis, *c, *v, *a);
                } else
                    printf("Cliente já cadastrado, tente novamente\n");
            } else
                printf("Entidade cliente atingiu sua capacidade máxima\n");
            break;
        case 2:
            if (*v < 100) {
                printf("Digite o código do veículo\n");
                scanf("%d", &codteste);
                if (procura_veiculo(veiculos, *v, codteste) == -1) {
                    veiculos[*v].codigo = codteste;
                    fflush(stdin);
                    printf("Digite a descricao\n");
                    gets(veiculos[*v].descricao);
                    printf("Digite a categoria\n");
                    gets(veiculos[*v].categoria);
                    printf("Digite o modelo\n");
                    gets(veiculos[*v].modelo);
                    printf("Digite a capacidade\n");
                    scanf("%f", &veiculos[*v].capacidade);
                    printf("Digite o combustivel\n");
                    scanf("%f", &veiculos[*v].combustivel);
                    printf("Digite o ano\n");
                    scanf("%d", &veiculos[*v].ano);
                    (*v)++;
                    printf("Cadastro efetuado com sucesso\n\n");
                    ordena_registro(2, clientes, veiculos, alugueis, *c, *v, *a);
                } else
                    printf("Veículo já cadastrado, tente novamente\n");
            } else
                printf("Entidade veículo atingiu sua capacidade máxima\n");
            break;
        case 3:
            fflush(stdin);
            if (*a < 100) {
                printf("Digite o CPF do cliente\n");
                gets(aluguelteste.cpfcli);
                cpf_regex(aluguelteste.cpfcli);
                if (procura_cliente(clientes, *c, aluguelteste.cpfcli) != -1) {
                    printf("Digite o código do carro\n");
                    scanf("%d", &aluguelteste.codveic);
                    if (procura_veiculo(veiculos, *v, aluguelteste.codveic) != -1) {
                        printf("Digite a data de retirada\n");
                        fflush(stdin);
                        gets(aluguelteste.dataretirada);
                        data_regex(aluguelteste.dataretirada);
                        printf("Digite a data de devolução\n");
                        gets(aluguelteste.datadevolucao);
                        data_regex(aluguelteste.datadevolucao);
                        if (veiculo_alugavel(alugueis, *a, aluguelteste.codveic, aluguelteste.dataretirada, aluguelteste.datadevolucao))
                            if (procura_aluguel(alugueis, *a, aluguelteste.dataretirada, aluguelteste.datadevolucao, aluguelteste.cpfcli, aluguelteste.codveic) == -1) {
                                strcpy(alugueis[*a].cpfcli, aluguelteste.cpfcli);
                                alugueis[*a].codveic = aluguelteste.codveic;
                                strcpy(alugueis[*a].dataretirada, aluguelteste.dataretirada);
                                strcpy(alugueis[*a].datadevolucao, aluguelteste.datadevolucao);
                                (*a)++;
                                printf("Cadastro efetuado com sucesso\n\n");
                                ordena_registro(3, clientes, veiculos, alugueis, *c, *v, *a);
                            } else
                                printf("Aluguel já existe, tente novamente\n");
                        else
                            printf("Veículo não pode ser alugado nas datas informadas, tente novamente\n");
                    } else
                        printf("Veículo não encontrado, tente novamente\n");
                } else
                    printf("Cliente não encontrado, tente novamente\n");
            } else
                printf("Entidade aluguel atingiu sua capacidade máxima\n");
    }
}

void listar(int n, struct cliente clientes[], struct veiculo veiculos[], struct aluguel alugueis[], int c, int v, int a) {
    int i, j;
    switch (n) {
        case 1:
            printf("\t\tLista de clientes\n\n");
            for (i=0;i<c;i++) {
                printf("Nome: %s\nCPF: %s\nEndereço: %s\n", clientes[i].nome, clientes[i].cpf, clientes[i].endereco);
                printf("Data de nascimento: %s\nCelular: %s\nTelefone: %s\n", clientes[i].dataNasc, clientes[i].celular, clientes[i].telefone);
                printf("---------------------------------------------\n");
            }
            break;
        case 2:
            printf("\t\tLista de veículos\n\n");
            for (i=0;i<v;i++) {
                printf("Modelo: %s\nCódigo: %d\nCategoria: %s\n", veiculos[i].modelo, veiculos[i].codigo, veiculos[i].categoria);
                printf("Ano: %d\nCapacidade: %f\nCombustível: %f\n", veiculos[i].ano, veiculos[i].capacidade, veiculos[i].combustivel);
                printf("descrição: %s\n", veiculos[i].descricao);
                printf("---------------------------------------------\n");
            }
            break;
        case 3:
            printf("\t\tLista de alugueis\n\n");
            for (i=0;i<a;i++) {
                printf("CPF: %s\nCódigo: %d\n", alugueis[i].cpfcli, alugueis[i].codveic);
                printf("Data de retirada: %s\nData de devolução: %s\n", alugueis[i].dataretirada, alugueis[i].datadevolucao);
                printf("---------------------------------------------\n");
            }
    }
}

void mostrar(int n, struct cliente clientes[], struct veiculo veiculos[], struct aluguel alugueis[], int c, int v, int a) {
    int indice;
    char cpfteste[15];
    int codteste;
    struct aluguel aluguelteste;
    switch (n) {
        case 1:
            printf("Digite o CPF do cliente procurado\n");
            scanf("%s", cpfteste);
            cpf_regex(cpfteste);
            indice = procura_cliente(clientes, c, cpfteste);
            if (indice == -1) 
                printf("Cliente não encontrado, tente novamente\n");
            else {
                printf("cadastro encontrado:\n");
                printf("Nome: %s\nCPF: %s\nEndereço: %s\n", clientes[indice].nome, clientes[indice].cpf, clientes[indice].endereco);
                printf("Data de nascimento: %s\nCelular: %s\nTelefone: %s\n", clientes[indice].dataNasc, clientes[indice].celular, clientes[indice].telefone);
            }
            break;
        case 2:
            printf("Digite o código do veículo procurado\n");
            scanf("%d", &codteste);
            indice = procura_veiculo(veiculos, v, codteste);
            if (indice == -1) 
                printf("Veículo não encontrado, tente novamente\n");
            else {
                printf("cadastro encontrado:\n");
                printf("Modelo: %s\nCódigo: %d\nCategoria: %s\n", veiculos[indice].modelo, veiculos[indice].codigo, veiculos[indice].categoria);
                printf("Ano: %d\nCapacidade: %f\nCombustível: %f\n", veiculos[indice].ano, veiculos[indice].capacidade, veiculos[indice].combustivel);
                printf("descrição: %s\n", veiculos[indice].descricao);
            }
            break;
        case 3:
            printf("Digite o cpf do cliente no aluguel procurado\n");
            scanf("%s", &aluguelteste.cpfcli);
            cpf_regex(aluguelteste.cpfcli);
            if (procura_cliente(clientes, c, aluguelteste.cpfcli) != -1) {
                printf("Digite o código do veículo no aluguel procurado\n");
                scanf("%d", &aluguelteste.codveic);
                if (procura_veiculo(veiculos, v, aluguelteste.codveic) != -1) {
                    printf("Digite a data de retirada do veículo no aluguel procurado\n");
                    scanf("%s", &aluguelteste.dataretirada);
                    data_regex(aluguelteste.dataretirada);
                    printf("Digite a data de devolução do veículo no aluguel procurado\n");
                    scanf("%s", &aluguelteste.datadevolucao);
                    data_regex(aluguelteste.datadevolucao);
                    if (procura_aluguel(alugueis, a, aluguelteste.dataretirada, aluguelteste.datadevolucao, aluguelteste.cpfcli, aluguelteste.codveic) != -1) {
                        printf("cadastro encontrado:\n");
                        printf("CPF: %s\nCódigo do veículo: %d\n", aluguelteste.cpfcli, aluguelteste.codveic);
                        printf("Data de retirada: %s\nData de devolução: %s\n", aluguelteste.dataretirada, aluguelteste.datadevolucao);
                    } else
                        printf("Aluguel não encontrado, tente novamente\n");
                } else
                    printf("Veículo não cadastrado, tente novamente\n");
            } else
                printf("Cliente não cadastrado, tente novamente\n");
    }
}

void alterar(int n, struct cliente clientes[], struct veiculo veiculos[], struct aluguel alugueis[], int c, int v, int a) {
    int indice, quanti, i, escolha;
    char cpfteste[15];
    int codteste;
    struct aluguel aluguelteste;
    switch (n) {
        case 1:
            printf("Digite o CPF do cliente\n");
            scanf("%s", cpfteste);
            cpf_regex(cpfteste);
            indice = procura_cliente(clientes, c, cpfteste);
            if (indice != -1) {
                printf("cadastro encontrado:\n");
                printf("Nome(1): %s\nCPF(2): %s\nEndereço(3): %s\n", clientes[indice].nome, clientes[indice].cpf, clientes[indice].endereco);
                printf("Data de nascimento(4): %s\nCelular(5): %s\nTelefone(6): %s\n", clientes[indice].dataNasc, clientes[indice].celular, clientes[indice].telefone);
                printf("\nDigite quantos campos serão alterados\n");
                scanf("%d", &quanti);
                for (i=0;i<quanti;i++) {
                    printf("Digite o número do campo que será alterado\n");
                    scanf("%d", &escolha);
                    printf("Digite o novo valor\n");
                    fflush(stdin);
                    switch (escolha) {
                        case 1:
                            gets(clientes[indice].nome);
                            break;
                        case 2:
                            gets(clientes[indice].cpf);
                            cpf_regex(clientes[indice].cpf);
                            break;
                        case 3:
                            gets(clientes[indice].endereco);
                            break;
                        case 4:
                            gets(clientes[indice].dataNasc);
                            data_regex(clientes[indice].dataNasc);
                            break;
                        case 5:
                            gets(clientes[indice].celular);
                            celular_regex(clientes[indice].celular);
                            break;
                        case 6:
                            gets(clientes[indice].telefone);
                            telefone_regex(clientes[indice].telefone);
                    }
                }
                ordena_registro(1, clientes, veiculos, alugueis, c, v, a);
            } else
                printf("Cliente não encontrado, tente novamente\n");
            break;
        case 2:
            printf("Digite o código do carro\n");
            scanf("%d", &codteste);
            indice = procura_veiculo(veiculos, v, codteste);
            if (indice != -1) {
                printf("cadastro encontrado:\n");
                printf("Modelo(1): %s\nCódigo(2): %d\nCategoria(3): %s\n", veiculos[indice].modelo, veiculos[indice].codigo, veiculos[indice].categoria);
                printf("Ano(4): %d\nCapacidade(5): %f\nCombustível(6): %f\n", veiculos[indice].ano, veiculos[indice].capacidade, veiculos[indice].combustivel);
                printf("descrição(7): %s\n", veiculos[indice].descricao);
                printf("\nDigite quantos campos serão alterados\n");
                scanf("%d", &quanti);
                for (i=0;i<quanti;i++) {
                    printf("Digite o número do campo que será alterado\n");
                    scanf("%d", &escolha);
                    printf("Digite o novo valor\n");
                    fflush(stdin);
                    switch (escolha) {
                        case 1:
                            gets(veiculos[indice].modelo);
                            break;
                        case 2:
                            scanf("%d", &veiculos[indice].codigo);
                            break;
                        case 3:
                            gets(veiculos[indice].categoria);
                            break;
                        case 4:
                            scanf("%d", &veiculos[indice].ano);
                            break;
                        case 5:
                            scanf("%f", &veiculos[indice].capacidade);
                            break;
                        case 6:
                            scanf("%f", &veiculos[indice].combustivel);
                            break;
                        case 7:
                            gets(veiculos[indice].descricao);
                    }
                }
                ordena_registro(2, clientes, veiculos, alugueis, c, v, a);
            } else 
                printf("Veículo não encontrado, tente novamente\n");
            break;
        case 3:
            printf("Digite o cpf do cliente\n");
            scanf("%s", &aluguelteste.cpfcli);
            cpf_regex(aluguelteste.cpfcli);
            if (procura_cliente(clientes, c, aluguelteste.cpfcli) != -1) {
                printf("Digite o código do veículo\n");
                scanf("%d", &aluguelteste.codveic);
                if (procura_veiculo(veiculos, v, aluguelteste.codveic) != -1) {
                    printf("Digite a data de retirada do veículo\n");
                    scanf("%s", &aluguelteste.dataretirada);
                    data_regex(aluguelteste.dataretirada);
                    printf("Digite a data de devolução do veículo\n");
                    scanf("%s", &aluguelteste.datadevolucao);
                    data_regex(aluguelteste.datadevolucao);
                    indice = procura_aluguel(alugueis, a, aluguelteste.dataretirada, aluguelteste.datadevolucao, aluguelteste.cpfcli, aluguelteste.codveic);
                    if (indice != -1) {
                        printf("cadastro encontrado:\n");
                        printf("CPF(1): %s\nCódigo do veículo(2): %d\n", aluguelteste.cpfcli, aluguelteste.codveic);
                        printf("Data de retirada(3): %s\nData de devolução(4): %s\n", aluguelteste.dataretirada, aluguelteste.datadevolucao);
                        printf("\nDigite quantos campos serão alterados\n");
                        scanf("%d", &quanti);
                        for (i=0;i<quanti;i++) {
                            printf("Digite o número do campo que será alterado\n");
                            scanf("%d", &escolha);
                            printf("Digite o novo valor\n");
                            fflush(stdin);
                            switch (escolha) {
                                case 1:
                                    gets(aluguelteste.cpfcli);
                                    cpf_regex(aluguelteste.cpfcli);
                                    if (procura_cliente(clientes, c, aluguelteste.cpfcli) != -1)
                                        strcpy(alugueis[indice].cpfcli, aluguelteste.cpfcli);
                                    else
                                        printf("Cliente não encontrado, tente novamente\n");
                                    break;
                                case 2:
                                    scanf("%d", &aluguelteste.codveic);
                                    if (procura_veiculo(veiculos, v, aluguelteste.codveic) != -1)
                                        alugueis[indice].codveic = aluguelteste.codveic;
                                    else
                                        printf("Veículo não encontrado, tente novamente\n");
                                    break;
                                case 3:
                                    gets(alugueis[indice].dataretirada);
                                    data_regex(alugueis[indice].dataretirada);
                                    break;
                                case 4:
                                    gets(alugueis[indice].datadevolucao);
                                    data_regex(alugueis[indice].datadevolucao);
                            }
                        }
                        ordena_registro(3, clientes, veiculos, alugueis, c, v, a);
                    } else
                        printf("Aluguel não encontrado, tente novamente\n");
                } else
                    printf("Veículo não encontrado, tente novamente\n");
            } else
                printf("Cliente não encontrado, tente novamente\n");
    }
}

void excluir(int n, struct cliente clientes[], struct veiculo veiculos[], struct aluguel alugueis[], int *c, int *v, int *a) {
    int indice, confirma, i;
    char cpfteste[15];
    int codteste;
    struct aluguel aluguelteste;
    switch (n) {
        case 1:
            printf("Digite o CPF do cliente a ser excluido\n");
            scanf("%s", cpfteste);
            cpf_regex(cpfteste);
            indice = procura_cliente(clientes, *c, cpfteste);
            if (indice != -1) {
                printf("cadastro encontrado:\n");
                printf("Nome: %s\nCPF: %s\nEndereço: %s\n", clientes[indice].nome, clientes[indice].cpf, clientes[indice].endereco);
                printf("Data de nascimento: %s\nCelular: %s\nTelefone: %s\n", clientes[indice].dataNasc, clientes[indice].celular, clientes[indice].telefone);
                printf("Deseja mesmo excluir este cliente? (1/0)\n");
                scanf("%d", &confirma);
                if (confirma) {
                    for (i=indice;i<(*c)-1;i++) {
                        strcpy(clientes[i].cpf, clientes[i+1].cpf);
                        strcpy(clientes[i].nome, clientes[i+1].nome);
                        strcpy(clientes[i].endereco, clientes[i+1].endereco);
                        strcpy(clientes[i].dataNasc, clientes[i+1].dataNasc);
                        strcpy(clientes[i].telefone, clientes[i+1].telefone);
                        strcpy(clientes[i].celular, clientes[i+1].celular);
                    }
                    (*c)--;
                    printf("Exclusão concluida\n");
                } else
                    printf("Exclusão cancelada\n");
            } else
                printf("Cliente não encontrado, tente novamente\n");
            break;
        case 2:
            printf("Digite o código do veículo a ser excluido\n");
            scanf("%d", &codteste);
            indice = procura_veiculo(veiculos, *v, codteste);
            if (indice != -1) {
                printf("Modelo: %s\nCódigo: %d\nCategoria: %s\n", veiculos[indice].modelo, veiculos[indice].codigo, veiculos[indice].categoria);
                printf("Ano: %d\nCapacidade: %f\nCombustível: %f\n", veiculos[indice].ano, veiculos[indice].capacidade, veiculos[indice].combustivel);
                printf("descrição: %s\n", veiculos[indice].descricao);
                printf("Deseja mesmo excluir este cliente? (1/0)\n");
                scanf("%d", &confirma);
                if (confirma) {
                    for (i=indice;i<(*v)-1;i++) {
                        veiculos[i].codigo = veiculos[i+1].codigo;
                        strcpy(veiculos[i].modelo, veiculos[i+1].modelo);
                        strcpy(veiculos[i].categoria, veiculos[i+1].categoria);
                        strcpy(veiculos[i].descricao, veiculos[i+1].descricao);
                        veiculos[i].capacidade = veiculos[i+1].capacidade;
                        veiculos[i].combustivel = veiculos[i+1].combustivel;
                        veiculos[i].ano = veiculos[i+1].ano;
                    }
                    (*v)--;
                    printf("Exclusão concluida\n");
                } else
                    printf("Exclusão cancelada\n");
            } else
                printf("Veículo não encontrado, tente novamente\n");
            break;
        case 3:
            printf("Digite o cpf do cliente\n");
            scanf("%s", &aluguelteste.cpfcli);
            cpf_regex(aluguelteste.cpfcli);
            if (procura_cliente(clientes, *c, aluguelteste.cpfcli) != -1) {
                printf("Digite o código do veículo\n");
                scanf("%d", &aluguelteste.codveic);
                if (procura_veiculo(veiculos, *v, aluguelteste.codveic) != -1) {
                    printf("Digite a data de retirada do veículo\n");
                    scanf("%s", &aluguelteste.dataretirada);
                    data_regex(aluguelteste.dataretirada);
                    printf("Digite a data de devolução do veículo\n");
                    scanf("%s", &aluguelteste.datadevolucao);
                    data_regex(aluguelteste.datadevolucao);
                    indice = procura_aluguel(alugueis, *a, aluguelteste.dataretirada, aluguelteste.datadevolucao, aluguelteste.cpfcli, aluguelteste.codveic);
                    if (indice != -1) {
                        printf("CPF(1): %s\nCódigo do veículo(2): %d\n", aluguelteste.cpfcli, aluguelteste.codveic);
                        printf("Data de retirada(3): %s\nData de devolução(4): %s\n", aluguelteste.dataretirada, aluguelteste.datadevolucao);
                        printf("Deseja mesmo excluir este cliente? (1/0)\n");
                        scanf("%d", &confirma);
                        if (confirma) {
                            for (i=indice;i<(*a)-1;i++) {
                                strcpy(alugueis[i].cpfcli, alugueis[i+1].cpfcli);
                                alugueis[i].codveic = alugueis[i+1].codveic;
                                strcpy(alugueis[i].dataretirada, alugueis[i+1].dataretirada);
                                strcpy(alugueis[i].datadevolucao, alugueis[i+1].datadevolucao);
                            }
                            (*a)--;
                            printf("Exclusão concluida\n");
                        } else
                            printf("Exclusão cancelada\n");
                    } else
                        printf("Aluguel não encontrado, tente novamente\n");
                } else
                    printf("Veículo não encontrado, tente novamente\n");
            } else
                printf("Cliente não encontrado, tente novamente\n");
    }
}

void submenu (int n, struct cliente clientes[], struct veiculo veiculos[], struct aluguel alugueis[], int *c, int *v, int *a) {
    int opcao = 1;
    while (opcao) {
        switch (n)
        {
            case 1:
                printf ("Submenu clientes\n");
                break;
            case 2:
                printf ("Submenu veículos\n");
                break;
            case 3:
                printf ("Submenu alugueis\n");
        }
        printf("1 - Adicionar cadastro\n");
        printf("2 - Listar todos os cadastros\n");
        printf("3 - Mostrar um cadastro específico\n");
        printf("4 - Alterar um cadastro\n");
        printf("5 - Excluir um cadastro\n");
        printf("0 - sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                system("cls");
                break;
            case 1:
                system("cls");
                adicionar(n, clientes, veiculos, alugueis, c, v, a);
                break;
            case 2:
                system("cls");
                listar(n, clientes, veiculos, alugueis, *c, *v, *a);
                break;
            case 3:
                system("cls");
                mostrar(n, clientes, veiculos, alugueis, *c, *v, *a);
                break;
            case 4:
                system("cls");
                alterar(n, clientes, veiculos, alugueis, *c, *v, *a);
                break;
            case 5:
                system("cls");
                excluir(n, clientes, veiculos, alugueis, c, v, a);
                break;
            default:
                system("cls");
                printf("Opção inválida, tente novamente\n");
        }
    }
}

void gerar_relatorio(struct cliente clientes[], struct veiculo veiculos[], struct aluguel alugueis[], int c, int v, int a) {
    int opcao = 1, i, alugou = 0;
    char cpf[15];
    int codigo;
    char dataini[11], datafim[11];
    char diarefin[3], mesrefin[3], anorefin[5], diareff[3], mesreff[3], anoreff[5];
    char diaAin[3], mesAin[3], anoAin[5], diaAf[3], mesAf[3], anoAf[5];
    while (opcao) {
        printf("Submenu Relatórios\n");
        printf("1 - Mostrar todas as reservas de um cliente\n");
        printf("2 - Mostrar todas as reservas de um veículo\n");
        printf("3 - Mostrar todas as reservas em um periodo de tempo\n");
        printf("0 - sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                system("cls");
                break;
            case 1:
                system("cls");
                printf("Digite o CPF do cliente\n");
                scanf("%s", cpf);
                cpf_regex(cpf);
                printf("------------Alugueis------------\n");
                for (i=0;i<a;i++) {
                    if (!strcmp(cpf, alugueis[i].cpfcli)) {
                        printf("CPF: %s\nCódigo: %d\nData de retirada: %s\nData de devolução: %s\n", alugueis[i].cpfcli, alugueis[i].codveic, alugueis[i].dataretirada, alugueis[i].datadevolucao);
                        printf("--------------------------------\n");
                        alugou++;
                    }
                }
                printf("O cliente fez %d aluguel(is)\n", alugou);
                if (!alugou)
                    printf("O cliente não possui alugueis cadastrados\n");
                break;
            case 2:
                system("cls");
                printf("Digite o codigo do veículo\n");
                scanf("%d", &codigo);
                printf("------------Alugueis------------\n");
                for (i=0;i<a;i++) {
                    if (codigo == alugueis[i].codveic) {
                        printf("CPF: %s\nCódigo: %d\nData de retirada: %s\nData de devolução: %s\n", alugueis[i].cpfcli, alugueis[i].codveic, alugueis[i].dataretirada, alugueis[i].datadevolucao);
                        printf("--------------------------------\n");
                        alugou++;
                    }
                }
                printf("O veículo foi alugado %d vez(es)\n", alugou);
                if (!alugou)
                    printf("O veículo não possui alugueis cadastrados\n");
                break;
            case 3:
                system("cls");
                printf("Digite a data de referencia de início\n");
                scanf("%s", dataini);
                data_regex(dataini);
                data_extrai(dataini, diarefin, mesrefin, anorefin);
                printf("Digite a data de referencia de fim\n");
                scanf("%s", datafim);
                data_regex(datafim);
                data_extrai(datafim, diareff, mesreff, anoreff);
                printf("------------Alugueis------------\n");
                for (i=0;i<a;i++) {
                    data_extrai(alugueis[i].dataretirada, diaAin, mesAin, anoAin);
                    data_extrai(alugueis[i].datadevolucao,diaAf, mesAf, anoAf);
                    if (data_valor(atoi(diarefin), atoi(mesrefin), atoi(anorefin)) < data_valor(atoi(diaAin), atoi(mesAin), atoi(anoAin)))
                        if(data_valor(atoi(diareff), atoi(mesreff), atoi(anoreff)) > data_valor(atoi(diaAf), atoi(mesAf), atoi(anoAf))) {
                            printf("CPF: %s\nCódigo: %d\nData de retirada: %s\nData de devolução: %s\n", alugueis[i].cpfcli, alugueis[i].codveic, alugueis[i].dataretirada, alugueis[i].datadevolucao);
                            printf("--------------------------------\n");
                            alugou++;
                        }
                }
                printf("Existem %d alugueis compreendidos entre as datas %s e %s\n", alugou, dataini, datafim);
        }
        alugou = 0;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao = 1;
    struct cliente clientes[100];
    struct veiculo veiculos[100];
    struct aluguel alugueis[100];
    int c, v, a;
    c = v = a = 0; 
    while (opcao) {
        printf("Menu Locadora de carros\n");
        printf("1 - Submenu clientes\n");
        printf("2 - Submenu veículos\n");
        printf("3 - Submenu alugueis\n");
        printf("4 - Submenu relatórios\n");
        printf("0 - sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                system("cls");
                break;
            case 1:
                system("cls");
                submenu(1, clientes, veiculos, alugueis, &c, &v, &a);
                break;
            case 2:
                system("cls");
                submenu(2, clientes, veiculos, alugueis, &c, &v, &a);
                break;
            case 3:
                system("cls");
                submenu(3, clientes, veiculos, alugueis, &c, &v, &a);
                break;
            case 4:
                system("cls");
                gerar_relatorio(clientes, veiculos, alugueis, c, v, a);
                break;
            default:
                system("cls");
                printf("Opção inválida, tente novamente\n");
        }
    }
}

/* 
**Sessão de comentários**

percausos do progresso (coisas que podem gerar erros ou alarmes ou apenas dicas):
    - declarar variáveis dentro de cases.
    - mudar o protótipo da função e não mudar os parâmetros na chamada dela.
    - usar a função sem incluir sua biblioteca
    - esquecer que strings não são como os outros valores (mas cada caracter que as compõem são)
    - criar muitas variáveis sendo que nós ja temos uma struct inteira que tem os mesmos tipos de dados
    - confundir as relações lógicas em condições de IFs
    - iterar índices a mais do que o vetor possui (ou acessar índices que ele não possui)
    - querer mais espaço do que o S.O. poderia me ceder (10000 posições nos vetores struct são incompiláveis)
    - esquecer de pedir para o usuário reescrever algum dado, gerando assim um loop infinito
    - funções muito grandes, que usam as mesmas linhas em várias partes de if-else (funções refatoradas, logo não teremos exemplos)
    - esquecer de chaves em estruturas com mais de 1 linha de execução
    - confundir mascará de formatação

data_extrai:
    com a data padronizada, é possível obter o dia, o mes e o ano de uma data, pois ja sabemos exatamente onde encontrar os digitos.
    Essa função de separação recebe uma string data e o endereço de outras 3 strings que são um dia, mes e ano, respectivamente.
    A função foi construida exclusivamente pq as funções strcpy e strncpy ficavam um pouco esquisitos do entender ao final do processo.
    Ela não retorna nada pois como são ponteiros, tudo ja foi modificado fora da função.

data_valor:
    Na necessidade de se comparar datas de forma correta, tendo em vista que strcmp("01/02/2001", "02/01/2001") retorna -1
    foi preciso atribuir uma valor às datas, para que eles fossem comparados e decidido se uma data é maior ou não que outra.
    Para isso, a ideia foi de que: soma ao valor do ano, multiplicado por 1000, o valor do dia e o valor de dias que o mes corresponde
    incluindo o dia 29/02. com isso, nós temos uma comparação eficiente que dita se a data é maior pelo ano ou pelo conjunto
    dia-mes, tendo em vista que: o ano vem pra frente e a comparação começa dele.
    Essa função foi contruida antes da data_extrai, então o código não foi refatorado, mas fica a dica.
    recebendo os valores já como inteiros, observa-se a necessidade do uso da função atoi() para a chamada da função.
    A ideia de usar uma expressão matemática para acessar indices veio de uma inspiração de converção de uma switch-case
    em POO(programação orientada a objetos). A função irá retornar o valor atribuido à data recebida.
    Essa função não saiu da minha cabeça, acaba que eu fiz a minha versão de uma função do excel que atribuia um valor a cada data.

verifica_cpf: 
    é uma função criada para validar o cpf (https://dicasdeprogramacao.com.br/algoritmo-para-validar-cpf/)
    onde a ideia é multiplicar os primeiros 9 números base pelos correspondentes da série dos números que começa em 10 e termina em 2
    após isso soma todas as multiplicações e divide por 11 e pega-se o resto, caso o resto seja 0 ou 1, o primeiro digito verificador é 0
    senão, o digito verificador deve ser a subtração de 11 pelo resto. o segundo faz-se a mesma coisa, porém incluindo o digito verificador
    e começando por 11. após cada 1 ser calculado, nós comparamos o resultado obtido com o que foi préviamente indicado.
    O intuito da função, como o nome sugere, é descobrir se o cpf é válido, então essa é uma função que recebe o cpf e retorna sim(1) ou não(0).
    P.S. o conversor (int) converte char para ascii, então é necessario que se retire 48 para que seja uma comparação entre números

Verifica_data:
    Com a necessidade de se ter datas precisas(mais pelo fato de que a função data_valor usa o mês como valor de acesso à índices de um vetor)
    essa função foi feita pra comportar todas as possíveis verificações, além de uma regra a mais que é a de que um ano não poderia ser menor que 1800.

cpf/data/celular/telefone _regex:
    curiosidade: regex significa regular expression, o nome dado para strings que possuem padrões.
    cada uma delas começa verificando se o número de digitos existentes na string a ser comparada é a quantidade esperada
    caso for então coloca-se cada digito no devido lugar do regex e (caso for cpf, devolve 1) termina a função.
    caso o número de digitos não for a esperada, então é requerido do usuário um novo input que deverá ser novamente testado até que ele esteja correto.
    no caso do cpf existe uma verificação a mais, a do verifica_cpf.
    O intuito das funções regex são de normalizar alguns dados, sendo eles de fácil normalização. cada uma recebe uma string
    e só são finalizadas quando o dado está devidamente preparado. (pequena parte estética que não foi explicitamente cobrada)

procura_ cliente/veículo/aluguel:
    Essas funções simples para localização, ou não, de valores em listas de dados, tal qual apenas itera o vetor até que se ache
    o valor esperado ou que se termine a iteração, retornando o indice ou -1, respectivamente.

veiculo_alugavel:
    Com a necessidade de comparar as datas de todos os alugueis de um mesmo carro para saber sua disponibilidade para um periodo
    especificado, nasceu a função veiculo_alugavel, que prepara as datas do periodo especificado, itera sobre o vetor de alugueis
    procurando por todos os alugueis que são do carro requerido no intuito de verificar se o periodo requerido não coincide com a
    um periodo já alugado, sendo que para um periodo não coincidir com outro, é necessário que ou a data de fim do requerido
    seja menor que a data de inicio de um ou que a data de inicio do periodo requerido seja maior que a data de fim.
    caso o periodo informado seja inválido, retorna 0, caso encontre um periodo conflitante retorna 0
    e caso nada disso tenha acontecido, retorna 1.

ordena_registro:
    Embora não haja uma necessidade numa quantidade pequena de dados, é de interesse já aprender a implementar bons algoritmos
    de organização. O algoritmo que eu uso nessa função para ordenar os registros é chamado de bubble sort (confesso que n acho sentido)
    já que cada registro acaba pulando de posição em posição a cada iteração até que ele atinja sua posição correta.
    Essa função itera o vetor inteiro e a cada iteração ele itera novamente para que cada posição seja comparada e, possivelmente, trocada.
    quando uma iteração localiza uma posição errada, ela irá trocar de forma lógica com a próxima posição, ou seja, uma das posições
    é armazenada em uma variável externa ao vetor, a posição toma para si os dados da próxima e então a variável externa descarrega
    os dados na próxima posição. Adendo: como pode se perceber, ele percorre o vetor em x*x-1, ou seja, um algoritmo ineficiente
    porém o mais básico também... 

adicionar:
    A primeira opção para um submenu de qualquer tipo. Irá pegar o a posição vazia, se houver uma, e irá
    adicionar os dados digitados e, as vezes, conferidos, pelo usuário caso a chave primária não tenha sido inserida em
    outro cadastro. no caso do aluguel é necessário verificar, também, se as chaves estrangeiras existem
    (pelo menos foi o que eu determinei como condição de adição). após isso a posição de inserção é atualizada.
    Para essa função, como uma variável que não um vetor, deverá ser atualizada, então nós passamos ela como ponteiro
    (variaveis de posição livre).

listar:
    A segunda opção para um submenu de qualquer tipo. Apenas itera sobre o vetor escolhido e printa todas as informações.
    Sem a necessidade de modificar nada, não são usados ponteiros.

Mostrar:
    A terceira opção de um submenu qualquer. Uma função que pede um valor de chave primária para mostrar os valores para cada outro atributo de uma entidade
    caso o valor especificado exista em um cadastro, então ela mostra. Para o aluguel cada tipo de dado poderá encontrar 1 problema diferente
    então cada excessão deverá ter sua mensagem de erro. Passagem de parâmetros sem ponteiro, já que não será necessário modificar nada posteriormente.

Alterar:
    A quarta opção de um submenu qualquer. Uma função que primeiro procura qual é o cadastro a ser alterado e, caso o cadastro exista
    ele mostrará as informações do cadastro, numerados de forma que após perguntado quantos campos serão alterados
    irá pedir para que informe o número do campo de pedir que informe o novo valor (alguns valores passam por verificações antes de serem adicionados)
    Assim que os cadastros foram devidamente alterados, os vetores, por precaução, passarão por uma verificação e, possivelmente, por uma reordenação
    Embora nós estejamos alternando cadastros, as próximas posições livres continuarão as mesmas, logo usamos passagem sem ponteiro.

Excluir:
    A quinta, e última, opção de um submenu qualquer. A função desempenha as mesmas verificações das anteriores
    porém assim que o cadastro a ser excluído é encontrado e mostrado, é verificado se o cadastro realmente está correto e deverá ser excluído
    caso sim, iniciasse um algoritmo de exclusão lógica, no qual consiste em copiar, a partir da posição do cadastro os cadastros posteriores
    e voltar uma posição na variável que controla as posições livres a fim de que a última posição, que está duplicada com a penúltima posição
    seja reescrita em uma nova adição de cadastro, assim trazendo uma sensação final de exclusão. Como dito anteriormente a variável de posição livre será alterada, logo deverá ser um ponteiro
    PS. Perceba que o vetor já está ordenado, então n há a necessidade de chamar a função de ordenação novamente.

gerar_relatorio:
    Por serem relatórios de mostrar ocorrencias, todos eles são gerados já dentro da função gerar_relatorio. 
    Tais relatórios só requeriam que o usuário informasse uma chave primária e que a função iterasse o vetor de alugueis.
    Adendo: alugueis que foram feitos dentro de um periodo, são alugueis cuja data de inicio deve ser maior ou igual a
    data inicial do periodo informado e que também sua data de fim seja menor ou igual a data de fim do periodo informado.
    gerar um relatório não modifica nada então são parâmetros não ponteiros.
*/