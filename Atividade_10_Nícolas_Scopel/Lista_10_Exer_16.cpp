/*16 - Faça um programa que preencha dois vetores de dez elementos inteiros cada um com números
menores que 100, mostre os dois vetores na tela e a seguir mostre o vetor resultante da intercalação
destes dois vetores, conforme exemplo abaixo:*/




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
void exibe3(int *p);
void realiza(int *x1, int *x2, int *x3);

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int *x1 =  new int[10];
    int *x2 = new int[10];
    int *x3 = new int[20];


    gerar(x1);
    gerar(x2);

    cout << "Vetor x1: [";
    exibe(x1);
    cout << "]";

    cout << "\nVetor x2: [";
    exibe(x2);
    cout << "]";

    cout << "\nVetor x3 Resultante da Intercalacao: [";
    realiza(x1,x2,x3);
    exibe3(x3);
    cout << "]" << endl;




}

void gerar(int *p)
{
    int *i = new int(0);

    while(*i < 10)
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


    while(*i < 10)
    {
        cout << *p << " ";
        p++;
        (*i)++;
    }
    p -= *i;
    *i = 0;
}
void exibe3(int *p)
{

    int *i = new int(0);


    while(*i < 20)
    {
        cout << *p << " ";
        p++;
        (*i)++;
    }
    p -= *i;
    *i = 0;
}


void realiza(int *x1, int *x2, int *x3)
{
    int *i = new int(0);
    int *j = new int(0);
    int *a = new int;
    int *b = new int;
    int *c = new int;

    while(*i < 20)
    {
        *x3 = *x1;
        x3++;
        *x3 = *x2;
        x3++;
        x2++;
        x1++;
        (*i)+= 2;
    }

    x3 -= *i;
    *i = 0;


}
