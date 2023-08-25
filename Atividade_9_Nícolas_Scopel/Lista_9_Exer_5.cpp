/*10 - Crie um programa que manipule dois vetores vet1 e vet2 ambos de 10 posições e devem ser
preenchidos com números inteiros entre 5 e 20, sem números repetidos.
Após o sistema deverá ordenar os dois vetores em ordem crescente e apresentar os dois vetores na tela e
também apresentar em quais posições os números são iguais, depois de ordenados.
Exemplo:
vet1 6 7 9 12 13 14 17 18 19 20
vet2 5 6 7 12 14 15 16 18 19 20
posições 0 1 2 3 4 5 6 7 8 9
Os números são iguais nas posições: 3, 7, 8 e 9
Utilize ponteiros e aritmética de ponteiros para resolver este exercício.*/




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

    int vetA[10], vetB[10], i, x;

    int *pA, *pB;

    pA = vetA;
    pB = vetB;

    gerar(vetA);

    gerar(vetB);

    cout << "Vetores gerados." << endl;
    cout << "Vetor A: [ ";

    for(int i = 0; i < 10; i++)
    {
        cout << vetA[i] << " ";
    }
    cout << "]";

    cout << "\nVetor B:[ ";
    for(int i = 0; i < 10; i++)
    {
        cout << vetB[i] << " ";
    }
    cout << "]";

    cout << "\nValores iguais nas posicoes: [ ";
    intersec(&pA, &pB);
    cout << "]";




}

void gerar(int *p)
{

    int valor, contV;
    bool repetido;


     for(int i=0; i < 10; i++)
    {
        do
        {
            valor = rand()% 16 + 5;

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

    for(int i = 0; i < 10; i++)
    {
            if((*pA)[i] == (*pB)[i])
            {
                    vetC[cont] = i;
                    cont++;
            }

        }




    for(int i = 1; i < cont; i++)
    {
        cout << vetC[i] << " ";
    }


}

