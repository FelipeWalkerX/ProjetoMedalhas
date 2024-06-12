#include <stdio.h>
#include <stdlib.h>
#include "medalha.h"

void exibirMenu() {
    printf("1. Inserir medalha\n");
    printf("2. Listar medalhas\n");
    printf("3. Pesquisar medalha\n");
    printf("4. Alterar medalha\n");
    printf("5. Excluir medalha\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Medalha *medalhas = NULL;
    int totalMedalhas = 0;
    const char *csvFilename = "medalhas.csv";
    const char *binFilename = "medalhas.bin";
    

    // Carregar arquivo binário
    carregarDadosBinario(&medalhas, &totalMedalhas, binFilename);

    // Carregar arquivo csv
    carregarDadosCSV(&medalhas, &totalMedalhas, csvFilename);

    // Exibir mensagem de boas-vindas
    printf("Bem-vindo ao sistema de gerenciamento de medalhas!\n");

    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: {
                Medalha novaMedalha;
                printf("\nGenero (m/w): ");
                scanf(" %c", &novaMedalha.genero);
                printf("\nModalidade: ");
                scanf("%s", novaMedalha.modalidade);
                printf("\nCidade: ");
                scanf("%s", novaMedalha.cidade);
                setbuf(stdin, NULL);
                printf("\nAno: ");
                scanf("%d", &novaMedalha.ano);
                printf("\nTipo de Medalha (G/B/S): ");
                scanf(" %c", &novaMedalha.tipoMedalha);
                printf("\nNome do Atleta: ");
                scanf("%s", novaMedalha.nomeAtleta);
                printf("\nPais de Origem: ");
                scanf("%s", novaMedalha.paisOrigem);
                printf("\nResultado: ");
                scanf("%s", novaMedalha.resultado);
                inserirMedalha(&medalhas, &totalMedalhas, novaMedalha);
                break;
            }
            case 2:
                listarMedalhas(medalhas, totalMedalhas);
                break;
            case 3:
                pesquisarMedalha(medalhas, totalMedalhas);
                break;
            case 4:
                alterarMedalha(medalhas, totalMedalhas);
                break;
            case 5:
                excluirMedalha(&medalhas, &totalMedalhas);
                break;
            case 0:
                printf("\n\n\nSaindo...\n");
                salvarDadosBinario(medalhas, totalMedalhas, binFilename);
                break;
            default:
                printf("\n\n\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    // Liberar memória
    free(medalhas);

    return 0;
}
