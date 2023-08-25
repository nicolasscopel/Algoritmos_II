/* 23 – Utilizando de ponteiros e alocação dinâmica de memória, escreva um programa que receba um
número qualquer N, sendo 3 >= N <= 20 e apresente uma figura como nos exemplos:
Entrada: 5
5
5 5
5 5 5
5 5 5 5
5 5 5 5 5
5 5 5 5
5 5 5
5 5
5
Entrada: 3
3
3 3
3 3 3
3 3
3*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

main()
{
	setlocale (LC_ALL, "Portuguese");

	int *N = new int;
	int *l = new int;
	int *c = new int;
	int *e = new int;



	do
    {
        system("cls");
        cout << "Informe um número entre 3 e 20: ";
        cin >> *N;
        fflush(stdin);

        if(*N < 3 || *N > 20)
        {
            cout << "Valor incorreto. Informe novamente.";
            getchar();
        }

    }while(*N < 3 || *N > 20);


    for (*l = 1; *l <= *N; (*l)++)
    {
        for (*e = 0; *e < *N - *l; (*e)++)
        cout << " ";

        for (*c = 1; *c <= *l; (*c)++)
        {
            cout<< *N;
             cout << " ";
        }
        cout << endl;

    }

     for (*l = *N - 1; *l >= 1; (*l)--)
    {
        for (*e = 0; *e < *N - *l; (*e)++)
        cout << " ";

        for (*c = 1; *c <= *l; (*c)++)
        {
            cout<< *N;
            cout << " ";
        }
        cout << endl;

    }

}
