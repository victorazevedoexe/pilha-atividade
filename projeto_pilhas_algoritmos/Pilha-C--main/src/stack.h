#ifndef STACK_H
#define STACK_H

typedef struct stack {
    int* data;  // Ponteiro para os dados da pilha
    int size;   // Tamanho máximo da pilha
    int top;    // Índice do topo da pilha
} Stack;

// Cria uma nova pilha com um tamanho especificado.
Stack* new_stack(int size);

// Adiciona um valor no topo da pilha.
void stack_push(Stack* s, int value);

// Remove e retorna o valor no topo da pilha.
int stack_pop(Stack* s);

// Exibe os elementos da pilha.
void stack_print(Stack* s);

#endif // STACK_H
