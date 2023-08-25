/* 25 - Escreva um programa que gere randomicamente valores inteiros menores que 11 para
preencher uma matriz 3 x 3 de tal forma que a matriz resultante forme um quadrado m�gico.
Quadrado m�gico ocorre se a soma dos elementos de cada linha, a soma dos elementos de cada
coluna e a soma dos elementos das diagonais principal e secund�ria s�o todas iguais.
A matriz abaixo forma um quadrado m�gico:
8 0 7
4 5 6
3 10 2

O sistema dever� contar quantas matrizes foram geradas at� gerar a matriz que resultou no
quadrado m�gico. Caso em 10 tentativas n�o foi gerado o quadrado m�gico o sistema dever�
permitir que o usu�rio informe valores para a matriz, utilize fun��es e passagem de par�metro
para resolver este exerc�cio.*/



#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

const int SIZE = 3; // tamanho da matriz


void preencherMatriz(int matriz[][SIZE])
{
    fflush(stdin);
    srand(time(NULL));
    int contV = 0,valor, soma = 0;

    bool repetido;

    for(int i = 0; i < 3; i++)
    {
        for(int x = 0; x < 3; x++)
        {
            do
            {
                valor = rand()% 11;

                repetido = false;
                for(int i = 0; i < 3; i++)
                {
                    for(int x = 0; x < 3; x++)
                    {
                        if(matriz[i][x] == valor)
                            repetido = true;
                    }
                }
                if(repetido == false)
                {
                    matriz[i][x] = valor;

                }
            }
            while(repetido == true);
        }

    }
}

void imprimirMatriz(int matriz[][SIZE])
{
    // imprime a matriz na tela
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\n\n";
}

bool QuadradoMagico(int matriz[][SIZE])
{
    int somaDiagonal1 = 0, somaDiagonal2 = 0;

    // verifica a soma das diagonais principal e secund�ria
    for (int i = 0; i < SIZE; i++)
    {
        somaDiagonal1 += matriz[i][i];
        somaDiagonal2 += matriz[i][SIZE - i - 1];
    }

    if (somaDiagonal1 != somaDiagonal2)
    {
        return false;
    }

    int somaLinha, somaColuna;
    for (int i = 0; i < SIZE; i++)
    {
        somaLinha = 0;
        somaColuna = 0;

        // verifica a soma dos elementos de cada linha e coluna
        for (int j = 0; j < SIZE; j++)
        {
            somaLinha += matriz[i][j];
            somaColuna += matriz[j][i];
        }

        if (somaLinha != somaColuna || somaLinha != somaDiagonal1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    srand(time(NULL));
    int matriz[SIZE][SIZE];
    int tentativas = 0;

    while (tentativas < 10)
    {
        preencherMatriz(matriz);
        imprimirMatriz(matriz);

        if (QuadradoMagico(matriz))
        {
            cout << "Quadrado magico encontrado!" << endl;
            break;
        }

        tentativas++;
    }

    if (tentativas == 10)
    {
        cout << "Nao foi encontrado um quadrado magico em 10 tentativas." << endl;

        // permite que o usu�rio informe valores manualmente
        cout << "Informe os valores da matriz: " << endl;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                cin >> matriz[i][j];
            }
        }

        if (QuadradoMagico(matriz))
        {
            cout << "Quadrado magico encontrado!" << endl;
        }
        else
        {
            cout << "Matriz informada nao e um quadrado magico." << endl;

        }
    }
}


