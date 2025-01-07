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
Casos de Teste
Testes Básicos
Operações Simples:

bash
Copiar código
> push 10
> push 20
> add
> print
Saída esperada:

Copiar código
30
Manipulação de Variáveis:

bash
Copiar código
> push 5
> pop x
> push x
> push 15
> mul
> print
Saída esperada:

Copiar código
75
Cenários de Erro
Divisão por Zero:

bash
Copiar código
> push 10
> push 0
> div
Saída esperada:

makefile
Copiar código
Erro: Divisão por zero!
Manipulação de Variáveis Não Declaradas:

bash
Copiar código
> push y
Saída esperada:

yaml
Copiar código
Erro: Variável não encontrada: y
Compilação
Para compilar o projeto, execute o seguinte comando no terminal:

bash
Copiar código
gcc src/*.c -Iinclude -o stack_machine
Execução
Após a compilação, o programa pode ser executado com o seguinte comando:

bash
Copiar código
./stack_machine
Contribuição
Sinta-se à vontade para contribuir com melhorias ou novos recursos. Para contribuir, siga estas etapas:

Faça um fork deste repositório.
Crie uma branch para suas alterações: git checkout -b feature/nova-funcionalidade.
Commit suas mudanças: git commit -m 'Adiciona nova funcionalidade'.
Envie suas alterações: git push origin feature/nova-funcionalidade.
Abra um Pull Request.
