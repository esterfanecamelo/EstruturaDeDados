#include <stdio.h>
#include <locale.h>
#include "conjunto.h"
#include "conjunto.c"

int main(void) {

    int maiorElemento, menorElemento;
    ConjuntoDeInteiros conjunto;

    fazConjuntoVazio(conjunto);

    inserirNoConjunto(50, conjunto);
    inserirNoConjunto(30, conjunto);
    inserirNoConjunto(9, conjunto);
    inserirNoConjunto(5, conjunto);
    inserirNoConjunto(12, conjunto);
    inserirNoConjunto(66, conjunto);
    inserirNoConjunto(66, conjunto);
    inserirNoConjunto(5, conjunto);
    imprimeConjunto(conjunto);
    retiraDoConjunto(5, conjunto);
    retiraDoConjunto(66, conjunto);
    imprimeConjunto(conjunto);

    if (maxMinDoConjunto(&maiorElemento, &menorElemento, conjunto)==True) {
        printf("maxMinDoConjunto: maior = %d, menor = %d\n", maiorElemento, menorElemento);
    } else {
        printf("Não foi possível buscar\n");
    }
    imprimeConjunto(conjunto);
    if (maxMinDoConjunto2(&maiorElemento, &menorElemento, conjunto)==True) {
        printf("maxMinDoConjunto2: maior = %d, menor = %d\n", maiorElemento, menorElemento);
    } else {
        printf("Não foi possível buscar, tente novamente\n");
    }

    imprimeConjunto(conjunto);

    return 0;
}
