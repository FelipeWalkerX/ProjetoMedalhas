#include <stdio.h>
#include <windows.h>

int main() {

    // Frequencia das notas
    int Ab = 209, AbG = 419, Db = 280, E = 333, Eb = 314, A = 444;

    //
    int melodiaPegandoMedalha[] = {Ab, Db, AbG, AbG, AbG, E, A, Eb, Eb}; 
    int duracaoPegandoMedalha[] = {500, 400, 450, 450, 300, 300, 400, 450, 450}; 


    int tamanhoMelodiaMedalha = sizeof(melodiaPegandoMedalha) / sizeof(melodiaPegandoMedalha[0]);
    for (int i = 0; i < tamanhoMelodiaMedalha; i++) {
        Beep(melodiaPegandoMedalha[i], duracaoPegandoMedalha[i]);
    }




    return 0;
}
