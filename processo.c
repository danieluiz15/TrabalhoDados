#include "processo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarProcessos(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    int contador = 0;
    char buffer[200];
    char linha[1024];

    fgets(linha, sizeof(linha), fp); // Lê o cabeçalho
    fscanf(fp, "%s", buffer);

    // Supondo que cada linha do arquivo representa um processo
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        contador++;
    }

    fclose(fp);
    return contador;
}

