#ifndef DICIONARIO_H
#define DICIONARIO_H

#include "arvoreBinaria.h"

// --------- FUNCOES DE CRIAÇÃO E DESTRUICAO ----------

/*Inicializa o dicionario
 * inputs: inteiro
 * output: ponteiro para dicionario alocado
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro de retorno existe e esta alocado
 */
char **inicializaDicionario(int numColunas);

/*Gera o dicionario com as informacoes da arvore
 * inputs: ponteiro para ponteiro de char, ponteiro para Arvore, ponteiro para char, inteiro
 * output: nenhum
 * pre-condicao: dicionario e Arvore precisam existir
 * pos-condicao: Arvore nao eh modifica, dicionario foi preenchido
 */
void geraDicionario(char** dicionario, Arvore* raiz, char *caminho, int colunas);

/*Libera memoria alocada para o dicionario
 * inputs: ponteiro para o dicionario
 * output: nenhum
 * pre-condicao: dicionario existe
 * pos-condicao: toda memoria alocada foi liberada
 */
void destroiDicionario(char **dicionario);

// --------- FUNCOES DE AUXILIARES ----------

/*Imprime dicionario
 * inputs: ponteiro para ponteiro de char
 * output: nenhum
 * pre-condicao: dicionario precisa existir
 * pos-condicao: dicionario nao eh modificado
 */
void imprimeDicionario(char** dicionario);

#endif