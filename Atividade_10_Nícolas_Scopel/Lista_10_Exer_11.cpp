/*11 � Crie um programa que receba do usu�rio a informa��o de quantos n�meros deseja digitar, a seguir
o programa dever� receber os n�meros e apresentar na tela:
- Total de n�meros pares digitados
- Percentual de n�meros �mpares digitados
- M�dia dos n�meros digitados com duas casas decimais
- Maior n�mero digitado e em qual digita��o ele foi informado.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

main()
{
    setlocale (LC_ALL, "Portuguese");

    int *tamanho = new int;

    cout << "Informe quantos numeros deseja diigtar: ";
    cin >> *tamanho;
    fflush(stdin);

    int *pvet = new int [*tamanho];
    int *i = new int(0);
    int *cont = new int(0);
    float *percent = new float(0);
    float *media = new float(0);
    float *soma = new float(0);
    int *maior = new int(0);
    int *pos = new int(0);


    while(*i < *tamanho)
    {
        cout << "Digite o n�mero " << *i << ": ";
        cin >> *pvet;
        *soma += *pvet;
        pvet++;
        (*i)++;
    }

    pvet -= *i;
    *i = 0;

    cout << "\nN�meros digitados: ";

    while(*i < *tamanho)
    {
        cout << *pvet << ", ";
        pvet++;
        (*i)++;
    }

    pvet -= *i;
    *i = 0;

    while(*i < *tamanho)
    {
        if(*pvet % 2 == 0)
        {
            (*cont)++;
        }
        pvet++;
        (*i)++;
    }

    cout << "\nQuantidade de pares: " << *cont << endl;

    pvet -= *i;
    *i =0;

    *percent = (*tamanho - *cont);
    *percent = (*percent / *tamanho) * 100;


    cout << "Percentual de impares: " << *percent << "% " << endl;


    *media = *soma / *tamanho;

    cout.precision(2);
    cout << fixed;
    cout << "Media dos valores digitados: " << *media << endl;


     while(*i < *tamanho)
    {
        if(*pvet > *maior)
        {
            *maior = *pvet;
            *pos = *i;
        }

        pvet++;
        (*i)++;
    }




    cout << "Maior valor " << *maior << " e sua posicao " << *pos << endl;



}
