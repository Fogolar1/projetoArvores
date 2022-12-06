enum coloracao { Vermelho, Preto };
typedef enum coloracao Cor;

typedef struct noRN {
    struct noRN* pai;
    struct noRN* esquerda;
    struct noRN* direita;
    Cor cor;
    int valor;
} NoRN;

typedef struct arvoreRubroNegro {
    struct noRN* raiz;
    struct noRN* nulo; 
} ArvoreRubroNegro;
 

int contadora = 0;

NoRN* criarNo(ArvoreRubroNegro*, NoRN*, int);
void balancear(ArvoreRubroNegro*, NoRN*);
void rotacionarEsquerda(ArvoreRubroNegro*, NoRN*);
void rotacionarDireita(ArvoreRubroNegro*, NoRN*);

ArvoreRubroNegro* criarRubroNegra();
int vaziaRubroNegra(ArvoreRubroNegro*);
int adicionarRubroNegra(ArvoreRubroNegro*, int);
NoRN* localizarArvoreRubroNegroB(ArvoreRubroNegro*, int); 