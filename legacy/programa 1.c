#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define CODIGO_EXCLUIDO 999
#define MAX_CONTAS 50

int indice=0;
int codigo;
int ordem;
int numRegistros;
FILE *arq;

struct Conta //struct das variáveis para uso na função incluirconta()
{
    char nasc[20];
    char pais[20];
    char nome[MAX_CONTAS];
    char nomeex[MAX_CONTAS];
    float saldo;
    char email[60];
    int codigo;
} contas [MAX_CONTAS];

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

        printf("Digite o seu pa�s: ");
        scanf(" %[^\n]%*c", contas[indice].pais);

        printf("Digite o seu nome: ");
        scanf(" %[^\n]%*c", contas[indice].nome);

        printf("Digite o seu nome de exibi��o (Nick): ");
        scanf(" %[^\n]%*c", contas[indice].nomeex);

        printf("Digite o seu saldo: ");
        scanf(" %f%*c", &contas[indice].saldo);

        printf("Digite o seu email: ");
        scanf(" %[^\n]%*c", &contas[indice].email);

        printf("\n\nCadastro realizado\n");
        verificacodigo();
        printf("Seu c�digo �: %i\n", contas[indice].codigo);

        indice++;
    }
    else
    {
        printf("N�mero m�ximo de cadastros atingido\n");
    }
}

