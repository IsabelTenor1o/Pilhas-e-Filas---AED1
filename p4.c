#include <stdio.h>
#include <stdlib.h>
#define MAX 100
//tamanho m�ximo da pilha

typedef int PilhaInt;
typedef struct {
    PilhaInt tamanho[MAX];
    //  tamanho m�ximo que � 20
    int topo;
    // Vari�vel inteira que representa o topo da pilha.
    // nome que representar� a pilha
} Pilha;

//criar uma pilha, recebendo um ponteiro para uma vari�vel do tipo Pilha
void criarPilha(Pilha *p) {
    p-> topo = -1;
    //indicando que a pilha est� vazia
}

//verificar se a pilha est� vazia
int isEmpty(Pilha p) {
    return (p.topo == -1);
    //retorna true se o topo for igual a -1, significa que a pilha est� vazia, se n�o retorna false
}

//empilhar (push) um elemento na pilha
void push(Pilha *p, PilhaInt numero) {
    // Verifica se a pilha est� cheia
    if (p-> topo == MAX - 1) {
        printf("A pilha esta cheia!");
    } else {
        // Incrementa o topo e adiciona o n�mero na posi��o correspondente na pilha
        p-> topo++;
        p-> tamanho[p->topo] = numero;
    }
}

//retornar o elemento no topo da pilha (sem remover)
int top(Pilha pilha, PilhaInt *numero) {
    if (pilha.topo == -1) {
        return 0;
        //caso o topo for igual a -1, a pilha est� vazia como definido anteriormente
    }
    *numero = pilha.tamanho[pilha.topo];
    //o valor do topo da pilha � armazenado ao valor
    return 1; }


//pop (remover o topo) pq em pilha ultimo a entrar � o primeiro a sair
int pop(Pilha *p, PilhaInt *numero)
{
    if (isEmpty(*p))
        //se a pilha estiver vazia
        return 0;

    *numero = p-> tamanho[p-> topo--];
    //armazena o valor do elemento do topo da pilha no numero e decrementa o topo
    return 1;
}


//imprimir os elementos da pilha
void print(Pilha *p) {
    int i;
    for (i = p-> topo; i >= 0; i--) {
        printf("[%d]", p-> tamanho[i]);
        //�percorre a pilha do topo at� o �ndice 0, imprimindo cada elemento entre colchetes.
    }
}
void fibonacciPilha(Pilha *p, int num) {
    //caso seja 0 ou menor nao tem pilha
    if (num <= 0)
        return 0;

    //os primeiros valores da sequencia igual 0 e igual 1
    //representam os dois �ltimos valores calculados na sequ�ncia
    int fib1 = 0;
    int fib2 = 1;

    //empilhando o valor fib1 na pilha
    push(p, fib1);
    //-- o valor do numero em 1, pq colocamos na pilha
    num--;

    //para saber se o numero j� chegou em zero
    //se nao, push novamente para empilhar o valor fib2 na pilha
    if (num > 0)
        push(p, fib2);

    //enquanto ainda tiver valor em numero
    while (num > 1) {
        //o pr�ximo valor da sequ�ncia � obtido somando os valores de fib1 e fib2
        int fibProximo = fib1 + fib2;
        //empilha o valor calculado
        push(p, fibProximo);
        //atualiza os valores de fib1 e 2
        //fib1 recebe o 2 e 2 recebe o que foi calculado anteriormente
        fib1 = fib2;
        fib2 = fibProximo;
        //diminui o numero para parar o loop
        num--;
    }
}
int main() {
    Pilha pilha;
    criarPilha(&pilha);

    int n;
    printf("Digite o numero de valores da sequencia de Fibonacci a serem acumulados: ");
    scanf("%d", &n);

    fibonacciPilha(&pilha, n);

    printf("Sequencia: \n");
    print(&pilha);

    return 0;
}
