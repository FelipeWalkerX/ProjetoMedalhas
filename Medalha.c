#include "medalha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserirMedalha(Medalha **medalhas, int *total, Medalha novaMedalha) {
    *medalhas = (Medalha *)realloc(*medalhas, (*total + 1) * sizeof(Medalha));
    if (*medalhas == NULL) {
        printf("Erro ao alocar memória.\n");
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
        printf("Código: %d\n", medalhas[i].codigo);
        printf("Gênero: %c\n", medalhas[i].genero);
        printf("Modalidade: %s\n", medalhas[i].modalidade);
        printf("Cidade: %s\n", medalhas[i].cidade);
        printf("Ano: %d\n", medalhas[i].ano);
        printf("Tipo Medalha: %c\n", medalhas[i].tipoMedalha);
        printf("Nome Atleta: %s\n", medalhas[i].nomeAtleta);
        printf("País Origem: %s\n", medalhas[i].paisOrigem);
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

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Medalha novaMedalha;
        sscanf(line, "%c,%49[^,],%49[^,],%d,%c,%49[^,],%49[^,],%49[^,\n]",
               &novaMedalha.genero, novaMedalha.modalidade, novaMedalha.cidade,
               &novaMedalha.ano, &novaMedalha.tipoMedalha, novaMedalha.nomeAtleta,
               novaMedalha.paisOrigem, novaMedalha.resultado);

        inserirMedalha(medalhas, total, novaMedalha);
    }

    fclose(file);
}

void salvarDadosBinario(Medalha *medalhas, int total, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Erro ao abrir arquivo binário");
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

void pesquisarMedalha(Medalha *medalhas, int total) {
    int codigo;
    printf("Digite o codigo da medalha que deseja pesquisar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total; i++) {
        if (medalhas[i].codigo == codigo) {
            printf("Medalha encontrada:\n");
            printf("Código: %d\n", medalhas[i].codigo);
            printf("Gênero: %c\n", medalhas[i].genero);
            printf("Modalidade: %s\n", medalhas[i].modalidade);
            printf("Cidade: %s\n", medalhas[i].cidade);
            printf("Ano: %d\n", medalhas[i].ano);
            printf("Tipo Medalha: %c\n", medalhas[i].tipoMedalha);
            printf("Nome Atleta: %s\n", medalhas[i].nomeAtleta);
            printf("País Origem: %s\n", medalhas[i].paisOrigem);
            printf("Resultado: %s\n", medalhas[i].resultado);
            return;
        }
    }

    printf("Medalha não encontrada.\n");
}

void alterarMedalha(Medalha *medalhas, int total) {
    int codigo;
    printf("Digite o codigo da medalha que deseja alterar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total; i++) {
        if (medalhas[i].codigo == codigo) {
            printf("Medalha encontrada. Digite os novos dados:\n");
            printf("\nGenero (m/w): ");
            scanf(" %c", &medalhas[i].genero);
            printf("\nModalidade: ");
            scanf("%s", medalhas[i].modalidade);
            printf("\nCidade: ");
            scanf("%s", medalhas[i].cidade);
            printf("\nAno: ");
            scanf("%d", &medalhas[i].ano);
            printf("\nTipo de Medalha (G/B/S): ");
            scanf(" %c", &medalhas[i].tipoMedalha);
            printf("\nNome do Atleta: ");
            scanf("%s", medalhas[i].nomeAtleta);
            printf("\nPais de Origem: ");
            scanf("%s", medalhas[i].paisOrigem);
            printf("\nResultado: ");
            scanf("%s", medalhas[i].resultado);
            printf("Medalha alterada com sucesso!\n");
            return;
        }
    }

    printf("Medalha nao encontrada.\n");
}

void excluirMedalha(Medalha **medalhas, int *total) {
    int codigo;
    printf("Digite o código da medalha que deseja excluir: ");
    scanf("%d", &codigo);

    for (int i = 0; i < *total; i++) {
        if ((*medalhas)[i].codigo == codigo) {
            for (int j = i; j < *total - 1; j++) {
                (*medalhas)[j] = (*medalhas)[j + 1];
            }
            (*total)--;
            *medalhas = (Medalha *)realloc(*medalhas, *total * sizeof(Medalha));
            if (*medalhas == NULL && *total > 0) {
                printf("Erro ao realocar memória.\n");
                exit(1);
            }
            printf("Medalha excluída com sucesso!\n");
            return;
        }
    }

    printf("Medalha não encontrada.\n");
}

