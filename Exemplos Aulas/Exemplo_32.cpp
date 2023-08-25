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
    escreve.open("exemplo_32.txt", ios::app);

    int num, soma = 0;

    ifstream ler("exemplo_32.txt", ios::in);
    if(ler.is_open())
    {
        cout << "\nLeitura realizada com sucesso" << endl;
        ler >> num;
        while(!ler.eof())
        {
            cout << num << endl;
            soma += num;
            ler >> num;
        }
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }
    ler.close();

    cout << "\n\nSoma dos valores: " << soma << endl;

}
