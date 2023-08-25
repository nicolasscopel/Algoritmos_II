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
    escreve.open("exemplo_31.txt", ios::app);

    char texto[10];
    int num, soma = 0;

    if(escreve.is_open())
    {
        cout << "Arquivo aberto com sucesso." << endl;
        cout << "Digite um Número qualquer: ";
        cin >> num;
        fflush(stdin);
        escreve << num;
        escreve << ";";
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }
    escreve.close();


    ifstream ler("exemplo_31.txt", ios::in);
    if(ler.is_open())
    {
        cout << "\nLeitura realizada com sucesso" << endl;
        while(ler.getline(texto,10, ';'))
        {
            cout << texto << endl;
            soma += atoi(texto);
        }
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }
    ler.close();

    cout << "\n\nSoma dos valores: " << soma << endl;

}
