typedef struct noAVL {
    struct noAVL* pai;
    struct noAVL* esquerda;
    struct noAVL* direita;
    int valor;
} NoAVL;

typedef struct arvoreAVL {
    struct noAVL* raiz;
} ArvoreAVL;

ArvoreAVL* criar();
int vazia(ArvoreAVL* arvoreAVL);
NoAVL* adicionarNo(NoAVL* no, int valor);
int adicionar(ArvoreAVL* arvoreAVL, int valor);
NoAVL* localizar(NoAVL* no, int valor);
void percorrerProfundidadeInOrderAVL(NoAVL* no, void (*callback)(int));
void percorrerProfundidadePreOrderAVL(NoAVL* no, void (*callback)(int));
void percorrerProfundidadePosOrderAVL(NoAVL* no, void (callback)(int));
void visitarAVL(int valor);
void balanceamento(ArvoreAVL*, NoAVL*);
int altura(NoAVL*);
int fb(NoAVL*);
NoAVL* rsd(ArvoreAVL*, NoAVL*);
NoAVL* rse(ArvoreAVL*, NoAVL*);
NoAVL* rdd(ArvoreAVL*, NoAVL*);
NoAVL* rde(ArvoreAVL*, NoAVL*);