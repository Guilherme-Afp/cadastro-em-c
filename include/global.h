#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>

#define MAX_CONTAS 50
#define CODIGO_EXCLUIDO 999

struct Conta {
    char nasc[20];
    char pais[20];
    char nome[50];
    char nomeex[50];
    float saldo;
    char email[60];
    int codigo;
};

extern int indice;
extern int ordem;
extern int numRegistros;

extern FILE *arq;

extern struct Conta contas[MAX_CONTAS];

#endif