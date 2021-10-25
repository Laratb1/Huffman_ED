/*
Feito por: Lara Tagarro e Milla Pereira
O seguinte programa tem como objetivo descompactar os arquivos
que foram compactados no arquivo "mainCompacts", portanto não 
ira funcionar com outros arquivos aleatorios.
*/

#include <stdio.h>
#include <stdlib.h>

#include "listaOrdenada.h"
#include "tabelaFreq.h"
#include "arvoreBinaria.h"
#include "dicionario.h"
#include "compacta.h"
#include "descompacta.h"

int main(int argc, char *argv[]){
    
    //Verifica se o nome do arquivo foi colocada na linha de comando  
    if(argc != 2){
        printf("Erro!\n");
        return 0;
    }

    //Descompacta arquivo
    descompactarArquivo(argv[1]);

    return 0;
}