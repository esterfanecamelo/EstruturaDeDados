#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

void fazFilaVazia(TipoFila *f) {
    f->primeiro = NULL;
    f->ultimo = NULL;
    f->tamanho = 0;
}

int tamanhoDaFila (TipoFila *f) {
    return f->tamanho;
}

int insereElementoNaFila(TipoFila *f, TipoRegistro reg) {
    No* novoNo = (No*)malloc(sizeof(No));

    if (novoNo == NULL) {
        return 0;
    }

    novoNo->elemento.chave = reg.chave;
    novoNo->proximo = NULL;

    if(f->tamanho == 0) {
        f->primeiro = novoNo;
        f->ultimo = novoNo;
    }
    else {
        f->ultimo->proximo = novoNo;
        f->ultimo = novoNo;
    }
    f->tamanho++;
    return 1;
}

int retiraElementoDaFila(TipoFila *f, TipoRegistro *reg) {
    if (f->tamanho == 0) {
        return 0;
    }

    *reg = f->primeiro->elemento;
    No* temp = f->primeiro;
    f->primeiro = f->primeiro->proximo;

    if (f->primeiro == NULL) {
        f->ultimo = NULL;
    }

    free(temp);
    f->tamanho--;

    return 1;
}

void imprimirFila(TipoFila *f) {
    No* atual = f->primeiro;
    while (atual != NULL) {
        printf("%d ", atual->elemento.chave);
        atual = atual->proximo;
    }
    printf("\n");
}

TipoRegistro criarRegistro(int chave) {
    TipoRegistro reg;
    reg.chave = chave;
    return reg;
}