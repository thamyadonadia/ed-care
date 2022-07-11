#ifndef IDOSO_H
#define IDOSO_H

/*Tipo que define Idoso
 *Um idoso consiste em uma série de informações inseridas durante e após sua incialização
 *Tais informações são as seguintes: nome, coordenadas, temperatura, status de queda, se esta vivo
 *quantidade de febres baixas, suas listas de amigos e cuidadores, endereço e nome dos arquivos de 
 *entrada e saída*/
typedef struct idoso Idoso;


#include "listaCuidador.h"
#include "listaAmigo.h"

/*Incializa a variável idoso
 *inputs: nome do idoso
 *output: idoso alocado e inicializado
 *pre-condicao: nao tem
 *pos-condicao: idoso alocado e inicializado*/
Idoso* inicializaIdoso(char* nome);

//------------------------------------------------------
// GETS E SETS DO TIPO IDOSO
//------------------------------------------------------

/*Retorna ponteiro para o nome do idoso
 *inputs: ponteiro para idoso
 *output: ponteiro para o nome do idoso (char*)
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
char* getNomeIdoso(Idoso* idoso);

/*Retorna ponteiro para as coordenadas do idoso
 *inputs: ponteiro para idoso
 *output: ponteiro para as coordenadas do idoso (int*)
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
int* getCoordenadasIdoso(Idoso* idoso);

/*Retorna a temperatura do idoso
 *inputs: ponteiro para idoso
 *output: a temperatura do idoso (float)
 *pre-condicao: nao tem
 *pos-condicao: valor retornado*/
float getTemp(Idoso* idoso);

/*Retorna o status de queda idoso
 *inputs: ponteiro para idoso
 *output: o status de queda do idoso (int)
 *pre-condicao: nao tem
 *pos-condicao: valor retornado*/
int getQueda(Idoso* idoso);

/*Retorna o status de vida do idoso
 *inputs: ponteiro para idoso
 *output: o status de vida do idoso (int)
 *pre-condicao: nao tem
 *pos-condicao: valor retornado*/
int getFalecimento(Idoso* idoso);

/*Retorna a quantidade de febres baixas do idoso
 *inputs: ponteiro para idoso
 *output: a quantidade de febres baixas do idoso (int)
 *pre-condicao: nao tem
 *pos-condicao: valor retornado*/
int getQtdFebreBaixa(Idoso* idoso);

/*Retorna ponteiro para a lista de amigos do idoso
 *inputs: ponteiro para idoso
 *output: a lista de amigos do idoso (ListaAmigo*)
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
ListaAmigo* getListaAmigos (Idoso* idoso);

/*Retorna ponteiro para a lista de cuidadores do idoso
 *inputs: ponteiro para idoso
 *output: a lista de cuidadores do idoso (ListaCuidadores*)
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
ListaCuidadores* getListaCuidadores(Idoso* idoso);

/*Retorna ponteiro para o arquivo de entrada do idoso
 *inputs: ponteiro para idoso
 *output: ponteiro para o arquivo de entrada do idoso (FILE*)
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
FILE* getArquivoEntradaIdoso(Idoso* idoso);

/*Retorna ponteiro para o nome do arquivo de entrada do idoso
 *inputs: ponteiro para idoso
 *output: ponteiro para o nome do arquivo de entrada do idoso (char*)
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
char* getNomeArquivoEntradaIdoso(Idoso* idoso);

/*Retorna ponteiro para o arquivo de saida do idoso
 *inputs: ponteiro para idoso
 *output: ponteiro para o arquivo de saida do idoso (FILE *)
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
FILE* getArquivoSaidaIdoso(Idoso* idoso);

/*Retorna ponteiro para o nome do arquivo de saida do idoso
 *inputs: ponteiro para idoso
 *output: ponteiro para o nome do arquivo de saida do idoso (char*)
 *pre-condicao: nao tem
 *pos-condicao: ponteiro retornado*/
char* getNomeArquivoSaidaIdoso(Idoso* idoso);

/*Faz o set das cordenadas do idoso
 *inputs: ponteiro para idoso, valor de latitude e longitude
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: coordenadas do idoso atualizadas*/
void setCoordenadasIdoso(Idoso* idoso, int lat, int longi);

/*Faz o set da temperatura do idoso
 *inputs: ponteiro para idoso, valor de temperatura
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: valor de temperatura do idoso atualizado*/
void setTemp(Idoso* idoso, float temp);

/*Faz o set do status de queda do idoso
 *inputs: ponteiro para idoso e valor do status de queda
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: valor do status de queda do idoso atualizado*/
void setQueda(Idoso* idoso, int queda);

/*Faz o set do status de vida do idoso
 *inputs: ponteiro para idoso e status de vida
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: valor do status de vida do idoso atualizado*/
void setFalecimento(Idoso* idoso, int falecimento);

/*Faz a adição de +1 no contador de quantidade de febre baixa do idoso
 *se o valor for 4, a adição não ocorrerá e retornará para o valor 0
 *inputs: ponteiro para idoso
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: quantidade de febre baixa do idoso atualizada*/
void setQtdFebreBaixa(Idoso* idoso);

/*Faz o set do ponteiro para arquivo de entrada do idoso
 *inputs: ponteiro para idoso e ponteiro para o arquivo
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: ponteiro para arquivo de entrada do idoso atualizado*/
void setArquivoEntradaIdoso(Idoso* idoso, FILE* arquivo);

/*Faz o set do ponteiro para arquivo de saida do idoso
 *inputs: ponteiro para idoso e ponteiro para o arquivo
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: ponteiro para arquivo de saida do idoso atualizado*/
void setArquivoSaidaIdoso(Idoso* idoso, FILE* arquivo);
//------------------------------------------------------

/*FUNÇÃO USADA NA FASE DE TESTES, NÃO USADA NO PROGRAMA FINAL
 *Imprime informações pessoais do idoso no console
 *inputs: ponteiro para idoso
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: informações pessoais impressas no console*/
void imprimeIdoso(Idoso* idoso);

/*Limpa a memória alocado para o idoso e suas listas
 *inputs: ponteiro para idoso
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: toda memoria alocada liberada*/
void destroiIdoso(Idoso* idoso);

#endif //IDOSO_H