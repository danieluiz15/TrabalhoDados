#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Date;

typedef struct Processo
{
    char *id_processo;
    char *numero_sigilo;
    char *sigla_grau;
    char *procedimento;
    char *ramo_justica;
    char *sigla_tribunal;
    int id_tribunal;
    int recurso;
    int id_ultimo_oj;
    char *id_ultima_classe;
    Date dt_recebimento;
    int flag_violencia_domestica;
    int flag_feminicidio;
    int flag_ambiental;
    int flag_quilombolas;
    int flag_indigenas;
    int flag_infancia;
    char *decisao;
    Date dt_resolvido;
    int cnm1;
    int primeirasentm1;
    int baixm1;
    int decm1;
    int mpum1;
    int julgadom1;
    int desm1;
    int susm1;
} Processo;

int contarProcessos(const char *filename);
int buscarIdUltimoOJ(const char *filename, const char *id_processo);
char *processoMaisAntigo(const char *filename);
int converterDataParaDias(const Date *data);
int calcularDiasEntreDatas(const char *filename, const char *id_processo);
double calcularMeta1(const char *filename);
int contarViolenciaDomestica(const char *filename);
int contarFeminicidio(const char *filename);
int contarProcessosAmbientais(const char *filename);
int contarProcessosQuilombolas(const char *filename);
int contarProcessosIndigenas(const char *filename);
int contarProcessosInfancia(const char *filename);
int gerarCSVjulgados(const char *inputFilename, const char *outputFilename);

#endif