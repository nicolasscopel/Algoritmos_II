/* 28 - Faça um programa para ler um arquivo texto (o usuário deve fornecer o nome do arquivo)
e o programa deverá imprimir seu conteúdo na tela. E em seguida mostrar quantos caracteres
existem no arquivo, quantas vogais e quantas consoantes.

http://tiagodemelo.info/livros/logica/node10.html
*/




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

    string nome;
    char texto[100], c;
    int cont = 0;
    int contvog = 0;

    cout << "Escreva o nome do arquivo a ser lido: ";
    cin >> nome;


    ifstream ler(nome, ios::in);

     if(ler.is_open())
    {
        cout << "\nLeitura realizada com sucesso!" << endl;
         cout << "\n\n";
         cout << "Texto do Arquivo: ";
        while(ler.getline(texto,100))
        {
            cout << texto << endl;

        }
        cout << "\n\n";

        ler.close();

    ler.open(nome, ios::in);


     if(ler.is_open())
    {
        while(ler.get(c))
        {
            if(isalnum(c))
            {
                cont++;
            }
            if(isspace(c))
            {
                cont--;
            }
           if(isalnum(c) == 0)
            {
                cont++;
            }
        }
    }
    cout << "Quantidade de caracteres do arquivo: " << cont << endl;

    ler.close();
    cont = 0;



    ler.open(nome, ios::in);

     if(ler.is_open())
    {
        while(ler.get(c))
        {
            if(isalpha(c))
            {
                cont++;
            }

        }
    }
    ler.close();

    ler.open(nome,ios::in);

    if(ler.is_open())
    {
        while(ler.get(c))
        {
            if((c) == 'A' || (c) == 'a' || (c) == 'E' || (c) == 'e' || (c) == 'I' ||(c) == 'O' || (c) == 'U' ||
               (c) == 'i' || (c) == 'o' || (c) == 'u')
            {
                contvog++;
            }

        }


    }
    cout << "Total de vogais: " << contvog;
    cout << "\nTotal de consoantes: " << cont - contvog;
    cout << "\n\n";

    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }

    ler.close();






}
