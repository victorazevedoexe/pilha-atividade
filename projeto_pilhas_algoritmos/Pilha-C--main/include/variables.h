#ifndef VARIABLES_H
#define VARIABLES_H

typedef struct {
    char nome[50];
    int valor;
} Variavel;

typedef struct {
    Variavel *variaveis;
    int tamanho;
    int capacidade;
} ListaVariaveis;

// Criação e manipulação da lista de variáveis
ListaVariaveis* cria_lista_variaveis();
void adiciona_variavel(ListaVariaveis *lista, const char *nome, int valor);
int obtem_valor_variavel(ListaVariaveis *lista, const char *nome);
void atualiza_valor_variavel(ListaVariaveis *lista, const char *nome, int valor);

#endif
