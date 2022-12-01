int contadora = 0;

typedef struct no {
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    int valor;
} No;

typedef struct arvoreAVL {
    struct no* raiz;
} ArvoreAVL;

ArvoreAVL* criar();
int vazia(ArvoreAVL* arvoreAVL);
No* adicionarNo(No* no, int valor);
int adicionar(ArvoreAVL* arvoreAVL, int valor);
No* localizar(No* no, int valor);
void percorrerProfundidadeInOrder(No* no, void (*callback)(int));
void percorrerProfundidadePreOrder(No* no, void (*callback)(int));
void percorrerProfundidadePosOrder(No* no, void (callback)(int));
void visitar(int valor);
void balanceamento(ArvoreAVL*, No*);
int altura(No*);
int fb(No*);
No* rsd(ArvoreAVL*, No*);
No* rse(ArvoreAVL*, No*);
No* rdd(ArvoreAVL*, No*);
No* rde(ArvoreAVL*, No*);