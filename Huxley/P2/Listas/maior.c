#include <stdio.h> 
#include <stdlib.h>

typedef struct Node { /*Nó da lista*/
    int item;
    struct Node *next;
}node;

node* create_list() { /*Criação da cabeça da lista*/
    return NULL;
}

node* add(node* head, int item) { /*Função que adiciona um novo nó começo da lista*/
    node *new_node = (node*) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = head;
    return new_node;
}

void print(node* head) { /*Função que printa uma lista encadeada*/
    while(head != NULL) {
        printf("%d\n", head->item);
        head = head->next;
    }
    return;
}

int divide(node *head, int num) {
    int i;
    
}

int main() {
    node* list = create_list(); /*Criação da lista encadeada*/

    int aux;
    
    while(1) { /*Função que vai ler a entrada do programa, caso contenha apenas um 0 o laço para*/
        scanf("%d", &aux);
        if(aux == 0) break;
        divide(list, aux);
    }

    print(list);
    return 0;
}

/*
A cabeça da lista vai receber num % 10 e depois rola o laço com a calda num/10 
toda vez que adicionar um 0, contador++, se o valor for 1 ou o contrário
se outro zero for adicionado um novo contador c2 vai ser adicionado++ e depois comparar com o ultimo c1
*/

/*
    Verificar a entrada como string, e depois separar convertendo para inteiro
*/