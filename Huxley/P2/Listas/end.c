#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int item;
    struct NODE *next;
}Node;
typedef Node* node;

node createlist(node head, int item) {
    head->item = item;
    head->next = NULL;
    return head;
}

node createnode(int item) {
    node new_node = (node) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;
    return new_node;
}

node end(node head, int item) {
    node new_node = createnode(item);
    if(head->next == NULL) {
        head->next = new_node;
        return head;
    }
    node aux = head->next;
    while (aux->next == NULL)
    {
        aux = aux->next;
    }
    aux->next = new_node;
    return head;
}

node beggin(node head, int item) {
    node new_node = createnode(item);
    new_node->item = item;
    new_node->next = head;
    return new_node;
}

node read(node head) {
    int n, i;
    for(i = 0; i < 3; i++) {
        scanf("%d", &n);
        if(i > 0) {
            head = end(head, n);
        } else {
            head = beggin(head, n);
        }
    }
    return head;
}

void display(node head) {
    if(head == NULL) return;
    printf("%d ", head->item);
    display(head->next);
    return;
}

int main() {
    node list = createlist(list, 333333);
    list = end(list, 6);
    list = end(list, 9);
    list = end(list, 10);
    list = end(list, 11);
    list = end(list, 119);
    display(list);
    return 0;
}