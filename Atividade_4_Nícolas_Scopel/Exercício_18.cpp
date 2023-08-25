/* 18 - Implemente um programa para manipular uma matriz de 5 x 5 de n�meros inteiros,
dever� ser poss�vel realizar as seguintes a��es:
- Gerar valores para a matriz, n�o sendo permitido n�meros duplicados.
- Mostrar os elementos da matriz
- Mostrar os elementos da diagonal principal da matriz
- Mostrar os elementos da diagonal secund�ria da matriz
- Encontrar o maior elemento da matriz e exibir sua posi��o (linha, coluna) onde se encontra
OBS: utilize fun��es e passagem de par�metro para resolver cada parte deste exerc�cio.*/




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
void dpmat(int mat[][5]);
void dsmat(int mat[][5]);
void maiorele(int mat[][5]);

main()
{
    fflush(stdin);
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");


    int i, x, m[5][5], vet[5];

    gerar(m);

    cout <<"\nMatriz: " << endl;
    mostra(m);

    cout << "\nDiagonal Principal da Matriz: ";
    dpmat(m);

    cout << "\nDiagonal Secuindaria da Matriz: ";
    dsmat(m);

    cout << "\nMaior elemento da Matriz: ";
    maiorele(m);

    getchar();

}

void gerar(int mat[][5])
{
    fflush(stdin);
    int contV = 0,valor;

    bool repetido;


    for(int i = 0; i < 5; i++)
    {
        for(int x = 0; x < 5; x++)
        {
            do
            {
                valor = rand()% 50;

                repetido = false;
                for(int i = 0; i < 5; i++)
                {
                    for(int x = 0; x < 5; x++)
                    {
                        if(mat[i][x] == valor)
                            repetido = true;
                    }
                }
                if(repetido == false)
                {
                    mat[i][x] = valor;

                }
            }
            while(repetido == true);
        }

    }


    return;
}

void mostra(int mat[][5])
{
    int i, x;
    for(i = 0; i < 5; i++)
    {
        for(x = 0; x < 5; x++)
        {
            cout << mat[i][x] << "\t";
        }
        cout << "\n";
    }
}

void dpmat(int mat[][5])
{

    int i, x;
    for(i = 0; i < 5; i++)
    {
        for(x = 0; x < 5; x++)
        {
            if(i == x)
                cout << mat[i][x] << "  ";
        }

    }
    cout << endl;
}


void dsmat(int mat[][5])
{

    int i, x;
    for(i = 0; i < 5; i++)
    {
        for(x = 0; x < 5; x++)
        {
            if(i + x == 4)
                cout << mat[i][x] << "  ";
        }

    }
    cout << endl;
}

void maiorele(int mat[][5])
{

    int i, x, maior = 0, linha, coluna;
    for(i = 0; i < 5; i++)
    {
        for(x = 0; x < 5; x++)
        {
            if(mat[i][x] > maior)
            {
                maior = mat[i][x];
                linha = i;
                coluna = x;
            }

        }

    }
    cout << maior << "  Linha: " << linha << "  Coluna: " << coluna << endl;

}




