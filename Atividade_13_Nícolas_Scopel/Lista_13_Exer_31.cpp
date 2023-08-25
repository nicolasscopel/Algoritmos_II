/*31 – Crie um programa que leia um arquivo texto chamado “numeros.txt”, o qual contém uma
série de números separados por ponto e vírgula, o sistema deverá ler os números necessários
para preencher uma matriz 5 x 5 de números inteiros. Após ler os dados o sistema deverá exibir
um menu com as seguintes ações:
1 – Mostrar elementos da diagonal principal
2 – Mostrar os elementos da diagonal secundária
3 – Mostrar a matriz e a soma dos elementos acima e abaixo da diagonal principal.*/




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

    int i = 0,l,c, num, x, menu = -1, ver;
    char texto[10];
    int mat[5][5];



    ifstream ler("numeros.txt",ios::in);

    if(ler.is_open())
    {
        cout << "\nLeitura realizada com sucesso!" << endl;
        getchar();

        for(l = 0; l < 5; l++)
        {
            for(c = 0; c < 5; c++)
            {
                ler.getline(texto,4,';');
                mat[l][c] = atoi(texto);
            }
        }
    }

    else
    {
        cout << "\nErro de leitura.";
    }

    ler.close();

    do
    {


        system("cls");

        cout << "=================================== MENU DE OPÇÕES ===================================" << endl;
        cout << "- 0 - Sair                                                                           -" << endl;
        cout << "- 1 – Mostrar elementos da diagonal principal                                        -" << endl;
        cout << "- 2 – Mostrar os elementos da diagonal secundária                                    -" << endl;
        cout << "- 3 – Mostrar a matriz e a soma dos elementos acima e abaixo da diagonal principal.  -" << endl;
        cout << "======================================================================================" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)



        case 0:
    {


        system("cls");
        cout << "Programa finalizado.";
        getchar();
        break;

        case 1 :
        {
            system("cls");
            cout << "Elementos da Diagonal Principal: [";

            for(l = 0; l < 5; l++)
            {
                for(c = 0; c < 5; c++)
                {
                    if(l == c)
                    {
                        cout << mat[l][c] << " ";
                    }
                }
            }
            cout << "]";
            getchar();
            break;
        }

        case 2:
        {
            system("cls");
            cout << "\nElementos da Diagonal Secundaria: [";
            for(l = 0; l < 5; l++)
            {
                for(c = 0; c < 5; c++)
                {
                    if(l + c == 4)
                    {
                        cout << mat[l][c] << " ";
                    }
                }
            }
            cout << "]";
            getchar();
            break;
        }

        case 3:
        {
            int somaacima = 0, somaabaixo = 0;

            system("cls");
            cout << "\nMatriz Gerada: " << endl;
            for(l = 0; l < 5; l++)
            {
                for(c = 0; c < 5; c++)
                {
                    cout << mat[l][c] << "\t";
                }
                cout << "\n";
            }
            for( l = 0; l < 5; l++)
            {
                for(c = 0; c < 5; c++)
                {
                    if (l < c)
                        somaacima += mat[l][c];
                    else if (l > c)
                        somaabaixo += mat[l][c];
                }
            }
            cout << "\nSoma Acima DP: " << somaacima;
            cout << "\nSoma Abaixo DP: " << somaabaixo;
            getchar();
            break;
        }

        default:
            system("cls");
            cout << "Opção inválida.";
            getchar();
            break;
        };
    }
    while(menu != 0);



}
