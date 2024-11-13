#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busca.h"
#define TAMANHO_ARRAY 10000
#define NUM_TESTES 50
//#define MAIN1
#define MAIN2

#ifdef MAIN1

int main()
{
    int array[TAMANHO_ARRAY];
    int comparacoesTotal = 0;
    int i, elemento, comparacoes;
    double mediaComparacoes;

    
    // Preenche o array com valores de 1 a 10000
    for (i = 0; i < TAMANHO_ARRAY; i++)
    {
        array[i] = i + 1;
    }

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("%d ", array[i]);  // Imprime cada elemento do array
    }
    printf("\n");

    // Realiza 50 testes de busca binária
    for (i = 0; i < NUM_TESTES; i++)
    {
        // Gera um número aleatório entre 1 e 10000
        //elemento = rand() % TAMANHO_ARRAY + 1;
        elemento = rand() % TAMANHO_ARRAY + 1;;

        printf("ELEMENTO %d\n", elemento);

        comparacoes = 0;
        buscaBinaria(array, TAMANHO_ARRAY, elemento, &comparacoes);
        comparacoesTotal += comparacoes;

    }

    // Calcula a média de comparações
    mediaComparacoes = (double)comparacoesTotal / NUM_TESTES;

    printf("Média de comparações: %.2f\n", mediaComparacoes);

    return 0;
}

#endif

#ifdef MAIN2

void Algoritmo(int A[], int n, int *comparacoes)
{
    int i, j, k, x;

    for (i = 1; i <= n - 1; i++){

        k = i ;

        for (j = i + 1; j <= n; j++){
             if (A[j] < A[k]){
                k = j;
            }
            (*comparacoes)++;
        }
        
        x = A[k]; //essas três atribuições são
        A[k] = A[i]; //para trocar os elementos A[k] e A[i]
        A[i] = x; //de posição no array A

    } // fim do for

} //fim do algoritmo

int main(){

    int A[TAMANHO_ARRAY];
    int comparacoes = 0;

    // Preenche o array com elementos em ordem crescente
    for (int i = 0; i < TAMANHO_ARRAY; i++)
    {
        A[i] = i + 1;
    }

    // Executa o algoritmo e imprime o número de comparações
    Algoritmo(A, TAMANHO_ARRAY, &comparacoes);
    printf("Número total de comparações para ordenar o array: %d\n", comparacoes);

    return 0;
}



#endif

