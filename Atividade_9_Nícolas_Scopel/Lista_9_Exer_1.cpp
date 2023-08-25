/* 6 – Crie um programa que receba um texto qualquer do teclado e implemente uma função que utilizando
aritmética de ponteiro realize as seguintes ações:
- Transformar todos os caracteres do texto para maiúsculo
- Remover os caracteres especiais existentes no texto
- Remover os espaços em branco.
- Contar quantas vogais existem no texto.
- Mostrar o texto resultante.
- Mostrar o total de vogais existentes no texto.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void exec(char *ptexto);

main()
{
    setlocale (LC_ALL, "Portuguese");


    char texto[100];



    cout << "Informe um texto: ";
    gets(texto);
    fflush(stdin);

    exec(texto);








}


void exec(char *ptexto)
{
    int cont = 0, contv = 0;
    string formatada;
    cout << "Texto com caracteres em maiúsculo: ";

    while(*ptexto)
    {
        *ptexto = toupper(*ptexto);

        cout << *ptexto;
        ptexto++;
        cont++;

    }

    ptexto -= cont;
    cont = 0;

    cout << "\nTexto sem caracteres especiais: ";

    while(*ptexto)
    {
        if(isalnum(*ptexto))
        {
            formatada += *ptexto;
        }
        if(isspace(*ptexto))
        {
            formatada += *ptexto;
        }
        ptexto++;
        cont++;

    }
    cout << formatada;

    ptexto -= cont;
    cont = 0;

    formatada = "";
    cout << "\nTexto sem espaços em branco: ";

    while(*ptexto)
    {
        if(isspace(*ptexto)== 0)
        {
            formatada += *ptexto;
        }

        ptexto++;
        cont++;

    }
    cout << formatada;

    ptexto -= cont;
    cont = 0;

     while(*ptexto)
    {
        if(*ptexto == 'A' || *ptexto == 'E' || *ptexto == 'I' || *ptexto == 'O' || *ptexto == 'U')
        {
            contv++;

        }
            ptexto++;
            cont++;
    }

    ptexto -= cont;
    cont = 0;














    cout << "\nNo texto existem " << contv << " vogais." << endl;

}
