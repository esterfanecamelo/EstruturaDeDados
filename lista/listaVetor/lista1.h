#ifndef LISTA1_H
#define LISTA1_H
#define MAX_TAM 100

typedef int TipoChave;

typedef struct tipolista {
    TipoChave elementos[MAX_TAM];
    int tamanho;
}Tipolista;

void faz_Lista_Vazia(Tipolista *lista);
int inserir_Elemento(Tipolista *lista, TipoChave chave);
int busca_remove_elemento(Tipolista *lista, TipoChave chave);
int tamanho_lista(Tipolista *lista);
int remove_primeiro_elemento(Tipolista *lista, TipoChave *chave);


#endif