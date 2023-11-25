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



int palindromo(char *frase) {
    //guarda o comprimento da string utilizando a função strlen
    int tamanho = strlen(frase);
    //i = primeiro digito
    int i = 0;
    //j = o ultimo, tamanho - 1 pq i inicia no zero
    int j = tamanho - 1;

    //comparar os caracteres saindo partir das extremidades até o centro
    while (i < j) {
        //converter as letras para minúsculas usando tolower
        char letra1 = tolower(frase[i]);
        char letra2 = tolower(frase[j]);

        //verifica se letra1 não é uma letra
        //se nao for
        //incrementa i em 1 e continua para a próxima iteração do loop usando continue
        if (!isalpha(letra1)) {
            i++;
            continue;
        }
        //mesma coisa do i mas j-- pois j é de tras pra frente
        if (!isalpha(letra2)) {
            j--;
            continue;
        }
        //verificação se é ou nao um palindromo
        if (letra1 != letra2) {
            return 0;
        }

        i++;
        j--;
    }

    return 1;
}


int main() {
    char frase[MAX];
    printf("Digite uma frase: ");
    fgets(frase, MAX, stdin);
    frase[strcspn(frase, "\n")] = '\0';

    if (palindromo(frase)) {
        printf("A frase digitada eh um palindromo.\n");
    } else {
        printf("A frase digitada nao eh um palindromo.\n");
    }

    return 0;
}

