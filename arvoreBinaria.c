#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvoreBinaria.h"

struct arvore{
  unsigned char c;
  int frequencia;
  Arvore *esq;
  Arvore *dir;
};

Arvore *criaArvoreVazia(void){
  return NULL;
}

Arvore *criaArvore(char c, int frequencia, Arvore *esq, Arvore *dir){
  //Aloca memora para a arvore
  Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
  arv->frequencia = frequencia;
  arv->c = c;
  arv->esq = esq;
  arv->dir = dir;

  return arv;
}

Arvore *criaArvoreBinariaComLista(Lista *lista, CelLista *p){
  Arvore *primeiro, *segundo, *novo;
  // Condicao de parada ate que reste apenas uma arvore na lista
  while(tamanhoDaLista(lista) != 1){
    primeiro = retiraArvoreDaLista(lista, retornaPrimeiroLista(lista));
    segundo = retiraArvoreDaLista(lista, retornaPrimeiroLista(lista));
    novo = criaArvoreVazia();
    // cria arvore com a soma das frequencias
    novo = criaArvore('+', primeiro->frequencia + segundo->frequencia, primeiro, segundo);
    // insere arvore criada
    insereArvoreNaLista(lista, novo);
  }
  // retorna a arvore criada retirando ela da lista e liberando a celula
  return retiraArvoreDaLista(lista, retornaPrimeiroLista(lista));
}

Arvore *liberaArvore(Arvore *arv){
  if (!arvoreVazia(arv)){
    liberaArvore(arv->esq);
    liberaArvore(arv->dir);
    free(arv);
  }
  return NULL;
}

Arvore *retornaDireita(Arvore *a){
  if (!arvoreVazia(a))
    return a->dir;
  return NULL;
}

Arvore *retornaEsquerda(Arvore *a){
  if (!arvoreVazia(a))
    return a->esq;
  return NULL;
}

int retornaFrequencia(Arvore *a){
  return a->frequencia;
}

unsigned char retornaCaracter(Arvore *a){
  if (!arvoreVazia(a))
    return a->c;
  return 0;
}

int arvoreVazia(Arvore *a){
  if (a == NULL){
    return 1;
  }
  return 0;
}

static int max2(int a, int b){
  return (a > b) ? a : b;
}

int alturaArvore(Arvore *a){
  if (arvoreVazia(a)){
    return -1;
  }
  else{
    return 1 + max2(alturaArvore(a->esq), alturaArvore(a->dir));
  }
}

void imprimeArvore(Arvore *a){
  if (!arvoreVazia(a)){
    printf("Caracter: %c Frequencia: %d\n", a->c, a->frequencia);
    imprimeArvore(a->esq);
    imprimeArvore(a->dir);
  }
}

void imprimeArvoreNoArquivo(Arvore *a, FILE *arquivo){
  char *c = (char *)malloc(sizeof(char));
  char freq[100];

  if(arquivo == NULL){
    printf("Ponteiro para arquivo invalido!\n");
    exit(1);
  }

  //Imprime so as folhas no arquivo separadas por ';' e a frequancia  e o caracter separados por ','
  if (!arvoreVazia(a)){
    if (a->dir == NULL && a->esq == NULL){
      *c = a->c;
      fwrite(c, 1, 1, arquivo);
      *c = ',';
      fwrite(c, 1, 1, arquivo);

      sprintf(freq, "%d", a->frequencia);

      for (int i = 0; i < strlen(freq); i++){
        *c = freq[i];
        fwrite(c, 1, 1, arquivo);
      }

      *c = ';';
      fwrite(c, 1, 1, arquivo);
    }

    imprimeArvoreNoArquivo(a->esq, arquivo);
    imprimeArvoreNoArquivo(a->dir, arquivo);
  }
  free(c);
}

Arvore *leArvoreDoArquivo(FILE *fp){
  unsigned char c;
  unsigned int *tabela = (unsigned int *)calloc(256, sizeof(unsigned int));
  Lista *lista = inicializaLista();

  unsigned char caracter;
  unsigned char freq[20];
  unsigned int frequencia;
  int j = 0;

  //Exemplo de arvore impressa no arquivo: m,1;l,2;a,1;>resto do arquivo

  //Vai ler o arquivo ate encontrar o sinalizador de fim de arvore
  while (1){
    fread(&c, sizeof(unsigned char), 1, fp);

    if (c == '>')
      break;

    caracter = c;

    fread(&c, sizeof(unsigned char), 1, fp);

    //Pega a frequencia de pois da ','
    for (j = 0, fread(&c, sizeof(unsigned char), 1, fp); c != ';'; fread(&c, sizeof(unsigned char), 1, fp), j++){
      freq[j] = c;
    }

    freq[j] = '\0';

    //Transforma a string frequencia em inteiro
    frequencia = atoi(freq);

    //Armazena a frequencia do caracter
    tabela[caracter] = frequencia;
  }

  //Cria lista ordenada
  criaLista(tabela, lista);
  
  //Cria arvore
  Arvore *arvore = criaArvoreBinariaComLista(lista, retornaPrimeiroLista(lista));

  //Liberacao de memoria
  free(tabela);
  destroiLista(lista);

  return arvore;
}
