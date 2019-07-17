#include <stdio.h>
#include <math.h>
#include <limits.h>

void contaprimos() {
    int i, j, c;
    for (i = 1; i < INT_MAX; i++){
        c = 0;
        for (j = 2; j < sqrt(i) / 2; j++){
            if (i % j == 0){
                printf("%d\n", i);
                break;
            }
        }
    }
}

int main() {
   contaprimos();
   return 0;
}