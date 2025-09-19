#include "processo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    const char* arquivoCsv = "TJDFT_amostra.csv";


    // ----------------------
    // Item 1 - Número de processos
    // ----------------------
    int total_processos = contarProcessos(arquivoCsv); // Funcao 1 

    if (total_processos >= 0) {
        printf("Total de processos no arquivo: %d\n", total_processos);
    } else {
        printf("Não foi possível contar os processos.\n");
    }


    // ----------------------
    // Item 2 - id_ultimo_oj a partir de id_processo
    // ----------------------
    char idBuscado[50] = "323961063"; // Char para buscar o ID do processo usado na funcao 2
    int ultimoOJ = buscarIdUltimoOJ(arquivoCsv, idBuscado);
    if (ultimoOJ != -1) {
        printf("2) id_ultimo_oj do processo %s: %d\n", idBuscado, ultimoOJ);
    } else {
        printf("2) Processo %s não encontrado.\n", idBuscado);
    }


    // ----------------------
    // Item 3 - Processo mais antigo
    // ----------------------
    char* maisAntigo = processoMaisAntigo(arquivoCsv);
    if (maisAntigo != NULL) {
        printf("3) Processo mais antigo: %s\n", maisAntigo);
    } else {
        printf("3) Não foi possível encontrar o processo mais antigo.\n");
    }


    int dias = calcularDiasEntreDatas(arquivoCsv, idBuscado); // Funcao 10 (atualmente nao esta funcionando corretamente sem a funcao 2)
    if (dias >= 0) {
        printf("O processo %s levou %d dias entre recebimento e resolucao.\n", idBuscado, dias);
    } else {
        printf("Não foi possível calcular os dias entre as datas.\n");
    }

    double percentual = calcularMeta1(arquivoCsv); // Funcao 11
    if (percentual >= 0) {
        printf("Percentual da Meta 1: %.2f%%\n", percentual);
    } else {
        printf("Não foi possível calcular o percentual da Meta 1.\n");
    }

    return 0;
}  

