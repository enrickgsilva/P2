#include <stdio.h>
#include <stdlib.h>
#define MAX 101

typedef struct HEAP {
    int tamanho;
    int itens[MAX];
} heap;

heap *createheap() {
    heap *new_heap = (heap *)malloc(sizeof(heap));
    new_heap->tamanho = 0;
    return new_heap;
}

int get_left_index(heap *new_heap, int i) {
    return 2 * i;
}

int get_right_index(heap *new_heap, int i) {
    return 2 * i + 1;
}

int item_of(heap *new_heap, int i) {
    return new_heap->itens[i];
}

void swap(int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}

void max_heapify(heap *new_heap, int i) {
    int largest;
    int left_index = get_left_index(new_heap, i);
    int right_index = get_right_index(new_heap, i);
    if (left_index <= new_heap->tamanho && new_heap->itens[left_index] > new_heap->itens[i]) {
        largest = left_index;
    } else {
        largest = i;
    }
    if (right_index <= new_heap->tamanho && new_heap->itens[right_index] > new_heap->itens[largest]) {
        largest = right_index;
    }
    if (new_heap->itens[i] != new_heap->itens[largest]) {
        swap(&new_heap->itens[i], &new_heap->itens[largest]);
        max_heapify(new_heap, largest);
    }
}

void displayheap(heap *new_heap) {
    int i;
    printf("Estado Atual da Heap: ");
    printf("%d", new_heap->itens[1]);
    for (i = 2; i <= new_heap->tamanho; i++) {
        printf(" | %d", new_heap->itens[i]);
    }
    printf("\n");
    if (new_heap->tamanho == 1) {
        return;
    }
    printf("Maior elemento neste passo: %d\n", new_heap->itens[1]);
}

void displayfirst(heap *new_heap) {
    int i;
    printf("%d", new_heap->itens[1]);
    for (i = 2; i <= new_heap->tamanho; i++) {
        printf(" | %d", new_heap->itens[i]);
    }
    printf("\n");
}

void ordenation(heap *new_heap) {
    displayheap(new_heap);
    int i;
    for (i = new_heap->tamanho; i >= 2; i -= 1) {
        swap(&new_heap->itens[1], &new_heap->itens[i]);
        new_heap->tamanho -= 1;
        max_heapify(new_heap, 1);
        displayheap(new_heap);
    }
}

int main() {
    heap *new_heap = createheap();
    int n, i = 1;
    while (scanf("%d", &n) != EOF) {
        new_heap->itens[i] = n;
        new_heap->tamanho += 1;
        i += 1;
    }
    printf("Estado inicial: ");
    displayfirst(new_heap);
    int tam = new_heap->tamanho;
    for (i = new_heap->tamanho; i > 0; i -= 1) {
        max_heapify(new_heap, i);
    }
    ordenation(new_heap);
    printf("Resultado Final: ");
    new_heap->tamanho = tam;
    displayfirst(new_heap);
}
