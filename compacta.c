#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compacta.h"

char *leExtensao(char *nomeArquivo){
  char *nome = strtok(nomeArquivo, "\0");
  char *aux;

  while(nome != NULL){
    
    nome = strtok(nome, "."); // usa o '.' para separar o nome do arquivo
    aux = nome;
    nome = strtok(NULL, "\0");
  }
 
  return aux;
}

void compactarArquivo(char **dicionario, char *arquivo, unsigned int *tabela, Arvore *a){
  FILE *fp = fopen(arquivo, "rb");

  if (fp == NULL){
    printf("Erro ao abrir o arquivo!");
    exit(1);
  }

  char *extensao = leExtensao(arquivo);

  long int tamArquivo = calculaTamanhoArquivo(fp);

  //Variavel para percorrer o arquivo que serah compactado 
  unsigned char *c = (unsigned char *)calloc(1, sizeof(unsigned char));

  //Variavel para percorrer o arquivo que serah o compactado
  unsigned char *c2 = (unsigned char *)calloc(1, sizeof(unsigned char));

  //Variavel para salvar o conteudo do arquivo com o padrao de bits do dicionario
  char *conteudo = (char*)calloc(200, sizeof(char));

  //Variavel para auxiliar na impressao de informacoes no novo  arquivo
  char* aux = (char*)calloc(200, sizeof(char));

  //bitmap que serah usado para imprimir no novo arquivo
  bitmap *bm = bitmapInit(200);
  int i, j;

  FILE *arquivoCompactado = fopen("compactado.comp", "wb");

  // ---- Impressao do cabecalho do arquivo (extensao e arvore) ----

  fwrite(extensao, sizeof(char), strlen(extensao), arquivoCompactado);
  
  *c = '<'; //sinalizador de inicio da arvore
  fwrite(c, 1, 1, arquivoCompactado);

  imprimeArvoreNoArquivo(a, arquivoCompactado);

  *c = '>'; //sinalizador de fim da arvore
  fwrite(c, 1, 1, arquivoCompactado);

  //Percorre o arquivo transformando cada caracter para o padrao do dicionario
  for (i = 0, j= 0; i < tamArquivo; i++, j++){

    fseek(fp, i, SEEK_SET);
    fread(c, 1, 1, fp);

    // Quando o conteudo tem tamanho maior que 8, imprime o que tem nele no arquivo
    if(strlen(conteudo) > 8 || i == tamArquivo - 1){

      int restoConteudo = strlen(conteudo)%8; 

      //Verifica se o conteudo eh divisivel por 8  
      if(restoConteudo != 0){
        //Salva o excedente do conteudo na variavel auxiliar
        for(int m = 0, n = strlen(conteudo) - restoConteudo; m < strlen(conteudo); m++, n++){
          aux[m] = conteudo[n];
        }
      }

      //Verifica se ja esya no final do arquivo para poder adicionar o sinalizador de final de conteudo real
      if(i == tamArquivo - 1){
        strcat(conteudo, dicionario[*c]); 
        strcat(conteudo, dicionario[255]);
      }

      //Adiciona os vits no bitmap
      for (int k = 0; k < strlen(conteudo) - strlen(conteudo)%8; k++){
        bitmapAppendLeastSignificantBit(bm, conteudo[k]);
      }

      //Escreve no arquivo novo o bytes dsalvos no bitmap
      for (int l = 0; l < bitmapGetLength(bm) / 8; l++){
        fseek(fp, l, SEEK_SET);
        *c2 = bitmapGetContents(bm)[l];
        fwrite(c2, 1, 1, arquivoCompactado);
      }

      //Libera o bitmap antigo e cria um novo
      bitmapLibera(bm);
      bm = bitmapInit(200);

      //Libera o conteudo antigo e cria um novo
      free(conteudo);
      conteudo = (char*)calloc(200, sizeof(char));

      //Se tiver algum resto do conteudo, salva ela para continuar concatenando
      if(restoConteudo > 0){
        strcat(conteudo, aux); 
      }

      j = 0;
    }

    //Concatena o codigo do dicionario em conteudo
    strcat(conteudo, dicionario[*c]);    
  }

  //Liberacao de memoria alocada
  bitmapLibera(bm);
  fclose(fp);
  fclose(arquivoCompactado);
  free(c);
  free(c2);
  free(aux);
  free(conteudo);
}