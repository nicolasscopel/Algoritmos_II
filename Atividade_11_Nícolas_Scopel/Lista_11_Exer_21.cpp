/*21 – Faça um programa que preencha três vetores com cinco posições cada. O primeiro vetor receberá os
nomes de cinco funcionários; o segundo e o terceiro vetor receberão, respectivamente, o salário e o
tempo de serviço de cada um.

Mostre um primeiro relatório apenas com os nomes dos funcionários que não terão aumento;

Mostre um segundo relatório apenas com os nomes e os novos salários dos funcionários que terão
aumento, sabe-se que os funcionários que terão direito ao aumento são aqueles que possuem tempo de
serviço superior a cinco anos ou salário inferior a R$ 1800,00, sabe-se, ainda, que, se o funcionário
satisfizer às duas condições anteriores, tempo de serviço e salário, o aumento será de 15%; para o
funcionário que satisfazer apenas à condição tempo de serviço, o aumento será de 10%; para aquele que
satisfazer apenas à condição salário, o aumento será de 5%.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

struct dados
{
    string nome;
    float salario;
    int tempo;
};

void preencherdados(dados *p);
void relatoriosem(dados *p);
void relatoriomuda(dados *p);




main()
{
    setlocale (LC_ALL, "Portuguese");

    dados funcionarios[5];
    dados *ptrfun = funcionarios;

    preencherdados(ptrfun);
    relatoriosem(ptrfun);
    relatoriomuda(ptrfun);






}
void preencherdados(dados *p)
{
    int *i = new int(5);

    for(*i = 0; *i < 5; (*i)++)
    {
        cout << "Digite o nome do funcionário " << *i + 1 << ": ";
        cin >> p[*i].nome;

        cout << "Digite o salário do funcionário " << *i + 1 << ": ";
        cin >> p[*i].salario;

        cout << "Digite o tempo de serviço do funcionário " << *i + 1 << ": ";
        cin >> p[*i].tempo;

        cout << "------------------------------------------------------";

        cout << endl;

    }
}

void relatoriosem(dados *p)
{
    int *i = new int(5);
    cout << "Relatório dos funcionários sem aumento. " << endl;
    cout << "\n\n";

    for(*i = 0; *i < 5; (*i)++)
    {
        if(p[*i].salario > 1800 && p[*i].tempo <= 5)
        {
            cout << "Nome: " << p[*i].nome << endl;
            cout << "------------------------------------------" << endl;

        }
    }

}
void relatoriomuda(dados *p)
{
    int *i = new int(5);
    cout << "\n\nRelatório dos funcionários que receberam aumento. " << endl;
    cout << "\n\n";
    for(*i = 0; *i < 5; (*i)++)
    {
        if(p[*i].salario < 1800 && p[*i].tempo > 5)
        {
            cout << "Nome: " << p[*i].nome << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Novo salário: " << p[*i].salario * 1.15 << endl;
            cout << "------------------------------------------" << endl;

        }
        if(p[*i].salario > 1800 && p[*i].tempo > 5)
        {
            cout << "Nome: " << p[*i].nome << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Novo salário: " << p[*i].salario * 1.10 << endl;
            cout << "------------------------------------------" << endl;

        }
        if(p[*i].salario < 1800 && p[*i].tempo <= 5)
        {
            cout << "Nome: " << p[*i].nome << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Novo salário: " << p[*i].salario * 1.05 << endl;
            cout << "------------------------------------------" << endl;

        }
    }


}









