/*12 - Escreva um programa que manipule um vetor de inteiros de 10 posições, o vetor deverá ser
preenchido de forma pseudoaleatória com valores entre 30 e 55, sem números repetidos, mostrar o vetor
gerado na tela, realizar a troca dos valores no vetor de tal forma que o primeiro passa a ser o último, o
segundo o penúltimo e assim sucessivamente. Mostre o vetor na tela após as trocas, utilize aritmética de
ponteiro para percorrer o vetor.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void gerar(int *pvet);
void mostra(int *pvet);
void mostrainvert(int *pvet);



main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int *p = new int[10];


    gerar(p);
    mostra(p);
    mostrainvert(p);



}


void gerar(int *pvet)
{

    int *valor = new int(0);
    int *contV = new int(0);
    int *j = new int(0);
    int *i = new int(0);
    bool *repetido = new bool(0);

    for( *i = 0; *i < 10; (*i)++)
    {
        do
        {
            *valor = rand()% 26 + 30;
            *repetido = false;

            for( *j = 0; *j < *contV; (*j)++)//loop de 0 até (i-1) -> o vetor foi preenchidocom valores não repetidos até (i-1)
            {
                if(pvet[*j] == *valor)
                    *repetido = true;
            }
            if(*repetido == false)
            {
                pvet[*i] = *valor;
                (*contV)++;
            }
        }
        while(*repetido == true);
    }




}

void mostra(int *pvet)
{
    int *i = new int;
    cout << "Vetor Original: [ ";

    *i = 0;
    while(*i < 10)
    {
        cout << *pvet << " ";
        pvet++;
        (*i)++;
    }
    cout << "]";
}

void mostrainvert(int *pvet)
{
    int *aux = new int(0);
    int *i = new int(0);
    int *inicio = new int;
    inicio = pvet;
    int *fim = new int;
    fim = pvet + 9;

    while(inicio < fim)
    {
        *aux = *inicio;
        *inicio = *fim;
        *fim = *aux;

        inicio++;
        fim--;

    }


    cout << "\nVetor Invertido: [ ";

    *i = 0;
    while(*i < 10)
    {
        cout << *pvet << " ";
        pvet++;
        (*i)++;
    }
    cout << "]" << endl;

}
