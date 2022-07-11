#ifndef REDE_H
#define REDE_H

#include "idoso.h"
#include "listaIdoso.h"

/*Le o arquivo de apoio e gera a lista geral de idosos.
 *Os idosos tem suas amizades lidas e registradas dentro da função
 *assim cobrindo todo o arquivo apoio.txt.
 *inputs: nao tem
 *output: lista alocada e populada
 *pre-condicao: nao tem
 *pos-condicao: lista alocada e populada*/
ListaIdoso* lerRedeApoio();

/*Recebe a primeira linha do arquivo apoio.txt e cria os idosos.
 *Os idosos são inseridos dentro da lista, mas suas amizades não 
 *são tratadas nesta função.
 *inputs: ponteiro para a lista geral e para a primeira linha do arquivo
 *output: lista populada com idosos
 *pre-condicao: nao tem
 *pos-condicao: lista populada com idosos*/
ListaIdoso* criaListaGeralIdosos(ListaIdoso* lista, char* linhaArquivo);

/*Recebe as linhas posteriores à primeira do arquivo apoio.txt, que tratam de amizades.
 *Os idosos suas amizades registradas com as informações providas na linha do arquivo.
 *inputs: ponteiro para a lista geral e para a linha do arquivo
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: amizade informada na linha agora esta registrada no programa*/
void criaRedeApoio(ListaIdoso* lista, char* linhaArquivo);

/*Le o arquivo de cuidadores e gera a lista geral de cuidadores.
 *Além disso, os idosos tem suas respectivas listas de cuidadores
 *também populadas dentro desta função.
 *inputs: ponteiro para lista geral de Idosos
 *output: lista alocada e populada
 *pre-condicao: nao tem
 *pos-condicao: lista alocada e populada*/
ListaCuidadores* lerRedeCuidado(ListaIdoso* listaI);

/*Recebe a primeira linha do arquivo cuidadores.txt e cria os cuidadores.
 *Os cuidadores são inseridos dentro da lista, mas não são inseridos dentro das
 *listas dos idosos nesta função.
 *inputs: ponteiro para a lista geral e para a primeira linha do arquivo
 *output: lista populada com cuidadores
 *pre-condicao: nao tem
 *pos-condicao: lista populada com cuidadores*/
ListaCuidadores* criaListaGeralCuidadores(ListaCuidadores* lista, char* linhaArquivo);

/*Recebe as linhas posteriores à primeira do arquivo cuidadores.txt, que tratam os cuidadores de cada idoso.
 *Os cuidadores são colocados nas lista do idoso informado nesta linha do arquivo.
 *inputs: ponteiro para a lista geral e para a linha do arquivo
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: vinculo cuidador/idoso informado na linha agora esta registrada no programa*/
void criaRedeCuidado(ListaIdoso* listaI, ListaCuidadores* listaC, char* linhaArquivo);

/*Função principal do programa, cuida do direcionamento das outras funções.
 *Tais funções se referem a manejamento de arquivos e informação ao decorrer do programa.
 *inputs: ponteiro para a lista geral de idosos, lista geral de cuidadores e numero de leituras
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: todas informações propriamente gerenciadas, tratadas e arquivos encerrados*/
void monitoramentoGeral(ListaIdoso* listaI, ListaCuidadores* listaC, int numLeituras);

/*Acessa o arquivo dos idosos e coloca suas informações da leitura necessaria em cada um.
 *Essa função apenas tranfere as informações do arquivo para o tipo Idoso correspondente.
 *inputs: ponteiro para a lista geral de idosos e o número de leitura correspondente do momento no programa
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: todas informações do momento no programa inserida em todos os seus respectivos idosos*/
void atualizaInfoIdoso(ListaIdoso* listaI, int numLeitura);

/*Acessa o arquivo dos cuidadores e coloca suas informações da leitura necessaria em cada um.
 *Essa função apenas tranfere as informações do arquivo para o tipo Cuidador correspondente.
 *inputs: ponteiro para a lista geral de cuidadores e o número de leitura correspondente do momento no programa
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: todas informações do momento no programa inserida em todos os seus respectivos cuidadores*/
void atualizaInfoCuidador(ListaCuidadores* listaC, int numLeitura);

/*Trata todas as informações de cada idoso na lista geral.
 *Essa função trata as informações já contidas dentro do tipo idoso e retorna o resultado no seu respectivo
 *arquivo de saida.
 *inputs: ponteiro para a lista geral de idosos e o número de leitura correspondente do momento no programa
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: todas as informações correspondentes do idoso tratadas e seu resultado inserido no arquivo de saida*/
void monitoraIdoso(ListaIdoso* listaI, int numLeitura);

/*Limpa toda a memória alocada em todo o percurso do programa.
 *Essa função utiliza as duas funções de limpeza de lista geral presente em listacuidadores.h e listaidoso.h
 *inputs: ponteiro para a lista geral de idosos e cuidadores
 *output: nao tem
 *pre-condicao: nao tem
 *pos-condicao: toda a memoria alocada dentro do programa liberada*/
void finalizaEdCare(ListaIdoso* listaI, ListaCuidadores* listaC);

#endif // REDE_H