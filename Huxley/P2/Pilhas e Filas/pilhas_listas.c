#include <stdio.h>
#include <stdlib.h>

typedef struct NODE { /*Estrutura de lista encadeada*/
    int item;
    struct NODE *next;
}Node;
typedef Node* node;

typedef struct STACK { /*Estrutura de pilhas*/
    node lista;
    struct STACK *next;
}Stack;
typedef Stack* stack;

/*Funções das listas encadeadas*/
node createnode(int item) { /*Criação dos nós da lista encadeada*/
    node new_node = (node) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;
    return new_node;
}

node push_end(node head, node aux, int item) { /*Função para adicionar itens no final de uma lista encadeada*/
    node new_node = createnode(item);
    if(head == NULL) {
        return new_node;
    }
    if(aux->next == NULL) {
        aux->next = new_node;
        return head;
    }
    free(new_node);
    push_end(head, aux->next, item);
}

node read() {
    char space;
    int n;
    node list = NULL;
    do {
        scanf("%d", &n);
        list = push_end(list, list, n);
        scanf("%c", &space);
    }while(space != '\n');
    return list;
}
/*-------------------------------------------------------------------------*/

/*Funções de pilhas*/
stack createstack() { /*Criação da pilha*/
    stack new_stack = (stack) malloc(sizeof(stack));
    new_stack->lista = NULL;
    new_stack->next = NULL;
    return new_stack;
}

stack push(stack pilha, node lista) { /*Função para adicionar uma lista ao topo da lista*/
    stack new_stack = createstack();
    new_stack->lista = lista;
    new_stack->next = pilha;
    return new_stack;
}

stack pop(stack pilha) { /*Função que remove o topo de uma pilha*/
    if(pilha == NULL) {
        printf("EMPTY STACK\n");
        return NULL;
    }
    node new_stack = pilha->next;
    return new_stack;
}
/*------------------------------------------------------------------------*/

/*Funções principais*/
void display(stack pilha) { /*Função para imprimir o topo da pilha*/
    while(pilha->lista->next != NULL) {
        printf("%d ", pilha->lista->item);
        pilha->lista = pilha->lista->next;
    }
    printf("%d", pilha->lista->item);
    return;
}

void stacks() { /*Função pra ler todas as entradas*/
    char input[4];
    stack pilha = NULL;
    while(scanf("%s", input) != EOF) {
        if(strcmp(input, "PUSH") == 0) {
            pilha = push(pilha, read());
        } else if(strcmp(input, "POP") == 0) {
            if(pilha != NULL) {
                display(pilha);
                printf("\n");
            }
            pilha = pop(pilha);
        }
    }
}

int main() {
    stacks();
    return 0;
}