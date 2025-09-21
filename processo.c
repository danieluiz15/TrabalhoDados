#include "processo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------------------
// Item 1 - Contar Processos
// -------------------------

int contarProcessos(const char* filename) { // Funcao 1 para contar processos
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    int contador = 0;
    char buffer[200];
    char linha[1024];

    fgets(linha, sizeof(linha), fp); 
    fscanf(fp, "%s", buffer);

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        contador++;
    }

    fclose(fp);
    return contador;
}


// ---------------------------------------------
// Item 2 - Buscar id_ultimo_oj pelo id_processo
// ---------------------------------------------

int buscarIdUltimoOJ(const char* filename, const char* id_processo) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    char linha[4096];
    fgets(linha, sizeof(linha), fp); // pula cabeçalho

    while (fgets(linha, sizeof(linha), fp)) {
        char copia[4096];
        strcpy(copia, linha);

        char *token = strtok(copia, ";"); // primeira coluna = id_processo
        if (token != NULL && strcmp(token, id_processo) == 0) {
            int coluna = 0;
            while (token != NULL) {
                if (coluna == 8) { // coluna 9 = id_ultimo_oj
                    fclose(fp);
                    return atoi(token);
                }
                token = strtok(NULL, ";");
                coluna++;
            }
        }
    }

    fclose(fp);
    return -1; // não encontrado
}


// ------------------------------------------------------
// Item 3 - id_processo com a data de recebimento mais antiga
// ------------------------------------------------------

char* processoMaisAntigo(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    static char id_antigo[100];
    char linha[4096];
    fgets(linha, sizeof(linha), fp); // pula cabeçalho

    int menorAno = 9999, menorMes = 12, menorDia = 31;

    while (fgets(linha, sizeof(linha), fp)) {
        char copia[4096];
        strcpy(copia, linha);

        char *token = strtok(copia, ";");
        char id[100];
        strcpy(id, token);

        int coluna = 0;
        int dia, mes, ano;

        while (token != NULL) {
            if (coluna == 9) { // coluna 10 = dt_recebimento
                sscanf(token, "%d-%d-%d", &ano, &mes, &dia);

                if (ano < menorAno ||
                   (ano == menorAno && mes < menorMes) ||
                   (ano == menorAno && mes == menorMes && dia < menorDia)) {
                    menorAno = ano;
                    menorMes = mes;
                    menorDia = dia;
                    strcpy(id_antigo, id);
                }
            }
            token = strtok(NULL, ";");
            coluna++;
        }
    }

    fclose(fp);
    return id_antigo;
}

// Item 6 - Contar processos relacionados a causas ambientais

int contarProcessosAmbientais(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    char linha[4096];
    fgets(linha, sizeof(linha), fp); 
    
    int contador_ambientais = 0;

    while (fgets(linha, sizeof(linha), fp)) {
        char copia[4096];
        strcpy(copia, linha);

        char *token = strtok(copia, ";");
        int coluna = 0;

        while (token != NULL) {
            if (coluna == 13) { 
                if (atoi(token) == 1) {
                    contador_ambientais++;
                }
                break;
            }
            token = strtok(NULL, ";");
            coluna++;
        }
    }

    fclose(fp);
    return contador_ambientais;
}

// Item 7 - Contar processos relacionados a causas de quilombolas

int contarProcessosQuilombolas(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    char linha[4096];
    fgets(linha, sizeof(linha), fp); 
    
    int contador_quilombolas = 0;

    while (fgets(linha, sizeof(linha), fp)) {
        char copia[4096];
        strcpy(copia, linha);

        char *token = strtok(copia, ";");
        int coluna = 0;

        while (token != NULL) {
            if (coluna == 14) { 
                if (atoi(token) == 1) {
                    contador_quilombolas++;
                }
                break;
            }
            token = strtok(NULL, ";");
            coluna++;
        }
    }

    fclose(fp);
    return contador_quilombolas;
}

// ========================================
// NOVAS FUNÇÕES - Itens 8 e 9
// ========================================

