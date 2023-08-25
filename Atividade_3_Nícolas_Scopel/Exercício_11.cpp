/* 11 – Crie programa em C++ que manipule um vetor de inteiros de 10 posições, o programa deve apresentar um menu com as seguintes opções:
0 – Sair
1 – Gerar Valores (Função que gera os valores para preencher o vetor com números entre 20 e 50 sem valores repetidos)
2 – Mostrar Vetor (Função que recebe o vetor e exibe seus valores na tela)
3 – Mostrar Ordenado (Função que recebe o vetor e exibe os seus valores ordenados em ordem crescente e decrescente)
OBS: A opção 2 e 3 do menu só podem ser executadas após a execução da opção 1, ao escolher a opção inválida do menu exibir mensagem de “opção inválida”. */

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

void gerar(int vet[]);
void mostra(int vet[]);
void ordemcresc(int vet[]);
void ordemdecresc(int vet[]);

main()
{
    setlocale (LC_ALL, "Portuguese");


    int i, x, menu = -1, gerou = 0;

    srand(time(NULL));


    do
    {
        system("cls");
        cout << "#####MENU DE OPÇÕES#####" << endl;
        cout << "# 0 - Sair             #" << endl;
        cout << "# 1 - Gerar Vetor      #" << endl;
        cout << "# 2 - Mostrar Vetor    #" << endl;
        cout << "# 3 - Mostrar Ordenado #" << endl;
        cout << "########################" << endl;
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

            int vet[10];
            system("cls");

            gerar(vet);

            gerou = 1;
            getchar();
            break;


        case 2:
            system("cls");

            if(gerou != 0)
            {
                mostra(vet);
            }

            else
            {
                cout << "\nÉ NECESSÁRIO GERAR O VETOR PRIMEIRO";
            }

            getchar();
            break;




        case 3 :
            system("cls");
            int aux;
            if(gerou != 0)
            {
                ordemcresc(vet);
                ordemdecresc(vet);
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

void gerar(int vet[])
{
    fflush(stdin);
    int contV = 0,valor;
    bool repetido;


    for(int i=0; i < 10; i++)
    {
        do
        {
            valor = rand()% 29 + 21; // 0..40

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

    cout << "Vetor gerado.";

    return;


}

void mostra(int vet[])
{
    cout << "Vetor [";
    for(int d = 0; d < 10; d++)
    {
        cout << vet[d] << " ";
    }
    cout << "]";

    return;
}


void ordemcresc(int vet[])
{
    int aux, i = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int x = i + 1; x < 10; x++)
        {
            if(vet[i] > vet[x])
            {
                aux = vet[i];
                vet[i] = vet[x];
                vet[x] = aux;
            }
        }
    }

    cout << "Vetor ordenado em ordem crescente [ ";
    for(i = 0; i < 10; i++)
    {
        cout << vet[i] << " ";
    }
    cout << "]";

    return;

}

void ordemdecresc(int vet[])
{
    int aux;
    for(int i = 0; i < 9; i++)
    {
        for( int x = i + 1; x < 10; x++)
        {
            if(vet[i] < vet[x])
            {
                aux = vet[i];
                vet[i] = vet[x];
                vet[x] = aux;
            }
        }
    }

    cout << "\n\nVetor ordenado em ordem descrescente [ ";
    for(int i = 0; i < 10; i++)
    {
        cout << vet[i] << " ";
    }
    cout << "]";

    return;

}
