/* 10 - Uma palavra A � um anagrama de outra palavra B se podemos transformar a
palavra A na palavra B apenas trocando de posi��o as letras da palavra A. Por exemplo,
"iracema" � um anagrama de "america", e "estudo" � um anagrama de "duetos".
Sabendo deste conceito escreva um programa que receba duas palavras diferentes
quaisquer e verifique se elas s�o um anagrama exibindo como resposta �SIM�, caso n�o
s�o um anagrama exibir �N�O�
Exemplos
Entrada Sa�da
coral
claro    SIM
porta
trapo   SIM
abacate
tesoura   N�O
a b   N�O*/




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

    char pala[15], compara[15];
    int x, y, cont = 0;

    cout << "Informe a primeira palavra: ";
    gets(pala);

    cout << "Informe a segunda palavra: ";
    gets(compara);

    x = strlen(pala);
    y = strlen(compara);

    if(x == y)
    {
        for(x = 0; x < strlen(pala); x++)
        {
            for(y = 0; y < strlen(compara); y++)
            {
                if(pala[x] == compara[y])
                {
                    cont++;
                    break;

                }
            }
        }
    }

    if(cont == strlen(pala))
        cout << "\nSIM\n";
    else
        cout << "\nNAO\n";










}
