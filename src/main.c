#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "../include/cadastro.h"
#include "../include/arquivo.h"
#include "../include/ordenacao.h"
#include "../include/global.h"

int indice = 0;
int ordem;
int numRegistros;

FILE *arq;

struct Conta contas[MAX_CONTAS];

void menu() //função para exibir o menu de opções, onde o usuário pode escolher a opção desejada e as funções correspondentes são chamadas, o menu é exibido em loop até que o usuário escolha a opção de sair
{
    setlocale(LC_ALL, "Portuguese");
    char opcao;

    do {
        system("cls");
        printf("\n|--------- MENU ---------|\n");
        printf("i. Incluir Conta\n");
        printf("c. Consultar Contas\n");
        printf("p. Pesquisar Conta Individual\n");
        printf("a. Alterar Conta\n");
        printf("e. Excluir Conta\n");
        printf("o. Ordenar Contas\n");
        printf("g. Gravar Contas no Arquivo\n");
        printf("l. Ler Contas do Arquivo\n");
        printf("f. Sair\n");
        printf("Digite uma opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'i':
                incluirconta();
                break;
            case 'c':
                consulta();
                break;
            case 'p':
                pesquisa();
                break;
            case 'a':
                alterar();
                break;
            case 'e':
                exclusao();
                break;
            case 'o':
                ordenarcontas();
                break;
            case 'g':
                armazenar();
                break;
            case 'l':
            	lerarquivo();
            	break;
            case 'f':
                printf("\nEncerrando o programa...");
                break;
            default:
                printf("\nOpção invalida. Digite novamente.\n");
        }
        printf("\n");
        system("pause");

    } while (opcao != 'f');
}

int main() //função principal, onde o arquivo é aberto para leitura e escrita, o menu é exibido e o arquivo é fechado ao final do programa
{
	char nome_arquivo[] = "cadastrojogop1.dat";
 	arq = fopen(nome_arquivo, "r+b");
 	if(arq == NULL)
 	{
 		if((arq = fopen(nome_arquivo, "w+b")) == NULL)
 		{
 			printf("o arquivo nao pode ser aberto\n");
 			printf("finalizando\n");
 			exit(0);
		}
	}
    menu();
    fclose(arq);
    return 0;
}