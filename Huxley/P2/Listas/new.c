#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE {
    int item;
    struct NODE *next;
}Node; 
typedef Node* node;

node createnode(int item) { /*Criação dos nós da lista*/
    node new_node = (node) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;
    return new_node;
}

node beggin(node head, int item) { /*Adiciona um elemento no inicio da lista*/
    node new_node = createnode(item);
    new_node->next = head;
    return new_node;
}

node end(node head, int item) { /*Adiciona um elemento no final da lista*/
    node new_node = createnode(item);
    if(head->next == NULL) { /*Caso o nó onde next aponta para nulo esteja após a cabeça*/
        head->next = new_node;
        return head;
    }
    node temp = head->next;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node; /*A ultima posição da lista se torna o new_node*/
    return head;
}

node read(int size) { /*Função pra ler todos os valores da lista*/
    int n, i;
    scanf("%d", &n); /*Lê o valor do item da cabeça da lista*/
    node head = createnode(n);
    for(i = 0; i < size-1; i++) {
        scanf("%d", &n);
        head = end(head, n); /*Adiciona sempre o n lido ao final da lista, não alterando o valor da cabeça*/
    }
    return head;
}

void display(node head) { /*Imprime uma lista encadeada*/
    if(head == NULL) {
        printf("VAZIO");
        return;
    }
    while(head != NULL) {
        printf("%d\n", head->item);
        head = head->next;
    }
    return;
}

node create_list() { /*Criação da lista vazia*/
    return NULL;
}

short search(node head, int element) { /*Procura um elemento em uma lista*/
    while(head != NULL) {
        if(head->item == element) {
            return true;
        }
        head = head->next;
    }
    return false;
}

node delete(node head, int item) { /*Apaga o item adicionado em intersection da lista*/
    if(head->item == item) {
        node aux = head->next;
        free(head);
        if(aux != NULL) {
            aux = delete(aux, item);
        }
        return aux;
    }
    if(head->next != NULL) {
        head->next = delete(head->next, item);
    }
    return head;
}

node ordenation(node head, int item) { /*Ordena uma lista  */
    if(head == NULL) return createnode(item);
    if(head->item > item) {
        head = beggin(head, item);
        return head;
    }
    node temp = head;
    while(temp->next != NULL) {
        if(temp->next->item > item) {
            node new_node = beggin(temp->next, item);
            temp->next = new_node;
            return head;
        }
        temp = temp->next;
    }
    return end(head, item);
}

node intersection(node list1, node list2) {
   node aux1 = list1;
   node aux2 = list2;
   node inter = create_list();
   while(aux1 != NULL) {
       while(aux2 != NULL) {
           if(search(aux2, aux1->item)) {
               inter = ordenation(inter, aux1->item);
               list2 = delete(list2, aux1->item);
           }
           aux2 = aux2->next;
       }
        aux2 = list2;
        aux1 = aux1->next;
   }
   return inter;
}

int main() {
    node list1 = create_list();
    node list2 = create_list();
    node new_node = create_list();
    list1 = read(20);
    list2 = read(20);
    new_node = intersection(list1, list2);
    display(new_node);
    return 0;
}