#include "lista2.h"
#include <stdlib.h>

void faz_Lista_Vazia(Tipolista *lista) {
    lista->primeiro = malloc(sizeof(Celula));
    lista->primeiro->prox = NULL;
    lista->ultimo = lista->primeiro;
}

int tamanho_lista(Tipolista *lista) {
    int tamanho = 0;
    Celula *aux = lista->primeiro->prox;
    while (aux != NULL) {
        tamanho++;
        aux = aux->prox;
    }
    return tamanho;
}

void inserir_Elemento(Tipolista *lista, int elemento) {
    lista->ultimo->prox = malloc(sizeof(Celula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->elemento = elemento;
    lista->ultimo->prox = NULL;
}

void remove_primeiro_elemento(Tipolista *lista, int *elemento) {
    if (lista->primeiro->prox != NULL) {
        Celula *aux = lista->primeiro->prox;
        *elemento = aux->elemento;
        lista->primeiro->prox = aux->prox;
        if (lista->ultimo == aux) lista->ultimo = lista->primeiro;
        free(aux);
    }
}

void busca_remove_elemento(Tipolista *lista, int elemento) {
    Celula *anterior = lista->primeiro;
    Celula *atual = lista->primeiro->prox;
    while (atual != NULL) {
        if (atual->elemento == elemento) {
            anterior->prox = atual->prox;
            if (lista->ultimo == atual) lista->ultimo = anterior;
            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }
}
