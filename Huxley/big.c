#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char cpf[10];
    while(1) {
        gets(cpf);
        if (strcmp(cpf, 0)) {
            printf("O programa acabou\n");
            return 0;
        }
        int conv = atoi(cpf);
        printf("\n%d", conv);
    }
    return 0;
}