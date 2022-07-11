#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaIdoso.h"

typedef struct celulaidoso CelulaIdoso;

struct celulaidoso{
    CelulaIdoso* ant;
    CelulaIdoso* prox;
    Idoso* idoso;
};

struct listaidoso{
    CelulaIdoso* prim;
    CelulaIdoso* ult;
};

ListaIdoso* inicializaListaIdoso(){
    ListaIdoso* listaIdoso = (ListaIdoso*) malloc(sizeof(ListaIdoso));
    listaIdoso->prim = NULL;
    listaIdoso->ult = NULL;
    return listaIdoso;
}

void insereIdoso(ListaIdoso* lista, Idoso* idoso){
    //insere idoso em um celula
    CelulaIdoso* nova = (CelulaIdoso*) malloc(sizeof(CelulaIdoso));
    nova->idoso = idoso;
    nova->prox = NULL;

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

void retiraIdoso(ListaIdoso* lista, Idoso* idoso){
    CelulaIdoso* p;

    for(p = lista->prim; p!=NULL; p = p->prox){
        if(p->idoso == idoso){
            //caso seja o único na lista
            if(lista->prim == lista->ult){
                lista->prim = NULL;
                lista->ult = NULL;
                free(p);
                return;

            // idoso no primeiro lugar da lista
            }else if(p == lista->prim){
                lista->prim = p->prox;
                p->prox->ant = NULL;
                free(p);
                return;
            
            // idoso no último lugar da lista
            }else if(p->prox == NULL){
                lista->ult = p->ant;
                p->ant->prox = NULL;
                free(p);
                return;

            // idoso está no meio da lista
            }else{
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
                free(p);
                return;
            }
        }
    }
}

Idoso* encontraIdoso(ListaIdoso* lista, char* nome){
    CelulaIdoso* p = NULL;

    //percorre a lista até encontrar um com o nome exato
    for(p = lista->prim; p!=NULL; p=p->prox){
        if(!strcmp(getNomeIdoso(p->idoso), nome)){
            return p->idoso;
        }
    }

    //caso não encontre, retorna NULL
    return NULL;
}

Idoso* getIdoso(ListaIdoso* lista, int indice){
    CelulaIdoso* p; int i;

    //percorre a lista até encontrar o índice desejado
    for(i=0, p=lista->prim; i<=indice && p!=NULL; i++, p=p->prox){
        if(i == indice){
            return p->idoso;
        }
    }
    
    //caso não encontre, retorna NULL
    return NULL;
}

int getTamListaIdoso(ListaIdoso* lista){
    CelulaIdoso* p; int tamLista=0;

    //percorre a lista contando cada espaço
    for(p=lista->prim; p!=NULL; p=p->prox){
        tamLista++;
    }

    //retorna tamanho da lista
    return tamLista;
}

void imprimeListaIdoso(ListaIdoso* lista){
    CelulaIdoso* p;
    
    //FUNÇÃO USADA EM PERIODO DE TESTES
    //Imprime a lista de idosos que receber
    for(p = lista->prim; p!=NULL; p = p->prox){
        imprimeIdoso(p->idoso);
    }
}

void finalizaArquivosIdoso(ListaIdoso* lista){
    CelulaIdoso* p; Idoso* idoso; FILE* arquivoE; FILE* arquivoS;

    //percorre uma lista de idosos, acessa seus arquivos de entrada e saida, e os fecha
    for(p = lista->prim; p!=NULL; p = p->prox){
        idoso = p->idoso;
        arquivoE = getArquivoEntradaIdoso(idoso);
        fclose(arquivoE);
        arquivoS = getArquivoSaidaIdoso(idoso);
        fclose(arquivoS);
    }
}

void destroiListaIdosos(ListaIdoso* lista){
    CelulaIdoso* p = lista->prim; CelulaIdoso* temp = NULL;

    //passa pela lista toda, liberando todas as suas celulas e seu conteudo
    while(p!=NULL){
        temp = p->prox;
        destroiIdoso(p->idoso);
        free(p);
        p = temp;
    }

    //libera a lista em si
    free(lista);
}