/**/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void preencher(int vet[]);

void mostra(int vet[]);

void procura(int vet[]);


main()
{
    setlocale (LC_ALL, "Portuguese");

    int v[10];

    cout << "Informe 10 valores para o preenchimento do vetor: ";
    preencher(v);

    cout << "\nVetor Informado: ";
    mostra(v);

    procura(v);








}


void preencher(int vet[])
{

    for (int j = 0; j < 10; j++)
    {
        cin >> vet[j];
    }

}

void mostra(int vet[])
{

    for (int j = 0; j < 10; j++)
    {
        cout << vet[j] << " ";
    }
}

void procura(int vet[])
{
    int j, cont = 0 , soma1 = 0, soma2 = 0, posicao = 0, dif = 0, res = 0;


    for(j = 0; j < 7; j++)
    {



        if(vet[j] < vet[j + 1] && vet[j + 1] < vet[j + 2] && vet[j + 2] < vet[j + 3])
        {
            posicao = j;
            cont++;
            if(cont == 2)
            {
                break;
            }
        }

        dif = posicao;

    }

    if(cont > 1)
    {
        soma1 = vet[posicao] + vet[posicao + 1] + vet[posicao + 2] + vet[posicao + 3];
        soma2 = vet[dif] + vet[dif + 1] + vet[dif + 2] + vet[dif + 3];

        if(soma2 > soma1)
        {
            posicao = dif;
        }
        else
        {
            posicao = posicao;
        }

    }

    if(cont == 0)
    {
        cout << "\n\nNão possui sequência com minímo 4 elementos contíguos. " << endl;
    }
    else
    {

    cout << "\n\nSoma da sequência contígua: " << vet[posicao] + vet[posicao + 1] + vet[posicao + 2] + vet[posicao + 3] << endl << endl;

    }









}
