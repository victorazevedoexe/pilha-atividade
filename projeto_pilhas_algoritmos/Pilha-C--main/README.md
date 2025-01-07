Stack Machine Interpreter
Este projeto implementa um interpretador baseado em pilha, permitindo manipulação de valores e variáveis com comandos intuitivos. A pilha é usada para armazenar valores temporários e realizar operações matemáticas.

Comandos Suportados
push <valor>: Empilha um valor literal na pilha.
push <nome_da_variável>: Empilha o valor associado a uma variável.
pop <nome_da_variável>: Remove o topo da pilha e atualiza o valor da variável correspondente.
add: Soma os dois últimos valores na pilha.
sub: Subtrai os dois últimos valores na pilha.
mul: Multiplica os dois últimos valores na pilha.
div: Divide os dois últimos valores na pilha. (Erro ao dividir por zero é tratado.)
print: Imprime o conteúdo atual da pilha.
exit: Encerra o programa.
Estrutura do Projeto
include/: Contém os arquivos de cabeçalho.

interpret.h: Declarações das funções do interpretador.
stack.h: Declarações das funções relacionadas à pilha e estrutura de variáveis.
src/: Contém a implementação em C.

main.c: Função principal que executa o REPL (read-eval-print-loop).
interpret.c: Implementação das funções do interpretador.
stack.c: Implementação das funções relacionadas à pilha.
