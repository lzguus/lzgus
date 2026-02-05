#include <stdio.h>

int main() {
    int L[] = {17, 5, 11, 23, 10, 1, 8, 15, 6, 19};
    int n = sizeof(L) / sizeof(L[0]);

    long long contagem_inversoes = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (L[i] > L[j]) {
                contagem_inversoes++;
            }
        }
    }
    printf("Solucao Forca Bruta:\n");
    printf("O numero total de inversoes e: %lld\n", contagem_inversoes);

    return 0;
}