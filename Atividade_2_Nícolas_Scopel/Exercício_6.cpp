/* 6 – Escreva um programa que receba um texto qualquer do teclado, em seguida
apresente:
- Total de caracteres do texto
- Total de caracteres em maiúsculo e em minúsculo do texto
- Total de vogais
- Total de consoantes
- Total de números
- Total de espaços em branco*/

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

    char texto[50];
    int x, cont = 0, contmai = 0, contmin = 0, contesp = 0, contvog = 0, contconso = 0, contnum = 0;

    cout << "Digite seu texto: ";
    gets(texto);


    for(x = 0; x < strlen(texto); x++)
    {
        if(isalnum(texto[x]))
        {
            cont ++;
        }
        else if(isspace(texto[x]))
        {
            contesp++;
        }

    }
    cout << "O total de caracteres do seu texto é de: " << cont << endl;

    for(x = 0; x < strlen(texto); x++)
    {
        if(isalpha(texto[x]))
        {
            if(islower(texto[x]))
            {
                contmin++;
            }
            else

                contmai++;
        }
    }

    cout << "O total de caracteres minúsculos do seu texto é de: " << contmin << endl;
    cout << "O total de caracteres maiúsculos do seu texto é de: " << contmai << endl;

    for(x = 0; x < strlen(texto); x++)
    {
        if(isalpha(texto[x]))
        {
            if(texto[x] == 'a' || texto[x] == 'e' || texto[x] == 'i' || texto[x] == 'o' || texto[x] == 'u'
               ||texto[x] == 'A' ||texto[x] == 'E' ||texto[x] == 'I' ||texto[x] == 'O' ||texto[x] == 'U')
            {
                contvog++;
            }
            else
            {
                 contconso++;
            }

        }
    }

    for(x = 0; x < strlen(texto); x++)
    {
        if(isdigit(texto[x]))
        {
            contnum++;
        }
    }


    cout << "O total de vogais do seu texto é de: " << contvog << endl;
    cout << "O total de consoantes do seu texto é de: " << contconso << endl;
    cout << "O total de numeros do seu texto é de: " << contnum << endl;
    cout << "O total de espacos do seu texto é de: " << contesp << endl;
















}
