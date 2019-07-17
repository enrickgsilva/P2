#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int item;
    struct NODE *next;
}Node;
typedef Node* node;

node createnode(int item) { /*Função para criar um nó na lista*/
    node new_node = (node) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;
    return new_node;
}

node beggin(node head, int item) { /*Função que adiciona um elemento no inicio da lista*/
    node new_node = createnode(item);
    new_node->next = head;
    return new_node;
}

node end(node head, int item) { /*Adiciona um elemento no final da lista*/
    node new_node = createnode(item);
    if(head->next == NULL) {
        head->next = new_node;
        return head;
    }
    node aux = head->next;
    while(aux->next == NULL) {
        aux = aux->next;
    }
    aux->next = new_node;
    return head;
}

node createlist() { /*criação da lista vazia*/;
    return NULL;
}

/*node ordenation(node head, int item) {
    if(head == NULL) {
        return createnode(item);
    }
    if(head->item > item) {
        head = beggin(head, item);
        return head;
    }
    node temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->item > item)
        {
            node new_node = beggin(temp->next, item);
            temp->next = new_node;
            return head;
        }
        temp = temp->next;
    }
    return end(head, item);
}*/


node read() { /*Função que lê a entrada até o final do arquivo*/
    int n;
    scanf("%d", &n);
    node head = createnode(n);
    while(1) {
        scanf("%d", &n);
        if(n == -1) break;
        head = end(head, n);
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
    display(list);
    return 0;
}