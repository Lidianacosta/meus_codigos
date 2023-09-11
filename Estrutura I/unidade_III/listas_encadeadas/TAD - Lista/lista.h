typedef struct no No;

No* lst_cria();

No* lst_insere(No* l, int v);

int lst_vazia(No* l);

void lst_imprime(No* l);

No* lst_busca(No* l, int elemento);

No* lst_retira(No* l, int v);

void lst_libera(No* l);

No* lst_insere_ordenada(No* l, int v);
