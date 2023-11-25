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


int main()
{
    fila f;
    inicializar(&f); // Inicializa a fila

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);

    print(f);
    // Output: Elementos da fila: 10 20 30

    filaInt removerInicio = dequeue(&f);
    printf("Elemento removido: %d\n", removerInicio);
    // Output: Elemento desenfileirado: 10

    print(f);
    // Output: Elementos da fila: 20 30

    enqueue(&f, 40);
    enqueue(&f, 50);
    enqueue(&f, 80);
    print(f);
    filaInt elemento1 = peek(f);
    printf("Primeiro elemento: %d\n", elemento1);



    return 0;
}
