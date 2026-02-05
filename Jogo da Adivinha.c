#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int numero_certo, tentativa = 0;
    srand(time(NULL)); 
    numero_certo = rand() % 11; 

    printf("Tente adivinhar o numero entre 0 e 10, se voce quiser desistir de adivinhar, digite -1.\n");

  while (1) {
        printf("Digite sua tentativa: ");
        scanf("%d", &tentativa);

        if (tentativa < 0 || tentativa > 10) {
            if (tentativa < 0) {
                printf("Voce desistiu do jogo. O numero era %d.\n", numero_certo);
                break;
            }
            continue;
        }

        if (tentativa == numero_certo) {
            printf("Parabens! Voce acertou o numero!\n");
            break;
        } else if (tentativa < numero_certo) {
            printf("O numero eh maior que %d, tente novamente.\n", tentativa);
        } else {
            printf("O numero eh menor que %d, tente novamente.\n", tentativa);
        }
    }

    return 0;
}