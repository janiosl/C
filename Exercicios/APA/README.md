# Estudos da disciplina APA - Análise e Projeto de Algoritmos

## Listas encadeadas

### Opções para implementação das funções para criação, visualização e manipulação de listas encadeadas


Estudo detalhado das etapas representadas por cada função disponível em: https://github.com/janiosl/C/tree/master/C_Binder

Na versão abaixo a criação da estrutura de dados e das funções foram separadas em uma biblioteca para organização do código.

A implementação desta forma foi realizada nas opções de implementação a seguir:

**Implementações:**
* `gcc lista_main.c lita.c lista.h -o lista_main`: Implementa o código mais detalhado
* `gcc apa_lista.c lita.c lista.h -o apa_lista`: Implementa o mesmo código simplificado
* `gcc apa_lista_ordenada.c lita.c lista.h -o apa_lista_ordenada`: Implementa o mesmo código simplificado com itens ordenados na lista

**Conteúdo dos códigos do repositório**:
* [`lista.h`](https://github.com/janiosl/C/blob/master/Exercicios/APA/lista.h): Biblioteca com estrutura de dados de funções;
* [`lista.c`](https://github.com/janiosl/C/blob/master/Exercicios/APA/lista.c): Biblioteca com estrutura de dados de funções;
* [`lista_main.c`](https://github.com/janiosl/C/blob/master/Exercicios/APA/lista_main.c): Implementa o código para criação e manutenção da lista (mais detalhado)
* [`apa_lista.c`](https://github.com/janiosl/C/blob/master/Exercicios/APA/apa_lista.c): Implementa o código simplificado
* [`apa_lista_ordenada.c`](https://github.com/janiosl/C/blob/master/Exercicios/APA/apa_lista_ordenada.c): Implementa o código da lista ordenada
