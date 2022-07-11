#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rede.h"

ListaIdoso* lerRedeApoio(){
    /*inicializa a lista de idosos, abre o arquivo de apoio e aloca uma string para armazenar
     *o conteúdo de uma linha inteira e passar para as funções */
    ListaIdoso* lista = inicializaListaIdoso(); int count=0;
    FILE* apoio = fopen("apoio.txt", "r"); 
    char* linhaArquivo = (char*) malloc(sizeof(char)*1000);

    //após abertura do arquivo percorre todo o seu conteudo
    while(!feof(apoio)){
        fscanf(apoio, "%[^\n]\n", linhaArquivo);

        // leitura da primeira linha do arquivo (lista de idosos usados no programa)
        if(count == 0){
            lista = criaListaGeralIdosos(lista, linhaArquivo);

        //leituras seguintes (relações de amizade entre os idosos)
        }else{
            criaRedeApoio(lista, linhaArquivo);
        }

        count++;
    }

    free(linhaArquivo);
    fclose(apoio);

    return lista;
}

ListaIdoso* criaListaGeralIdosos(ListaIdoso* lista, char* linhaArquivo){
    char* nomeIdoso; Idoso* idoso; 

    //fraciona a linha do arquivo, coletando apenas o nome do idoso
    nomeIdoso = strtok(linhaArquivo, ";");
    while(nomeIdoso){
        //continua fracionando e adicionando a lista geral de idosos
        idoso = inicializaIdoso(nomeIdoso);
        insereIdoso(lista, idoso);
        nomeIdoso = strtok(NULL, "; ");
    }

    return lista;
}

void criaRedeApoio(ListaIdoso* lista, char* linhaArquivo){
    char* nomeIdoso; char* nomeAmigo;

    //coleta o nome do idoso e o de seu amigo
    nomeIdoso = strtok(linhaArquivo, ";");
    nomeAmigo = strtok(NULL, "; ");

    //coleta os ponteiros correspondentes ao nome
    Idoso* idoso = encontraIdoso(lista, nomeIdoso);
    Idoso* amigo = encontraIdoso(lista, nomeAmigo);

    //faz a inserção em suas respectivas listas de amigo
    insereAmigo(idoso, amigo);
}

ListaCuidadores* lerRedeCuidado(ListaIdoso* listaI){
    /*inicializa a lista de cuidadores, abre o arquivo e aloca uma string para armazenar
     *o conteúdo de uma linha inteira e passar para as funções */

    FILE* cuidadores = fopen("cuidadores.txt", "r"); int count=0;
    char* linhaArquivo = (char*) malloc(sizeof(char)*100);
    ListaCuidadores* listaC = inicializaListaCuidadores();

    //após abertura do arquivo percorre todo o seu conteudo
    while(!feof(cuidadores)){
        fscanf(cuidadores, "%[^\n]\n", linhaArquivo);
        
        // leitura da primeira linha do arquivo (lista de cuidadores usados no programa)
        if(count==0){
          listaC = criaListaGeralCuidadores(listaC, linhaArquivo);

        //leituras seguintes (quais cuidadores são responsáveis por esse idoso em específico)
        }else{
            criaRedeCuidado(listaI, listaC, linhaArquivo);
        }
        
        count++;
    }

    fclose(cuidadores);
    free(linhaArquivo);

    return listaC;
}

ListaCuidadores* criaListaGeralCuidadores(ListaCuidadores* lista, char* linhaArquivo){
    char* nomeCuidador; Cuidador* cuidador; 

    //fraciona a linha do arquivo, coletando apenas o nome do idoso
    nomeCuidador = strtok(linhaArquivo, ";");
    while(nomeCuidador){
        //continua fracionando e adicionando a lista geral de cuidadores
        cuidador = inicializaCuidador(nomeCuidador);
        insereCuidadores(lista, cuidador);
        nomeCuidador = strtok(NULL, "; ");
    }

    return lista;
}

void criaRedeCuidado(ListaIdoso* listaI, ListaCuidadores* listaC, char* linhaArquivo){
    char* nome; Cuidador* cuidador;

    //coleta o nome do idoso e encontra o seu ponteiro correspondente na lista geral
    nome = strtok(linhaArquivo, ";");
    Idoso* idoso = encontraIdoso(listaI, nome);
    
    //coleta o primeiro cuidador responsável por este idoso
    nome = strtok(NULL, "; ");

    //adiciona o cuidador na lista do idoso e todos os cuidadores seguintes, até acabar a linha
    while(nome){
        cuidador = encontraCuidador(listaC, nome);
        insereCuidadores(getListaCuidadores(idoso), cuidador);
        nome = strtok(NULL, "; ");
    }
}


void monitoramentoGeral(ListaIdoso* listaI, ListaCuidadores* listaC, int numLeituras){

    for(int i=0; i<numLeituras; i++){
        // percorrem as listas, abrindo os arquivos e atualizando as infos de cada um 
        atualizaInfoIdoso(listaI, i);
        atualizaInfoCuidador(listaC, i);

        // interpreta as informações de cada idoso, tomando as devidas medidas para cada caso
        monitoraIdoso(listaI, i);
    }

    // fecha os arquivos de cada idoso e cuidador 
    finalizaArquivosIdoso(listaI);
    finalizaArquivosCuidadores(listaC);
}

