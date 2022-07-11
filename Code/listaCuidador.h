#ifndef LISTACUIDADOR_H
#define LISTACUIDADOR_H

/*Tipo que define a Lista de Cuidadores
 *Uma lista encadeada que armazena ponteiros para cuidadores, tais cuidadores
 *na lista correspondem aos que cuidam do idoso que carrega tal lista. Também pelo
 *programa foi utilizado esse tipo para armazenar uma lista geral de cuidadores, no
 *qual ficava destrelado de qualquer idoso, assim não perdendo referencia em caso de
 *falecimento de qualquer idoso que poderia conter tal. 
 *A lista não tem um limite de tamanho.*/
typedef struct listaCuidadores ListaCuidadores;

#include "cuidador.h"
#include "idoso.h"

/*Incializa a Lista de Cuidadores
 *inputs: nao tem
 *output: lista alocada e vazia
 *pre-condicao: nao tem
 *pos-condicao: lista alocada e vazia*/
ListaCuidadores* inicializaListaCuidadores();

/* Insere um cuidador na lista de cuidadores
 *inputs: ponteiros para o cuidador e a lista no qual sera inserido
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: Cuidador inserido na lista*/
void insereCuidadores(ListaCuidadores* lista, Cuidador* cuidador);

/* Encontra um cuidador dentro de uma lista pelo seu nome e retorna seu ponteiro
 *inputs: ponteiros para a lista e para o nome a ser procurado
 *output: ponteiro para o cuidador
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
Cuidador* encontraCuidador(ListaCuidadores* lista, char* nome);

/* Percorre um numero de posições na lista de cuidadores e retorna o correspondente ao indice
 *inputs: ponteiros para a lista e o valor do indice
 *output: ponteiro para o cuidador
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
Cuidador* retornaCuidador(ListaCuidadores* lista, int indice);

/* Conta o tamanho atual da lista e retorna o valor
 *inputs: ponteiro para a lista
 *output: numero de cuidadores na lista atualmente (int)
 *pre-condicao: nao tem
 *pos-condicao: valor retornado*/
int retornaTamListaCuidador(ListaCuidadores* lista);

/* Retorna nome do cuidador mais próximo do idoso
 *inputs: ponteiro para a lista de cuidadores do idoso e ponteiro para as coordenadas do idoso
 *output: ponteiro para o nome do cuidador mais proximo
 *pre-condicao: nao tem
 *pos-condicao: nome do cuidador mais proximo é retornado*/
char* chamaCuidador(ListaCuidadores* lista, int* coordIdoso);

/* Fecha os arquivos de cada cuidador na lista 
 *Usado com a lista geral de cuidadores no final do programa
 *inputs: ponteiro para a lista de cuidadores
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: todos os arquivos correspondentes de cada cuidador na lista fechado*/
void finalizaArquivosCuidadores(ListaCuidadores* lista);

/*Limpa a memória alocado para a lista, mas não os cuidadores inseridos em tal 
 *Usado para a limpeza da lista de cuidadores dentro do tipo Idoso
 *inputs: ponteiro para idoso que possui lista
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: toda memoria alocada liberada*/
void destroiListaCuidadores(Idoso* idosoFalecido);

/*Limpa a memória alocada para a lista e dos cuidadores inseridos em tal 
 *Usado com a lista geral de cuidadores no final do programa
 *inputs: ponteiro para lista de cuidadores 
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: toda memoria alocada liberada*/
void destroiListaCuidadoresG(ListaCuidadores* lista);

#endif //LISTACUIDADOR_H