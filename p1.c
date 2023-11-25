#include <stdio.h>
#include <stdlib.h>
#define MAX 20
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

//aqui ta o main para testes
int main() {
    Pilha pilhaTeste;
    criarPilha(&pilhaTeste);
    PilhaInt valor;

    push(&pilhaTeste, 2002);
    push(&pilhaTeste, 1999);
    push(&pilhaTeste, 18);
    //push para adicionar elementos na pilha

    print(&pilhaTeste);
    //print da lista

    //utilizando a fun��o que retorna o valor que esta no topo sem remover
    int topoAtual;
    //variavel para receber o numero do topo
    topoAtual = top(pilhaTeste, &valor);
    //fun��o top
        if (topoAtual == 1) {
            //verifica se o resultado da fun��o top � igual a 1
            //se for quer dizer q a lista n�o esta vazia
            printf("\nO elemento do topo da pilha eh: %d\n", valor);
            //imprime o valor do numero do topo da pilha
    }       else {
                printf("A pilha esta vazia.\n");
                //caso esteja vazia
}

    int resultado = pop(&pilhaTeste, &valor);
    //chama a fun��o pop
    if (resultado == 1) {
        //se a pilha tem elementos
        printf("Elemento removido: %d\n", valor);
        //mostrra qual foi o elemento removido
        printf("Nova pilha: ");
        //nova pilha sem o elemento
        print(&pilhaTeste);

    } else {
        printf("A pilha esta vazia.\n");
    }
}

