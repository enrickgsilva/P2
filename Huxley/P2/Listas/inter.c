#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int item;
    struct NODE *next;
}Node;
typedef Node* node;

node createnode(int item) { /*Cria e retorna um novo nó*/
    node new_node = (node) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;
    return new_node;
}

node beggin(node head, int item) { /*Adiciona um valor ao inicio da lista*/
    node new_node = createnode(item);
    new_node->next = head;
    return new_node;
}

node end(node head, int item) { /*Adiciona elemento no final de uma lista*/
    node new_node = (node) malloc(sizeof(node));
    if(head->next == NULL) {
        head->next = new_node;
        return head;
    }
    node aux = head->next;
    while(aux->next != NULL) {
        aux = aux->next;
    }
    aux->next = new_node;
    return head;
}

node ordenation(node head, int item) {
    if(head == NULL) {
        return createnode(item);
    }
    if(head->item > item) {
        head = beggin(head, item);
        return head;
    }
    node aux = head;
    while(aux->next != NULL) {
        if(aux->next->item > item) {
            node new_node = beggin(aux->next, item);
            aux->next = new_node;
            return head;
        }
        aux = aux->next;
    }
    return end(head, item);
}

node del(node head, int item) {
    if(head->item == item) {
        node aux = head->next;
        free(head);
        if(aux != NULL) {
            aux = del(aux, item);
        }
        return aux;
    }
    if(head->next != NULL) {
        head->next = del(head->next, item);
    }
    return head;
}

short list_search(node head, int chosen) {
    while(head != NULL) {
        if(head->item == chosen) return 1;
        head = head->next;
    }
    return 0;
}

node read(int size) { /*Função pra ler os itens das listas*/
    int n, i;
    scanf("%d", &n);
    node head = createnode(n);
    for(i = 0; i < size-1; i++) {
        scanf("%d", &n);
        head = end(head, n);
    }
    return head;
}

void display(node head) {
    if(head == NULL) {
        printf("VAZIO\n");
        return;
    }
    printf("%d\n", head->item);
    if(head->next == NULL) return;
    display(head->next);
}

node intersection(node lista1, node lista2) {
    node l1 = lista1;
    node l2 = lista2;
    node inter = NULL;
    while (l1 != NULL) {
        while (l2 != NULL) {
            if (list_search(l2, l1->item)) {
                inter = ordenation(inter, l1->item);
                lista2 = del(lista2, l1->item);
            }
            l2 = l2->next;
        }
        l2 = lista2;
        l1 = l1->next;
    }
    return inter;
}

int main() {
#define quantidade 3
    node l1, l2, new_list;
    l1 = read(quantidade);
    l2 = read(quantidade);
    new_list = intersection(l1, l2);
    display(new_list);
}