#include <stdlib.h>

#include "../include/ordenacao.h"
#include "../include/global.h"

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
        printf("\nNao existem cadastros\n");
    else {
    	printf("Escolha a ordem de ordenacao (1-crescente | 2-decrescente): ");
	    scanf(" %i", &ordem);
        ordenar(0, indice - 1);
        printf("\nContas ordenadas\n");
    }
}