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
    printf("Comandos disponíveis: push <valor>, add, sub, mul, div, print, exit\n");
    repl();
    return 0;
}

