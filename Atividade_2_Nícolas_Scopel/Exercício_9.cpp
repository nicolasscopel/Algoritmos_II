/* 9 - Um pangrama � uma frase que cont�m todas as letras de um determinado alfabeto.
Em portugu�s, um pangrama pode incluir tamb�m letras acentuadas, mas neste
problema vamos desconsiderar os acentos (mesmo que isso torne a frase mal escrita!),
tamb�m vamos considerar o seguintes alfabeto:
a b c d e f g h i j l m n o p q r s t u v x z
N�o consideramos as letras k, w ou y. Note ainda que as frases n�o cont�m letras
acentuadas mas podem conter s�mbolos gr�ficos como espa�o em branco, v�rgula, ponto
e dois pontos.
Entrada
Uma �nica linha da entrada cont�ndo uma cadeia de caracteres C.
Sa�da
Seu programa deve produzir uma �nica linha, contendo um �nico caractere, que deve
ser S se a frase for um pangrama ou N caso contr�rio.
Restri��es
A cadeia de caracteres C tem no m�nimo um e no m�ximo 200 caracteres. Os �nicos
caracteres em C s�o as letras min�sculas do alfabeto mostrado acima, podem existir
caracteres repetidos, espa�os em branco, v�rgulas, ponto e o caractere dois pontos.
Exemplos
Entrada Sa�da
abcdefghijlmnopqrstuvxz   S
esta frase nao usa todas as letras, estao faltando algumas    N
grave e cabisbaixo, o filho justo zelava pela querida mae doente    S*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

main()
{
    setlocale (LC_ALL, "Portuguese");

    string vet = {"abcdefghijlmnopqrstuvxz"};
    char palavra[200];
    int x, y, cont = 0;

    cout << "Informe um texto qualquer: ";
    cin.getline(palavra,sizeof(palavra));

    for(y = 0; y < 23; y++)
    {
        for(x = 0; x < strlen(palavra); x++)
        {
            if(vet[y] == palavra[x])
            {
                cont++;
                break;
            }
        }
    }

    if(cont == 23)
    {
        cout << "\nS\n";
    }
    else
    {
        cout << "\nN\n";
    }



}
