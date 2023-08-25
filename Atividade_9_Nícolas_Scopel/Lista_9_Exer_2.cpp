/*7 - Escreva uma função que receba como parâmetro um array de inteiros com N valores, e determina o
maior elemento do array e o número de vezes que este elemento ocorreu no array. Por exemplo, para um
array com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a função deve fornecer para o programa
que a chamou o valor 15 e o número 3 (indicando que o número 15 ocorreu 3 vezes). A função deve ser
do tipo void, utilize ponteiros e aritmética de ponteiro para resolver este exercício.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void gerar(int *p, int N);



main()
{
    setlocale (LC_ALL, "Portuguese");
    int N;

    cout << "Informe o tamanho do vetor; ";
    cin >> N;

    int *pvet, maior;
    int vet[N];
    pvet = vet;

   gerar(pvet, N);


}

void gerar(int *p, int N)
{
    srand(time(NULL));
    int maior = 0, aparece = 1;

    for (int i = 0; i < N; i++)
    {
        p[i] = rand() % 20;
    }


    for (int i = 0; i < N; i++)
    {
        cout << p[i] << " ";
    }

    for (int i = 0; i < N; i++)
    {
        if(p[i] > maior)
        {
            maior = p[i];
            aparece = 1;
        }
        else if(p[i] == maior)
        {

            aparece++;
        }


    }

    cout << "\nMaior elemento: " << maior << endl;
    cout << "Aparece " << aparece << " vezes." << endl;







}
