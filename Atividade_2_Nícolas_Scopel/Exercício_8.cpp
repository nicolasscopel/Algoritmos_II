/*8 - Escreva um programa que recebe uma string do usu�rio e verifica se ela � um
endere�o de e-mail do google v�lido, sabendo que os endere�os de e-mail do google
seguem o seguinte formato:
textoqualquer@gmail.com
Algumas restri��es importantes:
- endere�os de e-mail n�o podem conter espa�o em branco
- obrigatoriamente deve aparecer somente uma vez o caracter @
- considere que neste caso o endere�o de e-mail n�o pode iniciar por um n�mero
- endere�o de e-mail s� pode conter caracteres min�sculos
- o �_� underline e o �.� ponto podem aparecer entre duas palavras
Apresente como sa�da a mensagem �V�LIDO� se o endere�o for correto ou �INV�LIDO�
se o endere�o n�o estiver correto
Exemplos
Entrada Sa�da
52novo@gmail.com INV�LIDO
meu_email@gmail.com V�LIDO
teste@GMAIL.com INV�LIDO
pedro.freitas@gmail INV�LIDO*/




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

    char email[50], dom[11];
    int tam, x, y, contesp = 0, conta = 0, contnum = 0, contmai = 0, contpon = 0;

    cout << "Informe o seu e-mail: ";
    gets(email);

    fflush(stdin);
    tam = strlen(email);

    for(x = strlen(email) - 10, y = 0; y < 10; y++, x++)
    {
        dom[y] = email[x];
    }

    for(y = 0; y < strlen(email) ; y++)
    {
        if(isspace(email[y]))
        {
            contesp++;
        }
    }

    for(y = 0; y < strlen(email) ; y++)
    {
        if(isupper(email[y]))
        {
            contmai++;
        }
    }


    if(isdigit(email[0]))
    {
        contnum++;
    }


    for(y = 0; y < strlen(email); y++)
    {
        if(email[y] == '@')
        {
            conta++;
        }
    }

    x = strlen(email) - 11;


    if(isalpha(email[x]) && isalpha(email[0]))
    {
        contpon++;
    }

    cout << "\nE-mail digitado: ";
    cout << email << "\n";



    if((strcmp(dom,"@gmail.com")) == 0 && conta == 1 && contesp == 0 && contnum == 0 && contmai == 0 && contpon == 1)
    {
        cout << "V�LIDO.\n";
    }
    else
    {
        cout << "INV�LIDO.\n";
    }




}
