#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabelaFreq.h"

#define TAM 256

unsigned int *inicializaTabelaFrequencia(void){
  //incializa tabela com 0
  unsigned int *tabela = (unsigned int*) calloc(TAM, sizeof(unsigned int));

  return tabela;
}

long int calculaTamanhoArquivo(FILE *arquivo){
  long int tamanho;

  if(arquivo == NULL){
    printf("Ponteiro de arquivo invalido\n");
    exit(1);
  }

  // posiciona indicador no final do arquivo
  fseek(arquivo, 0, SEEK_END);
  // retorna o tamanho
  tamanho = ftell(arquivo);

  return tamanho;
}

void analisaFrequencia(char *arquivo, unsigned int *tabela){
  FILE *fp = fopen(arquivo, "rb");
  
  if (fp == NULL){
    printf("Erro ao abrir o arquivo para leitura. Arquivo da tabela.");
    exit(1);
  }

  unsigned char *c = (unsigned char *)malloc(sizeof(unsigned char));

  long int tamanho = calculaTamanhoArquivo(fp);

  // Leitura do arquivo
  for (int i = 0; i < tamanho; i++){
    fseek(fp, i, SEEK_SET);
    fread(c, 1, 1, fp);
    // Faz o acrescimo na frequencia do caracter
    tabela[*c]++;
  }
  // Define frequencia do indicador de final de arquivo 
  //(sera usado na hora de compactar e descompactar)
  tabela[255] = 1;

  // liberacao de memoria
  fclose(fp);
  free(c);
}

void destroiTabela(unsigned int* tabela){
  free(tabela);
}