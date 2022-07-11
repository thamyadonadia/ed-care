#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "listaCuidador.h"

typedef struct celulaCuidador CelulaCuidador;

struct celulaCuidador{
    CelulaCuidador* ant;
    CelulaCuidador* prox;
    Cuidador* cuidador;
};

struct listaCuidadores{
    CelulaCuidador* prim;
    CelulaCuidador* ult;
};

ListaCuidadores* inicializaListaCuidadores(){
    ListaCuidadores* listaCuidador = (ListaCuidadores*) malloc(sizeof(ListaCuidadores));
    listaCuidador->prim=NULL;
    listaCuidador->ult=NULL;
    return listaCuidador;
}

void insereCuidadores(ListaCuidadores* lista, Cuidador* cuidador){
    //insere cuidador em uma celula
    CelulaCuidador* nova = (CelulaCuidador*) malloc(sizeof(CelulaCuidador));
    nova->cuidador = cuidador;
    nova->prox=NULL;

    //caso a lista esteja vazia
    if(lista->prim == NULL){
        lista->prim = nova;
        nova->ant = NULL;

    //qualquer outro caso
    }else{
        lista->ult->prox = nova;
        nova->ant = lista->ult;
    }

    lista->ult = nova;
}

Cuidador* encontraCuidador(ListaCuidadores* lista, char* nome){
    CelulaCuidador* p = NULL;

    //percorre a lista até encontrar um com o nome exato
    for(p = lista->prim; p!=NULL; p = p->prox){
        if(!strcmp(getNomeCuidador(p->cuidador), nome)){
            return p->cuidador;
        }
    }

    //caso não encontre, retorna NULL
    return NULL;
}

Cuidador* retornaCuidador(ListaCuidadores* lista, int indice){
    CelulaCuidador* p; int i;

    //percorre a lista até encontrar o índice desejado
    for(i=0, p=lista->prim; i<=indice && p!=NULL; i++, p=p->prox){
        if(i == indice){
            return p->cuidador;
        }
    }
    
    //caso não encontre, retorna NULL
    return NULL;
}

int retornaTamListaCuidador(ListaCuidadores* lista){
    CelulaCuidador* p; int tamLista=0;

    //percorre a lista contando cada espaço
    for(p=lista->prim; p!=NULL; p=p->prox){
        tamLista++;
    }

    //retorna tamanho da lista
    return tamLista;
}

/* Recebe dois vetores de coordenadas e retorna a distancia
 *inputs: Ponteiros para coordenadas 
 *output: a distancia entre os dois (float)
 *pre-condicao: nao tem
 *pos-condicao: distancia retornada corretamente*/
static float calculaDistancia(int* coordIdoso, int* coordCuidador){

    //coleta coordenadas do idoso e do cuidador
    int xIdoso = coordIdoso[0], yIdoso = coordIdoso[1];
    int xCuidador = coordCuidador[0], yCuidador = coordCuidador[1];

    //calcula a distancia euclidiana
    float dist = sqrt((pow((xCuidador-xIdoso),2) + (pow((yCuidador-yIdoso),2))));
    
    return dist;
}

char* chamaCuidador(ListaCuidadores* lista, int* coordIdoso){
    /*atribui o primeiro da lista como o mais próximo (ja que todos os cuidadores estão
     * disponiveis), caso encontre algum mais próximo, substitui */

    CelulaCuidador* p = lista->prim; CelulaCuidador* maisProx = lista->prim;
    int* coordCuidador = getCoordenadasCuidador(p->cuidador);
    float dist = calculaDistancia(coordIdoso, coordCuidador), aux;

    //percorre a lista em busca de algum mais próximo
    for(p = lista->prim; p!=NULL; p = p->prox){
        aux= calculaDistancia(getCoordenadasCuidador(p->cuidador), coordIdoso);
        if(aux<dist){
            dist=aux;
            maisProx=p;
        }
    }

    //retorna o ponteiro para o nome do cuidador mais próximo
    return getNomeCuidador(maisProx->cuidador);
}


void finalizaArquivosCuidadores(ListaCuidadores* lista){
    CelulaCuidador* p; Cuidador* cuidador; FILE* arquivo;

    //passa pela lista, pega o ponteiro para o arquivo e o fecha
    for(p = lista->prim; p!=NULL; p = p->prox){
        cuidador = p->cuidador;
        arquivo = getArquivoCuidador(cuidador);
        fclose(arquivo);
    }
}

void destroiListaCuidadores(Idoso* idosoFalecido){
    ListaCuidadores* listaCuidadores = getListaCuidadores(idosoFalecido);
    CelulaCuidador* p = listaCuidadores->prim; CelulaCuidador* temp = NULL;

    //libera celula por celula, sem liberar o seu conteúdo
    while(p!=NULL){
        temp = p->prox;
        free(p);
        p=temp;
    }

    free(listaCuidadores);
} 

void destroiListaCuidadoresG(ListaCuidadores* lista){
    CelulaCuidador* p = lista->prim; CelulaCuidador* temp = NULL;

    //passa pela lista toda, liberando todas as suas celulas e seu conteudo
    while(p!=NULL){
        temp = p->prox;
        destroiCuidador(p->cuidador);
        free(p);
        p=temp;
    }

    //libera a lista em si
    free(lista);
}