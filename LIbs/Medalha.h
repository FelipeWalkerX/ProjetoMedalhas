#ifndef MEDALHA_H
#define MEDALHA_H

typedef struct {
    int codigo;
    char genero;
    char modalidade[50];
    char cidade[50];
    int ano;
    char tipoMedalha;
    char nomeAtleta[50];
    char paisOrigem[50];
    char resultado[50];
} Medalha;

void inserirMedalha(Medalha **medalhas, int *total, Medalha novaMedalha);
void listarMedalhas(Medalha *medalhas, int tamanho);
void carregarDadosCSV(Medalha **medalhas, int *total, const char *filename);
void salvarDadosBinario(Medalha *medalhas, int total, const char *filename);
void carregarDadosBinario(Medalha **medalhas, int *total, const char *filename);
void pesquisarMedalha(Medalha *medalhas, int total); 
void alterarMedalha(Medalha *medalhas, int total); 
void excluirMedalha(Medalha **medalhas, int *total); 

#endif // MEDALHA_H
