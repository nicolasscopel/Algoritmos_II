/* 25 - Escreva um programa em C++ que leia um número inteiro positivo N e crie dinamicamente uma matriz de inteiros de tamanho NxN.
Preencha a matriz com números pseudoaleatorios menores que o produto de N * N, imprima a matriz na tela e apresente também:
- Soma dos elementos da diagonal principal - DP
- Maior e menor elemento da diagonal secundária - DS
- Diferença das somas dos elementos acima da DP e abaixo da DP*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;
void gera(int *p, int *n);
void exibe(int *p, int *n);
void soma(int *p, int *n);
void maior(int *p, int *n);
void menor(int *p, int *n);
void diferenca(int *p, int *n);

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");


    int *tamanho = new int;


    cout << "Informe o número de linhas e colunas da matriz: ";
    cin >> *tamanho;

    int *pmat = new int[(*tamanho)*(*tamanho)];

    gera(pmat, tamanho);
    cout << "Matriz: " << endl;
    exibe(pmat, tamanho);
    cout << "Soma dos elementos da DP: "; soma(pmat,tamanho);
    maior(pmat,tamanho);
    menor(pmat,tamanho);
    diferenca(pmat,tamanho);







}
void gera(int *p, int *n)
{
    int *i = new int;

    for(*i = 0; *i < (*n)*(*n); (*i)++)
    {
        p[*i] = rand() % ((*n)*(*n));
    }


}

void exibe(int *p, int *n)
{
    int *i = new int;
    int *l = new int;
    int *c = new int;
    int *cont = new int(0);


    while(*i < (*n)*(*n))
    {
        cout << p[*i] << " ";
        (*cont)++;

        if(*cont == (*n))
        {
            cout << "\n";
            *cont = 0;

        }
        (*i)++;
    }

}

void soma(int *p, int *n)
{
    int *i = new int;
    int *soma = new int(0);
    int *cont = new int(0);
    int *aux = new int(0);
    aux = p;

    while(*i < *n)
    {
        *soma += *p;
        p+= ((*n) + 1);
        (*i)++;
    }
    p = aux;

    cout << *soma << endl;
}

void maior(int *p, int *n)
{
    int *i = new int;
    int *soma = new int(0);
    int *maior = new int(0);
    int *aux = new int(0);
    aux = p;
    p += ((*n) - 1);


    while(*i < *n)
    {
        if(*p > *maior)
        {
            *maior = *p;
        }

        p+= ((*n) - 1);
        (*i)++;
    }

    cout << "Maior elemento da DS: " << *maior << endl;
    p = aux;
    *i = 0;



}

void menor(int *p, int *n)
{
    int *i = new int;
    int *menor = new int(0);
    int *aux = new int(0);
    aux = p;
    p += ((*n) - 1);
    *menor = *p;


    while(*i < *n)
    {
        if(*p < *menor)
        {
            *menor = *p;
        }

        p+= ((*n) - 1);
        (*i)++;
    }

    cout << "Menor elemento da DS: " << *menor << endl;
    p = aux;
    *i = 0;
}
void diferenca(int *p, int *n)
{
    int *somaAcimaDP = new int(0);
    int *somaAbaixoDP = new int(0);
    int *i = new int(0);
    int *j = new int(0);


    for (*i = 0; *i < *n; (*i)++)
        {
        for (*j = 0; *j < *n; (*j)++)
        {
            if (*i < *j)
                {

                    *somaAcimaDP += *p;
            }
            else if (*i > *j)
            {

                *somaAbaixoDP += *p;
            }
           p++;
        }

    }

    cout << "Diferença das somas dos elementos acima da DP e abaixo da DP: " << (*somaAcimaDP) - (*somaAbaixoDP) << endl;

}

