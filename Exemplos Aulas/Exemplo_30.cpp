#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cstring>

using namespace std;

main()
{
    setlocale(LC_ALL, "Portuguese");

    ofstream escreve;
    escreve.open("exemplo_30.txt", ios::app);

    string nome;
    char c;
    char texto[100];

    if(escreve.is_open())
    {
        cout << "Arquivo aberto com sucesso.";
        cout << "Informe o nome para gravar no arquivo: ";
        getline(cin, nome);
        fflush(stdin);
        escreve << nome;
        escreve << "\n";
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }
    escreve.close();

    //ler caracter por caracter
    /*ifstream ler("exemplo_30.txt", ios::in);
    if(ler.is_open())
    {
        cout << "\nLeitura realizada com sucesso" << endl;
        while(ler.get(c))
        {
            cout << c << endl;
        }
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }
    ler.close();*/

    //ler linha inteira

    /*ifstream ler("exemplo_30.txt", ios::in);
    if(ler.is_open())
    {
        cout << "\nLeitura realizada com sucesso" << endl;
        while(ler.getline(texto,100))
        {
            cout << texto << endl;
        }
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }
    ler.close();*/

    //ler até um delimitador
    ifstream ler("exemplo_30.txt", ios::in);
    if(ler.is_open())
    {
        cout << "\nLeitura realizada com sucesso" << endl;
        while(ler.getline(texto,100, ';'))
        {
            cout << texto << endl;
        }
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }
    ler.close();



}
