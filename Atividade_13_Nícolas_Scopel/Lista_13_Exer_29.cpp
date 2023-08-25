/*29 � Escreva um programa que leia um arquivo texto contendo v�rios n�meros float, no
m�ximo 50, separados por ponto e v�rgula, o programa dever� mostrar a soma, m�dia, maior e
menor valor existente no arquivo e dever� mostrar os valores em ordem crescente, separando
cada elemento com uma v�rgula e exibindo no m�ximo 10 elementos em cada linha.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;

main()
{
    setlocale (LC_ALL, "Portuguese");

    int cont = 0, i = 0, j;
    float soma = 0, media = 0, maior, menor, num, v[50], aux, prox;
    char texto[10];

    ifstream ler("exer29.txt", ios::in);


    if(ler.is_open())
    {
        cout << "\nLeitura realizada com sucesso!" << endl;

        while(ler.getline(texto,10,';'))
        {
            num = atof(texto);
            soma += atof(texto);
            v[cont] = num;
            cont++;
        }
        cout << fixed;
        cout.precision(2);
        cout <<"\nSoma total dos numeros: " << soma;
        cout <<"\nMedia total dos numeros: " << soma / cont;



        for(i = 0; i < cont; i++)
        {
            for(j = 0; j <= cont -1; j++)
            {
                if(v[i] < v[j])
                {
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;

                }
            }
        }


        cout << "\nElementos lidos do arquivo: \n[";
        j = 0;

        for(i = 0; i < cont; i++)
        {

            cout << v[i] << ",";
            j++;
            if(j == 10)
            {
                cout << "\n";
                j = 0;
            }
        }
        cout << "]";

        cout << "\nMenor valor lido: " << v[0];
        cout << "\nMaior valor lido: " << v[cont - 1];
    }
    else
    {
        cout << "\nErro de Leitura: ";
    }
}
