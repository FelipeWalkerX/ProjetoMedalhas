#include "medalha.h"
#include "musica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Tentei colocar o #include "cor.h", mas ele da erro ao compilar

//funcao para inserir medalha
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
//funcao para listar todas as medalhas
void listarMedalhas(Medalha *medalhas, int tamanho) {
    if (tamanho == 0) {
        printf("Nenhuma medalha cadastrada.\n"); //aqui ele ve se tem alguma medalha cadastrada
        return;
    }
    //for para listar todos os dados dos jogadores do csv/bin e os novos que serao cadastrados
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
//funcao para abrir o arquivo csv e cadastrar as novas medalhas
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
//funcao para escrever as coisas do .csv em um .bin
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
//funcao para carregar os dados do arquivo .bin
void carregarDadosBinario(Medalha **medalhas, int *total, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Erro ao abrir arquivo binario"); //Da essa mensagem de erro se nao conseguir abrir o arquivo
        return;
    }

    fread(total, sizeof(int), 1, file);
    *medalhas = malloc(*total * sizeof(Medalha)); //Alocando o mtamanho de uma medalha inteira (com todos seus dados)
    if (*medalhas == NULL) {
        perror("Erro ao alocar memoria");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(*medalhas, sizeof(Medalha), *total, file); //Lendo a medalha pra cada posição alocada

    fclose(file);
}
//funcao para pesquisar medalha
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

    printf("Medalha não encontrada.\n"); //se a medalha nao foi encontrada
}
//funcao para alterar os dados da medalha
void alterarMedalha(Medalha *medalhas, int total) {
    int codigo;
    printf("Digite o codigo da medalha que deseja alterar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total; i++) {
        if (medalhas[i].codigo == codigo) {
            printf("\nGenero (m/w): ");
            fflush(stdin);  //limpar o buffer do teclado
            scanf("%c", &medalhas[i].genero);
            while (getchar() != '\n');  // Limpar buffer do stdin
            
            printf("\nModalidade: ");
            fflush(stdin);
            fgets(medalhas[i].modalidade, 50, stdin);
            medalhas[i].modalidade[strcspn(medalhas[i].modalidade, "\n")] = '\0';
            
            printf("\nCidade: ");
            fflush(stdin);
            fgets(medalhas[i].cidade, 50, stdin);
            medalhas[i].cidade[strcspn(medalhas[i].cidade, "\n")] = '\0';
            
            printf("\nAno: ");
            fflush(stdin);
            scanf("%d", &medalhas[i].ano);
            while (getchar() != '\n');  // Limpar buffer do stdin

            printf("\nTipo de Medalha (G/B/S): ");
            fflush(stdin);
            medalhas[i].tipoMedalha = fgetc(stdin);
            while (getchar() != '\n');  // Limpar buffer do stdin

            printf("\nNome do Atleta: ");
            fflush(stdin);
            fgets(medalhas[i].nomeAtleta, 50, stdin);
            medalhas[i].nomeAtleta[strcspn(medalhas[i].nomeAtleta, "\n")] = '\0';
            
            printf("\nPaís de Origem: ");
            fflush(stdin);
            fgets(medalhas[i].paisOrigem, 50, stdin);
            medalhas[i].paisOrigem[strcspn(medalhas[i].paisOrigem, "\n")] = '\0';
            
            printf("\nResultado: ");
            fflush(stdin); 
            fgets(medalhas[i].resultado, 50, stdin);
            medalhas[i].resultado[strcspn(medalhas[i].resultado, "\n")] = '\0';
            printf("Medalha alterada com sucesso!\n");
            return;
        }
    }

    printf("Medalha nao encontrada.\n");
}
//funcao para excluir uma medalha
void excluirMedalha(Medalha **medalhas, int *total) {
    int codigo;
    printf("Digite o código da medalha que deseja excluir: ");
    scanf("%d", &codigo);

    for (int i = 0; i < *total; i++) {  //Se der tudo certo, ele vem pra ca e gera a mensagem abaixo
        if ((*medalhas)[i].codigo == codigo) {  //para realocar a memoria
            for (int j = i; j < *total - 1; j++) {  //contador para achar a medalha que quero excluir
                (*medalhas)[j] = (*medalhas)[j + 1];
            }
            (*total)--;
            *medalhas = (Medalha *)realloc(*medalhas, *total * sizeof(Medalha));    //Realocar o tamanho da memoria em relacao ao tanto de jogadores que tem, para nao ficar com memoria vazia
            if (*medalhas == NULL && *total > 0) {
                printf("Erro ao realocar memória.\n");
                exit(1);
            }
            printf("Medalha excluída com sucesso!\n");
            return;
        }
    }

    printf("Medalha não encontrada.\n");    //Se nada der certo, fala que nao achou a medalha
}

