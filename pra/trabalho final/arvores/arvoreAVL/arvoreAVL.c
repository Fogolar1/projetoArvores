#include <stdlib.h>
#include <stdio.h>
#include "arvoreAVL.h"

ArvoreAVL* criar() {
    ArvoreAVL *arvoreAVL = malloc(sizeof(ArvoreAVL));
    arvoreAVL->raiz = NULL;
    arvoreAVL->contadoraAVL = 1;
    return arvoreAVL;
}

int vazia(ArvoreAVL* arvoreAVL) {
    return arvoreAVL->raiz == NULL;
}

NoAVL* adicionarNoAVL(NoAVL* no, int valor, ArvoreAVL* arvoreAVL) {
    arvoreAVL->contadoraAVL++;
    //printf("\nExecutei adicionarNoAVL %i", arvoreAVL->contadoraAVL);
    if (valor > no->valor) {
        if (no->direita == NULL) {
            NoAVL* novo = malloc(sizeof(NoAVL));
            novo->valor = valor;
            novo->pai = no;

            novo->direita = NULL;
            novo->esquerda = NULL;

            no->direita = novo;
				
            return novo;
        } else {
            return adicionarNoAVL(no->direita, valor, arvoreAVL);
        }
    } else {
        if (no->esquerda == NULL) {
            NoAVL* novo = malloc(sizeof(NoAVL));
			novo->valor = valor;
            novo->pai = no;
            novo->direita = NULL;
            novo->esquerda = NULL;
			
            no->esquerda = novo;
			
            return novo;
        } else {
            return adicionarNoAVL(no->esquerda, valor, arvoreAVL);
        }
    }
}

int adicionar(ArvoreAVL* arvoreAVL, int valor) {
    arvoreAVL->contadoraAVL = 1;
    //printf("\nExecutei adicionar1 %i", arvoreAVL->contadoraAVL);
    if (arvoreAVL->raiz == NULL) {
        arvoreAVL->contadoraAVL++;
        //printf("\nExecutei adicionar2 %i", arvoreAVL->contadoraAVL);
        NoAVL* novo = malloc(sizeof(NoAVL));
        novo->valor = valor;
        novo->pai = NULL;
        novo->esquerda = NULL;
        novo->direita = NULL;
        
        arvoreAVL->raiz = novo;
    } else {
        arvoreAVL->contadoraAVL++;
        //printf("\nExecutei adicionar3 %i", arvoreAVL->contadoraAVL);
        NoAVL* no = adicionarNoAVL(arvoreAVL->raiz, valor, arvoreAVL);
        balanceamento(arvoreAVL, no);
    }

    return arvoreAVL->contadoraAVL;
}


/*NoAVL* localizar(NoAVL* no, int valor) {
    if (no->valor == valor) {
        return no;
    } else {
        if (valor < no->valor) {
            if (no->esquerda != NULL) {
                return localizar(no->esquerda, valor);
            }
        } else {
            if (no->direita != NULL) {
                return localizar(no->direita, valor);
            }
        }
    }

    return NULL;
}*/

void balanceamento(ArvoreAVL* arvoreAVL, NoAVL* no) {
    while (no != NULL) {
        arvoreAVL->contadoraAVL++;
        //printf("\nExecutei balanceamento %i", arvoreAVL->contadoraAVL);
        int fator = fb(no, arvoreAVL);

        if (fator > 1) { //??rvore mais pesada para esquerda
            //rota????o para a direita
            if (fb(no->esquerda, arvoreAVL) > 0) {
                rsd(arvoreAVL, no); //rota????o simples a direita, pois o FB do filho tem sinal igual
            } else {
                rdd(arvoreAVL, no); //rota????o dupla a direita, pois o FB do filho tem sinal diferente
            }
        } else if (fator < -1) { //??rvore mais pesada para a direita
            //rota????o para a esquerda
            if (fb(no->direita, arvoreAVL) < 0) {
                rse(arvoreAVL, no); //rota????o simples a esquerda, pois o FB do filho tem sinal igual
            } else {
                rde(arvoreAVL, no); //rota????o dupla a esquerda, pois o FB do filho tem sinal diferente
            }
        }

        no = no->pai; 
    }
}

int altura(NoAVL* no, ArvoreAVL* arvoreAVL){
    int esquerda = 0,direita = 0;
    //arvoreAVL->contadoraAVL++;
    //printf("\nExecutei altura %i", arvoreAVL->contadoraAVL);

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda, arvoreAVL) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita, arvoreAVL) + 1;
    }
  
    return esquerda > direita ? esquerda : direita; //max(esquerda,direita)
}

int fb(NoAVL* no, ArvoreAVL* arvoreAVL) {
    arvoreAVL->contadoraAVL++;
    //printf("\nExecutei fb %i", arvoreAVL->contadoraAVL);
    int esquerda = 0,direita = 0;
  
    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda, arvoreAVL) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita, arvoreAVL) + 1;
    }
  
    return esquerda - direita;
}

NoAVL* rse(ArvoreAVL* arvoreAVL, NoAVL* no) {
    arvoreAVL->contadoraAVL++;
    //printf("\nExecutei rse %i", arvoreAVL->contadoraAVL);
    NoAVL* pai = no->pai;
    NoAVL* direita = no->direita;

    if (direita->esquerda != NULL) {
        direita->esquerda->pai = no;
    }
  
    no->direita = direita->esquerda;
    no->pai = direita;

    direita->esquerda = no;
    direita->pai = pai;

    if (pai == NULL) {
        arvoreAVL->raiz = direita;
    } else {
        if (pai->esquerda == no) {
            pai->esquerda = direita;
        } else {
            pai->direita = direita;
        }
    }

    return direita;
}

NoAVL* rsd(ArvoreAVL* arvoreAVL, NoAVL* no) {
    arvoreAVL->contadoraAVL++;
    //printf("\nExecutei rsd %i", arvoreAVL->contadoraAVL);
    NoAVL* pai = no->pai;
    NoAVL* esquerda = no->esquerda;

    if (esquerda->direita != NULL) {
        esquerda->direita->pai = no;
    }
  
    no->esquerda = esquerda->direita;
    no->pai = esquerda;
  
    esquerda->direita = no;
    esquerda->pai = pai;

    if (pai == NULL) {
        arvoreAVL->raiz = esquerda;
    } else {
        if (pai->esquerda == no) {
            pai->esquerda = esquerda;
        } else {
            pai->direita = esquerda;
        }
    }

    return esquerda;
}

NoAVL* rde(ArvoreAVL* arvoreAVL, NoAVL* no) {
    arvoreAVL->contadoraAVL++;
    //printf("\nExecutei rde %i", arvoreAVL->contadoraAVL);
    no->direita = rsd(arvoreAVL, no->direita);
    return rse(arvoreAVL, no);
}

NoAVL* rdd(ArvoreAVL* arvoreAVL, NoAVL* no) {
    arvoreAVL->contadoraAVL++;
    //printf("\nExecutei rdd %i", arvoreAVL->contadoraAVL);
    no->esquerda = rse(arvoreAVL, no->esquerda);
    return rsd(arvoreAVL, no);
}