/*18 – Escreva um programa que manipule um vetor de oito números inteiros, os quais devem ser
digitados pelo usuário, no momento de preencher o vetor, já os armazene de forma crescente e apresente
o vetor a cada inclusão.*/




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

    int *i = new int(0);
    int *n = new int;
    int *k = new int;
    int *j = new int;
    int *v = new int[*i];
    int *aux = new int;

    while(*i < 8)
    {
        cout << "Informe o " << *i + 1 << "º numero: ";
        cin >> *n;

        if(*i == 0)
        {
            v[*i] = *n;
        }
         else
        {
            for(*j=0; *j<*i; (*j)++)
            {
                if(*n <= v[*j])
                {
                    for(*k=*i; *k>=*j; (*k)--)
                    {
                        v[*k]= v[(*k)-1]; // se há um termo >= no vetor, todos os outro termos pulam pra frente
                    }
                    v[*j] = *n;
                    break;
                }
                else if(*j == (*i)-1)
                {
                    v[*i] = *n;// se nao encontrou nenhum termo menor ate o fim da rodagem, atribui o termo informado pelo usuário ao termo vazio disponível
                }
            }

        }

        cout << "Vetor: [";
        for(*j = 0; *j <= *i; (*j)++)
        {
            cout << v[*j] << " ";
        }
        cout << "]" << endl;



        (*i)++;

    }






}
