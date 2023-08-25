/*38 – Crie um programa que manipule uma struct chamada “data” a qual deve conter os
campos: dia, mês e ano. Em seguida escreva duas funções:
Função 1: recebe a struct por parâmetro e permite que o usuário informe o dia, mês e ano.
Função 2: recebe a struct por parâmetro e calcula quantos dias já se passaram até a presente
data e quantos ainda restam até o final do ano, considerar se o ano é bissexto ou não.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

struct data
{
    int dia;
    int mes;
    int ano;
};

void lerData(data &d);
int calcula(int dia, int mes, int ano);

main()
{
    data minhadata;

    setlocale (LC_ALL, "Portuguese");

    lerData(minhadata);

    calcula(minhadata.dia, minhadata.mes, minhadata.ano);

}


void lerData(data &d)
{
    cout << "Informe o dia: ";
    cin >> d.dia;
    fflush(stdin);
    cout << "Informe o mes: ";
    cin >> d.mes;
    fflush(stdin);
    cout << "Informe o ano: ";
    cin >> d.ano;
    fflush(stdin);
}


int calcula(int dia, int mes, int ano)
{
    int diasano = 0, diasfoi = 0, diasvem = 0, fev;


    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
    {
        diasano = 366;
        fev = 29;
    }
    else
    {
        diasano = 365;
        fev = 28;
    }


    if(mes == 1)
    {
        diasfoi = dia;
        diasvem = diasano - dia;
    }

    if(mes == 2)
    {


        if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
        {
            diasfoi = 31 + dia;
            diasvem = diasano - diasfoi;
        }

        else
        {
            diasfoi = 31 + dia;
            diasvem = diasano - diasfoi;
        }
    }

    if(mes == 3)
    {
        diasfoi = 31 + fev + dia;
        diasvem = diasano - diasfoi;
    }


    if(mes == 4)
    {
        diasfoi = 62 + fev + dia;
        diasvem = diasano - diasfoi;
    }


    if(mes == 5)
    {
        diasfoi = 92 + fev + dia;
         diasvem = diasano - diasfoi;
    }

    if(mes == 6)
    {

        diasfoi = 123 + fev + dia;
         diasvem = diasano - diasfoi;
    }

    if(mes == 7)
    {
        diasfoi = 153 + fev + dia;
        diasvem = diasano - diasfoi;
    }

    if(mes == 8)
    {

        diasfoi = 184 + fev + dia;
        diasvem = diasano - diasfoi;
    }


    if(mes == 9)
    {

        diasfoi = 215 + fev + dia;
        diasvem = diasano - diasfoi;
    }



    if(mes == 10)
    {

        diasfoi = 245 + fev + dia;
        diasvem = diasano - diasfoi;
    }



    if(mes == 11)
    {
        diasfoi = 276 + fev + dia;
        diasvem = diasano - diasfoi;
    }


    if(mes == 12)
    {
        diasfoi = 306 + fev + dia;
        diasvem = diasano - diasfoi;
    }


    cout << "Ja se passaram " << diasfoi << " dias desde o inicio do ano." << endl;
    cout << "Faltam " << diasvem << " dias ate o final do ano." << endl;

}


