#ifndef MEDALHA_H
#define MEDALHA_H

typedef struct {
    int codigo;
    char genero;
    char modalidade[100];
    char cidade[100];
    int ano;
    char tipo_medalha;
    char nome_atleta[100];
    char pais_origem[100];
    char resultado[100];
}Medalha;

void inserirMedalha(Medalha** medalhas, int* tamanho, Medalha novaMedalha);
void listarMedalhas(Medalha* medalhas, int tamanho);
void pesquisarMedalha(Medalha *medalhas, int tamanho);
void alterarMedalha(Medalha *medalhas, int tamanho);
void excluirMedalha(Medalha **medalhas, int *tamanho);


#endif /* MEDALHA_H */
