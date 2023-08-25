/* 1 – Escreva um programa que simule um caixa eletrônico que dispõem das seguintes notas: 2, 5, 10, 20, 50, 100 e 200 o
programa deverá receber o valor do saque e, sendo possível realizar o saque, deverá apresentar a quantidade e quais notas
devem ser entregues, sempre priorizando as notas maiores.Não é permitido saque de valores menores que 2 e igual a 3 os demais
valores é possível realizar o saque:
Exemplo: Valor do saque R$: 11.00
Retire seu dinheiro:
3 notas de 2
1 nota de 5*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

main()
{
    setlocale (LC_ALL, "Portuguese");

    int valor, cont2 = 0, cont5 = 0, cont10 = 0, cont20 = 0, cont50 = 0, cont100 = 0, cont200 = 0, resto;

    do
    {
        cout << " Informe o valor de saque: ";
        cin >> valor;
    }
    while(valor <= 3);


    if(valor >= 200)
    {
        do
        {
           cont200 = valor / 200;
            valor = valor % 200;

        }
        while(valor >= 200);
    }

    if(valor < 4 && valor != 0)
    {
        valor = valor + 200;
        cont200 --;
    }


    if(valor >= 100)
    {
        do
        {
           cont100 = valor / 100;
            valor = valor % 100;

        }while(valor >= 100);
    }

    if(valor < 4 && valor != 0)
    {
        valor = valor + 100;
        cont100 --;
    }

    if(valor >= 50)
    {
        do
        {
           cont50 = valor / 50;
            valor = valor % 50;

        }while(valor >= 50);
    }

    if(valor < 4 && valor != 0)
    {
        valor = valor + 50;
        cont50 --;
    }


    if(valor >= 20)
    {
        do
        {
           cont20 = valor / 20;
            valor = valor % 20;

        }while(valor >= 20);
    }

    if(valor < 4 && valor != 0)
    {
        valor = valor + 20;
        cont20 --;
    }

    if(valor >= 10)
    {
        do
        {
           cont10 = valor / 10;
            valor = valor % 10;

        }while(valor >= 10);
    }

    if(valor < 4 && valor != 0)
    {
        valor = valor + 10;
        cont10 --;
    }



    if(valor >= 5)
    {
        do
        {
           cont5 = valor / 5;
            valor = valor % 5;

        }while(valor >= 5);
    }

    if(valor < 4 && valor != 0)
    {
        valor = valor + 5;
        cont5 --;
    }

    if(valor >= 2)
    {
        do
        {
           cont2 = valor / 2;
            valor = valor % 2;

        }while(valor >= 2);
    }

    if(cont200 != 0)
        cout << cont200 << " notas de 200." << endl;
    if(cont100 != 0)
        cout << cont100 << " notas de 100." << endl;
    if(cont50 != 0)
        cout << cont50 << " notas de 50." << endl;
    if(cont20 != 0)
        cout << cont20 << " notas de 20." << endl;
    if(cont10 != 0)
        cout << cont10 << " notas de 10." << endl;
    if(cont5 != 0)
        cout << cont5 << " notas de 5." << endl;
    if(cont2 != 0)
        cout << cont2 << " notas de 2." << endl;
















}
