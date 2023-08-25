/* 22 � Escreva um programa que apresente os primeiros 20 termos da sequ�ncia de fibonacci: �A
gera��o n de Fibonacci retorna 1 quando for at� a 2a gera��o. Se n�o, retorna a soma das duas
�ltimas gera��es anteriores�. Utilize uma fun��o recursiva para resolver este problema.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

int fibo(int n);

main()
{

    int i = 0;

    setlocale (LC_ALL, "Portuguese");

    for(i = 0; i < 20; i++)
    {

        cout << fibo(i) << ", ";
    }

}

int fibo(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }

    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}


