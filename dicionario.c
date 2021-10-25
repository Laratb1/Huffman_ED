#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dicionario.h"

#define TAM 256

char **inicializaDicionario(int numColunas){
    char **dicionario;
    // aloca dicionario e faz apontar para null
    dicionario = (char**)calloc(TAM, sizeof(unsigned char*));

    //Aloca cada linha do dicionario
    for(int i = 0; i < TAM; i++){
        dicionario[i] = (char*)calloc(numColunas, sizeof(char));
    }
    return dicionario;
}

void geraDicionario(char** dicionario, Arvore* raiz, char *caminho, int colunas){
    char esquerda[colunas], direita[colunas];

    //Condicao de parada da recursao: arvore tem que ser uma folha
    if(retornaEsquerda(raiz) == NULL && retornaDireita(raiz) == NULL){
        strcpy(dicionario[retornaCaracter(raiz)], caminho);
    }
    else {
        strcpy(esquerda, caminho);
        strcpy(direita, caminho);
        
        //Se for para a esquerda, adicioana 0, e para direita, adiciona 1
        strcat(esquerda, "0");
        strcat(direita, "1");

        //Percorre  a arvore com recursao
        geraDicionario(dicionario, retornaEsquerda(raiz), esquerda, colunas);
        geraDicionario(dicionario, retornaDireita(raiz), direita, colunas);
    }
}

void destroiDicionario(char **d){
    for(int i = 0; i < TAM; i++){
        free(d[i]);
    }
    free(d);
}

void imprimeDicionario(char** dicionario){
    for(int i = 0; i < TAM; i++){
        printf ("%c %s\n", i, dicionario[i]);
    }
}

