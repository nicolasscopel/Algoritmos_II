/*8 - Escreva um programa que recebe uma string do usuário e verifica se ela é um
endereço de e-mail do google válido, sabendo que os endereços de e-mail do google
seguem o seguinte formato:
textoqualquer@gmail.com
Algumas restrições importantes:
- endereços de e-mail não podem conter espaço em branco
- obrigatoriamente deve aparecer somente uma vez o caracter @
- considere que neste caso o endereço de e-mail não pode iniciar por um número
- endereço de e-mail só pode conter caracteres minúsculos
- o “_” underline e o “.” ponto podem aparecer entre duas palavras
Apresente como saída a mensagem “VÁLIDO” se o endereço for correto ou “INVÁLIDO”
se o endereço não estiver correto
Exemplos
Entrada Saída
52novo@gmail.com INVÁLIDO
meu_email@gmail.com VÁLIDO
teste@GMAIL.com INVÁLIDO
pedro.freitas@gmail INVÁLIDO*/




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
        cout << "VÁLIDO.\n";
    }
    else
    {
        cout << "INVÁLIDO.\n";
    }




}
