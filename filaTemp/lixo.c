#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó
typedef struct no {
    char c;
    struct no *prox; // Corrigido: ponteiro para o próximo nó
} No;

// Tipo Pilha
typedef No *Pilha;

// Função para inicializar a pilha
void criapilha(Pilha *p) {
    *p = NULL; // Corrigido: modifica o conteúdo do ponteiro
}

// Função para empilhar um elemento
void empilha(Pilha *p, char *c) {
    No *n = (No *) malloc(sizeof(No));
    if (n == NULL) { // Verifica se a alocação foi bem-sucedida
        printf("Erro de alocação!\n");
        exit(1);
    }
    n->c = *c;    // Corrigido: acessa o valor apontado por c
    n->prox = *p; // Corrigido: ajusta o ponteiro para o próximo nó
    *p = n;       // Atualiza a pilha com o novo nó
}

int main() {
    Pilha p;      // Corrigido: não precisa ser Pilha *
    char c;       // Corrigido: não precisa ser um ponteiro
    criapilha(&p); // Corrigido: passa o endereço de p
    printf("Digite um caractere: ");
    scanf(" %c", &c); // Corrigido: leitura direta de um caractere
    empilha(&p, &c);  // Corrigido: passa o endereço de c

    return 0;
}
