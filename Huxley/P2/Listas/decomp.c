#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

typedef struct NODE {
    int item;
    struct NODE *next;
}Node;
typedef Node* node;

node createlist() { /*Criação da lista vazia*/
    return NULL;
}

node createnode(int item) { /*Criação dos nós da lista*/
    node new_node = (node) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;
    return new_node;
}

node end(node head, int item) { /*Adicionar um elemento no final da lista*/
    node new_node = createnode(item);
    if(head->next == NULL) {
        head->next = new_node;
        return head;
    }
    free(new_node);
    end(head->next, item);
}

node beggin(node head, int item) { /*Adiciona um item no começo da lista*/
    node new_node = createnode(item);
    new_node->next = head;
    return new_node;
}

bool searchlist(node head, int chosen) { /*Função que retorna se um elemento pertence a lista*/
    while(head != NULL) {
        if(head->item == chosen) return true;
        head = head->next;
    }
    return false;
}
/*Funções que envolvem as listas*/

void display(node head) { /*Função que mostra os valores na tela*/
   if(head == NULL) return;
   printf("%d ", head->item);
   display(head->next);
   return;
}

node base_prime(node head) { /*Função que pega o máximo de números primos possível*/
    int i, j, k = 0;
    int count = 0;
    for(i = 1000; i >= 1; i--) {
        for(j = 2; j < i/2; j++) {
            if(i % j == 0) {
                count++;
                break;
            }
        }
        if(count > 0) {
            count = 0;
        } else {
            head = beggin(head, i);
        }
    }
    return head;
}

void decomp(node head) {
    int n, count = 0;
    node divisor = createlist();
    node expoente = createlist();
    scanf("%d", &n);
    while(n > 1 || n == 0 || n < 0) {
        if(n % head->item == 0) {
            divisor = beggin(divisor, head->item);
            count++;
            n /= head->item;
        } else {
            if(count > 0) {
                expoente = beggin(expoente, count);
                count = 0;
                expoente = expoente->next;
            }
        }
        head = head->next;
    }
    printf("Divisores = ");
    display(divisor);
    printf("\n Expoentes = ");
    display(expoente);
    return;
}


int main() {
    node list = createlist();
    decomp(list);
    return 0;
}