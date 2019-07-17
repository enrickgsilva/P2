#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE {
    int item;
    struct NODE *next;
}Node;
typedef Node* node;

node createnode(int item) { /*Função para criar o nó das listas*/
    node new_node = (node) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;
    return new_node;
}

node beggin(node head, int item) { /*Função para adicionar os elementos no inicio da lista*/
    node new_node = createnode(item);
    new_node->next = head;
    return new_node;
}

node read(int size) { /*Função para ler a lista*/
    int n, i;
    scanf("%d", &n);
    node head = createnode(n);
    for(i = 0; i < size-1; i++) {
        scanf("%d", &n);
        head = beggin(head, n);
    }
    return head;
}

bool search(node head, int chosen) { /*Função para procurar elemento na lista*/
    while(head != NULL) {
        if(head->item == chosen) {
            return true;
        }
        head = head->next;
    }
    return false;
}

node delete(node head, int item) { /*Função pra deletar elementos que já foram buscados da lista*/
    node previous = NULL;
    node current = head;
    while(current != NULL && current->item != item) {
        previous = current;
        current = current->next;
    }
    if(current == NULL) {
        return head;
    }
    if(previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    return head;
}

void verify(node list1, node list2, int tam) {
    node aux1 = list1;
    node aux2 = list2;
    int contador = 0;
    while(aux2 != NULL) {
        while(aux1 != NULL) {
            if(search(aux1, aux2->item)) {
                contador++;
                if(contador == tam) {
                    printf("1\n");
                    return;
                } else {
                    list1 = delete(list1, aux2->item);
                }
            }
            aux1 = aux1->next;
        }
        aux1 = list1;
        aux2 = aux2->next;
    }
    if(contador != tam) {
        printf("0\n");
    }
    return;
}

node createlist() {
    return NULL;
}

int main() {
    int n, m;
    node list1, list2;
    scanf("%d", &n);
    list1 = read(n);
    scanf("%d", &m);
    list2 = read(m);
    if(m > n) {
        printf("0\n");
        return 0;
    }
    verify(list1, list2, m);
    return 0;
}