/*5 - Crie um programa que receba um valor qualquer representando o tamanho dos
lados de um quadrado, implemente uma função que receba esse valor e utilizando
ponteiros escreva com o caracter “*” asterisco na tela, um quadrado com as respectivas
diagonais, conforme exemplo apresentado abaixo:*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void mostra(int *tam);

main()
{
    setlocale (LC_ALL, "Portuguese");

    int tamanho;


    cout << "Informe o tamanho do lado do quadrado: ";
    cin >> tamanho;

    mostra(&tamanho);

}


void mostra(int *tam)
{
    int l,c;

    for (l = 0; l < *tam; l++ )
    {
        for(c = 0; c < *tam; c++)
        {
            if(l == c || l == 0 || c == 0 || l + c == *tam - 1 || l == *tam - 1 || c == *tam - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }



}
