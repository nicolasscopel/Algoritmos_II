/*7 - Escreva uma fun��o que receba como par�metro um array de inteiros com N valores, e determina o
maior elemento do array e o n�mero de vezes que este elemento ocorreu no array. Por exemplo, para um
array com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a fun��o deve fornecer para o programa
que a chamou o valor 15 e o n�mero 3 (indicando que o n�mero 15 ocorreu 3 vezes). A fun��o deve ser
do tipo void, utilize ponteiros e aritm�tica de ponteiro para resolver este exerc�cio.*/




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
