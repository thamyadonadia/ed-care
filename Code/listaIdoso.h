#ifndef LISTAIDOSO_H
#define LISTAIDOSO_H

#include "idoso.h"

/*Tipo que define a Lista de Idosos
 *Uma lista encadeada que armazena ponteiros para Idosos. No programa 
 *foi utilizado esse tipo para armazenar uma lista geral de Idosos.
 *A lista não tem um limite de tamanho.
 **/
typedef struct listaidoso ListaIdoso;

/*Incializa a Lista de Idosos
 *inputs: nao tem
 *output: lista alocada e vazia
 *pre-condicao: nao tem
 *pos-condicao: lista alocada e vazia*/
ListaIdoso* inicializaListaIdoso();

/* Insere um Idoso na lista de Idosos
 *inputs: ponteiros para o Idoso e a lista no qual sera inserido
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: Idoso inserido na lista*/
void insereIdoso(ListaIdoso* lista, Idoso* idoso);

/* Retira um Idoso da lista de Idosos
 *inputs: ponteiros para o Idoso e a lista no qual sera removido
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: Idoso retirado da lista*/
void retiraIdoso(ListaIdoso* lista, Idoso* idoso);

/* Encontra um idoso dentro de uma lista pelo seu nome e retorna seu ponteiro
 *inputs: ponteiros para a lista e para o nome a ser procurado
 *output: ponteiro para o idoso
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
Idoso* encontraIdoso(ListaIdoso* lista, char* nome);

/* Percorre um numero de posições na lista de idosos e retorna o correspondente ao indice
 *inputs: ponteiros para a lista e o valor do indice
 *output: ponteiro para o Idoso
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
Idoso* getIdoso(ListaIdoso* lista, int indice);

/* Conta o tamanho atual da lista e retorna o valor
 *inputs: ponteiro para a lista
 *output: numero de idosos na lista atualmente (int)
 *pre-condicao: nao tem
 *pos-condicao: valor retornado*/
int getTamListaIdoso(ListaIdoso* lista);

/*FUNÇÃO USADA NA FASE DE TESTES, NÃO USADA NO PROGRAMA FINAL
 *Imprime a lista de idosos no console
 *inputs: ponteiro para lista de idosos
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: lista de idosos impressa no console*/
void imprimeListaIdoso(ListaIdoso* lista);

/* Fecha os arquivos de cada idoso na lista 
 *Usado com a lista geral de idosos no final do programa
 *inputs: ponteiro para a lista de idosos
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: todos os arquivos correspondentes de cada idoso na lista fechado*/
void finalizaArquivosIdoso(ListaIdoso* lista);

/*Limpa a memória alocada para a lista e dos idosos inseridos em tal 
 *Usado com a lista geral de idosos no final do programa
 *inputs: ponteiro para lista de idosos 
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: toda memoria alocada liberada*/
void destroiListaIdosos(ListaIdoso* lista);

#endif // LISTAIDOSO_H  