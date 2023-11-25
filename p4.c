#include <stdio.h>
#include <stdlib.h>
#define MAX 100
//tamanho máximo da pilha

typedef int PilhaInt;
typedef struct {
    PilhaInt tamanho[MAX];
    //  tamanho máximo que é 20
    int topo;
    // Variável inteira que representa o topo da pilha.
    // nome que representará a pilha
} Pilha;

//criar uma pilha, recebendo um ponteiro para uma variável do tipo Pilha
void criarPilha(Pilha *p) {
    p-> topo = -1;
    //indicando que a pilha está vazia
}

//verificar se a pilha está vazia
int isEmpty(Pilha p) {
    return (p.topo == -1);
    //retorna true se o topo for igual a -1, significa que a pilha está vazia, se não retorna false
}

//empilhar (push) um elemento na pilha
void push(Pilha *p, PilhaInt numero) {
    // Verifica se a pilha está cheia
    if (p-> topo == MAX - 1) {
        printf("A pilha esta cheia!");
    } else {
        // Incrementa o topo e adiciona o número na posição correspondente na pilha
        p-> topo++;
        p-> tamanho[p->topo] = numero;
    }
}

//retornar o elemento no topo da pilha (sem remover)
int top(Pilha pilha, PilhaInt *numero) {
    if (pilha.topo == -1) {
        return 0;
        //caso o topo for igual a -1, a pilha está vazia como definido anteriormente
    }
    *numero = pilha.tamanho[pilha.topo];
    //o valor do topo da pilha é armazenado ao valor
    return 1; }


//pop (remover o topo) pq em pilha ultimo a entrar é o primeiro a sair
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
        //´percorre a pilha do topo até o índice 0, imprimindo cada elemento entre colchetes.
    }
}
void fibonacciPilha(Pilha *p, int num) {
    //caso seja 0 ou menor nao tem pilha
    if (num <= 0)
        return 0;

    //os primeiros valores da sequencia igual 0 e igual 1
    //representam os dois últimos valores calculados na sequência
    int fib1 = 0;
    int fib2 = 1;

    //empilhando o valor fib1 na pilha
    push(p, fib1);
    //-- o valor do numero em 1, pq colocamos na pilha
    num--;

    //para saber se o numero já chegou em zero
    //se nao, push novamente para empilhar o valor fib2 na pilha
    if (num > 0)
        push(p, fib2);

    //enquanto ainda tiver valor em numero
    while (num > 1) {
        //o próximo valor da sequência é obtido somando os valores de fib1 e fib2
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
