#include <stdio.h>
#include "interpret.h"

// Variável global para controle do comando exit
int should_exit = 0;

static void repl() {
    char line[1024];
    for (;;) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }

        interpret(line);

        // Se should_exit for verdadeiro, saímos do loop
        if (should_exit) {
            break;
        }
    }
}

int main() {
    printf("Bem-vindo ao interpretador de máquina baseada em pilha.\n");
    printf("Comandos disponíveis:\n");
    printf("- push <valor>: Empilha um valor literal.\n");
    printf("- push <nome_da_variavel>: Empilha o valor de uma variável.\n");
    printf("- pop <nome_da_variavel>: Atualiza uma variável com o topo da pilha.\n");
    printf("- add, sub, mul, div: Realiza operações matemáticas.\n");
    printf("- print: Mostra o conteúdo atual da pilha.\n");
    printf("- exit: Encerra o programa.\n");

    repl();
    return 0;
}


