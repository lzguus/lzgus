#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int L[] = {9, 19, 3, 27, 12, 6, 7, 11, 16, 24};
    int k = 30;
    int n = sizeof(L) / sizeof(L[0]);

    qsort(L, n, sizeof(int), comparar);

    int esquerda = 0;
    int direita = n - 1;
    int encontrou_par = 0;

    while (esquerda < direita) {
        int soma = L[esquerda] + L[direita];

        if (soma == k) {
            printf("Par encontrado: (%d, %d)\n", L[esquerda], L[direita]);
            encontrou_par = 1;
            break;
        } else if (soma < k) {
            esquerda++;
        } else {
            direita--;
        }
    }

    if (encontrou_par == 0) {
        printf("Nenhum par com soma igual a %d foi encontrado.\n", k);
    }
    return 0;
}