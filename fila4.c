#include <stdio.h>
#define MAX 50 /* tamanho máximo da fila */
typedef int filaInt; /* tipo base dos elementos da fila */
typedef struct {
    filaInt tamanho[MAX];
    int inicio; /* posição do primeiro elemento */
    int fim; /* posição do último elemento */
} fila;

void inicializar(fila *f)
{
    f-> inicio = 0;
    //posição inicial 0
    f-> fim = -1;
    //posição final como -1 (fila vazia)
}

int isFull(fila f)
{
    return (f.fim == MAX - 1);
}

//função fila vazia
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
    //incrementa a posição final
    f-> tamanho[f-> fim] = valor;
    // Insere o elemento na posição final
}

filaInt dequeue(fila *f)
{
    if (isEmpty(*f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    filaInt valor = f-> tamanho[f-> inicio];
    //armazena o elemento do início da fila
    f-> inicio++;
    //incrementa a posição inicial
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

void imprimirBinarios(int n) {
    fila f;
    inicializar(&f);


    // colocando 1 na fila inicia o processo de geração dos números binários
    enqueue(&f, 1);

    //inicia um loop que para quando chega no parametro passado
    for (int i = 1; i <= n; i++) {
        filaInt binario = dequeue(&f);
        //printando o numero atual
        printf("[%d]", binario);

        //como são formados os binários
        enqueue(&f, binario * 10 + 0);
        enqueue(&f, binario * 10 + 1);
    }

    printf("\n");
}

int main() {
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    printf("Numeros binarios entre 1 e %d:\n", numero);
    imprimirBinarios(numero);

    return 0;
}
