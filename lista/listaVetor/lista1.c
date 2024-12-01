#include "lista1.h"
#include "stdio.h"

#define MAX_TAM 100


void faz_Lista_Vazia(Tipolista *lista){
    lista->tamanho=0;
}

int inserir_Elemento(Tipolista *lista, TipoChave chave){

    if(lista->tamanho == MAX_TAM){
        return 0;
    }

    lista->elementos[lista->tamanho] = chave;
    lista->tamanho++;

    return 1;
}

int busca_remove_elemento(Tipolista *lista, TipoChave chave){

    if(lista->tamanho == 0){
        return 0;
    }

    for(int i = 0; i < lista->tamanho; i++){
        if (lista->elementos[i] == chave){
            for(int j=i;j<lista->tamanho-1;j++){
                lista->elementos[j] = lista->elementos[j+1];
            }
            lista->tamanho--;
            return 1;
        }
    }
    return 0;
}

int tamanho_lista(Tipolista *lista){
    return lista->tamanho;
}

int remove_primeiro_elemento(Tipolista *lista, TipoChave *chave){

    if(lista->tamanho == 0){
        return 0;
    }
    
    *chave = lista->elementos[0];

    for(int i = 0;i<lista->tamanho-1;i++){
       lista->elementos[i] = lista->elementos[i+1];
    }
    lista->tamanho--;
    return 1;
}