void atualizaInfoIdoso(ListaIdoso* listaI, int numLeitura){
    int tamLista = getTamListaIdoso(listaI);
    Idoso* idoso; FILE* arquivo;
    char* linhaArquivo = (char*) malloc(sizeof(char)*100);
    float tempIdoso; int latIdoso, longiIdoso, quedaIdoso;
    
    for(int i=0; i<tamLista; i++){
        //pega o idoso correspondente ao indice
        idoso = getIdoso(listaI, i);
       
        //caso seja a primeira leitura, abre o arquivo e armazena seu ponteiro
        if(numLeitura == 0){
            arquivo = fopen(getNomeArquivoEntradaIdoso(idoso), "r");
            setArquivoEntradaIdoso(idoso,arquivo);

        //em outros casos, pega o ponteiro salvo no idoso    
        }else{
            arquivo=getArquivoEntradaIdoso(idoso);
        }

        fscanf(arquivo, "%[^\n]\n", linhaArquivo);
        
        //verifica falecimento
        if(!strcmp(linhaArquivo, "falecimento")){
            setFalecimento(idoso, 1);

        //atualiza o restante das informações
        }else{
            sscanf(linhaArquivo, "%f%*[;]%d%*[;]%d%*[;]%d%*[\n]", &tempIdoso, &latIdoso, &longiIdoso, &quedaIdoso);
            setTemp(idoso, tempIdoso);
            setCoordenadasIdoso(idoso, latIdoso, longiIdoso);
            setQueda(idoso, quedaIdoso);
            
            //caso não haja queda, atualize seu contador de febre baixa
            if(quedaIdoso == 0){
                if(37.0<=tempIdoso && tempIdoso<38.0){
                    setQtdFebreBaixa(idoso);

                }else if(tempIdoso>=38.0){
                    while(getQtdFebreBaixa(idoso)!=0){
                        setQtdFebreBaixa(idoso);
                    }
                }
            }
            
        }
    }

    free(linhaArquivo);
}

void atualizaInfoCuidador(ListaCuidadores* listaC, int numLeitura){
    int tamLista = retornaTamListaCuidador(listaC);
    Cuidador* cuidador; FILE* arquivo;
    char* linhaArquivo = (char*) malloc(sizeof(char)*100);
    int latCuidador, longiCuidador;

    for(int i=0; i<tamLista; i++){
        //pega cuidador correspondente ao indice
        cuidador = retornaCuidador(listaC, i);
       
        //caso seja a primeira leitura, abre o arquivo e armazena seu ponteiro
        if(numLeitura == 0){
            arquivo = fopen(getNomeArquivoCuidador(cuidador), "r");
            setArquivoCuidador(cuidador,arquivo);

        //em outros casos, pega o ponteiro salvo no cuidador
        }else{
            arquivo = getArquivoCuidador(cuidador);
        }

        //atualiza as informações
        fscanf(arquivo, "%[^\n]\n", linhaArquivo);
        sscanf(linhaArquivo, "%d%*[;]%d%*[\n]",&latCuidador, &longiCuidador);
        setCoordenadasCuidador(cuidador, latCuidador, longiCuidador);
    }

    free(linhaArquivo);
}

void monitoraIdoso(ListaIdoso* listaI, int numLeitura){
    int falecimento, queda; int* coord; float temp;
    int tamLista = getTamListaIdoso(listaI); Idoso* idoso; FILE* arquivoE; FILE* arquivoS;

    for(int i=0; i<tamLista; i++){
        //passa as informações de idoso para variáveis locais
        idoso = getIdoso(listaI, i);
        falecimento = getFalecimento(idoso);
        queda = getQueda(idoso);
        coord = getCoordenadasIdoso(idoso);
        temp = getTemp(idoso);

        //caso seja a primeira leitura, cria o arquivo e armazena seu ponteiro
        if(numLeitura == 0){
            arquivoS = fopen(getNomeArquivoSaidaIdoso(idoso), "w");
            setArquivoSaidaIdoso(idoso, arquivoS);

        //em outros casos, pega o ponteiro salvo no idoso 
        }else{
            arquivoS=getArquivoSaidaIdoso(idoso);
        }
    
        //trata falecimento
        if(falecimento){
            fprintf(arquivoS, "falecimento\n");
            fclose(arquivoS);
            arquivoE = getArquivoEntradaIdoso(idoso);
            fclose(arquivoE);
            retiraFalecido(idoso);
            retiraIdoso(listaI, idoso);
            destroiIdoso(idoso);
            tamLista--;
            i--;

        //trata queda
        }else if(queda){
          
            fprintf(arquivoS, "queda, acionou %s\n",chamaCuidador(getListaCuidadores(idoso),coord));
        
        //trata febre alta
        }else if(temp >= 38){
    
            fprintf(arquivoS, "febre alta, acionou %s\n",chamaCuidador(getListaCuidadores(idoso),coord));
        
        //trata febre baixa
        }else if(37.0 <= temp && temp < 38.0){
            if(getQtdFebreBaixa(idoso)>3){
                fprintf(arquivoS, "febre baixa pela quarta vez, acionou %s\n",chamaCuidador(getListaCuidadores(idoso),coord));
            
            }else{
                if(chamaAmigo(getListaAmigos(idoso),coord)!=NULL){
                    fprintf(arquivoS, "febre baixa, acionou amigo %s\n",chamaAmigo(getListaAmigos(idoso),coord));
                }
                else{
                    fprintf(arquivoS,"Febre baixa mas, infelizmente, o idoso está sem amigos na rede\n");
                }   
            }

        //trata tudo ok
        }else{
            fprintf(arquivoS, "tudo ok\n");
        }
    }
}


void finalizaEdCare(ListaIdoso* listaI, ListaCuidadores* listaC){
    //limpa todas as listas gerais
    destroiListaIdosos(listaI);
    destroiListaCuidadoresG(listaC);
}
