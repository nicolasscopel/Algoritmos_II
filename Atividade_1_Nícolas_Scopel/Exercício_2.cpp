/*2 – Escreva um programa que manipule um vetor VET[20] de números float, os valores para preencher o vetor devem ser
gerados randomicamente, mostre o vetor gerado na tela, exibindo 5 valores em cada linha e separando cada valor com uma
vírgula, a seguir mostre o vetor com valores arredondados para cima,
para baixo e seguindo o critério da primeira casa decimal
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

main()
{

    setlocale (LC_ALL, "Portuguese");



    float VET[20];
    double num;



    fflush(stdin);
    srand(time(NULL));
    system("cls");


    for(int x = 0; x < 20; x++)
    {
        VET[x] = rand() % 100 * 1.23;
    }

    cout << "VETOR NORMAL" << endl;
    for(int x = 0; x < 5; x++)
    {

        cout << VET[x] << ", ";
    }
    cout << endl;

    for(int x = 5; x < 10; x++)
    {

        cout << VET[x] << ", ";
    }
    cout << endl;

    for(int x = 10; x < 15; x++)
    {

        cout << VET[x] << ", ";
    }
    cout << endl;

    for(int x = 15; x < 20; x++)
    {

        cout << VET[x] << ", ";
    }
    cout << endl;

    cout << " \n\n\n";



    cout << "VETOR ARREDONDADO" << endl;
    for(int x = 0; x < 5; x++)
    {

        cout << round(VET[x]) << ", ";
    }

    cout << endl;

    for(int x = 5; x < 10; x++)
    {

        cout << round(VET[x]) << ", ";
    }
    cout << endl;

     for(int x = 10; x < 15; x++)
    {

        cout << round(VET[x]) << ", ";
    }
    cout << endl;

     for(int x = 15; x < 20; x++)
    {

        cout << round(VET[x]) << ", ";
    }
    cout << endl;















}
