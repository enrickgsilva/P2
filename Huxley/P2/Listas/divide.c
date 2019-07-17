#include <stdio.h>
#include <stdlib.h>

int divide(int n) {
    return (n % 10);
}

int main() {
    int n, aux;
    scanf("%d", &n);
    printf("%d\n", aux = divide(n));
    return 0;
}