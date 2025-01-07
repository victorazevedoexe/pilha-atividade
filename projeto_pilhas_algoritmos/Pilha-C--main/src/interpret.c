#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "interpret.h"
#include "stack.h"

// Estrutura para variáveis
typedef struct {
    char nome[50];
    int valor;
} Variavel;

static Variavel variaveis[100]; // Lista estática de variáveis
static int num_variaveis = 0;   // Contador de variáveis
static Stack* stack = NULL;     // Pilha para operações

// Adicionamos uma variável para controlar o encerramento
extern int should_exit;

// Função auxiliar para encontrar uma variável pelo nome
static int encontra_variavel(const char* nome) {
    for (int i = 0; i < num_variaveis; i++) {
        if (strcmp(variaveis[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1; // Não encontrada
}

// Função principal para interpretar comandos
void interpret(const char* source) {
    if (!stack) {
        stack = new_stack(100);  // Inicializa a pilha com tamanho máximo
    }

    char op[10];
    char arg[50];
    int valor;

    if (sscanf(source, "%s %s", op, arg) == 2) {
        if (strcmp(op, "push") == 0) {
            // `push <nome_da_variavel>` ou `push <valor>`
            if (sscanf(arg, "%d", &valor) == 1) {
                stack_push(stack, valor); // Push de valor literal
            } else {
                int idx = encontra_variavel(arg);
                if (idx == -1) {
                    printf("Erro: Variável '%s' não declarada!\n", arg);
                } else {
                    stack_push(stack, variaveis[idx].valor);
                }
            }
        } else if (strcmp(op, "pop") == 0) {
            // `pop <nome_da_variavel>`
            int idx = encontra_variavel(arg);
            if (idx == -1) {
                printf("Erro: Variável '%s' não declarada!\n", arg);
            } else {
                variaveis[idx].valor = stack_pop(stack);
            }
        } else {
            printf("Comando desconhecido: %s\n", op);
        }
    } else if (sscanf(source, "%s", op) == 1) {
        if (strcmp(op, "add") == 0) {
            int b = stack_pop(stack);
            int a = stack_pop(stack);
            stack_push(stack, a + b);
        } else if (strcmp(op, "sub") == 0) {
            int b = stack_pop(stack);
            int a = stack_pop(stack);
            stack_push(stack, a - b);
        } else if (strcmp(op, "mul") == 0) {
            int b = stack_pop(stack);
            int a = stack_pop(stack);
            stack_push(stack, a * b);
        } else if (strcmp(op, "div") == 0) {
            int b = stack_pop(stack);
            if (b == 0) {
                printf("Erro: Divisão por zero!\n");
                stack_push(stack, b); // Retorna b para a pilha
                return;
            }
            int a = stack_pop(stack);
            stack_push(stack, a / b);
        } else if (strcmp(op, "print") == 0) {
            stack_print(stack);
        } else if (strcmp(op, "exit") == 0) {
            // Limpar a pilha antes de sair
            if (stack) {
                free(stack->data);
                free(stack);
                stack = NULL;
            }
            printf("Saindo...\n");
            should_exit = 1;  // Marca que o programa deve sair
        } else {
            printf("Comando desconhecido: %s\n", op);
        }
    } else {
        printf("Erro: Comando inválido!\n");
    }
}

