/* 24 – Escreva um programa que através de uma função receba como parâmetro um array de inteiros com N valores
(a dimensão deve ser definida pelo usuário ao iniciar o programa), e determina o maior elemento do array e o
número de vezes que este elemento ocorreu no array. Por exemplo, para um array com os seguintes elementos:
5, 2, 15, 3, 7, 15, 8, 6, 15, a função deve exibir o valor 15 e o número 3 (indicando que o número 15 ocorreu 3 vezes).
A função deve ser do tipo void, utilize ponteiros para fornecer as informações solicitadas.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

void gerar (int *p, int *N);
void exibe (int *p, int *N);
void realiza(int *p, int *N);

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int *N = new int;

    cout << "Informe o tamanho do vetor: ";
    cin >> *N;

    int *vet = new int [*N];

    gerar(vet,N);
    cout << "Vetor Gerado: ";
    exibe(vet,N);

    realiza(vet,N);





}

void gerar (int *p, int *N)
{
    int *i = new int(0);

    while(*i < *N)
    {
        p[*i] = rand() % 20;
        (*i)++;
    }
    *i = 0;

}
void exibe (int *p, int *N)
{
    int *i = new int (0);

    cout << "[ ";
    while(*i < *N)
    {
        cout << p[*i] << " ";
    (*i)++;
    }
    cout << "] ";
}

void realiza(int *p, int *N)
{
    int *i = new int(0);
    int *j = new int(0);
    int *maior = new int(0);
    int *aparece = new int(0);


    for(*i = 0; *i < *N; (*i)++)
    {
        if(p[*i] > *maior)
        {
            *maior = p[*i];
            *aparece = 1;
        }
        else if(p[*i] == *maior)
        {
            (*aparece)++;
        }
    }
    cout << "\nMaior elemento: " << *maior;
    cout << "\nApareceu: " << *aparece << " vez(es).";

}

