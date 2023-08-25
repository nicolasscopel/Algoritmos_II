/* 3 - Elabore um programa que possibilite a realiza��o dos seguintes c�lculos:
1 � Potencia��o (entrada dois valores inteiros e positivos)
2 � Raiz quadrada (entrada um valor inteiro e positivo)
3 - Arredondar o valor seguindo o crit�rio da primeira casa decimal e mostrar na tela (entrada um valor float)
4 � Verificar se um valor � primo ou n�o (entrada um valor inteiro positivo)
5 � Verificar se um valor � um n�mero perfeito ou n�o (entrada um valor inteiro positivo).
O sistema dever� apresentar um menu com as op��es e conforme a op��o desejada ser� solicitado os dados de entrada.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL, "Portuguese");

    int menu, x, y, num, cont;
    int soma = 0;

    float arred;

    cout << fixed;
    cout.precision(2);

    do
    {
        system("cls");
        cout << "#####MENU DE OP��ES#####" << endl;
        cout << "# 0 - Sair             #" << endl;
        cout << "# 1 - Potencia��o      #" << endl;
        cout << "# 2 - Raiz Quadrada    #" << endl;
        cout << "# 3 - Arredondar       #" << endl;
        cout << "# 4 - Primo ou N�o     #" << endl;
        cout << "# 5 - N�mero Perfeito  #" << endl;
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
            system("cls");

            cout << " Informe o n�mero que sera elevado: ";
            cin >> x;

            cout << "\n Informe a qual n�mero ele sera elevado: ";
            cin >> y;

            cout << "\n A potenciacao realizada e: " << pow(x,y) << endl;

            fflush(stdin);
            getchar();
            break;

        case 2 :
            system("cls");

            cout << " Informe um numero para calcular sua raiz: ";
            cin >> num;

            cout << " O raiz desse numero e: " << sqrt(num) << endl;


            fflush(stdin);
            getchar();
            break;

        case 3 :
            system("cls");

            cout << " Informe um numero para fazer seu arredondamento: ";
            cin >> arred;

            cout << " O numero arredondado e: " << round(arred) << endl;


            fflush(stdin);
            getchar();
            break;

        case 4 :
            cont = 0;
            system("cls");

            cout << " Informe um numero para ser verificado se e primo ou nao: ";
            cin >> num;

            for (x = 1; x <= num; x++ )
            {

                if (num % x == 0)
                    cont++;
            }

            if (cont == 2)
                cout << " Esse numero e primo.";

            else
                cout << " Esse numero nao e primo.";

            fflush(stdin);
            getchar();
            break;

        case 5 :

            system("cls");
            fflush(stdin);


            cout << " Informe um numero para ser verificado se e perfeito ou nao: ";
            cin >> num;

            for (x = 1; x <= num; x++ )
            {

                if (num % x == 0 && num != x)

                    soma = soma + x;

            }

            if (soma == num )
                cout << " Esse numero � perfeito.";

            else
            {
                cout << " Esse numero nao e perfeito. " << endl;
            }
                soma = 0;

            fflush(stdin);
            getchar();
            break;



        default:
            system("cls");
            cout << "Op��o inv�lida.";
            getchar();
            break;
        }

    }while(menu != 0);

    }
