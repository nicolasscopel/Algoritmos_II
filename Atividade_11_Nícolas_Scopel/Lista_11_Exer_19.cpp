/*19 - Escreva um programa que preencha dois vetores X e Y com cinco elementos numéricos cada e,
depois, ordene-os de maneira crescente. Deverá ser gerado um terceiro vetor com dez posições,
composto pela junção dos elementos dos vetores anteriores, também ordenado de maneira crescente.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

#define TAM 10;

using namespace std;

void gerar(int *p);
void exibe(int *p);
void ordem(int *p);
void uniao(int *x1, int *x2);

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int *x = new int[5];
    int *y = new int[5];
    int *u = new int [10];

    cout << "Vetor X: [ ";
    gerar(x);
    exibe(x);
    cout << "]" << endl;
    ordem(x);

    cout << "Vetor X ordenado: [ ";
    exibe(x);
    cout << "]" << endl;

    cout << "\nVetor Y: [ ";
    gerar(y);
    exibe(y);
    cout << "]" << endl;
    ordem(y);

    cout << "Vetor X ordenado: [ ";
    exibe(y);
    cout << "]" << endl;

    cout << "\nUnião Ordenada: [";
    uniao(x,y);
    cout << "]";






}

void gerar(int *p)
{
    int *i = new int(0);

    while(*i < 5)
    {
        *p = rand() % 50;
        p++;
        (*i)++;
    }

    p -= *i;
    *i = 0;
}

void exibe(int *p)
{

    int *i = new int(0);


    while(*i < 5)
    {
        cout << *p << " ";
        p++;
        (*i)++;
    }
    p -= *i;
    *i = 0;
}

void ordem(int *p)
{
    int *i = new int(0);
    int *j = new int(0);
    int *aux = new int(0);
    int *prox =  new int(0);



    for(*i = 0; *i < 5; (*i)++)
    {
        for(*j = 0; *j <=4; (*j)++)
        {
            if(p[*i] < p[*j])
            {
                *aux = p[*i];
                p[*i] = p[*j];
                p[*j] = *aux;

            }
        }
    }
}

void uniao(int *x1, int *x2)
{
    int *u =  new int[10];
    int *i =  new int;
    int *j = new int(0);
    int *aux = new int(0);
    int *prox =  new int(0);

    while(*i < 5)
    {
        *u = *x1;
        u++;
        x1++;
        (*i)++;
    }

    x1 -= 5;
    *i = 0;

    while(*i < 5)
    {
        *u = *x2;
        u++;
        x2++;
        (*i)++;
    }

    u -= 10;
    x2 -= 5;
    *i = 0;


    for(*i = 0; *i < 10; (*i)++)
    {
        for(*j = 0; *j <=9; (*j)++)
        {
            if(u[*i] < u[*j])
            {
                *aux = u[*i];
                u[*i] = u[*j];
                u[*j] = *aux;

            }
        }
    }
    *i = 0;

    while(*i < 10)
    {
        cout << *u << " ";
        u++;
        (*i)++;
    }

    u -= *i;
    *i = 0;


}

