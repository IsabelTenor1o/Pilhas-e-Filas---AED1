#include<stdio.h>
#include<string.h>

typedef int PilhaInt;
typedef struct no {
    PilhaInt valor;
    struct no* prox;
} no;

typedef no* pilha;

//fun��o para criar uma pilha vazia
void criarPilha(pilha *p) {
    *p = NULL;
}

//fun��o para verificar se a pilha est� vazia
int isEmpty(pilha p) {
    return (p == NULL);
}

//fun��o para obter o elemento do topo da pilha
int top(pilha p, PilhaInt *num) {
    if (isEmpty(p))
        return 0;

    *num = p-> valor;
    //valor do elemento do topo da pilha na vari�vel num.
    return 1;
}

//empilhar um elemento na pilha
int push(pilha *p, PilhaInt valor) {
    pilha novo;
    novo = (no *) malloc(sizeof(no));
    //sloca espa�o para um novo n� da pilha.

    if (novo == NULL)
        return 0;

    novo-> valor = valor;
    //atribui o valor ao campo valor do novo n�

    novo-> prox = *p;
    //novo n� aponta para o n� que antes era o topo da pilha
    *p = novo;
    //aponta para o novo n�
    return 1;
}

//desempilhar um elemento da pilha
int pop(pilha *p, PilhaInt *valor) {
    pilha aux;
    if (isEmpty(*p))
        return 0;
    aux = *p;
    //valor do ponteiro da pilha a um n� auxiliar
    *valor = (*p)-> valor;
    //armazena o valor do elemento do topo da pilha na vari�vel valor
    *p = aux-> prox;
    //passa para o proximo
    free(aux);
    //kibera a mem�ria
    return 1;
}

//imprimir os elementos da pilha
void print(pilha p) {
    if (isEmpty(p)) {
        printf("Pilha vazia\n");
        return;
    }

    printf("Elementos da pilha: ");
    while (p != NULL) {
        //percorre a lista
        printf("[%d]", p-> valor);
        //Imprime o valor do elemento atual da pilha
        p = p-> prox;
        //passa o pr�ximo elemento da pilha
    }
    printf("\n");
}


    int main (){
    pilha pilhaTeste;
    criarPilha(&pilhaTeste);

    push(&pilhaTeste, 02);
    push(&pilhaTeste, 07);
    push(&pilhaTeste, 1998);

    PilhaInt valor;
    if (top(pilhaTeste, &valor))
        printf("Elemento do topo: %d\n", valor);
    print(pilhaTeste);
    pop(&pilhaTeste, &valor);
    printf("Elemento removido: %d\n", valor);
    print(pilhaTeste);

    return 0;
    }

