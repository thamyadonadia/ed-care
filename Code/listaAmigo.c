#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "listaAmigo.h"

typedef struct celulaamigo CelulaAmigo;

struct listaamigo{
    CelulaAmigo* prim;
    CelulaAmigo* ult;
};

struct celulaamigo{
    CelulaAmigo* prox;
    CelulaAmigo* ant;
    Idoso* amigo;
};

ListaAmigo* inicializaListaAmigo(){
    ListaAmigo* listaAmigo = malloc(sizeof(ListaAmigo));
    listaAmigo->prim=NULL;
    listaAmigo->ult=NULL;
    return listaAmigo;
}

void insereAmigo(Idoso* idoso, Idoso* amigo){

    //Insere amigo na lista de amigos do idoso
    CelulaAmigo* nova = (CelulaAmigo*) malloc(sizeof(CelulaAmigo));
    nova->amigo=amigo;
    nova->prox=NULL;

    ListaAmigo* lista = getListaAmigos(idoso);

    if(lista->prim == NULL){
        lista->prim = nova;
        nova->ant = NULL;
        
    }else{
        lista->ult->prox = nova;
        nova->ant = lista->ult;
    }
    
    lista->ult = nova;

    //Insere idoso na lista de amigos do amigo
    CelulaAmigo* novaAmigo = malloc(sizeof(CelulaAmigo));
    novaAmigo->prox=NULL;
    novaAmigo->amigo=idoso;

    lista = getListaAmigos(amigo);

    if(lista->prim == NULL){
        lista->prim = novaAmigo;
        novaAmigo->ant = NULL;
        
    }else{
        lista->ult->prox = novaAmigo;
        novaAmigo->ant = lista->ult;
    }
    
    lista->ult = novaAmigo;    
}

void retiraAmigo(ListaAmigo* lista, Idoso* idoso){
    CelulaAmigo* p;

    //procura o amigo dentro da lista pelo seu ponteiro
    for(p = lista->prim; p!=NULL; p = p->prox){
        if(p->amigo == idoso){
            // se for o único da lista 
            if(lista->prim == lista->ult){
                lista->prim = NULL;
                lista->ult = NULL;
                free(p);
                return;

            // se for o primeiro da lista 
            }else if(p == lista->prim){
                lista->prim = p->prox;
                p->prox->ant = NULL;
                free(p);
                return;

            // se for o último da lista 
            }else if(p == lista->ult){
                lista->ult = p->ant;
                p->ant->prox = NULL;
                free(p);
                return;
            
            // outros casos
            }else{
                p->ant->prox = p->prox;
                 p->prox->ant = p->ant;
                free(p);
                return;
            }
        }
    }
}

void retiraFalecido(Idoso* idosoFalecido){
    ListaAmigo* listaAmigosFalecido = getListaAmigos(idosoFalecido);
    ListaAmigo* listaAmigos; CelulaAmigo* p;
  
    //passa por todas as listas de amigos de seus amigos e se retira dela
    for(p = listaAmigosFalecido->prim; p!=NULL; p = p->prox){
        listaAmigos = getListaAmigos(p->amigo);
        retiraAmigo(listaAmigos, idosoFalecido);
    }
}

/* Recebe dois vetores de coordenadas e retorna a distancia
 *inputs: Ponteiros para coordenadas 
 *output: a distancia entre os dois (float)
 *pre-condicao: nao tem
 *pos-condicao: distancia retornada corretamente*/
static float calculaDistancia(int* coordIdoso, int* coordAmigo){

    //coleta as coordenadas 
    int xIdoso = coordIdoso[0], yIdoso = coordIdoso[1];
    int xAmigo = coordAmigo[0], yAmigo = coordAmigo[1];

    //calcula a distancia euclidiana
    float dist = sqrt((pow((xAmigo-xIdoso),2) + (pow((yAmigo-yIdoso),2))));
    
    return dist;
}

char* chamaAmigo(ListaAmigo* lista, int* coordIdoso){
    CelulaAmigo* p = lista->prim; CelulaAmigo* maisProx = lista->prim;
    float dist=-1 , aux;
    int* coordAmigo;

    //caso nao tenha amigos
    if(lista->prim==NULL){
        return NULL;
    }

    for(p = lista->prim; p!=NULL; p = p->prox){
        // verfica se o idoso está em condições de ser chamado
        if(!(getFalecimento(p->amigo)==1)){
            //se for o primeiro idoso valido registra ele como o mais proximo
            if(dist==-1){
                coordAmigo = getCoordenadasIdoso(p->amigo);
                dist = calculaDistancia(coordIdoso, coordAmigo);
                maisProx = p;
            }

            //calcula sua distancia e atribui a variavel auxiliar
            aux = calculaDistancia(getCoordenadasIdoso(p->amigo),coordIdoso);

            //verifica se é mais próximo que o mais próximo até então, se for, registra
            if(aux<dist){
                dist = aux;
                maisProx = p;
            }
        }
    }

    // indica que não há nenhum amigo em condições de ajudar o idoso 
    if(dist==-1){
        return NULL;
    }
    
    //retorna o ponteiro para o nome do idoso mais próximo
    return getNomeIdoso(maisProx->amigo);
}

void imprimeListaAmigo(ListaAmigo* lista){
    CelulaAmigo* p;

    //FUNÇÃO USADA EM PERIODO DE TESTES
    //Imprime a lista de amigos que receber
    if(lista->prim == NULL && lista->ult == NULL){
        printf("A lista está vazia\n");
    }else{
        for(p = lista->prim; p!=NULL; p = p->prox){
            imprimeIdoso(p->amigo);
        }
    }
    
}

void destroiListaAmigos(Idoso* idosoFalecido){

    //Coleta lista de amigos do idoso falecido
    ListaAmigo* listaAmigos = getListaAmigos(idosoFalecido);
    CelulaAmigo* p = listaAmigos->prim ; CelulaAmigo* temp = NULL;

    //libera celula por celula, sem liberar oq ela contem
    while(p!= NULL){
        temp = p->prox;
        free(p);
        p=temp;
    }

    free(listaAmigos);
}