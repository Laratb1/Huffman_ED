#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "descompacta.h"


unsigned int verificaBit(unsigned char byte, int i){
  unsigned char mascara = (1 << i);
  return byte & mascara;
}

void descompactarArquivo(char *arquivo){
  FILE *compactado = fopen(arquivo, "rb");

  if (compactado == NULL){
    printf("Erro ao abrir o arquivo compactado.\n");
    exit(1);
  }

  char *extensao = (char*) malloc(20 * sizeof(char));
  char aux1;
  int j;

  //Le a extensao no comeco do arquivo
  for(j = 0; aux1 != '<'; j++){
   
    fread(&aux1, sizeof(char), 1, compactado);
    extensao[j] = aux1;
  }

  extensao[j-1] = '\0';

  //Montando o nome do novo arquivo
  char *novoArquivo = (char*) malloc(100 * sizeof(char));
  strcat(novoArquivo, "descompactado.");
  strcat(novoArquivo, extensao);

  FILE *descompactado = fopen(novoArquivo, "wb");

  if (descompactado == NULL){
    printf("Erro ao abrir o arquivo descompactado\n");
    exit(1);
  }

  Arvore *arvore = leArvoreDoArquivo(compactado);
  Arvore *raiz = arvore;
  unsigned char c;
  unsigned char *aux = (unsigned char*)malloc(sizeof(unsigned char));

  if (compactado == NULL){
    printf("Erro ao abrir o descompactado\n");
    exit(1);
  }
  
  int cont = 0;
  
  while (fread(&c, sizeof(unsigned char), 1, compactado)){
    for (int i = 7; i >= 0; i--){

      //Se o bit for 1, segue para direita
      if (verificaBit(c, i)){ 
        raiz = retornaDireita(raiz);
      }
      //Se o bit for diferente de 1, segue para esquerda
      else{
        raiz = retornaEsquerda(raiz);
      }
      //Se for uma folha
      if (retornaEsquerda(raiz) == NULL && retornaDireita(raiz) == NULL){
        *aux = retornaCaracter(raiz);

        //Verifica se o caracter atual eh o sinalizador de parada
        if(*aux != 255){
          fwrite(aux, sizeof(unsigned char), 1, descompactado);
          raiz = arvore;
        }
        else{
          break;
        }
      }
    }
  }

  //Liberacao de memoria
  fclose(compactado);
  fclose(descompactado);
  free(aux);
  liberaArvore(arvore);
}