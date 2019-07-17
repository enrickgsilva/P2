#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int item;
    struct NODE *next;
}Node; typedef Node* node;


node createnode(int item) { /*Cria um nó em uma lista*/
    node new_node = (node) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;
    return new_node;
}

node createlist() { /*Cria uma lista vazia*/
    return NULL;
}

node beggin(node head, int item) { /*Adiciona um item no inicio de uma lista encadeada*/
    node new_node = createnode(item);
    new_node->item = item;
    new_node->next = head;
    return new_node;
}

node read(int size) { /*Função para ler os valores da lista*/
    int i, n;
    scanf("%d", &n);
    node head = createnode(n);
    for(i = 0; i < size-1; i++) {
        scanf("%d", &n);
        head = beggin(head, n);
    }
    return head;
}

int count(node head) { /*Conta quantos elementos uma lista encadeada possui*/
    int contador = 0;
    while(head != NULL) {
        contador++;
        head = head->next;
    }
    return contador;
}

void display(node head) { /*Função que imprime os valores da lista na tela*/
    while(head != NULL) {
        printf("%d ", head->item);
        head = head->next;
    }
    return;
}

node ordena(node head, int tam) {
    while(head->next != NULL) {
        if(head->item > head->next->item) {
             node aux = head;
             node temp = aux->next->next;
             head = head->next;
             head->next = aux;
             aux->next = temp;
        }
        head = head->next;
    }
   //printf("%d ", head->item);
   //printf("%d ", aux->item);
    return head;
}

int main() {
    #define size 3
    node list = createlist();
    list = read(size);
    int tamanho = count(list);
    list = ordena(list, tamanho);
    display(list);
    return 0;
}