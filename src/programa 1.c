#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

int indice=0;
int codigo;
int ordem;
int numRegistros;
FILE *arq;

struct inccon //struct das variáveis para uso na função incluirconta()
{
    char nasc[20];
    char pais[20];
    char nome[50];
    char nomeex[50];
    float saldo;
    char email[60];
    int codigo;
} incconx [50];

void verificacodigo()
{
    int index = 0;
    int codigotmp = 0;
    int seeker = 0;

    srand(time(NULL));
    codigotmp = rand () % 100 + 1;

    while(index < indice && seeker == 0)
    {
        if(codigotmp == incconx[index].codigo){
            seeker = 1;
            codigotmp = rand () % 100 + 1;
        }
        else{
            seeker = 0;
            index++;
        }
    }
    incconx[indice].codigo = codigotmp;
}

void incluirconta()
{
    system("cls");

    if(indice < 50)
    {
        printf("|--------- INCLUIR CONTA ---------|");

        printf("\n\nDigite sua data de nascimento: ");
        scanf(" %[^\n]%*c", incconx[indice].nasc);

        printf("Digite o seu país: ");
        scanf(" %[^\n]%*c", incconx[indice].pais);

        printf("Digite o seu nome: ");
        scanf(" %[^\n]%*c", incconx[indice].nome);

        printf("Digite o seu nome de exibição (Nick): ");
        scanf(" %[^\n]%*c", incconx[indice].nomeex);

        printf("Digite o seu saldo: ");
        scanf(" %f%*c", &incconx[indice].saldo);

        printf("Digite o seu email: ");
        scanf(" %[^\n]%*c", &incconx[indice].email);

        printf("\n\nCadastro realizado\n");
        verificacodigo();
        printf("Seu código é: %i\n", incconx[indice].codigo);

        indice++;
    }
    else
    {
        printf("Número máximo de cadastros atingido\n");
    }
}

void consulta()
{
    system("cls");

    if(indice==0)
        printf("\nNão existem cadastrados\n");
    else
    {
        int index = 0;
        printf("|--------- CONSULTA DE CADASTROS ---------|\n");
        while(index < indice)
        {
            if(incconx[index].codigo != 999){
                printf("\n\nData de nascimento: %s\n", incconx[index].nasc );
                printf("País: %s\n", incconx[index].pais);
                printf("Nome: %s\n", incconx[index].nome);
                printf("Nome de exibição (Nick): %s\n", incconx[index].nomeex);
                printf("Saldo: %.2f\n", incconx[index].saldo);
                printf("Email: %s\n", incconx[index].email);
                printf("Código: %i\n\n", incconx[index].codigo);
                index++;
            }
            else{
                index++;
            }
        }
    }
}

void pesquisa()
{
    system("cls");
    int busca;
    int contador;

    if(indice==0)
        printf("\nNão existem cadastrados\n");
    else
    {
        int index = 0;
        printf("|--------- PESQUISA DE CADASTROS ---------|\n\n");
        printf("Digite o código a ser pesquisado: ");
        scanf("%i", &busca);

        while(index < indice)
        {
            if(incconx[index].codigo == busca && incconx[index].codigo != 999){
                printf("\n\nData de nascimento: %s\n", incconx[index].nasc );
                printf("País: %s\n", incconx[index].pais);
                printf("Nome: %s\n", incconx[index].nome);
                printf("Nome de exibição (Nick): %s\n", incconx[index].nomeex);
                printf("Saldo: %.2f\n", incconx[index].saldo);
                printf("Email: %s\n", incconx[index].email);
                printf("Código: %i\n", incconx[index].codigo);
                contador = 1000;
                break;
            }
            else{
                index++;
            }
        }
        if(contador != 1000){
            printf("\nO código não está cadastrado\n");
        }

    }
}

