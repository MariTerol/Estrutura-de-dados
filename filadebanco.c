#include <stdio.h>
#include <string.h>

#define MAX_SERVICOS 100
#define MAX_CLIENTES 100
#define MAX_PRESTADORES 100

struct Servico {
    char descricao[100];
    char tipo[50];
    char consumidor[50];
    float valor;
    char parametros[100];
    char prestador[50];
};

struct Prestador {
    char nome[50];
    char email[100];
    char telefone[15];
    char endereco[100];
    char uf[3];
};

struct Consumidor {
    char nome[50];
    int idade;
    char email[100];
    char telefone[15];
    char endereco[100];
    char uf[3];
};

struct Servico servicos[MAX_SERVICOS];
int numServicos = 0;

struct Prestador prestadores[MAX_PRESTADORES];
int numPrestadores = 0;

struct Consumidor clientes[MAX_CLIENTES];
int numClientes = 0;

void listarTiposDeServicos() {
    printf("Tipos de serviços disponíveis:\n");
    for (int i = 0; i < numServicos; i++) {
        printf("%s\n", servicos[i].tipo);
    }
}

void listarClientes() {
    printf("Lista de clientes:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("%s\n", clientes[i].nome);
    }
}

void listarPrestadores() {
    printf("Lista de prestadores de serviços:\n");
    for (int i = 0; i < numPrestadores; i++) {
        printf("%s\n", prestadores[i].nome);
    }
}

void listarClientesPorEstado(char estado[3]) {
    printf("Clientes no estado %s:\n", estado);
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].uf, estado) == 0) {
            printf("%s\n", clientes[i].nome);
        }
    }
}

void listarPrestadoresPorTipo(char tipo[50]) {
    printf("Prestadores de serviços do tipo %s:\n", tipo);
    for (int i = 0; i < numPrestadores; i++) {
        if (strcmp(prestadores[i].uf, tipo) == 0) {
            printf("%s\n", prestadores[i].nome);
        }
    }
}

void estadoComServicoMaisCaro() {
    float maxValor = 0;
    char estadoMaisCaro[3];

    for (int i = 0; i < numServicos; i++) {
        if (servicos[i].valor > maxValor) {
            maxValor = servicos[i].valor;
            strcpy(estadoMaisCaro, servicos[i].consumidor);
        }
    }

    printf("Estado(s) onde está registrado o serviço mais caro: %s\n", estadoMaisCaro);
}

void ordenarServicosPorValor() {
    for (int i = 0; i < numServicos - 1; i++) {
        for (int j = 0; j < numServicos - i - 1; j++) {
            if (servicos[j].valor > servicos[j + 1].valor) {
                struct Servico temp = servicos[j];
                servicos[j] = servicos[j + 1];
                servicos[j + 1] = temp;
            }
        }
    }

    printf("Serviços em ordem crescente de valor:\n");
    for (int i = 0; i < numServicos; i++) {
        printf("Descrição: %s, Valor: %.2f\n", servicos[i].descricao, servicos[i].valor);
    }
}

