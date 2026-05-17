#include <stdio.h>
#include <stdlib.h>

#include "../include/arquivo.h"
#include "../include/ordenacao.h"
#include "../include/global.h"

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
        printf("Nao existem cadastros\n");
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