#include "lista3.h"
#include <stdlib.h>

void faz_Lista_Vazia(Tipolista *lista) {
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

int tamanho_lista(Tipolista *lista) {
    int tamanho = 0;
    Celula *aux = lista->primeiro;
    while (aux != NULL) {
        tamanho++;
        aux = aux->prox;
    }
    return tamanho;
}

void inserir_Elemento(Tipolista *lista, int elemento) {
    Celula *nova = malloc(sizeof(Celula));
    nova->elemento = elemento;
    nova->prox = NULL;
    if (lista->primeiro == NULL) {
        lista->primeiro = nova;
        lista->ultimo = nova;
    } else {
        lista->ultimo->prox = nova;
        lista->ultimo = nova;
    }
}

void remove_primeiro_elemento(Tipolista *lista, int *elemento) {
    if (lista->primeiro != NULL) {
        Celula *aux = lista->primeiro;
        *elemento = aux->elemento;
        lista->primeiro = aux->prox;
        if (lista->primeiro == NULL) lista->ultimo = NULL;
        free(aux);
    }
}

void busca_remove_elemento(Tipolista *lista, int elemento) {
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;
    while (atual != NULL) {
        if (atual->elemento == elemento) {
            if (anterior == NULL) {
                lista->primeiro = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            if (lista->ultimo == atual) lista->ultimo = anterior;
            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }
}
