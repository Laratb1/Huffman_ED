#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaOrdenada.h"

#define TAM 256

struct celLista{
  Arvore *arv;
  CelLista *prox;
};

struct lista{
  CelLista *prim;
  CelLista *ult;
};

Lista *inicializaLista(void){
  //aloca memoria para lista
  Lista *lista = (Lista *)malloc(sizeof(Lista));

  lista->prim = NULL;
  lista->ult = NULL;

  return lista;
}

void criaLista(unsigned int *frequencia, Lista *lista){

  //Percorre tabela de frequencia e cria as arvores para serem adicionadas na lista
  for (int i = 0; i < TAM; i++){

    //Verifica se a frequancia do caracter eh diferente de 0
    if (frequencia[i] != 0){
      insereArvoreNaLista(lista, criaArvore(i, frequencia[i], criaArvoreVazia(), criaArvoreVazia()));
    }
  }
}

void destroiLista(Lista *lista){
  CelLista *p;
  CelLista *t;

  p = lista->prim;

  //Percorre a lista destuindo as arvores
  while (p != NULL){
    t = p->prox;
    liberaArvore(p->arv);
    free(p);
    p = t;
  }

  free(lista);
}

void insereArvoreNaLista(Lista *lista, Arvore *arv){
  CelLista *nova = (CelLista *)malloc(sizeof(CelLista));
  nova->arv = arv;

  // se a lista esta vazia
  if (lista->prim == NULL){
    lista->prim = nova;
    lista->ult = nova;
    nova->prox = NULL;
  }
  // se a frequencia da arvore nova for maior que a frequencia do ultimo da lista
  else if (retornaFrequencia(nova->arv) > retornaFrequencia(lista->ult->arv)){
    lista->ult->prox = nova;
    lista->ult = nova;
    nova->prox = NULL;
  }
  // se a frequencia da arvore nova for maior que a frequencia da primeira da lista
  else if (retornaFrequencia(arv) < retornaFrequencia(lista->prim->arv)){
    nova->prox = lista->prim;
    lista->prim = nova;
  }
  // se a frequencia da arvore nova estiver no meio da lista 
  else{
    CelLista *p = lista->prim;
    CelLista *anterior;

    while (p && retornaFrequencia(p->arv) <= retornaFrequencia(arv)){
      anterior = p;
      p = p->prox;
    }

    if (p == lista->prim){
      p->prox = nova;
      nova->prox = NULL;
    }

    else{
      anterior->prox = nova;
      nova->prox = p;
    }

    if (p == NULL){
      lista->ult = nova;
    }
  }
}

Arvore *retiraArvoreDaLista(Lista *lista, CelLista *celula){
  CelLista *p = lista->prim;
  CelLista *anterior = NULL;
  Arvore* arv;

  //Percorre a lista procurando o elemento
  while (p != NULL && p != celula){
    anterior = p;
    p = p->prox;
  }

  //Se o item nao estiver na lista
  if (p == NULL){
    printf("Item não encontrado na lista.\n");
    exit(1);
  }
  //Se a lista so tiver um item
  if (p == lista->prim && p == lista->ult){
    lista->prim = NULL;
    lista->ult = NULL;
  }
  //Se for o primeiro item da lista
  else if (p == lista->prim){
    lista->prim = p->prox;
  }
  //Se for o ultimo item da lista
  else if (p == lista->ult){
    lista->ult = anterior;
    lista->ult->prox = NULL;
  }
  //Se for um item do meio
  else{
    anterior->prox = p->prox;
  }
  arv = p->arv;
  free(p);

  //retorna a arvore da celula que foi destruida
  return arv;
}

CelLista *retornaPrimeiroLista(Lista *lista){
  return lista->prim;
}

CelLista *retornaUltimoLista(Lista *lista){
  return lista->ult;
}

CelLista *retornaProximoLista(CelLista *p){
  return p->prox;
}

Arvore *retornaArvoreDaCelLista(CelLista *p){
  return p->arv;
}

int tamanhoDaLista(Lista *lista){
  int cont = 0;
  CelLista *p = retornaPrimeiroLista(lista); 

  while (p != NULL){
    cont++;
    p = p->prox;
  }
  return cont;
}

void imprimeLista(Lista *lista){
  CelLista *p;
  int i = 1;
  for (p = lista->prim; p != NULL; p = p->prox, i++){
    printf("Item %d:\n", i);
    imprimeArvore(p->arv);
    printf("\n");
  }
}
