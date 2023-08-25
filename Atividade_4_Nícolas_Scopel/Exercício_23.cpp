/* 23 - Crie um programa que calcula o n-�simo n�mero harm�nico que � calculado pela seguinte
f�rmula: H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n, sendo (n >=1). Escreva uma fun��o
recursiva que calcula H(n).*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

float calcula(int num);


main()
{
    setlocale (LC_ALL, "Portuguese");

    int divi, x = 1;

    cout << "Escreva um n�mero para que seja calculado seu harm�nico: ";
    cin >> divi;

    if(divi >= 1)
    {
        cout << "O harm�nico �: " << calcula(divi) << endl;
    }

    else
    {
        cout << "N�mero inv�lido." << endl;
    }







}

float calcula(int num)
{
    if(num == 1)
    {
        return 1;

    }
    else
    {
        return ((float)1/num + calcula(num -1));

    }




}


