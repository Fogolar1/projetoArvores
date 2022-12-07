#include <stdlib.h>
#include <stdio.h>
#include "arvoreFlamengo.h"

int contadoraRN = 0;

ArvoreRubroNegro* criarRubroNegra() {
    ArvoreRubroNegro *arvoreRubroNegro = malloc(sizeof(ArvoreRubroNegro));
    arvoreRubroNegro->nulo = NULL;
    arvoreRubroNegro->raiz = NULL;

    arvoreRubroNegro->nulo = criarNo(arvoreRubroNegro, NULL, 0);
    arvoreRubroNegro->nulo->cor = Preto;

    return arvoreRubroNegro;
}

int vaziaRubroNegra(ArvoreRubroNegro* arvoreRubroNegro) {
    return arvoreRubroNegro->raiz == NULL;
}

NoRN* criarNo(ArvoreRubroNegro* arvoreRubroNegro, NoRN* pai, int valor) {
    NoRN* no = malloc(sizeof(NoRN));

    no->pai = pai;    
    no->valor = valor;
    no->direita = arvoreRubroNegro->nulo;
    no->esquerda = arvoreRubroNegro->nulo;

    return no;
}

NoRN* adicionarNoRN(ArvoreRubroNegro* arvoreRubroNegro, NoRN* no, int valor) {
    contadoraRN++;
    if (valor > no->valor) {
        if (no->direita == arvoreRubroNegro->nulo) {
            no->direita = criarNo(arvoreRubroNegro, no, valor);     
            no->direita->cor = Vermelho;       
        		
            return no->direita;
        } else {
            return adicionarNoRN(arvoreRubroNegro, no->direita, valor);
        }
    } else {
        if (no->esquerda == arvoreRubroNegro->nulo) {
            no->esquerda = criarNo(arvoreRubroNegro, no, valor);
            no->esquerda->cor = Vermelho;
            
            return no->esquerda;
        } else {
            return adicionarNoRN(arvoreRubroNegro, no->esquerda, valor);
        }
    }
}

int adicionarRubroNegra(ArvoreRubroNegro* arvoreRubroNegro, int valor) {
    //contadoraRN=0;
    if (vaziaRubroNegra(arvoreRubroNegro)) {
        arvoreRubroNegro->raiz = criarNo(arvoreRubroNegro, arvoreRubroNegro->nulo, valor);
        arvoreRubroNegro->raiz->cor = Preto;
    } else {
        NoRN* no = adicionarNoRN(arvoreRubroNegro, arvoreRubroNegro->raiz, valor);
        balancear(arvoreRubroNegro, no);
    }

    return contadoraRN;
}

NoRN* localizarArvoreRubroNegroB(ArvoreRubroNegro* arvoreRubroNegro, int valor) {
    if (!vaziaRubroNegra(arvoreRubroNegro)) {
        NoRN* no = arvoreRubroNegro->raiz;

        while (no != arvoreRubroNegro->nulo) {
            if (no->valor == valor) {
                return no;
            } else {
                no = valor < no->valor ? no->esquerda : no->direita;
            }
        }
    }

    return NULL;
}

void percorrerProfundidadeInOrderRN(ArvoreRubroNegro* arvoreRubroNegro, NoRN* no, void (*callback)(int)) {
    if (no != arvoreRubroNegro->nulo) {
        
        
        percorrerProfundidadeInOrderRN(arvoreRubroNegro, no->esquerda,callback);
        callback(no->valor);
        percorrerProfundidadeInOrderRN(arvoreRubroNegro, no->direita,callback);
    }
}

void percorrerProfundidadePreOrderRN(ArvoreRubroNegro* arvoreRubroNegro, NoRN* no, void (*callback)(int)) {
    if (no != arvoreRubroNegro->nulo) {
        callback(no->valor);
        percorrerProfundidadePreOrderRN(arvoreRubroNegro, no->esquerda,callback);
        percorrerProfundidadePreOrderRN(arvoreRubroNegro, no->direita,callback);
    }
}

void percorrerProfundidadePosOrderRN(ArvoreRubroNegro* arvoreRubroNegro, NoRN* no, void (callback)(int)) {
    if (no != arvoreRubroNegro->nulo) {
        percorrerProfundidadePosOrderRN(arvoreRubroNegro, no->esquerda,callback);
        percorrerProfundidadePosOrderRN(arvoreRubroNegro, no->direita,callback);
        callback(no->valor);
    }
}

void visitarRN(int valor){
    printf("%d ", valor);
}

void balancear(ArvoreRubroNegro* arvoreRubroNegro, NoRN* no) {
    while (no->pai->cor == Vermelho) {
        contadoraRN++;
        if (no->pai == no->pai->pai->esquerda) {
            NoRN *tio = no->pai->pai->direita;
            
            if (tio->cor == Vermelho) {
                tio->cor = Preto; //Caso 1
                no->pai->cor = Preto; 

                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            } else {
                if (no == no->pai->direita) {
                    no = no->pai; //Caso 2
                    rotacionarEsquerda(arvoreRubroNegro, no); //Caso 2
                } else {
                    no->pai->cor = Preto; 
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarDireita(arvoreRubroNegro, no->pai->pai); //Caso 3
                }
            }
        } else {
            NoRN *tio = no->pai->pai->esquerda;
            
            if (tio->cor == Vermelho) {
                tio->cor = Preto; //Caso 1
                no->pai->cor = Preto; 

                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            } else {
                if (no == no->pai->esquerda) {
                    no = no->pai; //Caso 2
                    rotacionarDireita(arvoreRubroNegro, no); //Caso 2
                } else {
                    no->pai->cor = Preto; 
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarEsquerda(arvoreRubroNegro, no->pai->pai); //Caso 3
                }
            }
        }
    }
    arvoreRubroNegro->raiz->cor = Preto; //Conserta possível quebra regra 2
}

void rotacionarEsquerda(ArvoreRubroNegro* arvoreRubroNegro, NoRN* no) {
    contadoraRN++;
    NoRN* direita = no->direita;
    no->direita = direita->esquerda; 

    if (direita->esquerda != arvoreRubroNegro->nulo) {
        direita->esquerda->pai = no;
    }

    direita->pai = no->pai;
    
    if (no->pai == arvoreRubroNegro->nulo) {
        arvoreRubroNegro->raiz = direita;
    } else if (no == no->pai->esquerda) {
        no->pai->esquerda = direita;
    } else {
        no->pai->direita = direita;
    }

    direita->esquerda = no;
    no->pai = direita;
}

void rotacionarDireita(ArvoreRubroNegro* arvoreRubroNegro, NoRN* no) {
    contadoraRN++;
    NoRN* esquerda = no->esquerda;
    no->esquerda = esquerda->direita;
    
    if (esquerda->direita != arvoreRubroNegro->nulo) {
        esquerda->direita->pai = no;
    }
    
    esquerda->pai = no->pai;
    
    if (no->pai == arvoreRubroNegro->nulo) {
        arvoreRubroNegro->raiz = esquerda;
    } else if (no == no->pai->esquerda) {
        no->pai->esquerda = esquerda;
    } else {
        no->pai->direita = esquerda;
    }
    
    esquerda->direita = no;
    no->pai = esquerda;
}