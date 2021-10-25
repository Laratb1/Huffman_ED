#ifndef TABELA_FREQ_H
#define TABELA_FREQ_H

/*Inicializa a tabela de frequencia
 * inputs: nenhum
 * output: ponteiro para vetor de inteiros
 * pre-condicao: nenhuma
 * pos-condicao: tabela de frequencia existe 
 */
unsigned int *inicializaTabelaFrequencia(void);

/*Preenche a tabale de frequencia
 * inputs: nome do arquivo e tabela de frequencia
 * output: nenhum
 * pre-condicao: tabela precisa existir
 * pos-condicao: tabela de frequencia esta preenchida com as frequencias de cada caracter do arquivo
 */
void analisaFrequencia(char *arquivo, unsigned int *tabela);

/*Calculo o tamanho do arquivo que sera analisado
 * inputs: ponteiro para os arquivo
 * output: inteiro
 * pre-condicao: arquivo já deve ter sido aberto
 * pos-condicao: ponteiro para arquivo esta apontando para o final dele
 */
long calculaTamanhoArquivo(FILE *arquivo);

/*Libera memoria alocada para tabela
 * inputs: tabela de frequencia
 * output: ponteiro para a struct Usuario
 * pre-condicao: tabela deve existe
 * pos-condicao: toda a memória alocada para tabela foi liberada
 */
void destroiTabela(unsigned int *tabela);

#endif