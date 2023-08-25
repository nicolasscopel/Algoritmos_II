/*21 � Fa�a um programa que preencha tr�s vetores com cinco posi��es cada. O primeiro vetor receber� os
nomes de cinco funcion�rios; o segundo e o terceiro vetor receber�o, respectivamente, o sal�rio e o
tempo de servi�o de cada um.

Mostre um primeiro relat�rio apenas com os nomes dos funcion�rios que n�o ter�o aumento;

Mostre um segundo relat�rio apenas com os nomes e os novos sal�rios dos funcion�rios que ter�o
aumento, sabe-se que os funcion�rios que ter�o direito ao aumento s�o aqueles que possuem tempo de
servi�o superior a cinco anos ou sal�rio inferior a R$ 1800,00, sabe-se, ainda, que, se o funcion�rio
satisfizer �s duas condi��es anteriores, tempo de servi�o e sal�rio, o aumento ser� de 15%; para o
funcion�rio que satisfazer apenas � condi��o tempo de servi�o, o aumento ser� de 10%; para aquele que
satisfazer apenas � condi��o sal�rio, o aumento ser� de 5%.*/




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
        cout << "Digite o nome do funcion�rio " << *i + 1 << ": ";
        cin >> p[*i].nome;

        cout << "Digite o sal�rio do funcion�rio " << *i + 1 << ": ";
        cin >> p[*i].salario;

        cout << "Digite o tempo de servi�o do funcion�rio " << *i + 1 << ": ";
        cin >> p[*i].tempo;

        cout << "------------------------------------------------------";

        cout << endl;

    }
}

void relatoriosem(dados *p)
{
    int *i = new int(5);
    cout << "Relat�rio dos funcion�rios sem aumento. " << endl;
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
    cout << "\n\nRelat�rio dos funcion�rios que receberam aumento. " << endl;
    cout << "\n\n";
    for(*i = 0; *i < 5; (*i)++)
    {
        if(p[*i].salario < 1800 && p[*i].tempo > 5)
        {
            cout << "Nome: " << p[*i].nome << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Novo sal�rio: " << p[*i].salario * 1.15 << endl;
            cout << "------------------------------------------" << endl;

        }
        if(p[*i].salario > 1800 && p[*i].tempo > 5)
        {
            cout << "Nome: " << p[*i].nome << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Novo sal�rio: " << p[*i].salario * 1.10 << endl;
            cout << "------------------------------------------" << endl;

        }
        if(p[*i].salario < 1800 && p[*i].tempo <= 5)
        {
            cout << "Nome: " << p[*i].nome << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Novo sal�rio: " << p[*i].salario * 1.05 << endl;
            cout << "------------------------------------------" << endl;

        }
    }


}









