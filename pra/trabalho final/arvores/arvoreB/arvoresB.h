typedef struct noB {
    int total;
    int* chaves;
    struct noB** filhos;
    struct noB* pai; 
} NoB;

typedef struct arvoreB {
  NoB* raiz;
  int ordem;
  int contadoraB;
} ArvoreB;

ArvoreB* criaArvore(int); 
NoB* criaNo(ArvoreB*);
void percorreArvore(NoB*);
int pesquisaBinaria(NoB*, int, ArvoreB* arvore);
int localizaChave(ArvoreB*, int);
NoB* localizaNo(ArvoreB*, int);
void adicionaChaveNo(NoB*, NoB*, int, ArvoreB* arvore);
int transbordo(ArvoreB*,NoB*);
NoB* divideNo(ArvoreB*, NoB*);
void adicionaChaveRecursivo(ArvoreB*, NoB*, NoB*, int);
int adicionaChave(ArvoreB*, int);