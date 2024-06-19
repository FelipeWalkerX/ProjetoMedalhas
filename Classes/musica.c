#include <stdio.h>
#include <windows.h>
#include "musica.h"

void tocarMelodia() {

    int Ab = 209, AbG = 419, Db = 280, E = 333, Eb = 314, A = 444;     // Frequencia das notas

    
    int melodia[] = {Ab, Db, AbG, AbG, AbG, E, A, Eb, Eb}; //Melodia da musica
    int duracao[] = {500, 400, 450, 450, 300, 300, 400, 450, 450}; //Tempo de duracao de cada nota


    int tamanhoMelodia = sizeof(melodia) / sizeof(melodia[0]);
    for (int i = 0; i < tamanhoMelodia; i++) {      //enquanto o i for menor que o tamanho da melodia, ele executa o loop
        Beep(melodia[i], duracao[i]);   //beep(nota, duracao da nota)
    }
}


/*Tentado fazer com a musica de moeda do mario simbolizando o ouro, mas saiu as frequencias muito baixas, entao coloquei outra musica

Codigo da musica do mario:

    int Ab = 209, AbG = 419, Db = 280, E = 333, Eb = 314, A = 444, BG = 971, EG = 1397;

    //
    int melodiaPegando[] = {BG, EG, BG, EG, BG, EG, BG, EG, BG, EG, BG, EG}; 
    int duracaoPegando[] = {100, 400, 100, 400, 100, 400, 100, 400, 100, 400, 100, 400}; 
*/