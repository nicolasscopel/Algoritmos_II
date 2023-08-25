/* 2 - Escreva um programa que utilizando ponteiros manipule um vetor de 6 posi��es, o
sistema dever� ter uma fun��o para gerar os valores para preencher o vetor com
valores aleat�rios entre 1 e 50. Ap�s dever� exibir o vetor e um relat�rio conforme
exemplo

Vetor
2 4 5 6 3 7
0 1 2 3 4 5

Relat�rio

Os n�meros pares s�o:
n�mero 2 na posi��o 0
n�mero 4 na posi��o 1
n�mero 6 na posi��o 3
Soma dos pares = 12

Os n�meros �mpares s�o:
n�mero 5 na posi��o 2
n�mero 3 na posi��o 4
n�mero 7 na posi��o 5
Quantidade de �mpares = 3*/




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
void relatorio(int *p);



main()
{
    setlocale (LC_ALL, "Portuguese");

    int vet[6];
    int *pont;
    pont = vet;

    gerar(pont);
    exibe(pont);
    relatorio(pont);






}


void gerar(int *p)
{
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        p[i] = rand() % 47 + 2;
    }
}

void exibe(int *p)
{
    for(int i = 0; i < 6; i++)
    {
        cout << p[i] << "  ";
    }
    cout << endl;

     for(int i = 0; i < 6; i++)
    {
        cout << i << "   ";
    }
}


void relatorio(int *p)
{
    int soma = 0, qtd = 0;
    cout << "\n\n---- Relatorio ----\n\n\n";



    cout << "Os numeros pares sao: \n\n" ;

    for(int i = 0; i < 6; i++)
    {
        if(p[i] % 2 == 0)
        {
            cout << "Numero " << p[i] << " na posicao " << i << endl;
            soma += p[i];
        }


    }
    cout << "Soma dos pares: " << soma << endl;


    cout << "\nOs numeros impares sao: \n\n" ;

    for(int i = 0; i < 6; i++)
    {
        if(p[i] % 2 != 0)
        {
            cout << "Numero " << p[i] << " na posicao " << i << endl;
              qtd += 1;
        }


    }
    cout << "Quantidade de impares: " << qtd << endl;



}
