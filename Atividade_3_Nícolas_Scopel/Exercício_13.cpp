/*13 – Escreva um programa que utilizando uma função leia um número inteiro qualquer, a
seguir execute outra função que receba o valor por parâmetro e gere e apresente na tela os primeiros
5 números primos maiores que o valor informado.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>



using namespace std;

bool primo(int num);
void primos(int num);


main()
{
    fflush(stdin);
	setlocale (LC_ALL, "Portuguese");

	int num;
    cout << "Digite um numero inteiro: ";
    cin >> num;

    primos(num);

}

bool primo(int num)
{
    if (num < 2)
    {
        return false;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
        {
            return false;
        }

    }
    return true;

}


void primos(int num)
{
    int cont = 0, i = num + 1;
    while (cont < 5)
        {
        if (primo(i))
{
            cout << i << " ";
            cont++;
        }
        i++;
    }
}








