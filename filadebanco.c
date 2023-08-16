#include <stdio.h>
#include <stdlib.h>

#define TAM 2

int main(void){

    int i=0;

  struct ficha_de_cliente{

    char nome[50];
    char cpf[30];
    char operacao[20];
    char email[20];
    char telefone[10];
    float ndconta;
    float saldo;

  };

    struct ficha_de_cliente cliente[TAM]; 

    for (i=0; i<TAM;i++){
        
        printf("Informe seu nome completo: ");
        scanf("%[^\n]s", &cliente[i].nome);
        fflush(stdin);

        printf("Informe seu CPF: ");
        scanf("%[^\n]s", &cliente[i].cpf);

        printf("Informe o numero da conta: ");
        scanf("%f", &cliente[i].ndconta);

        printf("Informe o saldo da conta: ");
        scanf("%f", &cliente[i].saldo);
        fflush(stdin);
        
        printf("Informe a operacao que deseja agendar: ");
        scanf("%[^\n]s", &cliente[i].operacao);
        fflush(stdin);

        printf("Informe seu email: ");
        scanf("%[^\n]s", &cliente[i].email);
        fflush(stdin);

        printf("Informe seu telefone: ");
        scanf("%[^\n]s", &cliente[i].telefone);
        fflush(stdin);
    }
    

    printf("\n--------Lista de Agendamento--------\n");
    for (i=0;i<TAM;i++) {

        printf("O nome informado foi: %s\n", cliente[i].nome);
        printf("O CPF informado foi: %s\n", cliente[i].cpf);
        printf("A conta informado foi: %.2f\n", cliente[i].ndconta);
        printf("O saldo informada foi: %.2f\n", cliente[i].saldo);
        printf("A operacao informada foi: %s\n", cliente[i].operacao);
        printf("O email informado foi: %s\n", cliente[i].email);
        printf("O telefone informado foi: %s\n", cliente[i].telefone);

    }
    


    return 0;
}