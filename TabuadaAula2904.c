#include <stdio.h>

int main(){

//Menu onde o usuario escolhe a tabuada que deseja ver
printf("Escolha a tabuada que deseja ver:\n (1) Tabuada da soma\t (2) Tabuada da subtracao\t (3) Tabuada da multiplicacao\t\n");
int f;
scanf("%d", &f);

switch (f) {

    case 1:
        //Tabuada da soma
        printf("Tabuada da soma:\n");
        for (int i = 0; i <= 10; i++){
            for (int j = 1; j <= 10; j++){
                printf("%d + %d = %d\n", i, j, i + j);
            }
            printf("0 + %d = %d\n", i, 0 + i);
        }
        break;

    case 2:
        //Tabuada da subtracao
        printf("Tabuada da subtracao:\n");
        for (int i = 0; i <= 10; i++){
            for (int j = 1; j <= 10; j++){
                printf("%d - %d = %d\n", i, j, i - j);
            }
            printf("0 - %d = %d\n", i, 0 - i);
        }
        break;

    case 3:
        //Tabuada da multiplicacao
        printf("Tabuada da multiplicacao:\n");
        for (int i = 1; i <= 10; i++){
            for (int j = 1; j <= 10; j++){
                printf("%d * %d = %d\n", i, j, i * j);
            }
            printf("1 * %d = %d\n", i, 1 * i);
        }
        break;
}

}