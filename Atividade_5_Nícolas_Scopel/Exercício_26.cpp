/* 26 � Crie um programa que manipule uma estrutura capaz de descrever um m�s do ano. A
estrutura deve conter os seguintes membros: n�mero do m�s, nome por extenso do m�s,
abreviatura com as tr�s iniciais do m�s e o n�mero de dias do m�s (validar o m�s de fevereiro
em caso de ano bissexto).
Ap�s alimentar os dados para esta estrutura o programa deve solicitar um dia e um m�s
qualquer e dever� mostrar o total de dias j� transcorrido no corrente ano, o dia e m�s
informado e os dados (nome, abreviatura, total de dias) referente ao m�s informado, caso seja
informado dia ou m�s inv�lido dever� apresentar uma mensagem com tal informa��o.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;


struct mes
{
    int numero;
    string nome;
    string abreviatura;
    int dias;

};

int fevereiro(int ano);


main()
{
    int ano = 2023;

    setlocale (LC_ALL, "Portuguese");



    mes meses[12] =
    {
        {1, "Janeiro", "Jan", 31},
        {2, "Fevereiro", "Fev", 0},
        {3, "Mar�o", "Mar", 31},
        {4, "Abril", "Abr", 30},
        {5, "Maio", "Mai", 31},
        {6, "Junho", "Jun", 30},
        {7, "Julho", "Jul", 31},
        {8, "Agosto", "Ago", 31},
        {9, "Setembro", "Set", 30},
        {10, "Outubro", "Out", 31},
        {11, "Novembro", "Nov", 30},
        {12, "Dezembro", "Dez", 31},

    };



    int dia, mes;

    cout << "Informe o dia: ";
    cin >> dia;
    cout << "Informe o mes: ";
    cin >> mes;

    if((mes == 2 && dia > 29)|| dia > 31)
    {
        cout << "N�o pode existir esse dia:" << endl;
        return 1;
    }

    if(mes < 1 || mes > 12)
    {
        cout << "M�s Inv�lido!" << endl;
        return 1 ;
    }

    int diasTranscorridos = 0;
    for (int i = 0; i < mes - 1; i++) {
        if (i == 1) {
            diasTranscorridos += fevereiro(ano);
        } else {
            diasTranscorridos += meses[i].dias;
        }
    }
    diasTranscorridos += dia;



    // Exibindo os resultados
    cout << "Total de dias transcorridos no ano: " << diasTranscorridos << endl;
    cout << "Dia informado: " << dia << endl;
    cout << "Mes informado: " << meses[mes - 1].nome << " (" << meses[mes - 1].abreviatura << ")" << endl;
    cout << "Dias no mes informado: ";

    if (mes == 2)
    {
       cout << fevereiro(2023);
        return 0;
    }
    else
    {
        cout << meses[mes - 1].dias << endl;
    }





    return 0;


}


int fevereiro(int ano)
{
    if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
     return 29;

    else {
        return 28;
    }

}


