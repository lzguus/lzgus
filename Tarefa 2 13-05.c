#include <stdio.h>
#include <stdlib.h> 

int calcular_digito1(int cpf[]) {
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += cpf[i] * (10 - i);
    }
    int resto = (soma * 10) % 11;
    if (resto == 10) return 0;
    return resto;
}

// Funcao para calcular o segundo digito verificador
int calcular_digito2(int cpf[]) {
    int soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += cpf[i] * (11 - i);
    }
    int resto = (soma * 10) % 11;
    if (resto == 10) return 0;
    return resto;
}

int main() {
    char entrada[12];
    int cpf[11];

    printf("Digite os 11 digitos do CPF (somente numeros):\n");
    scanf("%s", entrada);

    for (int i = 0; i < 11; i++) {
        cpf[i] = entrada[i] - '0';
    }

    int d1 = calcular_digito1(cpf);
    int d2 = calcular_digito2(cpf);

    if (d1 == cpf[9] && d2 == cpf[10]) {
        printf("CPF valido!\n");
    } else {
        printf("CPF invalido.\n");
    }

    return 0;
}