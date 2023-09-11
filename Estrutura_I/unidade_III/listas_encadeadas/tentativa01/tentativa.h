typedef struct lista Lista;
typedef struct listano ListaNo;

Lista* lst_cria (void);

void lst_insere (Lista* l, int v);

void lst_imprime (Lista* l);

int lst_pertence (Lista* l, int v);

void lst_insere_ordenado (Lista* l, int v);

void lst_retira (Lista* l, int v);
