#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medalha.h"
#include "musica.h"
#include "cor.h"

void exibirMenu() {
    Roxo("1. Inserir medalha\n");
    Roxo("2. Listar medalhas\n");
    Roxo("3. Pesquisar medalha\n");
    Roxo("4. Alterar medalha\n");
    Roxo("5. Excluir medalha\n");
    Vermelho("0. Sair\n");
    Verde("Escolha uma opcao: ");
}

int main() {
    Medalha *medalhas = NULL;
    Medalha novaMedalha;
    int totalMedalhas = 0;
    const char *csvFilename = "./medalhas.csv";
    const char *binFilename = "./medalhas.bin";
    

    //Carregar arquivo binário
    carregarDadosBinario(&medalhas, &totalMedalhas, binFilename);

    //Carregar arquivo csv
    if(totalMedalhas == 0) { carregarDadosCSV(&medalhas, &totalMedalhas, csvFilename); }

    Ciano("Bem-vindo ao sistema de gerenciamento de medalhas!\n");

    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: {       
                printf("\nGenero (m/w): ");
                fflush(stdin);
                scanf("%c", &novaMedalha.genero);
                printf("\nModalidade: ");
                fflush(stdin);
                fgets(novaMedalha.modalidade, 50, stdin);
                novaMedalha.modalidade[strcspn(novaMedalha.modalidade, "\n")] = '\0';
                fflush(stdin);
                printf("\nCidade: ");
                fgets(novaMedalha.cidade, 50, stdin);
                novaMedalha.cidade[strcspn(novaMedalha.cidade, "\n")] = '\0';
                fflush(stdin);
                printf("\nAno: ");
                scanf("%d", &novaMedalha.ano);
                printf("\nTipo de Medalha (G/B/S): ");
                fflush(stdin);
                novaMedalha.tipoMedalha = fgetc(stdin);
                fflush(stdin);
                printf("\nNome do Atleta: ");
                fgets(novaMedalha.nomeAtleta, 50, stdin);
                novaMedalha.nomeAtleta[strcspn(novaMedalha.nomeAtleta, "\n")] = '\0';
                fflush(stdin);
                printf("\nPaís de Origem: ");
                fgets(novaMedalha.paisOrigem, 50, stdin);
                novaMedalha.paisOrigem[strcspn(novaMedalha.paisOrigem, "\n")] = '\0';
                fflush(stdin);
                printf("\nResultado: ");
                fgets(novaMedalha.resultado, 50, stdin);
                novaMedalha.resultado[strcspn(novaMedalha.resultado, "\n")] = '\0';
                fflush(stdin);

                inserirMedalha(&medalhas, &totalMedalhas, novaMedalha);
                tocarMelodia();
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
                Vermelho("\n\n\nSaindo...\n");
                salvarDadosBinario(medalhas, totalMedalhas, binFilename);
                break;
            default:
                Amarelo("\n\n\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    // Liberar memória
    free(medalhas);

    return 0;
}
