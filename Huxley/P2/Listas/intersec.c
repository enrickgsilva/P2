#include <stdio.h>
#include <stdlib.h>

#define size 5

void display(int *vet, int c) { /*Função que imprime os valores do array final*/
    int i;
    printf("\nNOVO ARRAY!\n");
    for(i = 0; i < c; i ++) {
        printf("%d\n", vet[i]);
    }
    return;
}

void swap(int *v1, int *v2) { /*Função que faz as trocas dos valores*/
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
    
    return;
}

void bubble(int *vet, int c) { /*Algorítimo de ordenação*/
    int i, j;
    for(j = c-1; j >= 0; j--) {
        for(i = 0; i < j; i++) {
            if(vet[i] > vet[j]) {
                swap(&vet[i], &vet[i+1]);
            }
        }
    }
    return;
}

void inicializar(int *v) { /*Inicializa um array*/
    int i;
    for(i = 0; i < size; i++) {
        v[i] = -100;
    }
    return;
}

void intersection(int *v1, int *v2) { /*Algorítimo que pega a interseção entre dois arrays*/
    int i, j, k; int c = 0, l = 0;
    int new_vetor[size];
    inicializar(new_vetor);
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if(v1[i] == v2[j]) { /*Verificação da interseção*/
                for(k = 0; k < size; k++) { /*Verifica se o número está repetido no array*/
                    if(v1[i] == new_vetor[k]) {
                        l++;
                    }
                }
                 if(l == 0) {
                        new_vetor[c] = v1[i];
                        c++;
                 }
            }
        }
        l = 0;
    }

    if(c == 0) {
        printf("VAZIO\n");
        return;
    } else {
        bubble(new_vetor, c);
    }
    display(new_vetor, c);
    return;
}

void ler(int *vet) { /*Função que lê os valores do array*/
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &vet[i]);
    }
    return;
}

int main() {
    int vetor1[size];
    int vetor2[size];
    ler(vetor1); /*Ler os números do primeiro vetor*/
    ler(vetor2); /*Ler os números do segundo vetor*/
    intersection(vetor1, vetor2);
    return 0;
}