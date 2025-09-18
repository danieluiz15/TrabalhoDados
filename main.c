#include "processo.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    const char* arquivoCsv = "TJDFT_amostra.csv";
    int total_processos = contarProcessos(arquivoCsv);

    if (total_processos >= 0) {
        printf("Total de processos no arquivo: %d\n", total_processos);
    } else {
        printf("Não foi possível contar os processos.\n");
    }

    return 0;
}  

