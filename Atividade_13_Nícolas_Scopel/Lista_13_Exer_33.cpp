/*33 – Crie um programa que apresente um menu com as opções listadas a seguir:
0 – Sair
1 – Gerar valores (gera valores entre 5 e 50, para preencher um vetor[20] de números inteiros,
sem números repetidos)
2 – Escrever valores no arquivo texto (escreve os valores constantes no vetor em um arquivo
texto chamado vetor.txt, separando cada elemento com uma vírgula)
3 – Ler arquivo (lê os valores do arquivo e exibe eles na tela)
OBS: não será permitido executar as opções 2 e 3 do menu caso não tenha sido executado a
opção 1, caso a opção 1 seja executada mais de uma vez o programa deverá manter os dados
já existentes no arquivo.*/




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

void gerar(int v[20]);
void escrever(int v[20]);
void lermostrar(int v[20]);

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");
    int menu;
    int vet[20], gerou = 0;


    do
    {
        system("cls");
        cout << "########### MENU DE OPCOES ###########" << endl;
        cout << "# 0 - Sair                           #" << endl;
        cout << "# 1 - Gerar valores para o vetor     #" << endl;
        cout << "# 2 - Escrever valores               #" << endl;
        cout << "# 3 - Ler valores e mostrar          #" << endl;
        cout << "######################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        switch(menu)
        {
        case 0 :
        {





            system("cls");
            cout << "Programa finalizado com sucesso!";
            getchar();
            break;

        }


        case 1 :
        {
            system("cls");



            gerar(vet);
            gerou++;


            getchar();
            break;
        }


        case 2 :
        {


            system("cls");
            if(gerou > 0)
            {
                escrever(vet);
                cout << "Valores escritos no arquivo.";
            }
            else
                cout << "Você deve primeiro gerar o vetor!";
            getchar();
            break;
        }


        case 3 :
        {


            system("cls");
            if(gerou > 0)
                lermostrar(vet);

            else
                cout << "Você deve primeiro gerar o vetor!";
            getchar();
            break;
        }


        default :
            system("cls");
            cout << "Opcao invalida";
            getchar();
            break;

        };
    }
    while(menu != 0);






}


void gerar(int v[20])
{
    int valor = 0, contV = 0, j = 0,i = 0;

    bool repetido;

    for( i = 0; i < 20; i++)
    {
        do
        {
            valor = rand()% 46 + 5;
            repetido = false;

            for( j = 0; j < contV; j++)//loop de 0 até (i-1) -> o vetor foi preenchidocom valores não repetidos até (i-1)
            {
                if(v[j] == valor)
                    repetido = true;
            }
            if(repetido == false)
            {
                v[i] = valor;
                contV++;
            }
        }
        while(repetido == true);
    }

    cout << "\nVetor gerado com sucesso.";




}

void escrever(int v[20])
{
    int i = 0;
    ofstream escrever("vetor.txt", ios::app);

    for(i = 0; i < 20; i++)
    {
        escrever << v[i] << ",";
    }
    escrever << "\n";
    escrever.close();

}

void lermostrar(int v[20])
{
    char texto[10];
    int i = 0, num;
    ifstream ler("vetor.txt", ios::in);

    cout  <<"\nVetor Gerado: [";

    for (i = 0; i < 20; i++)
    {
        ler.getline(texto,4,',');
        num = atoi(texto);
        cout << num << " ";



    }
    cout << "]";
    ler.close();



}
