#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "variables.h"

// Cria uma lista dinâmica de variáveis
ListaVariaveis* cria_lista_variaveis() {
    ListaVariaveis *lista = (ListaVariaveis*)malloc(sizeof(ListaVariaveis));
    lista->variaveis = (Variavel*)malloc(10 * sizeof(Variavel));
    lista->tamanho = 0;
    lista->capacidade = 10;
    return lista;
}

// Adiciona uma variável à lista
void adiciona_variavel(ListaVariaveis *lista, const char *nome, int valor) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->variaveis[i].nome, nome) == 0) {
            printf("Erro: Variável '%s' já declarada.\n", nome);
            return;
        }
    }

    if (lista->tamanho == lista->capacidade) {
        lista->capacidade *= 2;
        lista->variaveis = (Variavel*)realloc(lista->variaveis, lista->capacidade * sizeof(Variavel));
    }

    strcpy(lista->variaveis[lista->tamanho].nome, nome);
    lista->variaveis[lista->tamanho].valor = valor;
    lista->tamanho++;
}

// Obtém o valor de uma variável
int obtem_valor_variavel(ListaVariaveis *lista, const char *nome) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->variaveis[i].nome, nome) == 0) {
            return lista->variaveis[i].valor;
        }
    }
    printf("Erro: Variável '%s' não encontrada.\n", nome);
    exit(EXIT_FAILURE);
}

// Atualiza o valor de uma variável existente
void atualiza_valor_variavel(ListaVariaveis *lista, const char *nome, int valor) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->variaveis[i].nome, nome) == 0) {
            lista->variaveis[i].valor = valor;
            return;
        }
    }
    printf("Erro: Variável '%s' não encontrada.\n", nome);
    exit(EXIT_FAILURE);
}
