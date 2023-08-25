/* 20 - Crie um programa que implemente uma função recursiva para calcular o MDC (Máximo
Divisor Comum) entre dois números inteiros e positivos. Para calcular o MDC deve-se utilizar o
algoritmo de Euclides, que possui como conceito: “O MDC de dois números inteiros é o maior
número inteiro que divide ambos sem deixar resto”, a figura abaixo exemplifica o algoritmo de
Euclides.

O MDC de 30 e 4 é: 2*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;


int mdc(int num1, int num2);

main()
{
    setlocale (LC_ALL, "Portuguese");


    int num1, num2, aux;

    cout << "Informe dois números inteiros para ver o MDC: " ;
    cin >> num1 >> num2;

    if(num1 > num2)
    {
        cout << "O MDC desses números é: "<< mdc(num1, num2);
    }

    else
    {
        aux = num1;
        num1 = num2;
        num2 = aux;

        cout << "O MDC desses números é: "<< mdc(num1, num2);
    }

}


int mdc(int num1, int num2)
{
    if(num1 % num2 == 0)
    {
        return num2;
    }
    else
    {
        return(num2, num1 % num2);
    }

}
