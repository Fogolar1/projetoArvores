enum coloracao { Vermelho, Preto };
typedef enum coloracao Cor;

typedef struct no {
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    Cor cor;
    int valor;
} No;

typedef struct arvoreRubroNegro {
    struct no* raiz;
    struct no* nulo; 
} ArvoreRubroNegro;
 

int contadora = 0;

No* criarNo(ArvoreRubroNegro*, No*, int);
void balancear(ArvoreRubroNegro*, No*);
void rotacionarEsquerda(ArvoreRubroNegro*, No*);
void rotacionarDireita(ArvoreRubroNegro*, No*);

ArvoreRubroNegro* criarRubroNegra();
int vaziaRubroNegra(ArvoreRubroNegro*);
int adicionarRubroNegra(ArvoreRubroNegro*, int);
No* localizarArvoreRubroNegroB(ArvoreRubroNegro*, int); 