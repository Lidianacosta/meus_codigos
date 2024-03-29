#include <stdio.h>
#include <stdlib.h>

// R = vazio = 1 = cubo virado  = 0 ,
// G = meio Prenchido = 2 =
// B = 2

typedef struct card Card;

struct card
{
    int hash_card;
    short p1; // p1 cor
    short p2; // p2figura
    short p3; // p3preencimento
    short p4; // p4formato
};

// Estrutura que define uma arvore
struct arvore
{
    Card dados;
    int altura;
    struct arvore *esq;
    struct arvore *dir;
};

void cria_hash_card(Card card)
{
    card.hash_card = card.p1 * (1) + card.p2 * (3 * 1) + card.p3 * (3 * 3) + card.p4 * (3 * 3 * 3);
}

int verifica(Card card)
{
    return card.p1 * (1) + card.p2 * (3 * 1) + card.p3 * (3 * 3) + card.p4 * (3 * 3 * 3);
}

Card construir_card(int p1, int p2, int p3, int p4)
{
    Card card;
    card.p1 = p1;
    card.p2 = p2;
    card.p3 = p3;
    card.p4 = p4;
    return card;
}

// Definição de escopo de funções
int max(int a, int b);
struct arvore *rotacaoDir(struct arvore *raiz);
struct arvore *rotacaoEsq(struct arvore *raiz);
int alturaDoNo(struct arvore *raiz);
int balanceamento(struct arvore *raiz);
int verificaBalanceamento(struct arvore *raiz);
int sucessor(struct arvore *raiz);
int alturaDaArvore(struct arvore *raiz);
struct arvore *inserirNovoNo(struct arvore *raiz, Card dados);
struct arvore *removerNo(struct arvore *raiz, int dados);
void mostrarArvore(struct arvore *raiz);

int main()
{

    struct arvore *raiz = (struct arvore *)malloc(sizeof(struct arvore));
    raiz = 0;

    raiz = inserirNovoNo(raiz, construir_card(2, 0, 0, 0));
    mostrarArvore(raiz);
    printf("\n\n");
    raiz = inserirNovoNo(raiz, construir_card(2, 0, 1, 1));
    mostrarArvore(raiz);
    printf("\n\n");
    raiz = inserirNovoNo(raiz, construir_card(2, 0, 2, 2));
    mostrarArvore(raiz);

    int altura = alturaDaArvore(raiz);
    if (verificaBalanceamento(raiz))
    {
        printf("\nA arvore esta balanceada");
    }
    else
    {
        printf("\nA arvore nao esta balanceada");
    }
    mostrarArvore(raiz);
}

// Função para inserir um novo nó na arvore
struct arvore *inserirNovoNo(struct arvore *raiz, Card dados)
{
    // Caso encontremos uma folha da arvore, inserimos os nossos novos dados naquela folha
    if (raiz == 0)
    {
        struct arvore *novoNo = (struct arvore *)malloc(sizeof(struct arvore));
        novoNo->dados = dados;
        novoNo->esq = novoNo->dir = 0;
        novoNo->altura = 1;
        return novoNo;
    }

    // Se a arvore nao estiver vazia, verificamos o valor dentro do nó
    // Se o valor a qual queremos inserir for menor do que o valor do nó atual, inserimos o novo nó a esquerda do nó atual
    if (verifica(dados) < verifica(raiz->dados))
    {
        // É realizado a recursão nos nós esquerdos até que cheguemos no caso base da linha 60
        raiz->esq = inserirNovoNo(raiz->esq, dados);
        // Se o valor a qual queremos inserir for maior do que o valor do nó atual, inserimos o novo nó a direita do nó atual
    }
    else if (verifica(dados) > verifica(raiz->dados))
    {
        // É realizado a recursão nos nós direitos até que cheguemos no caso base da linha 60
        raiz->dir = inserirNovoNo(raiz->dir, dados);
    }
    else
    {
        // Se nenhuma das condições forem atendidas, significa que o valor a qual queremos inserir ja está presente na arvore
        printf("\nEste valor já está presente na arvore");
    }

    // Atualizando altura do no atual passado como parametro
    raiz->altura = alturaDaArvore(raiz) + 1;
    // Verificando balanceamento do no atual para iniciar processo de balanceamento
    int b = balanceamento(raiz);
    if (b > 1 && (raiz->esq != 0) && verifica(dados) < verifica(raiz->esq->dados))
    {
        return rotacaoDir(raiz);
    }

    if (b < -1 && (raiz->dir != 0) && verifica(dados) > verifica(raiz->dir->dados))
    {
        return rotacaoEsq(raiz);
    }

    if (b > 1 && (raiz->esq != 0) && verifica(dados) > verifica(raiz->esq->dados))
    {
        raiz->esq = rotacaoEsq(raiz->esq);
        return rotacaoDir(raiz);
    }

