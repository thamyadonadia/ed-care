#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "idoso.h"

struct idoso{
    // informações pessoais do idoso
    char* nome;
    int* coordenadas;
    float temp;
    int queda;
    int falecimento;
    int qtdFebreBaixa;
    
    // listas de amigos e de cuidadores do idoso
    ListaAmigo* amigos;
    ListaCuidadores* cuidadores;
    
    // arquivos de entrada e de saída
    FILE* entrada;
    char* nomeArquivoEntrada;
    FILE* saida;
    char* nomeArquivoSaida;
};

Idoso* inicializaIdoso(char* nome){

    //Aloca espaço para suas informações pessoais, contadores e status
    Idoso* idoso = (Idoso*)malloc(sizeof(Idoso));
    idoso->nome = strdup(nome);
    idoso->coordenadas = (int*)malloc(sizeof(int) * 2);
    idoso->falecimento = 0;
    idoso->qtdFebreBaixa = 0;

    //Inicializa e atribui suas listas de amigos e cuidaddores
    idoso->amigos = inicializaListaAmigo();
    idoso->cuidadores = inicializaListaCuidadores();
    
    //Cria o nome para seus arquivos apartir do nome dado
    idoso->nomeArquivoEntrada = (char*) malloc(sizeof(char)*(strlen(idoso->nome)+6));
    sprintf(idoso->nomeArquivoEntrada, "%s.txt", idoso->nome);
    idoso->nomeArquivoSaida = (char*) malloc(sizeof(char)*(strlen(idoso->nome)+12));
    sprintf(idoso->nomeArquivoSaida, "%s-saida.txt", idoso->nome);
    return idoso;
}

int* getCoordenadasIdoso(Idoso* idoso){
    return idoso->coordenadas;
}

char* getNomeIdoso(Idoso* idoso){
    return idoso->nome;
}

float getTemp(Idoso* idoso){
    return idoso->temp;
}

int getQueda(Idoso* idoso){
    return idoso->queda;
}

FILE* getArquivoEntradaIdoso(Idoso* idoso){
    return idoso->entrada;
}

char* getNomeArquivoEntradaIdoso(Idoso* idoso){
    return idoso->nomeArquivoEntrada;
}

FILE* getArquivoSaidaIdoso(Idoso* idoso){
    return idoso->saida;
}

char* getNomeArquivoSaidaIdoso(Idoso* idoso){
    return idoso->nomeArquivoSaida;
}

ListaAmigo* getListaAmigos (Idoso* idoso){
    return idoso->amigos;
}

ListaCuidadores* getListaCuidadores(Idoso* idoso){
    ListaCuidadores *p = idoso->cuidadores;
    return p;
}

int getFalecimento(Idoso* idoso){
    return idoso->falecimento;
}

int getQtdFebreBaixa(Idoso* idoso){
    return idoso->qtdFebreBaixa;
}

void setCoordenadasIdoso(Idoso* idoso, int lat, int longi){
    idoso->coordenadas[0] = lat;
    idoso->coordenadas[1] = longi;
}

void setTemp(Idoso* idoso, float temp){
    idoso->temp = temp;
}

void setQueda(Idoso* idoso, int queda){
    idoso->queda = queda;
}

void setFalecimento(Idoso* idoso, int falecimento){
    idoso->falecimento = falecimento;
}

void setQtdFebreBaixa(Idoso* idoso){

    //Quando chamado, adiciona 1 ao contador
    idoso->qtdFebreBaixa++;

    //Se ultrapaçar o máximo (4), retorna a 0
    if(idoso->qtdFebreBaixa > 4){
       idoso->qtdFebreBaixa = 0;
    }
}

void setArquivoEntradaIdoso(Idoso* idoso, FILE* arquivo){
    idoso->entrada=arquivo;
}

void setArquivoSaidaIdoso(Idoso* idoso, FILE* arquivo){
    idoso->saida=arquivo;
}

void imprimeIdoso(Idoso* idoso){
    //FUNÇÃO USADA EM PERIODO DE TESTES
    //Imprime as informações básicas de Idoso
    printf("Nome do Idoso: %s\n", idoso->nome);
    printf("Coordenada: %d, %d\n", idoso->coordenadas[0], idoso->coordenadas[1]);
    printf("Queda: %d\n", idoso->queda);
    printf("Temperatura: %.2f\n\n", idoso->temp);
}

void destroiIdoso(Idoso* idoso){

    //Destroi as listas contidas em idoso, mas não oq elas contêm
    destroiListaAmigos(idoso);
    destroiListaCuidadores(idoso);

    //Libera as informações alocadas de idoso
    free(idoso->coordenadas);
    free(idoso->nome);
    free(idoso->nomeArquivoEntrada);
    free(idoso->nomeArquivoSaida);
    free(idoso);
}
