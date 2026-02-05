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
    int L[12] = {3, 8, 12, 15, 20, 23, 31}; 
    int B[] = {26, 19, 5, 9};
    
    int m = 7; 
    int k = 4; 

    printf("Listas Originais:\n");
    imprimir_lista("L", L, m);
    imprimir_lista("B", B, k);
    
    qsort(B, k, sizeof(int), comparar);

    int ptrL = m - 1;          
    int ptrB = k - 1;          
    int ptrInsert = m + k - 1;  

    while (ptrL >= 0 && ptrB >= 0) {
        if (L[ptrL] > B[ptrB]) {
            L[ptrInsert] = L[ptrL];
            ptrL--;
        } else {
            L[ptrInsert] = B[ptrB];
            ptrB--;
        }
        ptrInsert--;
    }