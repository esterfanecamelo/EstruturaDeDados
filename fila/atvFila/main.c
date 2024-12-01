#include <stdio.h>
#include "fila.h"

int main() {
    TipoFila fila;
    TipoRegistro reg;

    // Inicializa a fila vazia
    fazFilaVazia(&fila);
    printf("Fila criada. Tamanho inicial: %d\n", tamanhoDaFila(&fila));

    // Insere elementos na fila
    printf("Inserindo elementos na fila:\n");
    for (int i = 1; i <= 5; i++) {
        reg = criarRegistro(i);
        if (insereElementoNaFila(&fila, reg)) {
            printf("Elemento %d inserido com sucesso.\n", reg.chave);
        } else {
            printf("Falha ao inserir o elemento %d.\n", reg.chave);
        }
    }

    // Imprime a fila
    printf("Fila apos insercoes: ");
    imprimirFila(&fila);
    printf("Tamanho da fila: %d\n", tamanhoDaFila(&fila));

    // Remove um elemento da fila
    printf("Removendo um elemento da fila:\n");
    if (retiraElementoDaFila(&fila, &reg)) {
        printf("Elemento %d removido com sucesso.\n", reg.chave);
    } else {
        printf("Falha ao remover elemento da fila (fila vazia).\n");
    }

    // Imprime a fila após remoção
    printf("Fila apos remocao: ");
    imprimirFila(&fila);
    printf("Tamanho da fila: %d\n", tamanhoDaFila(&fila));

    // Testa outra remoção
    printf("Removendo mais um elemento:\n");
    if (retiraElementoDaFila(&fila, &reg)) {
        printf("Elemento %d removido com sucesso.\n", reg.chave);
    } else {
        printf("Falha ao remover elemento da fila (fila vazia).\n");
    }

    // Imprime a fila após remoção
    printf("Fila apos segunda remoção: ");
    imprimirFila(&fila);
    printf("Tamanho da fila: %d\n", tamanhoDaFila(&fila));

    return 0;
}
