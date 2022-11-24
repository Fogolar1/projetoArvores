int contadora = 0;

typedef struct no {
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    int valor;
} No;

typedef struct arvore {
    struct no* raiz;
} Arvore;

Arvore* criar();
int vazia(Arvore* arvore);
No* adicionarNo(No* no, int valor);
No* adicionar(Arvore* arvore, int valor);
No* localizar(No* no, int valor);
void percorrerProfundidadeInOrder(No* no, void (*callback)(int));
void percorrerProfundidadePreOrder(No* no, void (*callback)(int));
void percorrerProfundidadePosOrder(No* no, void (callback)(int));
void visitar(int valor);
void balanceamento(Arvore*, No*);
int altura(No*);
int fb(No*);
No* rsd(Arvore*, No*);
No* rse(Arvore*, No*);
No* rdd(Arvore*, No*);
No* rde(Arvore*, No*);