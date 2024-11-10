#include "conjunto.h"
#include <stdio.h>

static int tamanhoDoConjunto = 0;

void fazConjuntoVazio(ConjuntoDeInteiros conjunto){
    tamanhoDoConjunto = 0;
}

void imprimeConjunto(ConjuntoDeInteiros conjunto) {
    printf("{ ");
    for (int i=0; i < tamanhoDoConjunto; i++){
        printf("%d", conjunto[i]);
        if (i < tamanhoDoConjunto - 1) {
            printf(", ");
        }
    }
    printf(" }\n\n");
}

int pertenceAoConjunto(int num, ConjuntoDeInteiros conjunto){
    for (int i=0; i < tamanhoDoConjunto; i++){
        if (num == conjunto[i]){
            return True;
        }
    }
    return False;
}

int inserirNoConjunto(int num, ConjuntoDeInteiros conjunto){
    if (tamanhoDoConjunto >= MAX_SIZE){
        printf("Não é mais possível INSERIR: Tamanho máximo do conjunto atingido!\n\n");
        return False;
    } else if (pertenceAoConjunto(num, conjunto) == True){
        printf("Não é mais possível INSERIR: %d já pertence ao conjunto!\n\n", num);
        return False;
    } else {
        conjunto[tamanhoDoConjunto] = num;
        tamanhoDoConjunto++;
        printf("Número %d ADICIONADO com sucesso! \n\n", num);
        return True;
    }
}

int retiraDoConjunto(int num, ConjuntoDeInteiros conjunto){
    if (tamanhoDoConjunto <= 0){
        printf("Não é possível REMOVER, pois o conjunto está vazio!\n");
        return False;
    } else if (pertenceAoConjunto(num, conjunto) == False){
        printf("Não é possível REMOVER %d, pois não pertence ao conjunto!\n", num);
        return False;
    }
    else {
        for (int i=0; i < tamanhoDoConjunto; i++){
            if (conjunto[i] == num){
                for (int j=i; j < tamanhoDoConjunto-1; j++){
                    conjunto[j] = conjunto[j+1];
                }
                break;
            }
        }
        tamanhoDoConjunto--;
        printf("O número %d foi REMOVIDO!\n", num);
        return True;
    }
}

int maxDoConjunto(int *maiorElemento, ConjuntoDeInteiros conjunto){
    if (tamanhoDoConjunto == 0) return False;
    else {
        *maiorElemento = conjunto[0];
        for (int i=1; i < tamanhoDoConjunto; i++){
            if (conjunto[i] > *maiorElemento){
                *maiorElemento = conjunto[i];
            }
        }
        return True;
    }
}

int maxMinDoConjunto(int *maiorElemento, int *menorElemento, ConjuntoDeInteiros conjunto){
    if (tamanhoDoConjunto == 0) return False;
    else {
        *maiorElemento = conjunto[0];
        *menorElemento = conjunto[0];
        for (int i=1; i < tamanhoDoConjunto; i++){
            if (conjunto[i] > *maiorElemento){
                *maiorElemento = conjunto[i];
            } else if (conjunto[i] < *menorElemento){
                *menorElemento = conjunto[i];
            }
        }
        retiraDoConjunto(*maiorElemento, conjunto);
        retiraDoConjunto(*menorElemento, conjunto);
        return True;
    }
}

int maxMinDoConjunto2(int *maiorElemento, int *menorElemento, ConjuntoDeInteiros conjunto){
    if (tamanhoDoConjunto == 0) return False;

    int i, FimDoAnel;

    if ((tamanhoDoConjunto & 1) > 0) {
        conjunto[tamanhoDoConjunto] = conjunto[tamanhoDoConjunto - 1];
        FimDoAnel = tamanhoDoConjunto;
    } else {
        FimDoAnel = tamanhoDoConjunto - 1;
    }
    if (conjunto[0] > conjunto[1]) {
        *maiorElemento = conjunto[0];
        *menorElemento = conjunto[1];
    } else {
        *maiorElemento = conjunto[1];
        *menorElemento = conjunto[0];
    }

    i = 2;
    while (i <= FimDoAnel) {
        if (conjunto[i - 1] > conjunto[i]) {
            if (conjunto[i - 1] > *maiorElemento) {
                *maiorElemento = conjunto[i - 1];
            }
            if (conjunto[i] < *menorElemento) {
                *menorElemento = conjunto[i];
            }
        } else {
            if (conjunto[i] > *maiorElemento) {
                *maiorElemento = conjunto[i];
            }
            if (conjunto[i - 1] < *menorElemento) {
                *menorElemento = conjunto[i - 1];
            }
        }
        i += 2;
    }
    retiraDoConjunto(*maiorElemento, conjunto);
    retiraDoConjunto(*menorElemento, conjunto);
    return True;
}