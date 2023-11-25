#include <stdio.h>

#define MAX 50 /* tamanho m�ximo da fila */
typedef int filaInt; /* tipo base dos elementos da fila */
typedef struct {
    filaInt tamanho[MAX];
    int inicio; /* posi��o do primeiro elemento */
    int fim; /* posi��o do �ltimo elemento */
} fila;

void inicializar(fila *f)
{
    f-> inicio = 0;
    //posi��o inicial 0
    f-> fim = -1;
    //posi��o final como -1 (fila vazia)
}

int isFull(fila f)
{
    return (f.fim == MAX - 1);
}

//fun��o fila vazia
int isEmpty(fila f)
{
    return (f.inicio > f.fim);
}
//colocando elementos na fila
void enqueue(fila *f, filaInt valor)
{
    if (isFull(*f)) {
        printf("Fila cheia!\n");
        return;
    }
    f-> fim++;
    //incrementa a posi��o final
    f-> tamanho[f-> fim] = valor;
    // Insere o elemento na posi��o final
}

filaInt dequeue(fila *f)
{
    if (isEmpty(*f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    filaInt valor = f-> tamanho[f-> inicio];
    //armazena o elemento do in�cio da fila
    f-> inicio++;
    //incrementa a posi��o inicial
    return valor;
}

void print(fila f)
{
    if (isEmpty(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Elementos da fila: ");
    for (int i = f.inicio; i <= f.fim; i++) {
        printf("%d ", f.tamanho[i]);
    }
    printf("\n");
}

filaInt peek(fila f)
{
    if (isEmpty(f)) {
        printf("Fila vazia.\n");
        return -1;
    }
    return f.tamanho[f.inicio];
}

void intercalar(fila f1, fila f2, fila *f3)
{
    //fila 3 vazia
    inicializar(f3);

    //enquanto pelo menos uma das fila n�o t� vazia
    while (!isEmpty(f1) || !isEmpty(f2)) {
        //verificar se a fila f1 n�o est� vazia
        if (!isEmpty(f1)) {
            //desenfileirar o pr�ximo elemento de f1 e enfileirar em f3
            enqueue(f3, dequeue(&f1));
        }

        //verificar se a fila f2 n�o est� vazia
        if (!isEmpty(f2)) {
            //dsenfileirar o pr�ximo elemento de f2 e enfileirar em f3
            enqueue(f3, dequeue(&f2));
        }
    }
}


int main()
{
    //teste de codigo
    fila L1, L2, L3;
    inicializar(&L1);
    inicializar(&L2);

    //preencher a fila 1
    enqueue(&L1, 1);
    enqueue(&L1, 2);
    enqueue(&L1, 3);
    enqueue(&L1, 4);

    //preencher a fila 2
    enqueue(&L2, 50);
    enqueue(&L2, 51);
    enqueue(&L2, 18);
    enqueue(&L2, 21);
    enqueue(&L2, 20);
    enqueue(&L2, 24);


    //intercala as filas L1 e L2 e gerar a fila L3
    intercalar(L1, L2, &L3);

    //imprimir os elementos da fila L3
    print(L3);
    return 0;
}
