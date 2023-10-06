#include<stdio.h>
#include<stdlib.h>


typedef struct grafo Grafo;
typedef struct vertice Vertice;
typedef struct adjacencia Adjacencia;


struct grafo{
    int vertices;
    int arestas;
    Vertice* adj;
};


struct vertice{
    // info 
    Adjacencia *cab;
};


struct adjacencia{
    int vertice;
    int peso; //??
    Adjacencia *prox;
};


Grafo* criaGrafo(int v){
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    int i;
    g->vertices = v;
    g->arestas = 0;
    g->adj = (Vertice*)malloc(sizeof(Vertice)*v);

    for (i = 0; i < v; i++){
        g->adj[i].cab =NULL;
    }
    return g;
}


Adjacencia* criaAdj(int v, int peso){
    Adjacencia* temp = (Adjacencia*)malloc(sizeof(Adjacencia));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return temp;
}


int criaAresta(Grafo* g, int vi, int vf, int p){
    if(!g) return 0;
    if(vf < 0 || vi < 0 || vf >= g->vertices) return 0;

    Adjacencia* novo = criaAdj(vf,p);

    novo->prox = g->adj[vi].cab;
    g->adj[vi].cab = novo;
    g->arestas++;
    return 1;
}


void imprime(Grafo* g){
    if(!g) return;
    
    Adjacencia* adj;
    int i;

    printf("Vertices: %d. Arestas: %d. \n", g->vertices, g->arestas);

    for (i = 0; i < g->vertices; i++){
        printf("v%d: ", i);
        adj = g->adj[i].cab;
        while (adj){
            printf("v%d(%d)", adj->vertice, adj->peso);
            adj = adj->prox;
        }
        printf("\n");
    }
}


int main(){
    Grafo* g = criaGrafo(5);

    criaAresta(g, 0, 1, 2);
    criaAresta(g, 1, 2, 4);
    criaAresta(g, 2, 0, 12);
    criaAresta(g, 2, 4, 40);
    criaAresta(g, 3, 1, 3);
    criaAresta(g, 4, 3, 8);

    imprime(g);
}