void ordenarClientesPorNome() {
    for (int i = 0; i < numClientes - 1; i++) {
        for (int j = 0; j < numClientes - i - 1; j++) {
            if (strcmp(clientes[j].nome, clientes[j + 1].nome) > 0) {
                struct Consumidor temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }

    printf("Clientes em ordem crescente de nome:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("%s\n", clientes[i].nome);
    }
}

void adicionarServico() {
    if (numServicos < MAX_SERVICOS) {
        struct Servico novoServico;
        printf("Descrição do serviço: ");
        scanf(" %[^\n]s", novoServico.descricao);
        printf("Tipo do serviço: ");
        scanf(" %[^\n]s", novoServico.tipo);
        printf("Consumidor: ");
        scanf(" %[^\n]s", novoServico.consumidor);
        printf("Valor do serviço: ");
        scanf("%f", &novoServico.valor);
        printf("Parâmetros do serviço: ");
        scanf(" %[^\n]s", novoServico.parametros);
        printf("Prestador do serviço: ");
        scanf(" %[^\n]s", novoServico.prestador);

        servicos[numServicos] = novoServico;
        numServicos++;
        printf("Serviço adicionado com sucesso.\n");
    } else {
        printf("Limite de serviços atingido. Não é possível adicionar mais serviços.\n");
    }
}

void adicionarPrestador() {
    if (numPrestadores < MAX_PRESTADORES) {
        struct Prestador novoPrestador;
        printf("Nome do prestador: ");
        scanf(" %[^\n]s", novoPrestador.nome);
        printf("Email do prestador: ");
        scanf(" %[^\n]s", novoPrestador.email);
        printf("Telefone do prestador: ");
        scanf(" %[^\n]s", novoPrestador.telefone);
        printf("Endereço do prestador: ");
        scanf(" %[^\n]s", novoPrestador.endereco);
        printf("UF do prestador: ");
        scanf(" %[^\n]s", novoPrestador.uf);

        prestadores[numPrestadores] = novoPrestador;
        numPrestadores++;
        printf("Prestador adicionado com sucesso.\n");
    } else {
        printf("Limite de prestadores atingido. Não é possível adicionar mais prestadores.\n");
    }
}

void adicionarConsumidor() {
    if (numClientes < MAX_CLIENTES) {
        struct Consumidor novoConsumidor;
        printf("Nome do consumidor: ");
        scanf(" %[^\n]s", novoConsumidor.nome);
        printf("Idade do consumidor: ");
        scanf("%d", &novoConsumidor.idade);
        printf("Email do consumidor: ");
        scanf(" %[^\n]s", novoConsumidor.email);
        printf("Telefone do consumidor: ");
        scanf(" %[^\n]s", novoConsumidor.telefone);
        printf("Endereço do consumidor: ");
        scanf(" %[^\n]s", novoConsumidor.endereco);
        printf("UF do consumidor: ");
        scanf(" %[^\n]s", novoConsumidor.uf);

        clientes[numClientes] = novoConsumidor;
        numClientes++;
        printf("Consumidor adicionado com sucesso.\n");
    } else {
        printf("Limite de consumidores atingido. Não é possível adicionar mais consumidores.\n");
    }
}

void listarServicos() {
    printf("Lista de serviços:\n");
    for (int i = 0; i < numServicos; i++) {
        printf("Descrição: %s, Tipo: %s, Consumidor: %s, Valor: %.2f, Parâmetros: %s, Prestador: %s\n",
               servicos[i].descricao, servicos[i].tipo, servicos[i].consumidor, servicos[i].valor,
               servicos[i].parametros, servicos[i].prestador);
    }
}

int main() {
    int escolha;
    do {
        printf("\nMenu:\n");
        printf("1. Listar todos os tipos de serviços\n");
        printf("2. Listar todas as clientes\n");
        printf("3. Listar todos os prestadores de serviços\n");
        printf("4. Listar os clientes de um determinado estado\n");
        printf("5. Listar os prestadores de serviço de um determinado tipo\n");
        printf("6. Apresentar o(s) estado(s) onde está registrado o serviço mais caro\n");
        printf("7. Listar todos os serviços em ordem crescente de valor\n");
        printf("8. Listar todos os clientes em ordem crescente de nome\n");
        printf("9. Adicionar um novo consumidor\n");
        printf("10. Adicionar um novo servico\n");
        printf("11. Adicionar um novo prestador\n");
        printf("12. Sair\n");
        printf("Escolha a opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                listarTiposDeServicos();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                listarPrestadores();
                break;
            case 4:
                char uf[3];
                printf("Digite o estado: ");
                scanf(" %[^\n]s", uf);
                listarClientesPorEstado(uf);
                break;
            case 5:
                char tipo[50];
                printf("Digite o tipo de serviço: ");
                scanf(" %[^\n]s", tipo);
                listarPrestadoresPorTipo(tipo);
                break;
            case 6:
                estadoComServicoMaisCaro();
                break;
            case 7:
                ordenarServicosPorValor();
                break;
            case 8:
                ordenarClientesPorNome();
                break;
            case 9:
                adicionarConsumidor();
                break;
            case 10:
                adicionarServico();
                break;
            case 11:
                adicionarPrestador();
                break;
            case 12:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 12);

    return 0;
}
