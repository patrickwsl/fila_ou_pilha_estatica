#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "trabalho.h"

int main(){
    //VARIAVEIS PILHA
    setlocale(LC_ALL, "Portuguese");
    PILHA nossaPilha;

    //VARIAVEIS FILA
    FILA nossaFila;
    nossaFila.frente = 0; //controla o inicio da fila
    nossaFila.atras = 0; // controla o fim da fila


    //VARIAVEIS DE AUXILIO
    int ok, op=-1;
    int tipoPF = -1;

    //CONTEUDO
    iniciaPilha(&nossaPilha.topo);
    while( op!= 0 ) {

        //ESCOLHER O TIPO 1 PILHA OU O TIPO 2 FILA
        if (tipoPF == -1){
           menuTipo(&tipoPF);
        }
        if (tipoPF == 0){
            op = tipoPF;
        }

        if(tipoPF == 1){
            menuPilha(&op);
            if( op== 1) {
                printf( "\nDigite um número: ");
                scanf("%f", &nossaPilha.dado);
                push(nossaPilha.itens, &nossaPilha.topo, nossaPilha.dado);
            }else if( op== 2 ) {
                ok = pop(nossaPilha.itens, &nossaPilha.topo, &nossaPilha.dado);
                if( ok != ERRO)
                    printf( "\nElemento removido: %.2f ", nossaPilha.dado);
            }else if( op== 3 ) {
                exibirPilha(nossaPilha.itens, &nossaPilha.topo);
            }else if( op == 4){
                tipoPF = -1;
            }
        }else if(tipoPF == 2){
            menuFila(&op);
            if( op== 1) {
                printf( "\nDigite um número: ");
                scanf("%f", &nossaFila.dado);
                inserirItem(&nossaFila, nossaFila.dado);
            }else if( op== 2 ) {
                printf( "\nElemento removido: %.2f ", removerDaFila(&nossaFila));
            }else if( op== 3 ) {
                exibirFila(&nossaFila);
            }else if( op == 4){
                esvaziarFila(&nossaFila);
            }else if( op == 5){
                tipoPF = -1;
            }
        }

    }//fim do while

    return 0;
}


















