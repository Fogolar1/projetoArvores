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
    fprintf(nome_arquivo, "%i;%i;%i;%i;%i;%i\n", qntdExec, execsArvoreB1, execsArvoreB5, execsArvoreB10, execsArvoreRubroNegra, execsArvoreAVL);
}

void casoMedio(){
    ArvoreAVL* arvoreAVL[10];
    ArvoreB* arvoreB1[10];
    ArvoreB* arvoreB5[10] ;
    ArvoreB* arvoreB10[10];
    ArvoreRubroNegro* arvoreRubroNegro[10];

    for(int i=0; i <10; i++){
        arvoreRubroNegro[i] = criarRubroNegra();
        arvoreB10[i] = criaArvore(10);
        arvoreB5[i] = criaArvore(5);
        arvoreB1[i] = criaArvore(1);
        arvoreAVL[i] = criar();
    }

    int array[1000][10];

    for(int j = 0; j < 10; j++){
        for (int i = 0; i < 1000; i++) {     // fill array
            array[i][j] = i;
        }
    }

    for (int j = 0; j < 10; j++) {     // fill array
       
        for (int i = 0; i < 1000; i++) {    // shuffle array
            int temp = array[i][j];
            int randomIndex = rand() % 1000;
            array[i][j]           = array[randomIndex][j];
            array[randomIndex][j] = temp;
        }
    }
    
    execsArvoreB1=0;
    execsArvoreB5=0;
    execsArvoreB10=0;
    execsArvoreAVL=0;
    execsArvoreRubroNegra=0;
    
    for(int i = 0; i < 1000;i++){
        int aux[5];
        for(int j = 0; j <10; j++){
            aux[0] += adicionaChave(arvoreB1[j], array[i][j]); 
            aux[1] += adicionaChave(arvoreB5[j], array[i][j]);
            aux[2] += adicionaChave(arvoreB10[j], array[i][j]);
            aux[3] += adicionar(arvoreAVL[j],  array[i][j]);
            aux[4] += adicionarRubroNegra(arvoreRubroNegro[j], array[i][j]);
        }
        execsArvoreB1 = aux[0]/10;
        execsArvoreB5 = aux[1]/10;
        execsArvoreB10 = aux[2]/10;
        execsArvoreAVL = aux[3]/10;
        execsArvoreRubroNegra = aux[4]/10;
        int neymar;
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

    for(int numExec=0; numExec < 1000; numExec++){
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
    fprintf(saidaMedio, "N;B1;B5;B10;RN;AVL\n");
    saidaPior = fopen("arvore_pior.csv", "w");
    fprintf(saidaPior, "N;B1;B5;B10;RN;AVL\n");

    casoMedio();
    piorCaso();

    printf("Executei");

    fclose(saidaMedio);
    fclose(saidaPior);
    
}