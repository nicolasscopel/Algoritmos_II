/*36 – Escreva um programa que gere de forma aleatória uma matriz 8 x 8 de números inteiros,
após gerar a matriz o programa deverá escreve os seguintes dados em um arquivo texto
chamado “exer_36.txt”:
- Os dados da matriz (no formato linha coluna)
- Os elementos das diagonais (principal e secundária)
- Os elementos acima da DP
- Os elementos abaixo da DP*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    ofstream escrever ("exer_36.txt");

    int mat[8][8], l, c;

    for(l = 0; l < 8; l++)
    {
        for(c = 0; c < 8; c++)
        {
            mat[l][c] = rand() % 100;
        }
    }
    cout << "\nMatriz Gerada e escrita no arquivo texto: " << endl;
    escrever << "Matriz Gerada: " << endl;


    /*
    for(l = 0; l < 8; l++)
    {
        for(c = 0; c < 8; c++)
        {
            cout << mat[l][c] << "\t";
        }
        cout << "\n";
    }
    */

    for(l = 0; l < 8; l++)
    {
        for(c = 0; c < 8; c++)
        {
            escrever << mat[l][c] << "\t";
        }
        escrever << "\n";
    }
    escrever << "\nElementos da Diagonal Principal: [";

    for(l = 0; l < 8; l++)
    {
        for(c = 0; c < 8; c++)
        {
            if(l == c)
            escrever << mat[l][c] << " ";
        }

    }
    escrever << "]";

    escrever << "\nElementos da Diagonal Secundaria: [";

    for(l = 0; l < 8; l++)
    {
        for(c = 0; c < 8; c++)
        {
            if(l + c == 7)
            escrever << mat[l][c] << " ";
        }

    }
    escrever << "]";

    escrever << "\nElementos ACIMA Diagonal Principal: [";

    for(l = 0; l < 8; l++)
    {
        for(c = 0; c < 8; c++)
        {
            if(c > l)
            escrever << mat[l][c] << " ";
        }

    }
    escrever << "]";

    escrever << "\nElementos ABAIXO Diagonal Principal: [";

    for(l = 0; l < 8; l++)
    {
        for(c = 0; c < 8; c++)
        {
            if(l > c)
            escrever << mat[l][c] << " ";
        }

    }
    escrever << "]";














}
