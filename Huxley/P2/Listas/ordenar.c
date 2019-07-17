#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int item;
    struct NODE *next;
}Node;
typedef Node* node;

node createlist() {
    return NULL;
}

node createnode(int item) {
    node new_node = (node) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;
    return new_node;
}

node beggin(node head, int item) {
    node new_node = createnode(item);
    new_node->next = head;
    return new_node;
}

node read(node list) {
    int n;
    node head = createlist();
    while(1) {
        scanf("%d", &n);
        if(n == -1) break;
        head = beggin(head, n);
    }
    return head;
}
node ordena(node head) {
    if(head == NULL) return createlist();
    while(head != NULL) {
        node aux = head->next;
        while(aux->next != NULL) {
            if(head->item > aux->item) {
                node new_node;
                new_node->item = aux->item;
                aux->item = head->item;
                head->item = new_node->item;
            }
            aux = aux->next;
        }
        head = head->next;
    }
    return head;
}
void display(node head) {
    while(head != NULL) {
        printf("%d ", head->item);
        head = head->next;
    }
    return;
}

int main() {
    node list = createlist();
    list = read(list);
    list = ordena(list);
    display(list);
    return 0;
}