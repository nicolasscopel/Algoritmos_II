/*30 – Crie um programa que apresente um menu com as seguintes opções:
0 – Sair
1 – Cadastrar
2 – Mostrar
3 – Consultar
Onde, a opção 1 permita que o usuário informe o nome completo de uma pessoa e o sistema
deverá incluir este nome em um arquivo texto chamado “cadastro.txt”, colocando cada nome
em uma linha e mantendo os nomes já cadastrados.
Opção 2 deverá ler o arquivo texto e mostrar os nomes na tela.
Opção 3 deverá solicitar um nome qualquer e verificar se o nome já existe no arquivo texto.
Exibindo a respectiva informação na tela.*/




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
        cout << "=========== MENU DE OPÇÕES ===========" << endl;
        cout << "- 0 - Sair                           -" << endl;
        cout << "- 1 - Cadastrar                      -" << endl;
        cout << "- 2 – Mostrar                        -" << endl;
        cout << "- 3 – Consultar                      -" << endl;
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
            cout << "Opção inválida.";
            getchar();
            break;
        };
    }
    while(menu != 0);





}