// Item 8 - Contar processos relacionados a causas indígenas
int contarProcessosIndigenas(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    char linha[4096];
    fgets(linha, sizeof(linha), fp); // Pula o cabeçalho
    
    int contador_indigenas = 0;

    while (fgets(linha, sizeof(linha), fp)) {
        char copia[4096];
        strcpy(copia, linha);

        char *token = strtok(copia, ";");
        int coluna = 0;

        while (token != NULL) {
            if (coluna == 15) { // flag_indigenas está na coluna 15 (16ª coluna)
                if (atoi(token) == 1) {
                    contador_indigenas++;
                }
                break;
            }
            token = strtok(NULL, ";");
            coluna++;
        }
    }

    fclose(fp);
    return contador_indigenas;
}

// Item 9 - Contar processos relacionados a infância e juventude
int contarProcessosInfancia(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    char linha[4096];
    fgets(linha, sizeof(linha), fp); // Pula o cabeçalho
    
    int contador_infancia = 0;

    while (fgets(linha, sizeof(linha), fp)) {
        char copia[4096];
        strcpy(copia, linha);

        char *token = strtok(copia, ";");
        int coluna = 0;

        while (token != NULL) {
            if (coluna == 16) { // flag_infancia está na coluna 16 (17ª coluna)
                if (atoi(token) == 1) {
                    contador_infancia++;
                }
                break;
            }
            token = strtok(NULL, ";");
            coluna++;
        }
    }

    fclose(fp);
    return contador_infancia;
}

// ========================================
// FUNÇÕES EXISTENTES (continuação)
// ========================================

int converterDataParaDias(const Date* data) { // Função auxiliar para converter data em dias (parte da 10 função)
    return data->ano * 365 + data->mes * 30 + data->dia;
}

int calcularDiasEntreDatas(const char *filename, const char *id_processo) { // Funcao 10 para calcular dias entre datas
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    char linha[2048]; // As linhas deverao ser ajustadas no final do codigo
    fgets(linha, sizeof(linha), fp); // Lê o cabeçalho

    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char *token;
        char copiaLinha[2048];
        strcpy(copiaLinha, linha);

        token = strtok(copiaLinha, ",");
        if (token != NULL && strcmp(token, id_processo) == 0) {
            int coluna = 0;
            while (token != NULL && coluna < 9){
                token = strtok(NULL, ",");
                coluna++;
            }
            
            char dt_recebimento[20] = "";
            char dt_resolvido[20] = "";
            
            if (token != NULL) {
                strcpy(dt_recebimento, token);
            }

            while (token != NULL && coluna < 18){
                token = strtok(NULL, ",");
                coluna++;
            }

            if (token != NULL) {
                strcpy(dt_resolvido, token);
            }

            fclose(fp);

            if (strlen(dt_recebimento) == 0 || strlen(dt_resolvido) == 0) {
                return -1; // Datas inválidas
            }

            int dias1 = converterDataParaDias(dt_recebimento);
            int dias2 = converterDataParaDias(dt_resolvido);

            if(dias1 == -1 || dias2 == -1) {
                return -1; // Erro na conversão das datas
            }

            return dias2 - dias1;
        }
    }
}

int stringParaInt(const char *texto) { // Função auxiliar para converter string para int
    if(texto == NULL || strlen(texto) == 0 || texto[0] == '\n') 
        return 0; // Retorna 0 para strings nulas ou vazias
    return atoi(texto);
}

double calcularMeta1(const char *filename) { // Funcao 11 para calcular a meta 1
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1.0;
    }

    char linha[4096];
    fgets(linha, sizeof(linha), fp); 

    int soma_cnm1 = 0;
    int soma_julgado = 0;
    int soma_desm1 = 0;
    int soma_susm1 = 0;

    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char *token;
        char copiaLinha[4096];
        strcpy(copiaLinha, linha);

        int coluna = 0;
        token = strtok(copiaLinha, ",");

        while (token != NULL) {
            if (coluna == 19) { // Coluna cnm1
                soma_cnm1 += stringParaInt(token);
            } else if (coluna == 24) { // Coluna julgadom1
                soma_julgado += stringParaInt(token);
            } else if (coluna == 26) { // Coluna desm1
                soma_desm1 += stringParaInt(token);
            } else if (coluna == 27) { // Coluna susm1
                soma_susm1 += stringParaInt(token);
            }
            token = strtok(NULL, ",");
            coluna++;
        }
    }

    fclose(fp);

    int divisor = soma_cnm1 + soma_desm1 - soma_susm1;
    if(divisor == 0) {
        return -1.0; // Evita divisão por zero
    }

    return ((double)soma_julgado / divisor) * 100.0;
}