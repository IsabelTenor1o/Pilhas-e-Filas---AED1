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
    // Inicializa o ponteiro de in�cio da fila como NULL
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
    // Atribui o valor do primeiro elemento da fila � vari�vel 'valor'
    return 1;
}

int enqueue(fila* f, filaInt valor) {
    no* novo = (no*)malloc(sizeof(no));
    // Aloca mem�ria para um novo n�
    if (novo == NULL)
        return 0;

    novo->valor = valor;
    // Atribui o valor ao novo n�
    novo->prox = NULL;
    // Define o ponteiro para o pr�ximo n� como NULL
    if (isEmpty(*f))
        f->inicio = novo;
        // Se a fila estiver vazia, o novo n� ser� o primeiro e �ltimo n�
    else
        f->fim->prox = novo;
        // Se a fila n�o estiver vazia, o novo n� ser� o pr�ximo do �ltimo n�
    f->fim = novo;
    // O novo n� ser� o �ltimo n� da fila
    return 1;
}

int dequeue(fila* f, filaInt* valor) {
    if (isEmpty(*f))
        return 0;
    no* aux = f-> inicio;
    //cria um ponteiro auxiliar para o primeiro n� da fila
    *valor = aux-> valor;
    //atribui o valor do primeiro n� a valor
    f-> inicio = f-> inicio-> prox;
    //atualiza o ponteiro de in�cio para o pr�ximo n�
    free(aux);
    //libera a mem�ria
    if (f-> inicio == NULL)
        f-> fim = NULL;  /
        //se a fila ficar vazia ap�s a remo��o, atualiza o ponteiro de fim para NULL
    return 1;
}

void print(fila f) {
    if (isEmpty(f)) {
        printf("Fila vazia.\n");
        return;
    }
    no* aux = f.inicio;
    //percorrer a fila a partir do primeiro n�
    printf("Elementos da fila: ");
    while (aux != NULL) {
    //enquanto aux n�o for NULL
        printf("[%d]", aux->valor);
    //imprime o valor do n� atual
        aux = aux->prox;
    //avan�a para o pr�ximo n�
    }
    printf("\n");
}

int main() {
    fila f;
    inicializar(&f);

    //testando a inser��o de elementos na fila
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

