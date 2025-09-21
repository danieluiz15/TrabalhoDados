#include "processo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char* arquivoCsv = "TJDFT_amostra.csv";

    // Item 1 - Número de processos
    int total_processos = contarProcessos(arquivoCsv);
    if (total_processos >= 0) {
        printf("1) Total de processos no arquivo: %d\n", total_processos);
    } else {
        printf("1) Não foi possível contar os processos.\n");
    }

    // Item 2 - id_ultimo_oj a partir de id_processo
    char idBuscado[50] = "323961063";
    int ultimoOJ = buscarIdUltimoOJ(arquivoCsv, idBuscado);
    if (ultimoOJ != -1) {
        printf("2) id_ultimo_oj do processo %s: %d\n", idBuscado, ultimoOJ);
    } else {
        printf("2) Processo %s não encontrado.\n", idBuscado);
    }

    // Item 3 - Processo mais antigo
    char* maisAntigo = processoMaisAntigo(arquivoCsv);
    if (maisAntigo != NULL) {
        printf("3) Processo mais antigo: %s\n", maisAntigo);
    } else {
        printf("3) Não foi possível encontrar o processo mais antigo.\n");
    }

    // Item 6 - Processos ambientais
    int ambientais = contarProcessosAmbientais(arquivoCsv);
    if (ambientais >= 0) {
        printf("6) Processos relacionados a causas ambientais: %d\n", ambientais);
    } else {
        printf("6) Não foi possível contar processos ambientais.\n");
    }

    // Item 7 - Processos quilombolas
    int quilombolas = contarProcessosQuilombolas(arquivoCsv);
    if (quilombolas >= 0) {
        printf("7) Processos relacionados a causas quilombolas: %d\n", quilombolas);
    } else {
        printf("7) Não foi possível contar processos quilombolas.\n");
    }

    // Item 8 - Processos indígenas
    int indigenas = contarProcessosIndigenas(arquivoCsv);
    if (indigenas >= 0) {
        printf("8) Processos relacionados a causas indígenas: %d\n", indigenas);
    } else {
        printf("8) Não foi possível contar processos indígenas.\n");
    }

    // Item 9 - Processos de infância e juventude
    int infancia = contarProcessosInfancia(arquivoCsv);
    if (infancia >= 0) {
        printf("9) Processos relacionados a infância e juventude: %d\n", infancia);
    } else {
        printf("9) Não foi possível contar processos de infância e juventude.\n");
    }

    // Item 10 - Dias entre datas
    int dias = calcularDiasEntreDatas(arquivoCsv, idBuscado);
    if (dias >= 0) {
        printf("10) O processo %s levou %d dias entre recebimento e resolucao.\n", idBuscado, dias);
    } else {
        printf("10) Não foi possível calcular os dias entre as datas.\n");
    }

    // Item 11 - Meta 1
    double percentual = calcularMeta1(arquivoCsv);
    if (percentual >= 0) {
        printf("11) Percentual da Meta 1: %.2f%%\n", percentual);
    } else {
        printf("11) Não foi possível calcular o percentual da Meta 1.\n");
    }

    return 0;
}