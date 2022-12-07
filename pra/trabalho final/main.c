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
    fprintf(nome_arquivo, "%i;%i;%i;%i;%i\n", execsArvoreB1, execsArvoreB5, execsArvoreB10, execsArvoreRubroNegra, execsArvoreAVL);
}

void casoMedio(){
    ArvoreAVL* arvoreAVL[10];
    ArvoreB* arvoreB1[10];
    ArvoreB* arvoreB5[10] ;
    ArvoreB* arvoreB10[10];
    ArvoreRubroNegro* arvoreRubroNegro[10];

    for(int i=0; i <=10; i++){
        arvoreRubroNegro[i] = criarRubroNegra();
        arvoreB10[i] = criaArvore(10);
        arvoreB5[i] = criaArvore(5);
        arvoreB1[i] = criaArvore(1);
        arvoreAVL[i] = criar();
    }

    execsArvoreB1=0;
    execsArvoreB5=0;
    execsArvoreB10=0;
    execsArvoreAVL=0;
    execsArvoreRubroNegra=0;


    
    
    for(int i = 0; i <= 1000;i++){
        int aux[5];
        for(int j = 0; j <=10; j++){
            int numero = rand() % 1001;
            aux[0] = adicionaChave(arvoreB1[j], numero);    
            aux[1] += adicionaChave(arvoreB5[j], numero);
            aux[2] += adicionaChave(arvoreB10[j], numero);
            aux[3] += adicionar(arvoreAVL[j], numero);
            aux[4] += adicionarRubroNegra(arvoreRubroNegro[j], numero);
        }
        execsArvoreB1 = aux[0]/10;
        execsArvoreB5 = aux[1]/10;
        execsArvoreB10 = aux[2]/10;
        execsArvoreAVL = aux[3]/10;
        execsArvoreRubroNegra = aux[4]/10;
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