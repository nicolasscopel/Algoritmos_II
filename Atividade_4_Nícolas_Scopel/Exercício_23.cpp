/* 23 - Crie um programa que calcula o n-ésimo número harmônico que é calculado pela seguinte
fórmula: H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n, sendo (n >=1). Escreva uma função
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

    cout << "Escreva um número para que seja calculado seu harmônico: ";
    cin >> divi;

    if(divi >= 1)
    {
        cout << "O harmônico é: " << calcula(divi) << endl;
    }

    else
    {
        cout << "Número inválido." << endl;
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


