/* 15 - Escreva um programa em C++ que manipule dois vetores x1 e x2 de 10 elementos do tipo inteiro, o programa deverá apresentar um menu com as seguintes ações:
0 - Sair
1 – Gerar vetores (gerar valores para preencher os dois vetores com números pseudoaleatórios entre 35 e 85 (não incluindo o 35 e o 85) e não sendo permitido valores duplicados no mesmo vetor)
2 - Mostra (mostrar os dois vetores na tela.
3 – Intersecção (gerar um terceiro vetor que deverá conter a intersecção de x1 e x2, ou seja, os elementos que existem nos dois vetores.
Exemplo:
Sendo
x1 = {41, 54, 37, 65, 63, 72, 39, 49, 82, 79}
x2 = {71, 82, 39, 69, 62, 84, 53, 41, 77, 80}
x3 irá conter {41, 39, 82}
OBS: as ações 1, 2 e 3 do menu devem acionar as respectivas funções que deverão executar as ações solicitadas em cada item. Ao escolher opção inválida no menu deve exibir mensagem com tal informação.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

void leitura(int vet[], int qtd);
void mostra(int vet[], int qtd);
void intersec(int veta[], int vetb[]);


main()
{
    setlocale (LC_ALL, "Portuguese");


    int i, x, menu = -1, gerou = 0, a[10], b[10];

    srand(time(NULL));


    do
    {
        system("cls");
        cout << "##### MENU DE OPÇÕES #####" << endl;
        cout << "# 0 - Sair               #" << endl;
        cout << "# 1 - Gerar Vetores      #" << endl;
        cout << "# 2 - Mostrar Vetores    #" << endl;
        cout << "# 3 - Intersecção        #" << endl;
        cout << "##########################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
        case 0 :
            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;

        case 1 :


            system("cls");

            leitura(a, 10);
            leitura(b, 10);
            cout << "Vetores Gerados." << endl;

            gerou = 1;
            getchar();

            break;


        case 2:
            system("cls");

            if(gerou != 0)
            {
                cout << "Vetor A: " << endl;
                mostra(a, 10);

                cout << "\n\nVetor B: " << endl;
                mostra(b, 10);

            }

            else
            {
                cout << "\nÉ NECESSÁRIO GERAR O VETOR PRIMEIRO";
            }

            getchar();
            break;




        case 3 :
            system("cls");

            if(gerou != 0)
            {

                cout << "Vetor A: " << endl;
                mostra(a, 10);
                cout << "\n\nVetor B: " << endl;
                mostra(b, 10);

                cout << "\n\nIntersecção dos vetores: ";
                intersec(a, b);

            }


            else
                cout << "\nÉ NECESSÁRIO GERAR O VETOR PRIMEIRO";
            getchar();
            break;

        default :
            system("cls");
            cout << "Opção inválida.";
            getchar();
            break;
        };

    }
    while(menu != 0);


}

void leitura(int vet[], int qtd)
{
    fflush(stdin);
    int contV = 0,valor;
    bool repetido;


    for(int i = 0; i < 10; i++)
    {
        do
        {
            valor = rand()% 49 + 36; // 0..40

            repetido = false;
            for(int j=0; j < contV; j++)//loop de 0 até (i-1) -> o vetor foi preenchidocom valores não repetidos até (i-1)
            {
                if(vet[j] == valor)
                    repetido = true;
            }
            if(repetido == false)
            {
                vet[i] = valor;
                contV++;
            }
        }
        while(repetido == true);
    }


    return;
}




void mostra(int vet[], int qtd)
{
    cout << "Vetor [";
    for(int d = 0; d < 10; d++)
    {
        cout << vet[d] << " ";
    }
    cout << "]";

    return;
}

void intersec(int veta[], int vetb[])
{
    int vetc[10], cont = 0;

    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            if(veta[x] == vetb[y])
            {
                vetc[cont] = veta[x];
                cont++;
            }

        }
    }

    for(int x = 0; x < cont; x++)
    {
        cout << vetc[x] << " ";
    }

    return;




}





