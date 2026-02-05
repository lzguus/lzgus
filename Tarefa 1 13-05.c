#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
   int i, num;
   int maior, menor;

    printf("Digite 10 numeros inteiros positivos:\n");

    for (i=0; i<10; i++){
        printf("Numero %d: ", i + 1);
        scanf("%d", &num);
        
        if (i == 0) {

                menor = maior = num;
            } else {
                if (num > maior) {
                    maior = num;
                }
                if (num < menor) {
                    menor = num;
                }
        }
    }
printf("O maior numero e: %d\n", maior);
printf("O menor numero e: %d\n", menor);

    return 0;
}
