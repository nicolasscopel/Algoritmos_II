/*8 - Escreva um programa que manipule dois vetores x1 e x2 com 6 valores inteiros, os quais devem ser
preenchidos de forma randômica com valores menores que 20 e sem números repetidos no mesmo vetor.
Após implemente uma função que deverá gerar um vetor x3, contendo a intersecção de x1 e x2,
exemplo:
Sendo x1 = {1, 4, 3, 5, 6, 7} e x2 = {1, 2, 3, 9, 6, 8}, x3 irá conter {1, 3, 6}.*/




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
void intersec(int **pA, int **pB);

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int vetA[6], vetB[6], i, x;

    int *pA, *pB;

    pA = vetA;
    pB = vetB;

    gerar(vetA);

    gerar(vetB);

    cout << "Vetores gerados." << endl;
    cout << "Vetor A: [ ";

    for(int i = 0; i < 6; i++)
    {
        cout << vetA[i] << " ";
    }
    cout << "]";

    cout << "\nVetor B:[ ";
    for(int i = 0; i < 6; i++)
    {
        cout << vetB[i] << " ";
    }
    cout << "]";

    cout << "\nVetor C com a intersecção de A e B: [ ";
    intersec(&pA, &pB);
    cout << "]";




}

void gerar(int *p)
{

    int valor, contV;
    bool repetido;


     for(int i=0; i < 6; i++)
    {
        do
        {
            valor = rand()% 20;

            repetido = false;
            for(int j = 0; j < contV; j++)//loop de 0 até (i-1) -> o vetor foi preenchidocom valores não repetidos até (i-1)
            {
                if(p[j] == valor)
                    repetido = true;
            }
            if(repetido == false)
            {
                p[i] = valor;
                contV++;
            }
        }
        while(repetido == true);
    }

}

void intersec(int **pA, int **pB)
{
    int cont = 1;
    int vetC[cont];

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if((*pA)[i] == (*pB)[j])
            {
                    vetC[cont] = (*pA)[i];
                    cont++;
            }

        }
    }



    for(int i = 1; i < cont; i++)
    {
        cout << vetC[i] << " ";
    }


}
