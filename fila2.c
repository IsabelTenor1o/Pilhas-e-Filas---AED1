#include <stdio.h>
#include <stdlib.h>

typedef int filaInt;
typedef struct no {
    filaInt valor;
    struct no* prox;
} no;

typedef struct fila {
    no* inicio;
    no* fim;
} fila;

void inicializar(fila* f) {
    f->inicio = NULL;
    // Inicializa o ponteiro de início da fila como NULL
    f->fim = NULL;
     // Inicializa o ponteiro de fim da fila como NULL
}

int isEmpty(fila f) {
    return (f.inicio == NULL && f.fim == NULL);
}

int peek(fila f, filaInt* valor) {
    if (isEmpty(f))
        return 0;
    *valor = f.inicio->valor;
    // Atribui o valor do primeiro elemento da fila à variável 'valor'
    return 1;
}

int enqueue(fila* f, filaInt valor) {
    no* novo = (no*)malloc(sizeof(no));
    // Aloca memória para um novo nó
    if (novo == NULL)
        return 0;

    novo->valor = valor;
    // Atribui o valor ao novo nó
    novo->prox = NULL;
    // Define o ponteiro para o próximo nó como NULL
    if (isEmpty(*f))
        f->inicio = novo;
        // Se a fila estiver vazia, o novo nó será o primeiro e último nó
    else
        f->fim->prox = novo;
        // Se a fila não estiver vazia, o novo nó será o próximo do último nó
    f->fim = novo;
    // O novo nó será o último nó da fila
    return 1;
}

int dequeue(fila* f, filaInt* valor) {
    if (isEmpty(*f))
        return 0;
    no* aux = f-> inicio;
    //cria um ponteiro auxiliar para o primeiro nó da fila
    *valor = aux-> valor;
    //atribui o valor do primeiro nó a valor
    f-> inicio = f-> inicio-> prox;
    //atualiza o ponteiro de início para o próximo nó
    free(aux);
    //libera a memória
    if (f-> inicio == NULL)
        f-> fim = NULL;  /
        //se a fila ficar vazia após a remoção, atualiza o ponteiro de fim para NULL
    return 1;
}

void print(fila f) {
    if (isEmpty(f)) {
        printf("Fila vazia.\n");
        return;
    }
    no* aux = f.inicio;
    //percorrer a fila a partir do primeiro nó
    printf("Elementos da fila: ");
    while (aux != NULL) {
    //enquanto aux não for NULL
        printf("[%d]", aux->valor);
    //imprime o valor do nó atual
        aux = aux->prox;
    //avança para o próximo nó
    }
    printf("\n");
}

int main() {
    fila f;
    inicializar(&f);

    //testando a inserção de elementos na fila
    enqueue(&f, 1);
    enqueue(&f, 2);
    enqueue(&f, 3);
    enqueue(&f, 4);

    //imprimindo a fila
    print(f);

    //removendo um elemento da fila
    filaInt valor;
    if (dequeue(&f, &valor)) {
        printf("Elemento removido: %d\n", valor);
    } else {
        printf("Fila vazia.\n");
    }

    // Imprimindo a fila novamente
    print(f);

    return 0;
}

