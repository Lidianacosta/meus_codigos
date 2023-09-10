typedef struct arvore Arvore;

// Arvore* alocarMemoria();

Arvore* alocarMemoria(int valor);

Arvore* inserirNaArvore(Arvore* raiz, int valor);

void imprimirArvore(Arvore* raiz);

// não entendi bem
int antecessor(Arvore* raiz);

int sucessor(Arvore* raiz);

// não entendi bem
Arvore* removerNo(Arvore* raiz, int valor);

// entendi mais ou menos
int alturaDaArvore(Arvore* raiz);

int verificaBalanceamento(Arvore* raiz);

// 1 é true 

// add 
Arvore* rotacaoDir(Arvore* raiz);

Arvore* rotacaoEsq(Arvore* raiz);

int balanceamento(Arvore* raiz);

int alturaDoNo(Arvore* raiz);

int max(int a, int b);
