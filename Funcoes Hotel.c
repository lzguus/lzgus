#include <stdio.h>   // Necessário para funções de I/O, embora não usadas diretamente aqui.
#include <string.h>  // Para strlen() e outras funções de manipulação de string.
#include <ctype.h>   // Para isdigit(), que verifica se um caractere é um dígito.
#include <stdlib.h>  // Para atoi(), que converte string para inteiro.
#include "funcoes.h" // Inclui o cabeçalho onde essas funções são declaradas.

/**
 * @file funcoes.c
 * @brief Este arquivo contém as implementações das funções auxiliares
 * declaradas em 'funcoes.h' para o Sistema de Reservas do Hotel BGM.
 *
 * Aqui estão as lógicas para validação de dados como CPF e datas,
 * que são reutilizadas em diferentes partes do programa principal.
 */

/**
 * @brief Implementação da função para validar um número de CPF.
 *
 * Verifica se o CPF fornecido:
 * 1. Tem exatamente 11 dígitos.
 * 2. É composto apenas por caracteres numéricos.
 *
 * Esta validação é básica e verifica apenas o formato e o tipo de caractere.
 * Validações mais complexas de CPF (dígitos verificadores) não estão incluídas aqui.
 *
 * @param cpf Uma string constante contendo o número de CPF a ser validado.
 * @return Retorna 1 se o CPF atender aos critérios de formato e dígitos, 0 caso contrário.
 */
int validarCPF(const char* cpf) {
    // Verifica se o comprimento da string do CPF é exatamente 11 caracteres.
    if (strlen(cpf) != 11) {
        return 0; // Se não for 11, o CPF é inválido.
    }

    // Itera sobre cada caractere do CPF para garantir que todos sejam dígitos.
    for (int i = 0; i < 11; i++) {
        // isdigit() verifica se o caractere é um dígito (0-9).
        // (unsigned char) é um cast importante para evitar problemas com caracteres não-ASCII
        // e garantir que isdigit() funcione corretamente em todas as plataformas.
        if (!isdigit((unsigned char)cpf[i])) {
            return 0; // Se encontrar qualquer caractere que não seja dígito, o CPF é inválido.
        }
    }
    // Se passou por todas as verificações, o CPF é considerado válido (no que diz respeito ao formato).
    return 1;
}

/**
 * @brief Implementação da função para validar uma string de data.
 *
 * Verifica se a string de data fornecida está no formato "DD/MM/AAAA" e
 * se os caracteres são apropriados (dígitos ou barras).
 *
 * Esta validação é básica e verifica apenas o formato e tipo de caractere.
 * Validações mais profundas (dias válidos para o mês, anos bissextos, etc.)
 * não estão incluídas aqui e seriam implementadas em uma função mais robusta,
 * como a 'validarData' que você já usa no 'main.c' (que deve ser mais completa).
 *
 * @param data Uma string constante contendo a data a ser validada no formato "DD/MM/AAAA".
 * @return Retorna 1 se a data atender ao formato esperado, 0 caso contrário.
 */

int validarData(const char* data) {
    // Verifica se o comprimento da string da data é exatamente 10 caracteres (DD/MM/AAAA).
    if (strlen(data) != 10) {
        return 0;
    }

    // Verifica se as barras estão nas posições corretas
    if (data[2] != '/' || data[5] != '/') {
        return 0;
    }

    // Verifica se todos os outros caracteres são dígitos
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit((unsigned char)data[i])) return 0;
    }

    // Extrai dia, mês e ano como inteiros
    int dia = (data[0] - '0') * 10 + (data[1] - '0');
    int mes = (data[3] - '0') * 10 + (data[4] - '0');
   

    // Valida mês
    if (mes < 1 || mes > 12) return 0;

    // Valida dia (apenas faixa, não o mês correto)
    if (dia < 1 || dia > 31) return 0;

    // Se passou por todas as verificações, a data é considerada válida
    return 1;
}