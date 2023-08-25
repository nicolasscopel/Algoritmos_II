/*13 - Escrever um programa que gere um vetor V[20] com valores no intervalo de 0 a 100 e mostre os
valores gerados. Modifique o vetor de modo que o primeiro elemento passe para a última posição, e
desloque todos os outros elementos uma posição para a esquerda, conforme o exemplo:
Antes:
12 14 2 7 5 0 10 19 34 52 26 12 53 78 56 32 33 45 44 18
Depois:
14 2 7 5 0 10 19 34 52 26 12 53 78 56 32 33 45 44 18 12*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void gerar(int *p);
void exibe(int *p);
void trocado(int *p);
void exibet(int *p);

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int *pvet = new int[20];


    gerar(pvet);
    exibe(pvet);
    trocado(pvet);
    exibet(pvet);
}

void gerar(int *p)
{
    int *i = new int(0);

    while(*i < 20)
    {
        *p = rand() % 100;
        p++;
        (*i)++;
    }

     p -= *i;
     *i = 0;
}

void exibe(int *p)
{
    int *i = new int(0);
    cout << "Vetor Original: [";

    while(*i < 20)
    {
        cout << *p << " ";
        p++;
        (*i)++;
    }

    cout << "]" << endl;
}
void trocado(int *p)
{
    int *primeiro = new int(0);
    int *segundo = new int(0);
    int *ultimo = new int(0);
    int *i = new int(0);
    int *aux = new int(0);

    primeiro = p;
    *aux = *p;
    segundo = p + 1;
    ultimo = p + 19;

    while(*i < 20)
    {
        *primeiro = *segundo;

        primeiro++;
        segundo++;
        (*i)++;


    }

    *ultimo = *aux;




}
void exibet(int *p)
{
     int *i = new int(0);
    cout << "Vetor Trocado: [";

    while(*i < 20)
    {
        cout << *p << " ";
        p++;
        (*i)++;
    }

    cout << "]" << endl;

}
