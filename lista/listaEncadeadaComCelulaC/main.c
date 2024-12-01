#include "lista2.h"
#include <stdio.h>
#define MAX_TAREFAS 100

int main() {
    int n, j, k;
    printf("Digite o número de tarefas: ");
    scanf("%d", &n);
    Tipolista entraEm[MAX_TAREFAS], saiDe[MAX_TAREFAS];
    int foiPraSaida[MAX_TAREFAS] = {0};
    int ordemDeSaida[MAX_TAREFAS] = {0};

    for (int i = 1; i <= n; i++) {
        faz_Lista_Vazia(&entraEm[i]);
        faz_Lista_Vazia(&saiDe[i]);
    }

    printf("Digite os pares (j,k) de pre-requisitos (0 0 para parar):\n");
    while (1) {
        scanf("%d %d", &j, &k);
        if (j == 0 && k == 0) break;
        inserir_Elemento(&entraEm[k], j);
        inserir_Elemento(&saiDe[j], k);
    }

    for (int i = 1; i <= n; i++) {
        int w = -1;
        for (int t = 1; t <= n; t++) {
            if (tamanho_lista(&entraEm[t]) == 0 && !foiPraSaida[t]) {
                w = t;
                break;
            }
        }
        if (w == -1) {
            printf("Erro: pre-requisitos impossíveis\n");
            return 1;
        }

        while (tamanho_lista(&saiDe[w]) > 0) {
            int t;
            remove_primeiro_elemento(&saiDe[w], &t);
            busca_remove_elemento(&entraEm[t], w);
        }

        ordemDeSaida[i] = w;
        foiPraSaida[w] = 1;
    }

    printf("Ordem de saída das tarefas:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", ordemDeSaida[i]);
    }
    printf("\n");

    return 0;
}