    if (b < -1 && (raiz->dir != 0) && verifica(dados) < verifica(raiz->dir->dados))
    {
        raiz->dir = rotacaoDir(raiz->dir);
        return rotacaoEsq(raiz);
    }

    return raiz;
}

// Função para calcular a altura da arvore
int alturaDaArvore(struct arvore *raiz)
{
    // Caso cheguemos em uma folha, retornamos o valor -1 para a chamada recursiva de cima
    if (raiz == 0)
    {
        return -1;
    }
    // Calculando a altura das subarvore a esquerda
    int alturaEsq = alturaDaArvore(raiz->esq);
    // Calculando a altura das subarvore a direita
    int alturaDir = alturaDaArvore(raiz->dir);

    // Quando estamos em um nó preenchido com algum valor, verificamos a altura das subarvores a esquerda e direita do nó pai e retornamos o maior valor da alturas de uma das duas subarvores
    return max(alturaDir, alturaEsq) + 1;
}

// Função que verifica se uma arvore está balanceada
int verificaBalanceamento(struct arvore *raiz)
{
    // caso a arvore esteja vazia, ela está balanceada e retornamos 1, sinalizando verdadeiro para o balanceamento
    if (raiz == 0)
    {
        return 1;
    }
    // Para verificar se uma arvore está balanceada devemos calcular a altura de ambos os lados da arvore, esquerdo e direito
    int alturaEsq = alturaDaArvore(raiz->esq);
    int alturaDir = alturaDaArvore(raiz->dir);

    // Depois, atraves de um operador ternario, que verifica atraves da subtração da altura direita com a esquerda ou ao contrario a diferença das alturas
    int balanceamento = (alturaEsq > alturaDir) ? alturaEsq - alturaDir : alturaDir - alturaEsq;

    // caso a diferença de altura seja mais que 1, então a arvore está desbalanceada
    if (balanceamento > 1)
    {
        return 0;
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int balanceamento(struct arvore *raiz)
{
    if (raiz == 0)
    {
        return 0;
    }

    return alturaDaArvore(raiz->esq) - alturaDaArvore(raiz->dir);
}

int alturaDoNo(struct arvore *raiz)
{
    if (raiz == 0)
    {
        return 0;
    }

    return raiz->altura;
}

struct arvore *rotacaoDir(struct arvore *raiz)
{
    struct arvore *novoNo = raiz->esq;
    raiz->esq = novoNo->dir;
    novoNo->dir = raiz;

    raiz->altura = max(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;
    novoNo->altura = max(alturaDoNo(novoNo->esq), alturaDoNo(novoNo->dir)) + 1;

    return novoNo;
}

struct arvore *rotacaoEsq(struct arvore *raiz)
{
    struct arvore *novoNo = raiz->dir;
    raiz->dir = novoNo->esq;
    novoNo->esq = raiz;

    raiz->altura = max(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;
    novoNo->altura = max(alturaDoNo(novoNo->esq), alturaDoNo(novoNo->dir)) + 1;

    return novoNo;
}

// int sucessor(struct arvore *raiz)
// {
//     int s = verifica(raiz->dados);
//     while (raiz->esq != 0)
//     {
//         s = verifica(raiz->esq->dados);
//         raiz = raiz->esq;
//     }
//     // Removendo o sucessor encontrado para não permitir duplicação de valores
//     raiz->esq = 0;
//     return s;
// }

// struct arvore *removerNo(struct arvore *raiz, Card dados)
// {

//     if (raiz == 0)
//     {
//         printf("\nO valor buscado não está na arvore");
//         return 0;
//     }

//     if (verifica(dados) < verifica(raiz->dados))
//     {
//         raiz->esq = removerNo(raiz->esq, dados);
//     }
//     else if (verifica(dados) > verifica(raiz->dados))
//     {
//         raiz->dir = removerNo(raiz->dir, dados);
//     }
//     else
//     {

//         if (raiz->esq == 0)
//         {
//             return raiz->dir;
//         }
//         if (raiz->dir == 0)
//         {
//             return raiz->esq;
//         }

//         // Essa função reorganiza a arvore com base no sucessor do nó atual, colocando o sucessor no lugar do nó que queremos remover
//         raiz->dados = sucessor(raiz->dir);
//         // Ao realizar o processo anterior, agora precisamos remover dados duplicados na arvore, neste caso, o sucessor do numero a ser removido que foi encontrado
//         raiz->dir = removerNo(raiz->dir, raiz->dados);
//     }

//     return raiz;
// }

void mostrarArvore(struct arvore *raiz){
    if (raiz != 0){
        mostrarArvore(raiz->esq);
        printf("\ncarta = { %d , %d , %d , %d}\n", raiz->dados.p1, raiz->dados.p2, raiz->dados.p3, raiz->dados.p4);
        mostrarArvore(raiz->dir);
    }
}