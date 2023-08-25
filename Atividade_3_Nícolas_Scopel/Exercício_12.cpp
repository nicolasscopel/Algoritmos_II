/*12 - Escreva um programa que simule um caixa eletrônico, sabendo que o caixa dispõe das seguintes notas: 2, 5, 10, 20, 50, 100 e 200. O caixa deve priorizar (sempre que possível) a entrega das notas de maior
valor, por exemplo:
Saque 75,00: uma nota de 50, uma nota de 20 e uma nota de 5
Saque 11,00: uma nota de 5, 3 notas de 2
Caso seja solicitado um valor inválido para saque deverá informar uma mensagem com tal informação e solicitar a leitura de outro valor.
O valor do saque deve ser lido e validado utilizando função
O cálculo das notas deverá ser realizado utilizando uma função que recebe como parâmetro o valor do saque e a nota e retornar a quantidade de notas do referido valor.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

void notas200(int saque, int qtd200);
void notas100(int saque, int qtd100);
void notas50(int saque, int qtd50);
void notas20(int saque, int qtd20);
void notas10(int saque, int qtd10);
void notas5(int saque, int qtd5);
void notas2(int saque, int qtd2);



main()
{
    setlocale (LC_ALL, "Portuguese");

    int saque = 0, qtd200 = 0, qtd100 = 0, qtd50 = 0, qtd20 = 0, qtd10 = 0, qtd5 = 0, qtd2 = 0;

    do
    {
        system("cls");
        cout << "Informe o valor de saque: ";
        cin >> saque;
        fflush(stdin);

        if(saque <= 3)
        {
            cout << "Valor Inválido. Informe novamente." << endl;
            getchar();

        }
    }
    while(saque <= 3);


    if(saque >= 200)
    {
        notas200(saque,qtd200);

        saque = saque % 200;

        if(saque < 4 && saque != 0)
        {
            saque = saque + 200;
            qtd200 --;
        }
    }

    if(saque >= 100)
    {
        notas100(saque,qtd100);

        saque = saque % 100;

        if(saque < 4 && saque != 0)
        {
            saque = saque + 100;
            qtd100 --;
        }
    }

    if(saque >= 50)
    {
        notas50(saque,qtd50);
        saque = saque % 50;

        if(saque < 4 && saque != 0)
        {
            saque = saque + 50;
            qtd50 --;
        }
    }

    if(saque >= 20)
    {
        notas20(saque,qtd20);
        saque = saque % 20;

        if(saque < 4 && saque != 0)
        {
            saque = saque + 20;
            qtd20 --;
        }
    }

    if(saque >= 10)
    {
         notas10(saque,qtd10);

        saque = saque % 10;

        if(saque < 4 && saque != 0)
        {
            saque = saque + 10;
        }


    }
    if(saque >= 5)
    {
        notas5(saque,qtd5);
        saque = saque % 5;

        if(saque < 4 && saque != 0)
        {
            saque = saque + 5;
            qtd5 --;
        }
    }

    if(saque >= 2)
    {
        notas2(saque,qtd2);

    }
}

void notas200(int saque, int qtd200)
{

    if(saque >= 200)
    {

        qtd200 = saque / 200;
    }

    if(saque < 4 && saque != 0)
    {
        saque = saque + 200;
        qtd200 --;
    }

    if(qtd200 != 0)
    {
        cout << qtd200 << " notas de 200." << endl;
    }



}

void notas100(int saque, int qtd100)
{

    if(saque >= 100)
    {

        qtd100 = saque / 100;
        saque = saque % 100;
    }

    if(saque < 4 && saque != 0)
    {
        saque = saque + 100;
        qtd100 --;
    }

    if(qtd100 != 0)
    {
        cout << qtd100 << " notas de 100." << endl;
    }



}

void notas50(int saque, int qtd50)
{

    if(saque >= 50)
    {

        qtd50 = saque / 50;
        saque = saque % 50;
    }

    if(saque < 4 && saque != 0)
    {
        saque = saque + 50;
        qtd50 --;
    }

    if(qtd50 != 0)
    {
        cout << qtd50 << " notas de 50." << endl;
    }

}

void notas20(int saque, int qtd20)
{

    if(saque >= 20)
    {

        qtd20 = saque / 20;
        saque = saque % 20;
    }

    if(saque < 4 && saque != 0)
    {
        saque = saque + 20;
        qtd20 --;
    }

    if(qtd20 != 0)
    {
        cout << qtd20 << " notas de 20." << endl;
    }

}

void notas10(int saque, int qtd10)
{


    if(saque >= 10)
    {

        qtd10 = saque / 10;
        saque = saque % 10;
    }



    if(saque < 4 && saque != 0)
        qtd10--;
        saque += 10;


    if(qtd10 > 0)
    {
        cout << qtd10 << " notas de 10." << endl;
    }

}

void notas5(int saque, int qtd5)
{

    if(saque >= 5)
    {

        qtd5 = saque / 5;
        saque = saque % 5;
    }



    if(saque < 4 && saque != 0 && saque != 2)
        qtd5--;
        saque += 5;


    if(qtd5 != 0)
    {
        cout << qtd5 << " notas de 5." << endl;
    }

}


void notas2(int saque, int qtd2)
{

    if(saque >= 2)
    {

        qtd2 = saque / 2;
        saque = saque % 2;
    }

    if(saque < 4 && saque != 0)
    {
        saque = saque + 2;
        qtd2 --;
    }

    if(qtd2 != 0)
    {
        cout << qtd2 << " notas de 2." << endl;
    }

}




