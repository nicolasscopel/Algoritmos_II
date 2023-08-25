/*22 - Faça um programa que preencha de forma aleatória um primeiro vetor com dez números inteiros
entre 1 e 30, e um segundo vetor com cinco números inteiros entre 2 e 15. O programa deverá mostrar
uma lista dos números do primeiro vetor com seus respectivos divisores armazenados no segundo vetor,
bem como suas posições.
Exemplo de saída do programa:*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void gerarnum(int *p);
void gerardiv(int *p);
void exibe(int *p, int *tam);
void realiza (int *n, int *d);

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int *a = new int[10];
    int *b = new int[5];
    int *tama = new int(10);
    int *tamb = new int(5);

    gerarnum(a);
    cout << "Vetor Numeros: [";
    exibe (a, tama);
    cout << "]";
    gerardiv(b);
    cout << "\nVetor Divisores: [";
    exibe (b, tamb);
    cout << "]";

    realiza(a,b);




}


void gerarnum(int *p)
{
    int *valor = new int(0);
    int *contV = new int(0);
    int *j = new int(0);
    int *i = new int(0);
    bool *repetido = new bool(0);

    for( *i = 0; *i < 10; (*i)++)
    {
        do
        {
            *valor = rand()% 30 + 1;
            *repetido = false;

            for( *j = 0; *j < *contV; (*j)++)//loop de 0 até (i-1) -> o vetor foi preenchidocom valores não repetidos até (i-1)
            {
                if(p[*j] == *valor)
                    *repetido = true;
            }
            if(*repetido == false)
            {
                p[*i] = *valor;
                (*contV)++;
            }
        }
        while(*repetido == true);
    }




}
void gerardiv(int *p)
{
    int *valor = new int(0);
    int *contV = new int(0);
    int *j = new int(0);
    int *i = new int(0);
    bool *repetido = new bool(0);

    for( *i = 0; *i < 5; (*i)++)
    {
        do
        {
            *valor = rand()% 14 + 2;
            *repetido = false;

            for( *j = 0; *j < *contV; (*j)++)//loop de 0 até (i-1) -> o vetor foi preenchidocom valores não repetidos até (i-1)
            {
                if(p[*j] == *valor)
                    *repetido = true;
            }
            if(*repetido == false)
            {
                p[*i] = *valor;
                (*contV)++;
            }
        }
        while(*repetido == true);
    }

}

void exibe(int *p, int *tam)
{

    int *i = new int(0);


    while(*i < *tam)
    {
        cout << *p << " ";
        p++;
        (*i)++;
    }
    p -= *i;
    *i = 0;

}

void realiza (int *n, int *d)
{
    int *i = new int (0);
    int *j = new int (0);
    int *cont = new int(0);

    do
    {
        cout << "\n\nNumero " << *n;

        do
        {
            if((*n) % (*d) == 0)
            {
                (*cont)++;
                cout << "\nDivisivel por " << *d << " na posicao " << *j;
            }

            d++;
            (*j)++;
        }while(*j < 5);
        if(*cont == 0)
            {
                cout << "\nNao possui divisores.";
            }

        *cont = 0;


        (*i)++;
        n++;
        d -= *j;
        *j = 0;

    }while(*i < 10);

}
