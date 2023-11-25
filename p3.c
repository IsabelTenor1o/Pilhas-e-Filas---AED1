#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char tamanho[MAX];
    int topo;
} Pilha;

//mesma função do exercicio pilha 1
void criarPilha(Pilha *p) {
    p->topo = -1;
}

//mesma função do exercicio pilha 1
int isEmpty(Pilha p) {
    return (p.topo == -1);

}
//função modificada para facilitar resolução do problema
//além de add um elemento a lista ela armazena qual foi o elemento
void push(Pilha *p, char elemento) {
    if (p-> topo == MAX - 1) {
        //verifica se a pilha está cheia
        printf("A pilha está cheia!\n");

    } else {
        p-> topo++;
        //++ no topo para indicar a nova posição
        p-> tamanho[p-> topo] = elemento;
        //armazena o caractere na posição correspondente do topo da pilha
    }
}

//mesma função do exercicio pilha 1
int pop(Pilha *p) {
    if (isEmpty(*p))
        return 0;
    p->topo--;
    // Decrementa o topo para indicar a nova posição do topo da pilha
    return 1;
}
//verifica se o par de símbolos corresponde corretamente
//compara esses dois símbolos para determinar se eles formam um par
int ParIgual(char abertura, char fechamento) {
    if (abertura == '(' && fechamento == ')')
        return 1;
    //parênteses
    if (abertura == '[' && fechamento == ']')
        return 1;
    //colchetes
    if (abertura == '{' && fechamento == '}')
        return 1;
    //chaves
    return 0;
    // Retorna 0 se os símbolos não corresponderem
}

//agora sim, verificar balanceamento
int Balanceado(char *conta) {
    Pilha pilha;
    criarPilha(&pilha);
    //criar uma nova pilha

    int i;
    for (i = 0; conta[i] != '\0'; i++) {
    //´percorrer a string que foi passada
        if (conta[i] == '(' || conta[i] == '[' || conta[i] == '{') {
            //caso o char seja igual a um um parentes, colchetes ou chaves que abre
            push(&pilha, conta[i]);
            // empilha na pilha
        } else if (conta[i] == ')' || conta[i] == ']' || conta[i] == '}') {
             //caso o char seja igual a um um parentes, colchetes ou chaves que feche
            if (isEmpty(pilha) || !ParIgual(pilha.tamanho[pilha.topo], conta[i])) {
                return 0;
                //caso encontre um parentese, colchetes ou chaves de fechamento
                //verifica se a pilha está vazia ou se o símbolo de fechamento não corresponde ao que ta no topo
                //caso a pilha estiver vazia OU não corresponderem,indica desbalanceamento
            } else {
                pop(&pilha);
                // Se correspondem pop para remover o último símbolo de abertura empilhado
            }
        }
    }

    return isEmpty(pilha);
    // Verifica se a pilha está vazia
    // Se estiver vazia, indica que os símbolos estão bem balanceados e retorna 1
    // Caso contrário, indica que há símbolos desbalanceados e retorna 0
}

int main() {
    char expressao[MAX];

    printf("Digite a conta que deseja avaliar: ");
   fgets(expressao, MAX, stdin);
   //ler uma linha de entrada do usuário e armazena em expressao
    expressao[strcspn(expressao, "\n")] = '\0';
    // Encontra o índice do primeiro caractere de nova linha ('\n') na string 'expressao' usando a função 'strcspn'
    // e substitui esse caractere por um caractere nulo ('\0') para marcar o final da string

    if (Balanceado(expressao)) {
        printf("ESTA BALANCEADO!\n");
    } else {
        printf("NAO ESTA BALANCEADO\n");
    }
    // Verifica se a expressão está bem balanceada e exibe a mensagem correspondente

    return 0;
}
