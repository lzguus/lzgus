#include <stdio.h>
#include <stdlib.h>

void imprimir_lista(const char* nome, int lista[], int n) {
    printf("%s: ", nome);
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}
int main() {
    int L[] = {2, 21, 10, 5, 13, 18, 11, 1, 9, 26};
    int x = 10;
    int y = 20;
    int n = sizeof(L) / sizeof(L[0]);

    printf("Lista Original:\n");
    imprimir_lista("L", L, n);
    
    int L_aux[n];
    int index_aux = 0; 
    
    for (int i = 0; i < n; i++) {
        if (L[i] < x) {
            L_aux[index_aux] = L[i];
            index_aux++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (L[i] >= x && L[i] <= y) {
            L_aux[index_aux] = L[i];
            index_aux++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (L[i] > y) {
            L_aux[index_aux] = L[i];
            index_aux++;
        }
    }
    for (int i = 0; i < n; i++) {
        L[i] = L_aux[i];
    }
    printf("\nLista apos a separacao com x=%d e y=%d:\n", x, y);
    imprimir_lista("L", L, n);

    return 0;
}