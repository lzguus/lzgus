#include <stdio.h>

int main(){
int f;
int suporte;


printf("Boa tarde! Selecione a opcao de atendimento wue voce deseja:\n (1) Valor do saldo de ligacoes\t (2)Seu saldo de internet\t (3) Suporte tecnico\n");
scanf("%d", &f);

switch (f){
case 1:
printf("Seu saldo de ligacoes eh de ****");

return 0;

case 2: 

printf("Seu saldo de internet eh de ****");

return 0;

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
    

    
