#include <stdio.h>
#include <stdlib.h> 

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void imprimir_lista(const char* nome, int lista[], int n) {
    printf("%s: ", nome);
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int U[] = {9, 19, 3, 26, 12, 7, 18, 23, 14, 10};
    int W[] = {11, 7, 8, 16, 21, 2, 4, 28, 15, 24};
    
    int n = sizeof(U) / sizeof(U[0]);
    
    int tamanho_junto = 2 * n;
    int junto[tamanho_junto];
    
    for (int i = 0; i < n; i++) {
        junto[i] = U[i];
        junto[i + n] = W[i];
    }
    
    qsort(junto, tamanho_junto, sizeof(int), comparar);
    
    for (int i = 0; i < n; i++) {
        U[i] = junto[i];             
        W[i] = junto[i + n];         
    }
    
    printf("Listas organizada:\n");
    imprimir_lista("U", U, n);
    imprimir_lista("W", W, n);

    return 0;
}