void alterar()
{
    system("cls");
    int busca;
    int index = 0;
    int contador;

    if(indice != 0)
    {
        printf("|--------- ALTERAR CONTA ---------|\n\n");
        printf("Digite o código a ser alterado: ");
        scanf("%i", &busca);


        while (index < indice)
        {
            if(incconx[index].codigo == busca && incconx[index].codigo != 999){
                printf("\n\nDigite sua data de nascimento: ");
                scanf(" %[^\n]%*c", incconx[index].nasc);

                printf("Digite o seu país: ");
                scanf(" %[^\n]%*c", incconx[index].pais);

                printf("Digite o seu nome: ");
                scanf(" %[^\n]%*c", incconx[index].nome);

                printf("Digite o seu nome de exibição (Nick): ");
                scanf(" %[^\n]%*c", incconx[index].nomeex);

                printf("Digite o seu saldo: ");
                scanf(" %f%*c", &incconx[index].saldo);

                printf("Digite o seu email: ");
                scanf(" %[^\n]%*c", &incconx[index].email);

                printf("\n\nCadastro alterado\n");
                contador = 1000;
                break;
            }
            else{
                index++;
            }
        }
        if(contador != 1000){
            printf("\nO código não está cadastrado\n");
        }
    }
    else
    {
        printf("\nNão existem cadastros\n");
    }
}

void exclusao()
{
    system("cls");
    int busca;
    int index = 0;
    int contador;

    if(indice != 0)
    {
        printf("|--------- EXCLUIR CONTA ---------|\n\n");
        printf("Digite o código a ser excluído: ");
        scanf("%i", &busca);


        while (index < indice)
        {
            if(incconx[index].codigo == busca && incconx[index].codigo != 999 ){
                incconx[index].codigo = 999;
                printf("\nCadastro excluído\n");
                contador = 1000;
                indice--;
                break;
            }
            else{
                index++;
            }
        }
        if(contador != 1000){
            printf("\nO código não está cadastrado\n");
        }
    }
    else
    {
        printf("\nNão existem cadastros\n");
    }
}

void ordenar(int left, int right) 
{
	
	if(ordem == 1){
		
	int i = left, j = right;
    struct inccon tmp;
    struct inccon pivot = incconx[(left + right) / 2];

    while (i <= j) {
        while (incconx[i].codigo < pivot.codigo)
            i++;
        while (incconx[j].codigo > pivot.codigo)
            j--;
        if (i <= j) {
            tmp = incconx[i];
            incconx[i] = incconx[j];
            incconx[j] = tmp;
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
    struct inccon tmp;
    struct inccon pivot = incconx[(left + right) / 2];

    while (i <= j) {
        while (incconx[i].codigo > pivot.codigo)
            i++;
        while (incconx[j].codigo < pivot.codigo)
            j--;
        if (i <= j) {
            tmp = incconx[i];
            incconx[i] = incconx[j];
            incconx[j] = tmp;
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

void ordenarcontas() 
{
	system("cls");
    if (indice == 0)
        printf("\nNão existem cadastros\n");
    else {
    	printf("Escolha a ordem de ordenação (1-crescente | 2-decrescente): ");
	    scanf(" %i", &ordem);
        ordenar(0, indice - 1);
        printf("\nContas ordenadas\n");
    }
}

void armazenar()
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
            if (incconx[index].codigo != 999)
            {
                fwrite(&incconx[index], sizeof(struct inccon), 1, arq);
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
        printf("Não existem cadastros\n");
    }
}

void contareg()
{
	fseek(arq, 0, SEEK_END); 
    int tamanhoArquivo = ftell(arq);
    numRegistros = tamanhoArquivo / sizeof(struct inccon);
}

void lerarquivo()
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
            if (incconx[index].codigo != 999)
            {
                fseek(arq, index * sizeof(struct inccon), SEEK_SET);
                fread(&incconx[index], sizeof(struct inccon), 1, arq);
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

void menu()
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
        printf("Digite uma opção: ");
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
                printf("\nOpção inválida. Digite novamente.\n");
        }
        printf("\n");
        system("pause");

    } while (opcao != 'f');
}

int main()
{
	char nome_arquivo[] = "cadastrojogop1.dat";
 	arq = fopen(nome_arquivo, "r+b");
 	if(arq == NULL)
 	{
 		if((arq = fopen(nome_arquivo, "w+b")) == NULL)
 		{
 			printf("o arquivo não pode ser aberto\n");
 			printf("finalizando\n");
 			exit(0);
		}
	}
    menu();
    fclose(arq);
    return 0;
}

