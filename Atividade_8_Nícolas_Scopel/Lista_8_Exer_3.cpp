/*3 - Faça um programa que utilizando ponteiros preencha dois vetores, A e B, com dez
caracteres cada. A seguir, troque o 1o elemento de A com o 10o de B, o 2o de A com o
9o de B, e assim por diante, até trocar o 10o de A com o 1o de B. Mostre os vetores
antes e depois da troca.*/




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
void troca(int *a, int *b);

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int vetA[10];
    int vetB[10];

    int *pontA;
    int *pontB;


    pontA = vetA;
    pontB = vetB;


    cout << "Vetor A: " << endl;
    gerar(pontA);
    exibe(pontA);
    fflush(stdin);

    cout << "\nVetor B: " << endl;
    gerar(pontB);
    exibe(pontB);

    cout << "\n\nVetores A e B após a troca realizada: " << endl;
    troca(pontA, pontB);


}


void gerar(int *p)
{
    int num;

    for (int i = 0; i < 10; i++)
    {
        num = rand() % 40;

        p[i] = num;
    }
}

void exibe(int *p)
{

    for(int i = 0; i < 10; i++)
    {
        cout << p[i] << "  ";
    }
    cout << endl;

}

void troca(int *a, int *b)
{
    int aux, i;

    for(i = 0; i < 10; i++)
    {
        aux = a[i];
        a[i] = b[9 - i];
        b[9 - i] = aux;

    }
    cout << "\nVetor A: " << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;

    cout << "\nVetor B:" << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << b[i] << "  ";
    }
    cout << endl;


}

