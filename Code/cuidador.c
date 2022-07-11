#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuidador.h"

struct cuidador{
    //Informações pessoais do Cuidador
    char* nome;
    int* coordenadas;

    //Informações do arquivo do Cuidador
    FILE* arquivo;
    char* nomeArquivo;
};

Cuidador* inicializaCuidador(char* nome){

    //Aloca espaço para Cuidador e suas informações
    Cuidador* cuidador = (Cuidador*) malloc(sizeof(Cuidador));
    cuidador->nome = strdup(nome);
    cuidador->coordenadas = (int*) malloc(sizeof(int)*2);

    //Cria o nome de seu arquivo apartir do seu nome dado
    cuidador->nomeArquivo = (char*) malloc(sizeof(char)*(strlen(cuidador->nome)+5));
    sprintf(cuidador->nomeArquivo, "%s.txt", cuidador->nome);

    return cuidador;
}

int* getCoordenadasCuidador(Cuidador* cuidador){
    return cuidador->coordenadas;
}

void setCoordenadasCuidador(Cuidador* cuidador, int lat, int longi){
    cuidador->coordenadas[0] = lat;
    cuidador->coordenadas[1] = longi;
}

char* getNomeCuidador(Cuidador* cuidador){
    return cuidador->nome;
}

FILE* getArquivoCuidador(Cuidador* cuidador){
    return cuidador->arquivo;
}

char* getNomeArquivoCuidador(Cuidador* cuidador){
    return cuidador->nomeArquivo;
}

void setArquivoCuidador(Cuidador* cuidador, FILE* arquivo){
    cuidador->arquivo=arquivo;
}

void destroiCuidador(Cuidador* cuidador){
    free(cuidador->nome);
    free(cuidador->coordenadas);
    free(cuidador->nomeArquivo);
    free(cuidador);
}