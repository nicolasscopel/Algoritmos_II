/* 14 - Crie uma função que receba como parâmetros dois vetores de inteiros: x1[10] e x2[10]. A função
deverá alocar um terceiro vetor, x3, alocado dinamicamente, contendo a união de x1 e x2 e deverá
apresentar:
- Os elementos do vetor x3.
- Os elementos do vetor x3 em ordem crescente.
- O maior e o menor elemento do vetor x3.
- Quantos dos elementos do vetor x3 são primos e quais são eles.
OBS: os vetores x1 e x2 devem ser gerados de forma randômica contendo valores entre 200 e 300*/




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
void ordem(int *p);
void maior(int *p);
void primos(int *p);


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

    cout << "\nVetor x3 Original: [";
    realiza(x1,x2,x3);
    exibe3(x3);

    cout << "]";

    cout << "\nVetor x3 em Ordem Crescente: [";
    ordem(x3);
    exibe3(x3);

    cout << "]" << endl;

    maior(x3);

    primos(x3);


}




void gerar(int *p)
{
    int *i = new int(0);

    while(*i < 10)
    {
        *p = rand() % 101 + 200;
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

void ordem(int *p)
{
    int *i = new int(0);
    int *j = new int(0);
    int *aux = new int(0);
    int *prox =  new int(0);



    for(*i = 0; *i < 20; (*i)++)
    {
        for(*j = 0; *j <=19; (*j)++)
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

void maior(int *p)
{
    int *aux = new int(0);
    aux = p + 19;
    cout << "Maior elemento do vetor: " << *aux << endl;
    *aux = *p;
    cout << "Menor elemento do vetor: " << *p << endl;
}
void primos(int *p)
{
    int *i = new int (0);
    int *x = new int (0);
    int *cont = new int (0);
    int *total = new int(0);
    cout << "Números primos sao: [";

    while(*x < 20)
    {
        for (*i = 1; *i <= *p; (*i)++ )
        {
            if (*p % *i == 0)
                (*cont)++;
        }

        if(*cont == 2)
        {
            cout << *p << " ";
            (*total)++;
        }
        *cont = 0;
        p++;
        (*x)++;

    }
    cout << "]";
    cout << "\nTotalizando " << *total << " numeros." << endl;


}



