/* 2 - Escreva um programa que utilizando ponteiros manipule um vetor de 6 posições, o
sistema deverá ter uma função para gerar os valores para preencher o vetor com
valores aleatórios entre 1 e 50. Após deverá exibir o vetor e um relatório conforme
exemplo

Vetor
2 4 5 6 3 7
0 1 2 3 4 5

Relatório

Os números pares são:
número 2 na posição 0
número 4 na posição 1
número 6 na posição 3
Soma dos pares = 12

Os números ímpares são:
número 5 na posição 2
número 3 na posição 4
número 7 na posição 5
Quantidade de ímpares = 3*/




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
