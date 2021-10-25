#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct arvore Arvore;

#include "listaOrdenada.h"


// --------- FUNCOES DE CRIAÇÃO E DESTRUICAO ----------

/*Cria a Arvore binaria vazia
 * inputs: nenhum
 * output: ponteiro para Arvore
 * pre-condicao: nenhuma
 * pos-condicao: Arvore aponta para NULL
 */
Arvore* criaArvoreVazia(void);

/*Cria a Arvore binaria
 * inputs: char, inteiro, ponteiro para Arvore da esqueda e ponteiro para Arvore da direita
 * output: ponteiro Arvore alocada
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro de retorno existe e esta alocado
 */
Arvore* criaArvore(char c, int frequencia, Arvore *esq, Arvore* dir);

/*Cria a Arvore binaria a partir da Lista 
 * inputs: Lista e celula da lista
 * output: ponteiro para Arvore criada
 * pre-condicao: Arvore da celula e Lista devem existir
 * pos-condicao: ponteiro para Arvore criada existe e esta preenchido
 */
Arvore* criaArvoreBinariaComLista(Lista* lista, CelLista* p);

/*Libera memoria alocada para a Arvore
 * inputs: ponteiro para Arvore
 * output: ponteiro para Arvore retirada
 * pre-condicao: Arvore deve existir 
 * pos-condicao: toda memoria alocada foi liberada
 */
Arvore* liberaArvore(Arvore* arv);

// --------- FUNCOES DE RETORNO ----------

/*Retorna Arvore da direita
 * inputs: ponteiro para Arvore
 * output: ponteiro para Arvore da direita
 * pre-condicao: Arvore deve existir
 * pos-condicao: Arvore nao eh modificada
 */
Arvore* retornaDireita(Arvore* a);

/*Retorna Arvore da esqueda
 * inputs: ponteiro para Arvore
 * output: ponteiro para Arvore da esquerda
 * pre-condicao: Arvore deve existir
 * pos-condicao: Arvore nao eh modificada
 */
Arvore* retornaEsquerda(Arvore* a);

/*Retorna a frequencia da Arvore
 * inputs: ponteiro para  Arvore
 * output: inteiro
 * pre-condicao: Arvore precisa existir
 * pos-condicao: Arvore nao eh modificada
 */
int retornaFrequencia(Arvore *a);

/*Retorna o caracter da Arvore
 * inputs: ponteiro para  Arvore
 * output: char
 * pre-condicao: Arvore precisa existir
 * pos-condicao: Arvore nao eh modificada
 */
unsigned char retornaCaracter(Arvore* a);

// --------- FUNCOES AUXILIARES ----------

/*Verifica se uma Arvore esta vazia
 * inputs: ponteiro para Arvore
 * output: inteiro
 * pre-condicao: Arvore precisa existir
 * pos-condicao: Arvore nao eh modificada
 */
int arvoreVazia(Arvore* a);

/*Compara dois inteiros e retorna o maior
 * inputs: dois inteiros
 * output: inteiro
 * pre-condicao: nenhuma
 * pos-condicao: nenhuma
 */
static int max2(int a, int b);

/*Calcula a altura da Arvore
 * inputs: ponteiro para Arvore
 * output: inteiro
 * pre-condicao: Arvore precisa existir
 * pos-condicao: Arvore nao eh modificada
 */
int alturaArvore(Arvore* a);

/*Imprime Arvore
 * inputs: ponteiro para Arvore
 * output: nenhum
 * pre-condicao: Arvore precisa existir
 * pos-condicao: Arvore nao eh modificada
 */
void imprimeArvore (Arvore* a);

// --------- FUNCOES DE MANIPULACAO DE ARQUIVO ----------

/*Imprime Arvore no arquivo
 * inputs: ponteiro para arvore e ponteiro para arquivo
 * output: nenhum
 * pre-condicao: Arvore precisa existir e arquivo já deve ter sido aberto
 * pos-condicao: o arquivo eh modificado e arvore contina existindo sem ser modificada
 */
void imprimeArvoreNoArquivo (Arvore* a, FILE* arquivo);

/*Le o cabeçalho do arquivo e cria a arvore binaria
 * inputs: ponteiro para arquivo
 * output: ponteiro para arvore
 * pre-condicao: arquivo já deve ter sido aberto
 * pos-condicao: o arquivo nao eh modificado e arvore existe
 */
Arvore *leArvoreDoArquivo(FILE *fp);

#endif