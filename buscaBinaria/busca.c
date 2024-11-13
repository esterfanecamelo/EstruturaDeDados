#include "busca.h"
#include <stdio.h>

// o busca binaria retorna 1 se encontrar o elemento e
// retorna zero se não o encontrar

int buscaBinaria(int array[], int tamanho, int elemento, int *comparacoes) {

    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

   
    while (inicio <= fim) {

        meio = (inicio + fim) / 2;

        (*comparacoes)++;  

        if (array[meio] == elemento) {
            printf("ELEMENTO %d encontrado \n", elemento);
            return 1;  
        }

        if (array[meio] > elemento) {
            fim = meio - 1;  
        } else {
            inicio = meio + 1;  
        }
    }
    printf("ELEMENTO %d não encontrado", elemento);
    return 0;  
}
