/* 16 – Crie um programa que manipule uma matriz 3 x 5 de números inteiros, o sistema deverá
utilizar funções para realizar as ações apresentadas abaixo:
- Gerar valores para preencher toda a matriz, não sendo permitido números maiores que 50 e
somente números pares serão aceitos na matriz
- Mostrar a matriz gerada e sua respectiva matriz transposta.
- Calcular e mostrar o maior, o menor e a média dos elementos existentes na matriz.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;


void gerar(int mat[][5]);
void mostra(int mat[][5]);
void transp(int mat[][5], int trans[][3]);
void mostratrans(int trans[][3]);
int maior(int mat[][5]);
int menor(int mat[][5]);
int media(int mat[][5]);


main()
{

    setlocale (LC_ALL, "Portuguese");

    int a[3][5], b[5][3];


    srand(time(NULL));

    gerar(a);

    cout << "MATRIZ GERADA" << endl;

    mostra(a);

    transp(a,b);

    cout << "\n\nMATRIZ TRANSPOSTA" << endl;

    mostratrans(b);

    cout << "\nMAIOR VALOR: " << maior(a) << endl;

    cout << "MENOR VALOR: " << menor(a) << endl;

    cout << "MEDIA DOS VALORES: " << media(a) << endl;



}


void gerar(int mat[][5])
{
    fflush(stdin);

    int i, x, aux = 0, cont = 0;

    for(i = 0; i < 3; i++)
    {
        for(x = 0; x < 5; x++)
        {
            aux = rand() % 50;

            if(aux % 2 == 0)
            {
                mat[i][x] = aux;
            }
            else
                x--;
        }
    }


}

void mostra(int mat[][5])
{
    int i, x;
    for(i = 0; i < 3; i++)
    {
        for(x = 0; x < 5; x++)
        {
            cout << mat[i][x] << "\t";
        }
        cout << "\n";
    }
}

void transp(int mat[][5], int trans[][3])
{
    int i, x;

    for(i = 0; i < 5; i++)
    {
        for(x = 0; x < 3; x++)
        {
            trans[i][x] = mat[x][i];
        }

    }

}

void mostratrans(int trans[][3])
{
    int i, x;
    for(i = 0; i < 5; i++)
    {
        for(x = 0; x < 3; x++)
        {
            cout << trans[i][x] << "\t";
        }
        cout << "\n";
    }
}

int maior(int mat[][5])
{
    int i, x, maior = 0;
    for(i = 0; i < 3; i++)
    {
        for(x = 0; x < 5; x++)
        {
            if(mat[i][x] > maior)
                maior = mat[i][x];
        }

    }

    return maior;

}
int menor(int mat[][5])
{
    int i, x, menor;
    menor = 49;
    for(i = 0; i < 3; i++)
    {
        for(x = 0; x < 5; x++)
        {
            if(mat[i][x] < menor)
                menor = mat[i][x];
        }

    }
    return menor;
}

int media(int mat[][5])
{
    int i, x, soma = 0;

    for(i = 0; i < 3; i++)
    {
        for(x = 0; x < 5; x++)
        {
            soma += mat[i][x];

        }

    }
    return soma / 15;
}




