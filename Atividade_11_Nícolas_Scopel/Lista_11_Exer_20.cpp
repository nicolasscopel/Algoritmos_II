/*20 – Escreva um programa que preencha um vetor A com dez números inteiros entre 1 e 50, a seguir
gere dois vetores: X contendo os valores do vetor A menores que 26 e outro vetor Y com os números
acima de 25. Os vetores X e Y devem ser alocados dinamicamente com a dimensão necessária. Caso o
vetor A não tiver valores para gerar um dos dois vetores X e Y o programa deverá mostrar mensagem
com esta condição.
O programa deverá exibir o vetor A e caso possível X e Y*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void gerar(int *a);
void exibe(int *a);
void operacao(int *a);

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int *a = new int [10];

    cout << "Vetor A: [ ";
    gerar(a);
    exibe(a);
    cout << "] ";
    operacao(a);






}

void gerar(int *a)
{
    int *i = new int;


    while(*i < 10)
    {
        *a = rand() % 50 + 1;
        a++;
        (*i)++;

    }

    a -= *i;
    *i = 0;

}
void exibe(int *a)
{
    int *i = new int;


    while(*i < 10)
    {
        cout << *a << " ";
        a++;
        (*i)++;

    }

    a -= *i;
    *i = 0;

}

void operacao(int *a)
{
    int *contmen = new int(0);
    int *contmai = new int(0);
    int *x = new int;
    int *y = new int;
    int *i = new int;


    while(*i < 10)
    {
        if(*a < 25)
        {
            (*contmen)++;
        }
        else
        {
            (*contmai)++;
        }

        a++;
        (*i)++;

    }
    a -= *i;
    *i = 0;

    x = new int[*contmen];
    y = new int[*contmai];

    while(*i < 10)
    {
        if(*a < 25)
        {
            *x = *a;
            x++;
        }
        else
        {
            *y = *a;
            y++;
        }

        a++;
        (*i)++;

    }
    x -= *contmen;
    y -= *contmai;
    a -= *i;
    *i = 0;

    if(*contmen == 0 )
    {
        cout << "\nNão existem elementos no vetor X!";
    }
    else
    {
        cout << "\nVetor X com valores menores que 26: [";

        while(*i < *contmen)
        {
            cout << *x << " ";
            x++;
            (*i)++;
        }
        cout << "]";

    }


    x -= *contmen;
    *i = 0;

    if(*contmai == 0 )
    {
        cout << "\nNão existem elementos no vetor Y!";
    }
    else
    {
        cout << "\nVetor Y com valores maiores que 25: [";

        while(*i < *contmai)
        {
            cout << *y << " ";
            y++;
            (*i)++;
        }
        cout << "]";
    }



    y -= *contmen;
    *i = 0;






}
