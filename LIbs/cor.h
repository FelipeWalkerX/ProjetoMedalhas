#ifndef COR_H
#define COR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Resetar()
{
    printf("\033[0m");  //volta a cor para branco
}
//colorir o texto
void Ciano(char *Mensagem)
{
    printf("\033[0;36m"); //Printa a mensagem em ciano (\033 serve pra indicar que vai mudar de cor, 0 serve pra falar que vai mudar a cor do texto, 36 é o codigo da cor ciano)
    while (*Mensagem != '\0') //Enquanto o ponteiro para mensagem for 
    {
        printf("%c", *(Mensagem));
        Mensagem++;
    }
    Resetar();  //Reseta pra branco pra nao deixar o texto todo em ciano
}

void Roxo(char *Mensagem)
{
    printf("\033[0;35m");
    while (*Mensagem != '\0')
    {
        printf("%c", *(Mensagem));
        Mensagem++;
    }
    Resetar();
}

void Azul(char *Mensagem)
{
    printf("\033[0;34m");
    while (*Mensagem != '\0')
    {
        printf("%c", *(Mensagem));
        Mensagem++;
    }
    Resetar();
}

void Amarelo(char *Mensagem)
{
    printf("\033[0;33m");
    while (*Mensagem != '\0')
    {
        printf("%c", *(Mensagem));
        Mensagem++;
    }
    Resetar();
}

void Verde(char *Mensagem)
{
    printf("\033[0;32m");
    while (*Mensagem != '\0')
    {
        printf("%c", *(Mensagem));
        Mensagem++;
    }
    Resetar();
}

void Vermelho(char *Mensagem)
{
    printf("\033[0;31m");
    while (*Mensagem != '\0')
    {
        printf("%c", *(Mensagem));
        Mensagem++;
    }
    Resetar();
}


#endif