void consulta() //função para consultar os cadastros, onde os cadastros excluídos não são exibidos
{
    system("cls");

    if(indice==0)
        printf("\nN�o existem cadastrados\n");
    else
    {
        int index = 0;
        printf("|--------- CONSULTA DE CADASTROS ---------|\n");
        while(index < indice)
        {
            if(contas[index].codigo != CODIGO_EXCLUIDO){
                printf("\n\nData de nascimento: %s\n", contas[index].nasc );
                printf("Pa�s: %s\n", contas[index].pais);
                printf("Nome: %s\n", contas[index].nome);
                printf("Nome de exibi��o (Nick): %s\n", contas[index].nomeex);
                printf("Saldo: %.2f\n", contas[index].saldo);
                printf("Email: %s\n", contas[index].email);
                printf("C�digo: %i\n\n", contas[index].codigo);
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
        printf("\nN�o existem cadastrados\n");
    else
    {
        int index = 0;
        printf("|--------- PESQUISA DE CADASTROS ---------|\n\n");
        printf("Digite o c�digo a ser pesquisado: ");
        scanf("%i", &codigoBusca);

        while(index < indice)
        {
            if(contas[index].codigo == codigoBusca && contas[index].codigo != CODIGO_EXCLUIDO){
                printf("\n\nData de nascimento: %s\n", contas[index].nasc );
                printf("Pa�s: %s\n", contas[index].pais);
                printf("Nome: %s\n", contas[index].nome);
                printf("Nome de exibi��o (Nick): %s\n", contas[index].nomeex);
                printf("Saldo: %.2f\n", contas[index].saldo);
                printf("Email: %s\n", contas[index].email);
                printf("C�digo: %i\n", contas[index].codigo);
                contador = 1000;
                break;
            }
            else{
                index++;
            }
        }
        if(contador != 1000){
            printf("\nO c�digo n�o est� cadastrado\n");
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
        printf("Digite o c�digo a ser alterado: ");
        scanf("%i", &codigoBusca);


        while (index < indice)
        {
            if(contas[index].codigo == codigoBusca && contas[index].codigo != CODIGO_EXCLUIDO){
                printf("\n\nDigite sua data de nascimento: ");
                scanf(" %[^\n]%*c", contas[index].nasc);

                printf("Digite o seu pa�s: ");
                scanf(" %[^\n]%*c", contas[index].pais);

                printf("Digite o seu nome: ");
                scanf(" %[^\n]%*c", contas[index].nome);

                printf("Digite o seu nome de exibi��o (Nick): ");
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
            printf("\nO c�digo n�o est� cadastrado\n");
        }
    }
    else
    {
        printf("\nN�o existem cadastros\n");
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
        printf("Digite o c�digo a ser exclu�do: ");
        scanf("%i", &codigoBusca);


        while (index < indice)
        {
            if(contas[index].codigo == codigoBusca && contas[index].codigo != CODIGO_EXCLUIDO ){
                contas[index].codigo = CODIGO_EXCLUIDO;
                printf("\nCadastro exclu�do\n");
                contador = 1000;
                break;
            }
            else{
                index++;
            }
        }
        if(contador != 1000){
            printf("\nO c�digo n�o est� cadastrado\n");
        }
    }
    else
    {
        printf("\nN�o existem cadastros\n");
    }
}

void ordenar(int left, int right) //função para ordenar os cadastros, onde o usuário escolhe a ordem de ordenação (crescente ou decrescente) e os cadastros são ordenados pelo código, utilizando o algoritmo de ordenação quicksort
{
	
	if(ordem == 1){
		
	int i = left, j = right;
    struct Conta tmp;
    struct Conta pivot = contas[(left + right) / 2];

    while (i <= j) {
        while (contas[i].codigo < pivot.codigo)
            i++;
        while (contas[j].codigo > pivot.codigo)
            j--;
        if (i <= j) {
            tmp = contas[i];
            contas[i] = contas[j];
            contas[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
        ordenar(left, j);
    if (i < right)
        ordenar(i, right);
	}
	else {
		
	int i = left, j = right;
    struct Conta tmp;
    struct Conta pivot = contas[(left + right) / 2];

    while (i <= j) {
        while (contas[i].codigo > pivot.codigo)
            i++;
        while (contas[j].codigo < pivot.codigo)
            j--;
        if (i <= j) {
            tmp = contas[i];
            contas[i] = contas[j];
            contas[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
        ordenar(left, j);
    if (i < right)
        ordenar(i, right);
	}
    
}

void ordenarcontas() //função para ordenar os cadastros, onde o usuário escolhe a ordem de ordenação (crescente ou decrescente) e os cadastros são ordenados pelo código, utilizando o algoritmo de ordenação quicksort
{
	system("cls");
    if (indice == 0)
        printf("\nN�o existem cadastros\n");
    else {
    	printf("Escolha a ordem de ordena��o (1-crescente | 2-decrescente): ");
	    scanf(" %i", &ordem);
        ordenar(0, indice - 1);
        printf("\nContas ordenadas\n");
    }
}

void armazenar() //função para armazenar os cadastros em um arquivo, onde os cadastros são ordenados pelo código e armazenados em um arquivo binário, utilizando a função fwrite() para escrever os dados no arquivo
{
	system ("cls");
	int index = 0;
    ordem = 1;

    if (indice != 0)
    {
        printf("|--------- ARMAZENAR CONTAS ---------|\n\n");

        ordenar(0, indice - 1);

        if (arq == NULL)
        {
            printf("\nErro ao abrir o arquivo para armazenar os cadastros.");
            return;
        }

        while (index < indice)
        {
            if (contas[index].codigo != CODIGO_EXCLUIDO)
            {
                fwrite(&contas[index], sizeof(struct Conta), 1, arq);
                index++;
            }
            else
            {
                index++;
            }
        }
        printf("Cadastros armazenados\n");
    }
    else
    {
        printf("N�o existem cadastros\n");
    }
}

void contareg() //função para contar o número de registros no arquivo, onde o arquivo é lido e o número de registros é calculado dividindo o tamanho do arquivo pelo tamanho da struct Conta
{
	fseek(arq, 0, SEEK_END); 
    int tamanhoArquivo = ftell(arq);
    numRegistros = tamanhoArquivo / sizeof(struct Conta);
}

void lerarquivo() //função para ler os cadastros do arquivo, onde o arquivo é lido e os cadastros são armazenados em um array, utilizando a função fread() para ler os dados do arquivo, e os cadastros excluídos não são exibidos
{
	int index = 0;
    system("cls");
    contareg();
    
    
        printf("|--------- LER CONTAS DO ARQUIVO ---------|\n\n");

        if (arq == NULL)
        {
            printf("\nErro ao abrir o arquivo para armazenar os cadastros.");
            return;
        }

        while (index < numRegistros)
        {
            if (contas[index].codigo != CODIGO_EXCLUIDO)
            {
                fseek(arq, index * sizeof(struct Conta), SEEK_SET);
                fread(&contas[index], sizeof(struct Conta), 1, arq);
                indice++;
                index++;
            }
            else
            {
                index++;
            }
        }
        printf("Cadastros armazenados\n");
}

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
        printf("Digite uma op��o: ");
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
                printf("\nOp��o inv�lida. Digite novamente.\n");
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
 			printf("o arquivo n�o pode ser aberto\n");
 			printf("finalizando\n");
 			exit(0);
		}
	}
    menu();
    fclose(arq);
    return 0;
}

