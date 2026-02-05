#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>  
#include <ctype.h>   
#include <time.h>    
#include "funcoes.h" 


typedef struct {
    char nome[100];     
    char cpf[15];        
    char data[11];       
    char hora[6];        
    char tipo_de_quarto[20]; 
} Cadastro;

typedef enum {
    QUARTO_SIMPLES = 1, 
    QUARTO_DUPLO,       
    SUITE               
} TipoQuarto;

typedef struct reserva {
    Cadastro hospede;           
    TipoQuarto tipoQuarto;      
    char checkin[11];           
    char checkout[11];          
    int status;                 
    struct reserva* proxima;    
} Reserva;


/**
 * @brief 
 
 
  @param dataStr A string contendo a data no formato "DD/MM/AAAA".
  @param dataTm Um ponteiro para o struct tm onde os dados da data serão armazenados.
 */
void stringParaData(const char* dataStr, struct tm* dataTm) {
    int dia, mes, ano;
    
    sscanf(dataStr, "%2d/%2d/%4d", &dia, &mes, &ano);

    
    dataTm->tm_mday = dia;
    dataTm->tm_mon = mes - 1;
    dataTm->tm_year = ano - 1900;
    dataTm->tm_hour = 0;   
    dataTm->tm_min = 0;    
    dataTm->tm_sec = 0;    
    dataTm->tm_isdst = -1; 
}



