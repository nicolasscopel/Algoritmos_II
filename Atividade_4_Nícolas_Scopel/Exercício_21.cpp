/* 21 – Faça um programa que receba dois valores inteiros e positivos, referentes a uma base e
um expoente, após crie uma função recursiva para realizar o cálculo e retornar o valor
resultante.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

int calcula(int base, int expo);

main()
{
    setlocale (LC_ALL, "Portuguese");

    int base, expo;

    cout << "Informe a base: ";
    cin >> base;

    cout << "Informe o expoente: ";
    cin >> expo;




    cout <<"A sua base elevada ao seu expoente da: " << calcula(base, expo);



}


int calcula(int base, int expo)
{

    if(expo == 0)
        return 1;


    else
    {
        return base * calcula(base, expo - 1);
    }

}
