/*
Feito por: Lara Tagarro e Milla Pereira
O seguinte programa tem como objetivo compactar arquivos binarios.
Nele foi utilizada a logica do codigo de Huffman.
Cuidados: O programa funciona bem para arquivos de 
texto de ate 4 Mb e para imagens de ate 500 bytes.
Para arquivos de texto maiores, o tempo de espera para compilacar 
e descompilacar eh muito grande, o que torna inviavel a utilizacao
do programa.
Alem disso, imagens maiores que 500 bytes nao funcionam bem com
o funcionamento do programa.
Por fim, vale ressaltar que quanto maior o arquivo, maior sera o 
tempo de esperar para que ocorra a compilacao de descompilacao.
Como exemplo, um arquivo de aproximadamente 6 Mb leva em torna de 
5 minutos para compilar e descompilar.
*/

#include <stdio.h>
#include <stdlib.h>

#include "compacta.h"

int main(int argc, char *argv[]){

  //Verifica se o nome do arquivo foi colocada na linha de comando  
  if(argc != 2){
    printf("Arquivo nao indicado na linha de comando!\n");
    return 0;
  }

  // --------- CRIACAO DA TABELA DE FREQUENCIA ---------- 

  unsigned int* tabela = inicializaTabelaFrequencia();
  
  analisaFrequencia(argv[1], tabela);

  // --------- CRIACAO DA LISTA ORDENADA DE ARVORES ----------

  Lista *lista = inicializaLista();

  criaLista(tabela, lista);

  // --------- CRIACAO DA ARVORE ----------

  Arvore* arvore = criaArvoreBinariaComLista(lista, retornaPrimeiroLista(lista));

  // --------- CRIACAO DO DICIONARIO ----------

  int colunas = alturaArvore(arvore) + 1;

  char **dicionario = inicializaDicionario(colunas);
  
  geraDicionario(dicionario, arvore, "", colunas);

  // --------- COMPACTACAO DO ARQUIVO ----------

  compactarArquivo(dicionario, argv[1], tabela, arvore);

  //Liberacao da memoria
  free(tabela);
  destroiLista(lista);
  liberaArvore(arvore);
  destroiDicionario(dicionario);

  return 0;
}