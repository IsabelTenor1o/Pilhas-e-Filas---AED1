#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char tamanho[MAX];
    int topo;
} Pilha;

//mesma fun��o do exercicio pilha 1
void criarPilha(Pilha *p) {
    p->topo = -1;
}

//mesma fun��o do exercicio pilha 1
int isEmpty(Pilha p) {
    return (p.topo == -1);

}
//fun��o modificada para facilitar resolu��o do problema
//al�m de add um elemento a lista ela armazena qual foi o elemento
void push(Pilha *p, char elemento) {
    if (p-> topo == MAX - 1) {
        //verifica se a pilha est� cheia
        printf("A pilha est� cheia!\n");

    } else {
        p-> topo++;
        //++ no topo para indicar a nova posi��o
        p-> tamanho[p-> topo] = elemento;
        //armazena o caractere na posi��o correspondente do topo da pilha
    }
}

//mesma fun��o do exercicio pilha 1
int pop(Pilha *p) {
    if (isEmpty(*p))
        return 0;
    p->topo--;
    // Decrementa o topo para indicar a nova posi��o do topo da pilha
    return 1;
}
//verifica se o par de s�mbolos corresponde corretamente
//compara esses dois s�mbolos para determinar se eles formam um par
int ParIgual(char abertura, char fechamento) {
    if (abertura == '(' && fechamento == ')')
        return 1;
    //par�nteses
    if (abertura == '[' && fechamento == ']')
        return 1;
    //colchetes
    if (abertura == '{' && fechamento == '}')
        return 1;
    //chaves
    return 0;
    // Retorna 0 se os s�mbolos n�o corresponderem
}

//agora sim, verificar balanceamento
int Balanceado(char *conta) {
    Pilha pilha;
    criarPilha(&pilha);
    //criar uma nova pilha

    int i;
    for (i = 0; conta[i] != '\0'; i++) {
    //�percorrer a string que foi passada
        if (conta[i] == '(' || conta[i] == '[' || conta[i] == '{') {
            //caso o char seja igual a um um parentes, colchetes ou chaves que abre
            push(&pilha, conta[i]);
            // empilha na pilha
        } else if (conta[i] == ')' || conta[i] == ']' || conta[i] == '}') {
             //caso o char seja igual a um um parentes, colchetes ou chaves que feche
            if (isEmpty(pilha) || !ParIgual(pilha.tamanho[pilha.topo], conta[i])) {
                return 0;
                //caso encontre um parentese, colchetes ou chaves de fechamento
                //verifica se a pilha est� vazia ou se o s�mbolo de fechamento n�o corresponde ao que ta no topo
                //caso a pilha estiver vazia OU n�o corresponderem,indica desbalanceamento
            } else {
                pop(&pilha);
                // Se correspondem pop para remover o �ltimo s�mbolo de abertura empilhado
            }
        }
    }

    return isEmpty(pilha);
    // Verifica se a pilha est� vazia
    // Se estiver vazia, indica que os s�mbolos est�o bem balanceados e retorna 1
    // Caso contr�rio, indica que h� s�mbolos desbalanceados e retorna 0
}

int main() {
    char expressao[MAX];

    printf("Digite a conta que deseja avaliar: ");
   fgets(expressao, MAX, stdin);
   //ler uma linha de entrada do usu�rio e armazena em expressao
    expressao[strcspn(expressao, "\n")] = '\0';
    // Encontra o �ndice do primeiro caractere de nova linha ('\n') na string 'expressao' usando a fun��o 'strcspn'
    // e substitui esse caractere por um caractere nulo ('\0') para marcar o final da string

    if (Balanceado(expressao)) {
        printf("ESTA BALANCEADO!\n");
    } else {
        printf("NAO ESTA BALANCEADO\n");
    }
    // Verifica se a express�o est� bem balanceada e exibe a mensagem correspondente

    return 0;
}
