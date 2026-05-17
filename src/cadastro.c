#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/cadastro.h"
#include "../include/global.h"

void verificacodigo() //função para verificar se o código gerado é único
{
    int index = 0;
    int codigotmp = 0;
    int encontrado = 0;

    srand(time(NULL));
    codigotmp = rand () % 100 + 1;

    while(index < indice && encontrado == 0)
    {
        if(codigotmp == contas[index].codigo){
            encontrado = 1;
            codigotmp = rand () % 100 + 1;
        }
        else{
            encontrado = 0;
            index++;
        }
    }
    contas[indice].codigo = codigotmp;
}

void incluirconta() //função para incluir conta, onde o código é gerado automaticamente e verificado para ser único
{
    system("cls");

    if(indice < MAX_CONTAS)
    {
        printf("|--------- INCLUIR CONTA ---------|");

        printf("\n\nDigite sua data de nascimento: ");
        scanf(" %[^\n]%*c", contas[indice].nasc);

        printf("Digite o seu pais: ");
        scanf(" %[^\n]%*c", contas[indice].pais);

        printf("Digite o seu nome: ");
        scanf(" %[^\n]%*c", contas[indice].nome);

        printf("Digite o seu nome de exibicao (Nick): ");
        scanf(" %[^\n]%*c", contas[indice].nomeex);

        printf("Digite o seu saldo: ");
        scanf(" %f%*c", &contas[indice].saldo);

        printf("Digite o seu email: ");
        scanf(" %[^\n]%*c", &contas[indice].email);

        printf("\n\nCadastro realizado\n");
        verificacodigo();
        printf("Seu codigo e: %i\n", contas[indice].codigo);

        indice++;
    }
    else
    {
        printf("Numero maximo de cadastros atingido\n");
    }
}

void consulta() //função para consultar os cadastros, onde os cadastros excluídos não são exibidos
{
    system("cls");

    if(indice==0)
        printf("\nNao existem cadastrados\n");
    else
    {
        int index = 0;
        printf("|--------- CONSULTA DE CADASTROS ---------|\n");
        while(index < indice)
        {
            if(contas[index].codigo != CODIGO_EXCLUIDO){
                printf("\n\nData de nascimento: %s\n", contas[index].nasc );
                printf("Pais: %s\n", contas[index].pais);
                printf("Nome: %s\n", contas[index].nome);
                printf("Nome de exibicao (Nick): %s\n", contas[index].nomeex);
                printf("Saldo: %.2f\n", contas[index].saldo);
                printf("Email: %s\n", contas[index].email);
                printf("Codigo: %i\n\n", contas[index].codigo);
                index++;
            }
            else{
                index++;
            }
        }
    }
}

void pesquisa() //função para pesquisar um cadastro individual, onde o código é solicitado e os dados são exibidos caso o código seja encontrado, ou uma mensagem de erro caso o código não esteja cadastrado
{
    system("cls");
    int codigoBusca;
    int contador = 0;

    if(indice==0)
        printf("\nNao existem cadastrados\n");
    else
    {
        int index = 0;
        printf("|--------- PESQUISA DE CADASTROS ---------|\n\n");
        printf("Digite o codigo a ser pesquisado: ");
        scanf("%i", &codigoBusca);

        while(index < indice)
        {
            if(contas[index].codigo == codigoBusca && contas[index].codigo != CODIGO_EXCLUIDO){
                printf("\n\nData de nascimento: %s\n", contas[index].nasc );
                printf("Pais: %s\n", contas[index].pais);
                printf("Nome: %s\n", contas[index].nome);
                printf("Nome de exibicao (Nick): %s\n", contas[index].nomeex);
                printf("Saldo: %.2f\n", contas[index].saldo);
                printf("Email: %s\n", contas[index].email);
                printf("Codigo: %i\n", contas[index].codigo);
                contador = 1000;
                break;
            }
            else{
                index++;
            }
        }
        if(contador != 1000){
            printf("\nO codigo nao esta cadastrado\n");
        }

    }
}

void alterar() //função para alterar um cadastro, onde o código é solicitado e os dados são alterados caso o código seja encontrado, ou uma mensagem de erro caso o código não esteja cadastrado
{
    system("cls");
    int codigoBusca;
    int index = 0;
    int contador;

    if(indice != 0)
    {
        printf("|--------- ALTERAR CONTA ---------|\n\n");
        printf("Digite o codigo a ser alterado: ");
        scanf("%i", &codigoBusca);


        while (index < indice)
        {
            if(contas[index].codigo == codigoBusca && contas[index].codigo != CODIGO_EXCLUIDO){
                printf("\n\nDigite sua data de nascimento: ");
                scanf(" %[^\n]%*c", contas[index].nasc);

                printf("Digite o seu pais: ");
                scanf(" %[^\n]%*c", contas[index].pais);

                printf("Digite o seu nome: ");
                scanf(" %[^\n]%*c", contas[index].nome);

                printf("Digite o seu nome de exibicao (Nick): ");
                scanf(" %[^\n]%*c", contas[index].nomeex);

                printf("Digite o seu saldo: ");
                scanf(" %f%*c", &contas[index].saldo);

                printf("Digite o seu email: ");
                scanf(" %[^\n]%*c", &contas[index].email);

                printf("\n\nCadastro alterado\n");
                contador = 1000;
                break;
            }
            else{
                index++;
            }
        }
        if(contador != 1000){
            printf("\nO codigo nao esta cadastrado\n");
        }
    }
    else
    {
        printf("\nNao existem cadastros\n");
    }
}

void exclusao() //função para excluir um cadastro, onde o código é solicitado e o cadastro é excluído caso o código seja encontrado, ou uma mensagem de erro caso o código não esteja cadastrado
{
    system("cls");
    int codigoBusca;
    int index = 0;
    int contador = 0;

    if(indice != 0)
    {
        printf("|--------- EXCLUIR CONTA ---------|\n\n");
        printf("Digite o codigo a ser excluido: ");
        scanf("%i", &codigoBusca);


        while (index < indice)
        {
            if(contas[index].codigo == codigoBusca && contas[index].codigo != CODIGO_EXCLUIDO ){
                contas[index].codigo = CODIGO_EXCLUIDO;
                printf("\nCadastro excluido\n");
                contador = 1000;
                break;
            }
            else{
                index++;
            }
        }
        if(contador != 1000){
            printf("\nO codigo nao esta cadastrado\n");
        }
    }
    else
    {
        printf("\nNao existem cadastros\n");
    }
}