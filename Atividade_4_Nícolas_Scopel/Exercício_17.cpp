/* 17 - Crie um programa que manipule uma matriz de inteiros m[7][7]. Utilizando funções o
programa deverá apresentar um menu para acionar as seguintes funcionalidades:
1 – Gerar valores para preencher a matriz, não sendo permitido números duplicados e devem
ser menores que 100.
2 – Mostrar a matriz na tela
3 - Encontrar o maior elemento de cada linha e passá-lo para a posição da diagonal principal na
linha e o elemento que estava na diagonal principal para o local do número, exibir a matriz
original e depois modificada.
4 – Verificar se a Matriz é uma matriz simétrica
5 – Mostrar os elementos acima e abaixo da diagonal principal*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void gerar(int mat[][7]);
void mostra(int mat[][7]);
void dpmudada(int mat[][7], int dif[][7]);
void simetrica(int mat[][7]);
void acimadp(int mat[][7]);
void abaixodp(int mat[][7]);




main()
{
    setlocale (LC_ALL, "Portuguese");

    int i, x, menu = -1, gerou = 0, m[7][7], d[7][7];

    srand(time(NULL));

    do
    {
        system("cls");
        cout << "=================== MENU DE OPÇÕES ==================" << endl;
        cout << "- 0 - Sair                                          -" << endl;
        cout << "- 1 - Gerar Matriz                                  -" << endl;
        cout << "- 2 - Mostrar Matriz                                -" << endl;
        cout << "- 3 - Trocar maior elemento da linha com a DP       -" << endl;
        cout << "- 4 - Verificar se e simetrica                      -" << endl;
        cout << "- 5 - Elementos acima e abaixo da DP                -" << endl;
        cout << "=====================================================" << endl;
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

            gerar(m);

            cout << "Matriz Gerada." << endl;

            gerou = 1;
            getchar();

            break;


        case 2:
            system("cls");

            if(gerou != 0)
            {
                cout <<"\nMatriz: " << endl;
                mostra(m);


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

                cout <<"\nMatriz: " << endl;
                mostra(m);

                cout <<"\nMatriz com as trocas realizadas: " << endl;
                dpmudada(m, d);

            }


            else
                cout << "\nÉ NECESSÁRIO GERAR O VETOR PRIMEIRO";
            getchar();
            break;




        case 4 :
            system("cls");

            if(gerou != 0)
            {
                cout <<"\nMatriz: " << endl;
                mostra(m);

                simetrica(m);

            }


            else
                cout << "\nÉ NECESSÁRIO GERAR O VETOR PRIMEIRO";
            getchar();
            break;

        case 5 :
            system("cls");

            if(gerou != 0)
            {
                cout <<"\nMatriz: " << endl;
                mostra(m);

                cout << "Elementos acima da DP: " << endl;
                acimadp(m);

                cout << "\nElementos abaixc da DP: " << endl;
                abaixodp(m);


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

void gerar(int mat[][7])
{
    fflush(stdin);
    int contV = 0,valor;

    bool repetido;


    for(int i = 0; i < 7; i++)
    {
        for(int x = 0; x < 7; x++)
        {
            do
            {
                valor = rand()% 100;

                repetido = false;
                for(int i = 0; i < 7; i++)
                {
                    for(int x = 0; x < 7; x++)
                    {
                        if(mat[i][x] == valor)
                            repetido = true;
                    }
                }
                if(repetido == false)
                {
                    mat[i][x] = valor;

                }
            }
            while(repetido == true);
        }

    }


    return;
}

void mostra(int mat[][7])
{
    int i, x;
    for(i = 0; i < 7; i++)
    {
        for(x = 0; x < 7; x++)
        {
            cout << mat[i][x] << "\t";
        }
        cout << "\n";
    }
}

void dpmudada(int mat[][7], int dif[][7])
{
    int i, x, maior = 0, aux = 0, pos;

    for(i = 0; i < 7; i++)
    {

        for(x = 0; x < 7; x++)
        {
            dif[i][x] = mat[i][x];
        }
    }


    for(i = 0; i < 7; i++)
    {
        maior = 0;
        aux = dif[i][i];

        for(x = 0; x < 7; x++)
        {
            if(dif[i][x] > maior)
            {
                maior = dif[i][x];
                pos = x;
            }

        }

        dif[i][i] = dif[i][pos];
        dif[i][pos] = aux;
    }


    for(i = 0; i < 7; i++)
    {
        for(x = 0; x < 7; x++)
        {
            cout << dif[i][x] << "\t";
        }
        cout << "\n";
    }
}

void simetrica(int mat[][7])
{
    int i, x, cont = 0;

     for(i = 0; i < 7; i++)
    {

        for(x = 0; x < 7; x++)
        {
            if(mat[i][x] = mat[x][i])
                cont++;
        }
    }


    if(cont == 21)
    {
        cout << "É Simétrica." << endl;

    }

      else
      {
          cout << "Não é simétrica." << endl;
      }

}

void acimadp(int mat[][7])
{
    int i, x;

    for(i = 0; i < 7; i++)
    {

        for(x = 0; x < 7; x++)
        {
            if(x > i)
                cout << mat[i][x] << " ";
        }
    }


}

void abaixodp(int mat[][7])
{
    int i, x;

    for(i = 0; i < 7; i++)
    {
        for(x = 0; x < 7; x++)
        {
            if(x < i)
            {
                cout << mat[i][x] << " ";
            }

        }
    }



}
