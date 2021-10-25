#ifndef DESCOMPACTA_H
#define DESCOMPACTA_H

#include "arvoreBinaria.h"
#include "tabelaFreq.h"
#include "compacta.h"

// --------- FUNCAO AUXILIAR ----------

/*Verifica se o bit eh 0 ou nao
 * inputs: byte e posicao do bit
 * output: unsigned int
 * pre-condicao: nenhuma
 * pos-condicao: byte nao eh alterado
 */
unsigned int verificaBit(unsigned char byte, int i);

// --------- FUNCAO DE DESCOMPACTACAO ----------

/*Descompacta um arquivo
 * inputs: ponteiro char
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: arquivo esta descompactado
 */
void descompactarArquivo(char *arquivo);

#endif