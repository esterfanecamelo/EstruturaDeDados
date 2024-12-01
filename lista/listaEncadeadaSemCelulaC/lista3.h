#ifndef LISTA3_H
#define LISTA3_H

typedef struct celula {
    int elemento;
    struct celula *prox;
} Celula;

typedef struct {
    Celula *primeiro;
    Celula *ultimo;
} Tipolista;

void faz_Lista_Vazia(Tipolista *lista);
int tamanho_lista(Tipolista *lista);
void inserir_Elemento(Tipolista *lista, int elemento);
void remove_primeiro_elemento(Tipolista *lista, int *elemento);
void busca_remove_elemento(Tipolista *lista, int elemento);

#endif

