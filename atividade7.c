#include <stdio.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void imprimir_lista(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void bubbleSort(int arr[], int n) {
    int i, j;
    int trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = 0;

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
                trocou = 1;
            }
        }
        if (trocou == 0) {
            break;
        }
    }
}
int main() {
    int L[] = {25, 17, 19, 4, 31, 8, 18, 27, 14, 6};
    int n = sizeof(L) / sizeof(L[0]);

    printf("Lista original: \n");
    imprimir_lista(L, n);

    bubbleSort(L, n);

    printf("\nLista ordenada com Bubble Sort: \n");
    imprimir_lista(L, n);

    return 0;
}