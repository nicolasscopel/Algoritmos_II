/* 22 – Escreva um programa que apresente os primeiros 20 termos da sequência de fibonacci: “A
geração n de Fibonacci retorna 1 quando for até a 2a geração. Se não, retorna a soma das duas
últimas gerações anteriores”. Utilize uma função recursiva para resolver este problema.*/




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


