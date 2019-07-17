#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE {
    int item;
    struct NODE *next;
}Node;
typedef Node* node;

node createlist() {
    return NULL;
}

node createnode(int item) {
    node new = (node) malloc(sizeof(node));
    new->item = item;
    new->next = NULL;
    return new;
}

node beggin(node head, int item) {
    node new = createnode(item);
    new->next = head;
    return new;
}

node end(node head, node aux, int item) {
    node new_node = createnode(item);
    if(aux == NULL) { /*Caso seja o primeiro item a ser adicionado adiciona no começo*/
        new_node = createnode(item);
        return new_node;
    }
    if(aux->next == NULL) { /*Usando o ponteiro do próximo adiciona no final*/
        aux->next = new_node;
        return head;
    }
    free(new_node);
    end(head, aux->next, item); /*Não alterar o head, pois o head é a referencia da cabeça, inicio da lista*/
}

bool searchlist(node head, int chosen) {
    while(head != NULL) {
        if(head->item == chosen) return true;
        head = head->next;
    }
    return false;
}

void display(node head)  {
    while(head != NULL) {
        printf("%d ", head->item);
        head = head->next;
    }
    return;
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
            node new = beggin(aux->next, item);
            aux->next = new;
            return head;
        }
        aux = aux->next;
    }
    return end(head, head, item);
}

node read() {
    int n;
    scanf("%d", &n);
    node head = createnode(n);
    while(scanf("%d", &n) != EOF) {
        head = ordenation(head, n);
    }
    return head;
}

int main() {
    node list = createlist();
    list = read();
    display(list);
    return 0;
}