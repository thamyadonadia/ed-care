#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rede.h"

int main(int argc, char const *argv[]){
    int numLeituras;

    if(argc<=1){
        printf("ERRO: NAO FOI INFORMADO O NUMERO DE LEITURAS");
        return 1;
    }
    
    //Coleta número de leituras
    sscanf(argv[1], "%d", &numLeituras);

    //Trata o arquvio Apoio.txt
    ListaIdoso* listaGeralIdosos = lerRedeApoio();
    //Trata o arquivo Cuidadores.txt
    ListaCuidadores* listaGeralCuidadores = lerRedeCuidado(listaGeralIdosos);

    //Trata a coleta de informações e os resultados de tais inforamções
    monitoramentoGeral(listaGeralIdosos, listaGeralCuidadores, numLeituras);

    //Destroi listas gerais e seus elementos
    finalizaEdCare(listaGeralIdosos, listaGeralCuidadores);
    
    return 0;
}
