#include <stdio.h>
#include <stdlib.h>

#define size 20

typedef struct Node { /*Estrutura de controle dos nós da lista*/
    int element;
    struct Node* next;
}node;

node* createlist(int element) { /*Criação dos nós da lista*/
    node *new_node = (node*) malloc(sizeof(node));
    new_node->element = element;
    new_node->next = NULL;
    return new_node;
}

node* beggin(node *head, int element) { /*Função que adiciona um elemento no inicio da lista*/
    node *new_node = createlist(element);
    new_node->next = head;
    return new_node;
}

node* end(node *head, int element) { /*Função que adiciona um elemento no final da lista*/
    node *new_node = createlist(element);
    if(head->next == NULL) { /*Caso o próximo nó após a cabeça seja o final da lista, ele adiciona um novo nó após a cabeça*/
        head->next = new_node;
        return head;
    }
    node *last = head->next;
    while(last->next != NULL) { /*Caminha na lista levando o novo nó para o final*/
        last = last->next;
    }
    last->next = new_node;
    return head;
}

node* read() { /*Função que lê os valores das listas e os torna em nós*/
    int n, i;
    scanf("%d", &n);
    node *head = createlist(n);
    for(i = 0; i < size; i++) {
        scanf("%d", &n);
        head = end(head, n);
    }
    return head;
}

node* emptylist() { /*Cria a lista vazia para lista de inserção*/
    return NULL;
}

short list_search(node *head, int search) { /*Função que busca um elemento em uma lista*/
    while(head != NULL) {
        if(search = head->element) {
            return 1;
        }
    }
    return 0;
}

node* delete(node *head, int element) { /*Deleta os elementos iguais da lista*/
    if(head->element == element) {
        node *temp = head->next;
        free(head);
        if(temp != NULL) {
            temp = delete(temp, element);
        }
        return temp;
    }
    if(head->next != NULL) {
        head->next = delete(head->next, element);
    }
    return head;
}

node* ordenation(node *head, int element) { /*Ordenação de lista encadeada*/
    if(head == NULL) {
        return createlist(element);
    }
    if(head->element > element) {
        head = beggin(head, element);
        return head;
    }
    node *temp = head;
    while(temp->next != NULL) {
        if(temp->next->element > element) { /*Se o elemento for menor que o da lista atual*/
            node *new_node = beggin(temp->next, element);
            temp->next = new_node;
            return head;
        }
        temp = temp->next;
    }
    return end(head, element);
}

node* intersection(node *l1, node *l2) {
    node *list1 = l1;
    node *list2 = l2;
    node *inter = emptylist(); /*Criação da lista de interseção*/
    while(list1 != NULL) { /*Laço de verificação de todos os elementos da lista*/
        while(list2 != NULL) {
            if(list_search(list2, list1->element)) { /*Se o elemento da lista1 estiver na lista2 ele adiciona na lista de interseção e apaga o elemento da segunda lista*/
                inter = ordenation(inter, list1->element);
                list2 = delete(list2, list1->element);
            }
            list2 = list2->next;
        }
        list2 = l2;
        list1 = list1->next;
    }
    return inter;
}

void display(node *head) { /*Função para imprimir os valores da lista*/
    if(head == NULL) {
        printf("VAZIO");
        return;
    }
    printf("%d\n", head->element);
    if(head->next == NULL) {
        return;
    }
    display(head->next);
}

int main() {
    node *list1, *list2, *new_list;
    list1 = read(); /*Ler os elementos da lista 1*/
    list2 = read(); /*Ler os elementos da lista 2*/
    new_list = intersection(list1, list2);
    display(new_list);
    return 0;
}