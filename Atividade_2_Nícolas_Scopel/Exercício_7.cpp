/*7 - Escreva um programa que recebe uma string qualquer do usuário e imprime a
mesma string em três formatos: todas as letras em maiúsculo, todas as letras em
minúsculo e somente as letras iniciais de cada palavra em maiúsculo o restante em
minúsculo.*/




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
    setlocale (LC_ALL, "Portuguese");


    string nome;
    cout << "Informe o nome: ";
    getline(cin, nome);
    fflush(stdin);

    for(int i = 0; i < nome.size(); i++)
    {
        nome[i] = toupper(nome[i]);
    }
    cout << "\nNome com todas as letras em maiúsculo: ";
    cout << nome << endl;

    for(int i = 0; i < nome.size(); i++)
    {
        nome[i] = tolower(nome[i]);
    }

    cout << "\nNome com todas as letras em minúsculo: ";
    cout << nome << endl;



    for(int i = 0; i < nome.size(); i++)
    {
        if(i == 0)
            nome[i] = toupper(nome[i]);
        else
        {
            if(isspace(nome[i]))
                nome[i + 1] = toupper(nome[i + 1]);
        }
    }

    cout << "\nNome com iniciais em maiúsculo: ";
    cout << nome << endl;






}
