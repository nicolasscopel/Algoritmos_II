/* 24 - Dado um vetor V[10] implemente um programa com as seguintes fun��es:
- Fun��o para gerar valores para o vetor sem n�mero repetidos e menores que 100.

- Fun��o para mostrar os elementos do vetor na tela.

- Fun��o RECURSIVA que recebe o vetor por par�metro, percorrendo todo o vetor e retornando
o maior elemento existente no vetor, n�o � permitido o uso de la�os de repeti��o para percorrer
o vetor.

OBS: As tr�s fun��es devem ser acionadas na respectiva ordem no programa principal.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void gerar(int vet[]);
void mostra(int vet[]);
int maior(int vet[], int tam, int indice);


main()
{

    fflush(stdin);
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int a[10];


    gerar(a);

    cout << "Vetor: " << "[";

    mostra(a);

    cout << "]" << endl;

    cout << "\nMaior elemento do vetor: " << maior(a, 10, 0) << endl;



}


void gerar(int vet[])
{
    fflush(stdin);
    int contV = 0,valor;

    bool repetido;

    for(int i = 0; i < 10; i++)
    {

            do
            {
                valor = rand()% 100;

                repetido = false;

                for(int i = 0; i < 10; i++)
                {

                        if(vet[i] == valor)
                            repetido = true;

                }
                if(repetido == false)
                {
                    vet[i] = valor;

                }
            }
            while(repetido == true);
        }

    return;

}

void mostra(int vet[])
{
    int i;

    for(i = 0; i < 10; i++)
    {
        cout << vet[i] << " ";
    }
}

int maior(int vet[], int tam, int indice)
{

    if(tam == 0)
    {
        return vet[indice];
    }

    else
    {
        if(vet[tam - 1] > vet[indice])
        {
            return maior(vet, tam - 1, tam - 1);
        }
        else
        {
            return maior(vet, tam -1, indice);
        }
    }

}



