#ifndef FILA_H
#define FILA_H

typedef int TipoChave;

typedef struct registro {
    TipoChave chave;
} TipoRegistro;

typedef struct no {
    TipoRegistro elemento;
    struct no* proximo;
} No;

typedef struct fila {
    No* primeiro;
    No* ultimo;
    int tamanho;
} TipoFila;

void fazFilaVazia(TipoFila *f);
int tamanhoDaFila (TipoFila *f);
int insereElementoNaFila(TipoFila *f, TipoRegistro reg);
int retiraElementoDaFila(TipoFila *f, TipoRegistro *reg);
void imprimirFila(TipoFila *f);
TipoRegistro criarRegistro(int chave);

#endif