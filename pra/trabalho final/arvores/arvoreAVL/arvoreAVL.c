#include <stdlib.h>
#include <stdio.h>
#include "arvoreAVL.h"

int contadoraAVL = 0;

ArvoreAVL* criar() {
    ArvoreAVL *arvoreAVL = malloc(sizeof(ArvoreAVL));
    arvoreAVL->raiz = NULL;
  
    return arvoreAVL;
}

int vazia(ArvoreAVL* arvoreAVL) {
    return arvoreAVL->raiz == NULL;
}

NoAVL* adicionarNoAVL(NoAVL* no, int valor) {
    if (valor > no->valor) {
        if (no->direita == NULL) {
            printf("Adicionando %d\n",valor);
            NoAVL* novo = malloc(sizeof(NoAVL));
            novo->valor = valor;
            novo->pai = no;

            no->direita = novo;
				
            return novo;
        } else {
            printf("ta preso?");
            return adicionarNoAVL(no->direita, valor);
        }
    } else {
        if (no->esquerda == NULL) {
            printf("Adicionando %d\n",valor);
            NoAVL* novo = malloc(sizeof(NoAVL));
			novo->valor = valor;
            novo->pai = no;
			
            no->esquerda = novo;
			
            return novo;
        } else {
            printf("ta preso2?");
            return adicionarNoAVL(no->esquerda, valor);
        }
    }
}

int adicionar(ArvoreAVL* arvoreAVL, int valor) {
    contadoraAVL++;
    if (arvoreAVL->raiz == NULL) {
        printf("Adicionando %d\n",valor);
        NoAVL* novo = malloc(sizeof(NoAVL));
        novo->valor = valor;
        
        arvoreAVL->raiz = novo;
    } else {
        printf("Dentro da func");
        NoAVL* no = adicionarNoAVL(arvoreAVL->raiz, valor);
        printf("Sai da func");
        balanceamento(arvoreAVL, no);
        printf("Sla");
    }

    return contadoraAVL;
}


NoAVL* localizar(NoAVL* no, int valor) {
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
}

void percorrerProfundidadeInOrderAVL(NoAVL* no, void (*callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadeInOrderAVL(no->esquerda,callback);
        callback(no->valor);
        percorrerProfundidadeInOrderAVL(no->direita,callback);
    }
}

void percorrerProfundidadePreOrderAVL(NoAVL* no, void (*callback)(int)) {
    if (no != NULL) {
        callback(no->valor);
        percorrerProfundidadePreOrderAVL(no->esquerda,callback);
        percorrerProfundidadePreOrderAVL(no->direita,callback);
    }
}

void percorrerProfundidadePosOrderAVL(NoAVL* no, void (callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadePosOrderAVL(no->esquerda,callback);
        percorrerProfundidadePosOrderAVL(no->direita,callback);
        callback(no->valor);
    }
}

void visitarAVL(int valor){
    printf("%d ", valor);
}

void balanceamento(ArvoreAVL* arvoreAVL, NoAVL* no) {
    while (no != NULL) {
        contadoraAVL++;
        int fator = fb(no);

        if (fator > 1) { //árvore mais pesada para esquerda
            //rotação para a direita
            if (fb(no->esquerda) > 0) {
                printf("RSD(%d)\n",no->valor);
                rsd(arvoreAVL, no); //rotação simples a direita, pois o FB do filho tem sinal igual
            } else {
                printf("RDD(%d)\n",no->valor);
                rdd(arvoreAVL, no); //rotação dupla a direita, pois o FB do filho tem sinal diferente
            }
        } else if (fator < -1) { //árvore mais pesada para a direita
            //rotação para a esquerda
            if (fb(no->direita) < 0) {
                printf("RSE(%d)\n",no->valor);
                rse(arvoreAVL, no); //rotação simples a esquerda, pois o FB do filho tem sinal igual
            } else {
                printf("RDE(%d)\n",no->valor);
                rde(arvoreAVL, no); //rotação dupla a esquerda, pois o FB do filho tem sinal diferente
            }
        }

        no = no->pai; 
    }
}

int altura(NoAVL* no){
    int esquerda = 0,direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }
  
    return esquerda > direita ? esquerda : direita; //max(esquerda,direita)
}

int fb(NoAVL* no) {
    int esquerda = 0,direita = 0;
  
    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }
  
    return esquerda - direita;
}

NoAVL* rse(ArvoreAVL* arvoreAVL, NoAVL* no) {
    contadoraAVL++;
    NoAVL* pai = no->pai;
    NoAVL* direita = no->direita;
  
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
    contadoraAVL++;
    NoAVL* pai = no->pai;
    NoAVL* esquerda = no->esquerda;
  
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
    no->direita = rsd(arvoreAVL, no->direita);
    return rse(arvoreAVL, no);
}

NoAVL* rdd(ArvoreAVL* arvoreAVL, NoAVL* no) {
    no->esquerda = rse(arvoreAVL, no->esquerda);
    return rsd(arvoreAVL, no);
}