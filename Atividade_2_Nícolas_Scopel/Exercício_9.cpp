/* 9 - Um pangrama é uma frase que contém todas as letras de um determinado alfabeto.
Em português, um pangrama pode incluir também letras acentuadas, mas neste
problema vamos desconsiderar os acentos (mesmo que isso torne a frase mal escrita!),
também vamos considerar o seguintes alfabeto:
a b c d e f g h i j l m n o p q r s t u v x z
Não consideramos as letras k, w ou y. Note ainda que as frases não contêm letras
acentuadas mas podem conter símbolos gráficos como espaço em branco, vírgula, ponto
e dois pontos.
Entrada
Uma única linha da entrada conténdo uma cadeia de caracteres C.
Saída
Seu programa deve produzir uma única linha, contendo um único caractere, que deve
ser S se a frase for um pangrama ou N caso contrário.
Restrições
A cadeia de caracteres C tem no mínimo um e no máximo 200 caracteres. Os únicos
caracteres em C são as letras minúsculas do alfabeto mostrado acima, podem existir
caracteres repetidos, espaços em branco, vírgulas, ponto e o caractere dois pontos.
Exemplos
Entrada Saída
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
