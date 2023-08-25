#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>

using namespace std;

main()
{
    setlocale(LC_ALL, "Portuguese");

    ofstream escreve;
    escreve.open("exemplo_29.txt", ios::app);

    if(escreve.is_open())
    {
        cout << "Arquivo aberto com sucesso.";
        escreve << "Meu terceiro teste com arquivo texto";
        escreve << "\n";
        escreve << "usando abertura app";
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }


}
