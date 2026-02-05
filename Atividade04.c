#include <stdio.h>
#include <stdlib.h> 

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Funcao para imprimir a lista
void imprimir_lista(const char* nome, int lista[], int n) {
    printf("%s: ", nome);
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int L[12] = {6, 8, 13, 17, 21, 25, 31, 34}; 
    int B[] = {31, 34, 8, 21};
    
    int m = 8; 
    int k = 4; 
    printf("Listas Originais:\n");
    imprimir_lista("L", L, m);
    imprimir_lista("B", B, k);
    
    qsort(B, k, sizeof(int), comparar);

    int ptrWrite = 0; 
    for (int ptrRead = 0; ptrRead < m; ptrRead++) {
        int elemento_atual = L[ptrRead];

        void* encontrado = bsearch(&elemento_atual, B, k, sizeof(int), comparar);
        
        if (encontrado == NULL) {
            L[ptrWrite] = L[ptrRead];
            ptrWrite++;
        }
}
}