#ifndef CUIDADOR_H
#define CUIDADOR_H

/*Tipo que define Cuidador
 *Um cuidador consiste em sére de informações inseridas durante e após sua inicialização
 *Tais informações são as seguintes: nome, coordenadas, endereço e nome de seu arquivo*/
typedef struct cuidador Cuidador; 

/*Incializa a variável cuidador
 *inputs: nome do cuidador
 *output: cuidador alocado e inicializado
 *pre-condicao: nao tem
 *pos-condicao: cuidador alocado e inicializado*/
Cuidador* inicializaCuidador(char* nome);

//------------------------------------------------------
// GETS E SETS DO TIPO CUIDADOR
//------------------------------------------------------

/*Retorna ponteiro para o nome do cuidador
 *inputs: ponteiro para cuidador
 *output: ponteiro para o nome do cuidador (char*)
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
char* getNomeCuidador(Cuidador* cuidador);

/*Retorna ponteiro para as coordenadas do cuidador
 *inputs: ponteiro para cuidador
 *output: ponteiro para as coordenadas do cuidador (int*)
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
int* getCoordenadasCuidador(Cuidador* cuidador);

/*Retorna ponteiro para o nome do arquivo do cuidador
 *inputs: ponteiro para cuidador
 *output: ponteiro para o nome do arquivo do cuidador (char*)
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
char* getNomeArquivoCuidador(Cuidador* cuidador);

/*Retorna ponteiro para o arquivo do cuidador
 *inputs: ponteiro para cuidador
 *output: ponteiro para o arquivo do cuidador (FILE*)
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
FILE* getArquivoCuidador(Cuidador* cuidador);

/*Faz o set das cordenadas do cuidador
 *inputs: ponteiro para cuidador, valor de latitude e longitude
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: coordenadas do cuidador atualizadas*/
void setCoordenadasCuidador(Cuidador* cuidador, int lat, int longi);

/*Faz o set do ponteiro para arquivo do cuidador
 *inputs: ponteiro para cuidador e ponteiro para o arquivo
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: ponteiro para arquivo do cuidador atualizado*/
void setArquivoCuidador(Cuidador* cuidador, FILE* arquivo);
//------------------------------------------------------

/*Limpa a memória alocado para o cuidador
 *inputs: ponteiro para cuidador
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: toda memoria alocada liberada*/
void destroiCuidador(Cuidador* cuidador);

#endif // CUIDADOR_H