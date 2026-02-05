#include <stdio.h>

int main(){
int f;
int suporte;

//Menu onde o usuario escolhe a tabuada que deseja ver
printf("Boa tarde! Selecione a opcao de atendimento wue voce deseja:\n (1) Valor do saldo de ligacoes\t (2)Seu saldo de internet\t (3) Suporte tecnico\n");
scanf("%d", &f);

switch (f){
case 1:
printf("Seu saldo de ligacoes eh de ****");

return 0;

case 2: 

printf("Seu saldo de internet eh de ****");

return 0;
// Caso o usuario escolha a opcao 3, ele podera escolher entre 3 opcoes de suporte tecnico      
    case 3: 
    printf("Boa tarde! Selecione o problema a ser falado com o tecnico:\n (1)Conexao a internet\t (2)Suporte sobre as ligacoes\t (3)Falar com atendente\n");
                scanf("%d", &suporte);

switch (suporte)
{
case 1:
        printf("Siga o seguinte tutorial para conectar-se a internet: ******\n");

    
    break;


case 2: 
        printf("Siga o seguinte tutorial para realizar uma ligacao: ******\n");

        break;

case 3:
        printf("Aguarde um momento para ser atendido por um de nossos tecnicos.");
        return 0;
}
}
    return 0;
    }



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
            pri
        }
        break;
}

}