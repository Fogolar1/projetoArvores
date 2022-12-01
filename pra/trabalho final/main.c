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

char* files[] = {"arvoreAVL", "arvoreB1", "arvoreB5", "arvoreB10",  "arvoreRubroNegra"};


void main(){
    for(int numExec = 0; numExec <= 1000; numExec++){
        casoMedio();
        
        piorCaso();
    }
    

}

void casoMedio(){
    ArvoreAVL* arvoreAVL = criar();
    ArvoreB* arvoreB1 = criaArvore(1);
    ArvoreB* arvoreB5 = criaArvore(5);
    ArvoreB* arvoreB10 = criaArvore(10);
    ArvoreRubroNegro* arvoreRubroNegro = criarRubroNegra();
    for(int i = 0; i <= 10;i++){
        int numero = rand() % 1001;
        execsArvoreB1 += adicionaChave(arvoreB1, numero);
        execsArvoreB5 += adicionaChave(arvoreB5, numero);
        execsArvoreB10 += adicionaChave(arvoreB10, numero);
        execsArvoreAVL += adicionar(arvoreAVL, numero);
        execsArvoreRubroNegra += adicionarRubroNegra(arvoreRubroNegro, numero);
    }
}

void piorCaso(){
    ArvoreAVL* arvoreAVL = criar();
    ArvoreB* arvoreB1 = criaArvore(1);
    ArvoreB* arvoreB5 = criaArvore(5);
    ArvoreB* arvoreB10 = criaArvore(10);
    ArvoreRubroNegro* arvoreRubroNegro = criarRubroNegra();
    for(int i = 0; i <= 10;i++){
        execsArvoreB1 += adicionaChave(arvoreB1, i);
        execsArvoreB5 += adicionaChave(arvoreB5, i);
        execsArvoreB10 += adicionaChave(arvoreB10, i);
        execsArvoreAVL += adicionar(arvoreAVL, i);
        execsArvoreRubroNegra += adicionarRubroNegra(arvoreRubroNegro, i);
    }
}