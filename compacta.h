#ifndef COMPACTA_H
#define COMPACTA_H

#include "arvoreBinaria.h"
#include "tabelaFreq.h"
#include "dicionario.h"
#include "bitmap.h"

// --------- FUNCOES AUXILIARES ----------

/*Le a extensao do arquivo que sera compactado
 * inputs: ponteiro para char
 * output: ponteiro para char
 * pre-condicao: nenhuma
 * pos-condicao: nenhuma
 */
char *leExtensao(char *nomeArquivo);

// --------- FUNCAO DE COMPACTACAO ----------

/*Compacta um arquivo
 * inputs: ponteiro para ponteiro de char, ponteiro para char, ponteiro para inteiro, ponteiro para arvore
 * output: nenhum
 * pre-condicao: dicionario, tabela de frequencia e arvore precisam existir
 * pos-condicao: arquivo foi compactado
 */
void compactarArquivo(char **dicionario, char *arquivo, unsigned int *tabela, Arvore *a);

#endif