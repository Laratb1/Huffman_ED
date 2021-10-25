#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H

typedef struct celLista CelLista;
typedef struct lista Lista;

#include "arvoreBinaria.h"

// --------- FUNCOES DE CRIAÇÃO E DESTRUICAO ----------

/*Inicializa a lista
 * inputs: nenhum
 * output: ponteiro para lista criada
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro de retorno existe e esta alocado
 */
Lista *inicializaLista(void);

/*Cria a lista
 * inputs: tabela de frequencia e lista 
 * output: nenhum
 * pre-condicao: tabela de frequencia e lista existe
 * pos-condicao: lista existe e esta preenchida
 */
void criaLista(unsigned int *frequencia, Lista *lista);

/*Libera memoria alocada para lista
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista existe
 * pos-condicao: toda memoria alocada foi liberada
 */
void destroiLista(Lista *lista);

// --------- FUNCOES INSERÇÃO E RETIRADA DE ITENS  ----------

/*Insere arvore na lista
 * inputs: lista e arvore
 * output: void
 * pre-condicao: lista e arvore existem
 * pos-condicao: lista continua existindo, agora com uma arvore nova 
 */
void insereArvoreNaLista(Lista *lista, Arvore *arv);

/*Retira uma celula da lista
 * inputs: ponteiro para lista e ponteiro para celula que precisa ser retirada
 * output: ponteiro para Arvore
 * pre-condicao: lista precisa existir
 * pos-condicao: lista foi alterada e esta com um elemento a menos, celula foi destruida
 */
Arvore *retiraArvoreDaLista(Lista *lista, CelLista *celula);

// --------- FUNCOES DE RETORNO ----------

/*Retorno o primeiro elemento da celula
 * inputs: ponteiro para  lista
 * output: ponteiro para celula da lista
 * pre-condicao: lista precisa existir
 * pos-condicao: lista nao eh modificada
 */
CelLista *retornaPrimeiroLista(Lista *lista);

/*Retorno o ultimo elemento da celula
 * inputs: ponteiro para  lista
 * output: ponteiro para celula da lista
 * pre-condicao: lista precisa existir
 * pos-condicao: lista nao eh modificada
 */
CelLista *retornaUltimoLista(Lista *lista);

/*Retorno o proximo elemento da celula
 * inputs: ponteiro para celula da lista
 * output: ponteiro para celula da lista
 * pre-condicao: celula precisa existir
 * pos-condicao: celula nao eh modificada
 */
CelLista *retornaProximoLista(CelLista *p);

/*Retorna a Arvore de uma celula da lista
 * inputs: ponteiro para a celula da lista
 * output: ponteiro para Arvore
 * pre-condicao: celula precisa existir
 * pos-condicao: celula nao eh modificada
 */
Arvore *retornaArvoreDaCelLista(CelLista *p);

// --------- FUNCOES AUXILIARES ----------

/*Calcula a quantidade de elementos da lista
 * inputs: ponteiro para lista
 * output: inteiro
 * pre-condicao: lista precisa existir
 * pos-condicao: lista não eh modificada
 */
int tamanhoDaLista(Lista *lista);

/*Imprime a lista
 * inputs: ponteiro para lista
 * output: nenhum
 * pre-condicao: lista precisa existir
 * pos-condicao: lista nao eh modificada
 */
void imprimeLista(Lista *lista);

#endif