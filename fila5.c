#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    struct no* prox;
} no;

typedef struct {
    no* frente;
    no* tras;
} Fila;

void inicializarFila(Fila* fila) {
    fila->frente = NULL;
    fila->tras = NULL;
}

int estaVazia(Fila* fila) {
    return (fila->frente == NULL);
}

void enfileirar(Fila* fila, int valor) {
    no* novo = (no*)malloc(sizeof(no));
    novo->valor = valor;
    novo->prox = NULL;

    if (estaVazia(fila)) {
        fila->frente = novo;
        fila->tras = novo;
    } else {
        fila->tras->prox = novo;
        fila->tras = novo;
    }
}

int desenfileirar(Fila* fila) {
    if (estaVazia(fila)) {
        printf("A fila está vazia.\n");
        return -1;
    }

    int valor = fila->frente->valor;
    no* temp = fila->frente;

    if (fila->frente == fila->tras) {
        fila->frente = NULL;
        fila->tras = NULL;
    } else {
        fila->frente = fila->frente->prox;
    }

    free(temp);
    return valor;
}

int main() {
    int disco;
    scanf("%d", &disco);

    Fila fila;
    inicializarFila(&fila);

    int min = disco, size = disco;

    int q;
    for (int i = 0; i < disco; i++) {
        scanf("%d", &q);
        enfileirar(&fila, q);

        if (q == min) {
            while (!estaVazia(&fila)) {
                printf("%d ", size);
                size--;
                desenfileirar(&fila);
            }

            min = size;
            printf("\n");
        }
    }

    return 0;
}
