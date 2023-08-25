/* 15 - Implemente um programa que manipule uma matriz, onde o n�mero de linhas deve ser alocado
dinamicamente (usu�rio informa quantas linhas) no m�ximo 20 e com 5 colunas, ap�s preencha a matriz
com valores rand�micos menores que 100, o programa dever� ter um menu com as seguintes op��es:
0 � Sair
1 � Gerar matriz (nesta op��o dever� ser informado o n�mero de linhas)
2 � Mostrar a matriz
3 � Soma das diagonais (dever� mostrar os elementos da diagonal principal e secund�ria, juntamente
com as respectivas somas)
4 � Mostrar a matriz de forma invertida (a primeira linha passa a ser a �ltima e a �ltima linha a primeira e
assim sucessivamente)
OBS: as op��es 2, 3 e 4 s� poder�o ser acionadas ap�s a execu��o da op��o 1 (mostrar mensagem com
tratamento deste erro), tratar op��o inv�lida no menu.



void mostra(int (*notas)[3], int n)
{
for(int i = 0; i < n; i++)
{
for(int j = 0; j < 3; j++)
{
cout << notas[i][j] << "\t";
}
cout << "\n";
}
}
*/




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
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int *i = new int (0);
    int *l = new int (0);
    int *x = new int(0);
    int *j = new int(0);
    int *menu = new int (-1);
    int *indice = new int (-1);
    int *tamanho = new int;
    int (*pmat)[5] = new int[*tamanho][5];
    int *somadp = new int (0);




    do
    {
        system("cls");
        cout << "================ MENU DE OP��ES ================" << endl;
        cout << "- 0 - Sair                                     -" << endl;
        cout << "- 1 - Gerar Matriz                             -" << endl;
        cout << "- 2 � Mostrar Matriz                           -" << endl;
        cout << "- 3 � Soma das diagonais                       -" << endl;
        cout << "- 4 � Mostrar a matriz invertida               -" << endl;
        cout << "================================================" << endl;
        cout << "Sua escolha: ";
        cin >> *menu;
        fflush(stdin);

        switch(*menu)

        {

        case 0:
            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;



        case 1 :

            system("cls");


            do
            {
                cout << "Informe o n�mero de linhas da matriz: ";
                cin >> *tamanho;


            }

            while(*tamanho < 1 || *tamanho > 20);

            pmat = new int [*tamanho][5];

            for( *l = 0; *l < *tamanho; (*l)++)
            {
                for( *j = 0 ; *j < 5; (*j)++)
                {
                    pmat[*l][*j] = rand() % 100;
                }
            }

            (*indice)++;

            cout << "\nMatriz Gerada!";



            getchar();
            break;


        case 2:

            system("cls");

            if(*indice < 0)
                cout << "Necessario gerar a matriz primeiro!";
            else
            {

                for( *l = 0; *l < *tamanho; (*l)++)
                {
                    for(*j = 0 ; *j < 5; (*j)++)
                    {
                        cout << pmat[*l][*j] << "\t";
                    }
                    cout << endl;
                }


            }

            getchar();
            break;


        case 3 :
            system("cls");

            if(*indice < 0)
            {
                cout << "Necessario gerar a matriz primeiro!";

            }


            if(*tamanho == 5)
            {


                cout << "Elementos da DP: ";

                for( *l = 0; *l < *tamanho; (*l)++)
                {
                    for(*j = 0 ; *j < 5; (*j)++)
                    {
                        if(*l == *j)
                        {
                            cout << pmat[*l][*j] << "  ";
                            *somadp += pmat[*l][*j];
                        }

                    }

                }


                cout << "\nSoma dos elementos: " << *somadp;
                *somadp = 0;


                cout << "\nElementos da DS: ";

                for( *l = 0; *l < *tamanho; (*l)++)
                {
                    for(*j = 0 ; *j < 5; (*j)++)
                    {
                        if(*l + *j == 4)
                        {
                            cout << pmat[*l][*j] << "  ";
                            *somadp += pmat[*l][*j];
                        }

                    }

                }
                cout << "\nSoma dos elementos da DS: " << *somadp;
                *somadp = 0;
            }
            if(*indice != -1 && *tamanho != 5)
            {
                cout << "\nNao existe diagonal principal de matriz nao quadrada!";
            }


            getchar();
            break;

        case 4:

            system("cls");

            if(*indice < 0)
                cout << "Necessario gerar a matriz primeiro!";
            else
            {

                for( *l = *tamanho - 1; *l > -1; (*l)--)
                {
                    for(*j = 0 ; *j < 5; (*j)++)
                    {
                        cout << pmat[*l][*j] << "\t";
                    }
                    cout << endl;
                }

            }

            getchar();
            break;



        default :
            system("cls");
            cout << "Op��o inv�lida.";
            getchar();
            break;
        };

    }
    while(*menu != 0);



}



