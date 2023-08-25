/*30 � Crie um programa que apresente um menu com as seguintes op��es:
0 � Sair
1 � Cadastrar
2 � Mostrar
3 � Consultar
Onde, a op��o 1 permita que o usu�rio informe o nome completo de uma pessoa e o sistema
dever� incluir este nome em um arquivo texto chamado �cadastro.txt�, colocando cada nome
em uma linha e mantendo os nomes j� cadastrados.
Op��o 2 dever� ler o arquivo texto e mostrar os nomes na tela.
Op��o 3 dever� solicitar um nome qualquer e verificar se o nome j� existe no arquivo texto.
Exibindo a respectiva informa��o na tela.*/




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
    int i, x, menu = -1, ver;
    string nome;
    char texto[100];
    char procura[100];


    ofstream escrever("cadastro.txt", ios::app);
    escrever.close();



    do
    {
        system("cls");
        cout << "=========== MENU DE OP��ES ===========" << endl;
        cout << "- 0 - Sair                           -" << endl;
        cout << "- 1 - Cadastrar                      -" << endl;
        cout << "- 2 � Mostrar                        -" << endl;
        cout << "- 3 � Consultar                      -" << endl;
        cout << "======================================" << endl;
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
            escrever.open("cadastro.txt",ios::app);

            if(escrever.is_open())
            {
                cout << "\nLeitura do arquivo realizada com sucesso!" << endl;

                cout << "\nInforme um nome para gravar no arquivo: " ;
                getline(cin,nome);
                fflush(stdin);
                escrever << nome;
                escrever << "\n";

            }
            else
            {
                cout << "\nErro ao abrir o arquivo:";
            }

            escrever.close();



            getchar();
            break;
        }


        case 2:
        {



            system("cls");

            ifstream ler("cadastro.txt", ios::in);

            if(ler.is_open())
            {
                cout << "\nLeitura realizada com sucesso" << endl;
                cout << "\nNomes gravados no arquivo: " << endl;
                while(ler.getline(texto,100))
                {
                    cout << texto << endl;
                }
            }
            else
            {
                cout << "Erro ao abrir o arquivo";
            }
            ler.close();



            getchar();
            break;
        }


        case 3:
        {
            int cont = 0;
            system("cls");

            ifstream ler("cadastro.txt",ios::in);

            if(ler.is_open())
            {
                cout << "\nLeitura realizada com sucesso" << endl;
                cout << "\nInforme um nome para procurar no arquivo: ";
                cin.getline(procura,100);

                fflush(stdin);

                while(ler.getline(texto,100))
                {
                    if((strcmp(procura,texto)) == 0)
                    {
                        cout << "\nNome encontrado: " << texto << endl;
                        cont++;
                    }

                }
                if(cont == 0)
                {
                    cout << "Nome nao encotrado!";
                }


            }
            else
            {
                cout << "Erro ao abrir o arquivo";
            }
            ler.close();

            getchar();
            break;

        }

        default:
            system("cls");
            cout << "Op��o inv�lida.";
            getchar();
            break;
        };
    }
    while(menu != 0);





}
