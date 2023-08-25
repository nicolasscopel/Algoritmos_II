/*14 – Escreva um programa em C++ que manipule uma matriz de inteiros M[8][8] e acione as seguintes funções:
A) Função que gere valores aleatórios, menores que 100 para preencher a matriz.
B) Função que receba a matriz por parâmetro e exiba os seus valores na tela.
C) Função que receba a matriz M e um vetor V[8] o qual deve ser formado pela soma dos elementos de cada linha da matriz, apresente o vetor na tela.
D) Função que recebe a matriz e apresenta os elementos da diagonal principal e diagonal secundária.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

void leitura(int mat[][8]);
void mostra(int mat[][8]);
void somalinhas(int mat[][8], int V[]);
void prinsec(int mat[][8], int V[]);



main()
{
    fflush(stdin);
    setlocale(LC_ALL,"portuguese");
    int a[8][8], v[8] = {0,0,0,0,0,0,0,0};
    leitura(a);
    cout << "MATRIZ: " << endl;
    mostra(a);

    cout << "\n\nSOMA DAS LINHAS DA MATRIZ: ";
    somalinhas(a, v);

    prinsec(a,v);



}


void leitura(int mat[][8])
{
    int i, x;
    srand(time(NULL));
    for(i = 0; i < 8; i++)
    {
        for(x = 0; x < 8; x++)
        {
            mat[i][x] = rand() % 100;
        }
    }
}


void mostra(int mat[][8])
{
    int i, x, soma = 0;
    for(i = 0; i < 8; i++)
    {
        for(x = 0; x < 8; x++)
        {
            cout << mat[i][x] << "\t";
        }
        cout << "\n";
    }
}


void somalinhas(int mat[][8], int V[8])
{
    int i, x;


    for(i = 0; i < 8; i++)
    {
        for(x = 0; x < 8; x++)
        {
            V[i] += mat[i][x];
        }
    }
    fflush(stdin);
    for(i = 0; i < 8; i++)
    {
        cout << V[i] << "    ";
    }


}
void prinsec(int mat[][8], int V[])
{
    int i, x;



    for(i = 0; i < 8; i++)
        {
        for(x = 0; x < 8; x++)
        {
            if(i == x )
            {
                V[i] = mat[i][x];
            }
        }
    }
    cout << "\n\nDIAGONAL PRINCIPAL: ";
    for(i = 0; i < 8; i++)
    {
        cout << V[i] << "    ";
    }


    for(i = 0; i < 8; i++)
        {
        for(x = 0; x < 8; x++)
        {
            if(i + x == 7)
            {
                V[i] = mat[i][x];
            }
        }
    }

    cout << "\n\nDIAGONAL SECUNDARIA: ";

    for(i = 0; i < 8; i++)
    {
        cout << V[i] << "    ";
    }
    cout << "\n\n";



}




