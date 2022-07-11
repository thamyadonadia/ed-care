#ifndef LISTAAMIGO_H
#define LISTAAMIGO_H

/*Tipo que define a Lista de Amigos
 *Uma lista encadeada que armazena ponteiros para idosos, tais idosos
 *na lista correspondem aos amigos do idoso que carrega tal lista. Qualquer amizade
 *dentro do programa é recíproca, logo, um idoso esta na lista de amigos de seu amigo.
 *A lista não tem um limite de tamanho.*/
typedef struct listaamigo ListaAmigo;

#include "idoso.h"

/*Incializa a Lista de Amigos
 *inputs: nao tem
 *output: lista alocada e vazia
 *pre-condicao: nao tem
 *pos-condicao: lista alocada e vazia*/
ListaAmigo* inicializaListaAmigo();

/* Insere um idoso na lista de amigos do outro e vise versa
 *inputs: ponteiros para os dois idosos
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: Idosos inseridos na lista de amigo um do outro*/
void insereAmigo(Idoso* idoso, Idoso* amigo);

/* Retira um idoso de um lista de amigos
 *inputs: ponteiros para a lista e para o idoso
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: Idoso é retirado da lista*/
void retiraAmigo(ListaAmigo* lista, Idoso* idoso);


/* Retira o idoso falecido da lista de amigos que ele estava quando vivo
 *inputs: ponteiro para o idoso falecido
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: Idoso é retirado da lista de amigos de todos os seus amigos*/
void retiraFalecido(Idoso* idosoFalecido);

/* Retorna nome do amigo valido (vivo) mais próximo do idoso
 *inputs: ponteiro para a lista do idoso e ponteiro para as coordenadas do idoso
 *output: ponteiro para o nome do amigo mais proximo
 *pre-condicao: nao tem
 *pos-condicao: nome do amigo valido mais proximo é retornado*/
char* chamaAmigo(ListaAmigo* lista, int* coordIdoso);

/*FUNÇÃO USADA NA FASE DE TESTES, NÃO USADA NO PROGRAMA FINAL
 *Imprime a lista de amigos no console
 *inputs: ponteiro para lista de amigos
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: lista de amigos impressa no console*/
void imprimeListaAmigo(ListaAmigo* lista);

/*Limpa a memória alocado para a lista, mas não os idosos inseridos em tal 
 *Usado tanto para a limpeza da lista de amigos de um idoso falecido ou para encerramento do programa
 *inputs: ponteiro para idoso que possui lista
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: toda memoria alocada liberada*/
void destroiListaAmigos(Idoso* idosoFalecido);

#endif // LISTAAMIGO_H