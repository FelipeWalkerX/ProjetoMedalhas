#include "medalha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserirMedalha(Medalha **medalhas, int *total, Medalha novaMedalha) {
    *medalhas = (Medalha *)realloc(*medalhas, (*total + 1) * sizeof(Medalha));
    if (*medalhas == NULL) {
        printf("Erro ao alocar memÃ³ria.\n");
        exit(1);
    }
    novaMedalha.codigo = *total + 1;
    (*medalhas)[*total] = novaMedalha;
    (*total)++;
    printf("Medalha inserida com sucesso!\n");
}

void listarMedalhas(Medalha *medalhas, int tamanho) {
    if (tamanho == 0) {
        printf("Nenhuma medalha cadastrada.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("Codigo: %d\n", medalhas[i].codigo);
        printf("Genero: %c\n", medalhas[i].genero);
        printf("Modalidade: %s\n", medalhas[i].modalidade);
        printf("Cidade: %s\n", medalhas[i].cidade);
        printf("Ano: %d\n", medalhas[i].ano);
        printf("Tipo Medalha: %c\n", medalhas[i].tipoMedalha);
        printf("Nome Atleta: %s\n", medalhas[i].nomeAtleta);
        printf("Pais Origem: %s\n", medalhas[i].paisOrigem);
        printf("Resultado: %s\n", medalhas[i].resultado);
        printf("\n");
    }
}

void carregarDadosCSV(Medalha **medalhas, int *total, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir arquivo CSV");
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), linha)) {
        Medalha novaMedalha;
        sscanf(linha, "%d,%c,%99[^,],%99[^,],%d,%c,%99[^,],%99[^,],%99[^,\n]",
               &novaMedalha.codigo, &novaMedalha.genero, novaMedalha.modalidade, novaMedalha.cidade,
               &novaMedalha.ano, &novaMedalha.tipoMedalha, novaMedalha.nomeAtleta, novaMedalha.paisOrigem, novaMedalha.resultado);

        inserirMedalha(medalhas, total, novaMedalha);
    }

    fclose(file);
}

void salvarDadosBinario(Medalha *medalhas, int total, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Erro ao abrir arquivo binario");
        return;
    }

    fwrite(&total, sizeof(int), 1, file);
    fwrite(medalhas, sizeof(Medalha), total, file);

    fclose(file);
}

void carregarDadosBinario(Medalha **medalhas, int *total, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Erro ao abrir arquivo binario");
        return;
    }

    fread(total, sizeof(int), 1, file);
    *medalhas = malloc(*total * sizeof(Medalha));
    if (*medalhas == NULL) {
        perror("Erro ao alocar memoria");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(*medalhas, sizeof(Medalha), *total, file);

    fclose(file);
}
