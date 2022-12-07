#include <stdio.h>
#include <stdlib.h>
#include "arvores/arvoreAVL/arvoreAVL.h"
#include "arvores/arvoreB/arvoresB.h"
#include "arvores/arvoreRubroNegra/arvoreFlamengo.h"


int execsArvoreB1 = 0;
int execsArvoreB5 = 0;
int execsArvoreB10 = 0;
int execsArvoreRubroNegra = 0;
int execsArvoreAVL = 0;

FILE *saidaMedio;
FILE *saidaPior;

void salvar(FILE *nome_arquivo, int qntdExec){
    printf("\nSalvei %i", qntdExec);
    fprintf(nome_arquivo, "%i;%i;%i;%i;%i;%i\n", qntdExec, execsArvoreB1, execsArvoreB5, execsArvoreB10, execsArvoreRubroNegra, execsArvoreAVL);
}

void casoMedio(){
    ArvoreAVL* arvoreAVL = criar();
    ArvoreB* arvoreB1 = criaArvore(1);
    ArvoreB* arvoreB5 = criaArvore(5);
    ArvoreB* arvoreB10 = criaArvore(10);
    ArvoreRubroNegro* arvoreRubroNegro = criarRubroNegra();

    execsArvoreB1=0;
    execsArvoreB5=0;
    execsArvoreB10=0;
    execsArvoreAVL=0;
    execsArvoreRubroNegra=0;
    
    
    for(int i = 0; i <= 1000;i++){
        int aux = 0;
        for(int j = 0; j <=10; j++){
            int numero = rand() % 1001;
            aux = adicionaChave(arvoreB1, numero);
            execsArvoreB1 += aux;
            execsArvoreB5 += adicionaChave(arvoreB5, numero);
            execsArvoreB10 += adicionaChave(arvoreB10, numero);
            execsArvoreAVL += adicionar(arvoreAVL, numero);
            execsArvoreRubroNegra += adicionarRubroNegra(arvoreRubroNegro, numero);
        }
        execsArvoreB1 = execsArvoreB1/10;
        execsArvoreB5 = execsArvoreB5/10;
        execsArvoreB10 = execsArvoreB10/10;
        execsArvoreAVL = execsArvoreAVL/10;
        execsArvoreRubroNegra = execsArvoreRubroNegra/10;
        salvar(saidaMedio, i);
    }
    
}

void piorCaso(){

    ArvoreAVL* arvoreAVL = criar();
    ArvoreB* arvoreB1 = criaArvore(1);
    ArvoreB* arvoreB5 = criaArvore(5);
    ArvoreB* arvoreB10 = criaArvore(10);
    ArvoreRubroNegro* arvoreRubroNegro = criarRubroNegra();

    execsArvoreB1=0;
    execsArvoreB5=0;
    execsArvoreB10=0;
    execsArvoreAVL=0;
    execsArvoreRubroNegra=0;

    for(int numExec=0; numExec <= 1000; numExec++){
        execsArvoreB1 += adicionaChave(arvoreB1, numExec);
        execsArvoreB5 += adicionaChave(arvoreB5, numExec);
        execsArvoreB10 += adicionaChave(arvoreB10, numExec);
        execsArvoreAVL += adicionar(arvoreAVL, numExec);
        execsArvoreRubroNegra += adicionarRubroNegra(arvoreRubroNegro, numExec);
        salvar(saidaPior, numExec);
    }

}

void main(){

    saidaMedio = fopen("arvore_medio.csv", "w");
    saidaPior = fopen("arvore_pior.csv", "w");

    casoMedio();
    piorCaso();

    printf("FOI");

    fclose(saidaMedio);
    fclose(saidaPior);
    
}