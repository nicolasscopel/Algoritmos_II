/* 19 - Crie um programa que, utilizando uma função recursiva, inverta um número inteiro
qualquer.
Exemplo:
Número informado: 123
Resultado exibido: 321*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void imprimir(int num);

main()
{
    setlocale (LC_ALL, "Portuguese");

    int n;

    cout << "Informe um número inteiro para ser invertido: ";
    cin >> n;

    imprimir(n);





}

void imprimir(int num)
{
    if(num == 0)
    {
        return;
    }
    else
    {
        cout << num % 10;
        num = num/10;
        return imprimir(num);

    }

}