int main() {
    int opcao; 

    
    
    
    system("mkdir \"Hotel_BGM\"");

    
    while (1) {
        
        printf("============================================\n");
        printf("           BEM-VINDO AO HOTEL BGM        \n");
        printf("============================================\n\n");
        printf("1. Fazer reserva   2. Cancelar reserva   3. Sair\n"); 
        printf("\nEscolha uma opcao: ");
        char buffer_opcao[10];
        fgets(buffer_opcao, sizeof(buffer_opcao), stdin);
        opcao = atoi(buffer_opcao);    
        getchar();              

        

        if (opcao == 1) {
            
            
            do {
                FILE *hotel; 
                Cadastro armazenamento; 

                
                
                hotel = fopen("Hotel_BGM\\Lista_de_hospedagem.txt", "a");
                if (hotel == NULL) {
                    
                    printf("Erro: O arquivo nao pode ser aberto. Verifique as permissoes ou o caminho.\n");
                    exit(1); 
                }

                
                printf("\n--- Nova Reserva ---\n");
                printf("Para darmos inicio ao seu processo de hospedagem, insira os dados abaixo:\n");

                
                printf("Seu nome completo: ");
                
                
                fgets(armazenamento.nome, sizeof(armazenamento.nome), stdin);
                armazenamento.nome[strcspn(armazenamento.nome, "\n")] = 0;

                
                do {
                    printf("Digite seu CPF (somente numeros, 11 digitos): ");
                    fgets(armazenamento.cpf, sizeof(armazenamento.cpf), stdin);
                    armazenamento.cpf[strcspn(armazenamento.cpf, "\n")] = 0; 
                    if (!validarCPF(armazenamento.cpf)) {
                        printf("CPF invalido. Por favor, tente novamente.\n");
                    }
                } while (!validarCPF(armazenamento.cpf)); 

                
                printf("Escolha o tipo de quarto: (1)Simples (2)Duplo (3)Luxo:\n");
                fgets(armazenamento.tipo_de_quarto, sizeof(armazenamento.tipo_de_quarto), stdin);
                armazenamento.tipo_de_quarto[strcspn(armazenamento.tipo_de_quarto, "\n")] = 0;

                
                int data_checkin_valida;
                do {
                    printf("Data de check-in (DD/MM/AAAA):\n");
                    fgets(armazenamento.data, sizeof(armazenamento.data), stdin);
                    armazenamento.data[strcspn(armazenamento.data, "\n")] = 0; 
                    
                    data_checkin_valida = validarData(armazenamento.data);

                    if (!data_checkin_valida) {
                        printf("Data de check-in invalida ou em formato incorreto. Tente novamente.\n");
                    }
                } while (!data_checkin_valida);  

                
                char data_checkout[11]; 
                int data_valida;
               do {
                 printf("Data de check-out (DD/MM/AAAA): ");
                fgets(data_checkout, sizeof(data_checkout), stdin);
                data_checkout[strcspn(data_checkout, "\n")] = 0; 

                data_valida = validarData(data_checkout);

                if (!data_valida) {
                printf("Data de check-out invalida ou em formato incorreto. Tente novamente.\n");
                 }
                } while (!data_valida);  

                
                int valor_quarto = 0; 

                
                
                if (strcmp(armazenamento.tipo_de_quarto, "1") == 0) {
                    valor_quarto = 100;
                    strcpy(armazenamento.tipo_de_quarto, "Simples");
                } else if (strcmp(armazenamento.tipo_de_quarto, "2") == 0) {
                    valor_quarto = 200;
                    strcpy(armazenamento.tipo_de_quarto, "Duplo");
                } else if (strcmp(armazenamento.tipo_de_quarto, "3") == 0) {
                    valor_quarto = 300;
                    strcpy(armazenamento.tipo_de_quarto, "Luxo"); 
                } else {
                    
                    printf("Erro: Tipo de quarto invalido. Por favor, escolha 1, 2 ou 3.\n");
                    fclose(hotel); 
                    continue;      
                }

                printf("Reserva realizada com sucesso!\n");

                
                struct tm data_checkin_tm;
                struct tm data_checkout_tm;
                stringParaData(armazenamento.data, &data_checkin_tm); 
                stringParaData(data_checkout, &data_checkout_tm);

                
                time_t time_checkin = mktime(&data_checkin_tm);
                time_t time_checkout = mktime(&data_checkout_tm);

                
                
                double diferenca_segundos = difftime(time_checkout, time_checkin);
                
                int numero_diarias = (int)(diferenca_segundos / (60.0 * 60.0 * 24.0));
                if (numero_diarias == 0 && diferenca_segundos > 0) { 
                    numero_diarias = 1; 
                } else if (diferenca_segundos <= 0) { 
                    printf("Erro: Data de check-out deve ser posterior a data de check-in.\n");
                    fclose(hotel);
                    continue; 
                }

                
                double valor_total = valor_quarto * numero_diarias;
                printf("Numero de diarias: %d\n", numero_diarias);
                printf("Valor total da reserva: R$ %.2f\n", valor_total);

                
                fprintf(hotel, "Nome: %s\nCPF: %s\nCheck-in: %s\nCheck-out: %s\nTipo de quarto: %s\nValor Total: R$ %.2f\n------------------------------\n\n",
                        armazenamento.nome,
                        armazenamento.cpf,
                        armazenamento.data,      
                        data_checkout,           
                        armazenamento.tipo_de_quarto,
                        valor_total);            

                fclose(hotel); 
                break; 
            } while (1); 

        } else if (opcao == 2) {
            
            
            char cpf_para_cancelar[15]; 

            printf("\n--- Cancelamento de Reserva ---\n");
            printf("Digite o CPF do hospede para cancelar a reserva: ");
            fgets(cpf_para_cancelar, sizeof(cpf_para_cancelar), stdin);
            cpf_para_cancelar[strcspn(cpf_para_cancelar, "\n")] = 0; 

            
            FILE *arquivo_original = fopen("Hotel_BGM\\Lista_de_hospedagem.txt", "r");
            FILE *arquivo_temp = fopen("Hotel_BGM\\temp.txt", "w");

            if (arquivo_original == NULL || arquivo_temp == NULL) {
                
                printf("Erro ao acessar os arquivos. Verifique as permissoes ou se o arquivo de reservas existe.\n");
                
                if (arquivo_original) fclose(arquivo_original);
                if (arquivo_temp) fclose(arquivo_temp);
                exit(1); 
            }

            char linha[200];         
            int excluir_bloco = 0;   
            int encontrado = 0;      
            char buffer_nome[200] = ""; 
            char buffer_cpf[200] = "";  

            
            while (fgets(linha, sizeof(linha), arquivo_original)) {
                
                if (strncmp(linha, "Nome: ", 6) == 0) {
                    strcpy(buffer_nome, linha); 
                    
                    if (fgets(buffer_cpf, sizeof(buffer_cpf), arquivo_original)) {
                        
                        if (strncmp(buffer_cpf, "CPF: ", 5) == 0 && strstr(buffer_cpf, cpf_para_cancelar)) {
                            excluir_bloco = 1; 
                            encontrado = 1;    
                        } else {
                            excluir_bloco = 0; 
                        }
                        
                        if (!excluir_bloco) {
                            fputs(buffer_nome, arquivo_temp);
                            fputs(buffer_cpf, arquivo_temp);
                        }
                        continue; 
                    }
                }
                
                if (!excluir_bloco) {
                    fputs(linha, arquivo_temp);
                }
                
                if (strstr(linha, "------------------------------")) {
                    excluir_bloco = 0; 
                }
            }

            
            fclose(arquivo_original);
            fclose(arquivo_temp);

            
            remove("Hotel_BGM\\Lista_de_hospedagem.txt"); 
            rename("Hotel_BGM\\temp.txt", "Hotel_BGM\\Lista_de_hospedagem.txt"); 

            if (encontrado) {
                printf("Reserva com CPF %s cancelada com sucesso.\n", cpf_para_cancelar);
            } else {
                printf("Nenhuma reserva encontrada com o CPF %s.\n", cpf_para_cancelar);
            }

        } else if (opcao == 3) {
            
            printf("Saindo do Sistema de Reservas do Hotel BGM. Ate mais!\n");
            break; 
        } else {
            printf("Opcao invalida. Por favor, escolha 1, 2 ou 3.\n");
        }
    }

        return 0; 
    }

    