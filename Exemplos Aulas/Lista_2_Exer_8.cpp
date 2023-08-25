#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;

main()
{
    setlocale(LC_ALL,"portuguese");
    char email[200], aux[] = "gmail.com";
    int cont = 0;
    bool v = 1;
    cout << "Informe o endere�o de e-mail que deseja validar: ";
    gets(email);
    fflush(stdin);

    //Verificar se cont�m a quantidade m�nima de caracteres
    //sabendo que @gmail.com ocupa 10 posi��es

    if((strlen(email)) < 11)
    {
        v = 0;
        cout << "O e-mail informado n�o possui a quantidade m�nima de caracteres" << endl;
    }

    //Verificar se o primeiro caracter � um n�mero
    if(v == 1)
    {
        if (isdigit(email[0]))
        {
            v = 0;
            cout << "O e-mail n�o pode iniciar por um n�mero" << endl;
        }
    }


    //Verificar se existe espa�o em branco
    if(v == 1)
    {
        for(int i = 0; i < strlen(email); i++)
        {
            if(isspace(email[i]))
            {
                v = 0;
                cout << "O e-mail n�o pode ter espa�os em branco" << endl;
                break;
            }
        }
    }

    //Verificar se � um alfanum�rico ou underline ou ponto
    if(v == 1)
    {
        for(int i = 0; i < strlen(email); i++)
        {
            if(!isalnum(email[i]))
            {
                if(email[i] != '@' && email[i] != '_' && email[i] != '.')
                {
                    v = 0;
                    cout << "O e-mail cont�m caracteres inv�lidos" << endl;
                    break;
                }
            }
        }
    }

    //Verificar se todos os caracteres s�o min�sculos
    if(v == 1)
    {
        cont = 0;
        for(int i = 0; i < strlen(email); i++)
        {
            if (isupper(email[i]))
                cont++;
            if(cont > 0)
                break;
        }
        if (cont > 0)
        {
            v = 0;
            cout << "O e-mail n�o pode ter caracteres mai�sculos" << endl;
        }
    }

    //Contar quantas vezes o caracter @ aparece no e-mail
    if(v == 1)
    {
        cont = 0;
        for(int i = 0; i < strlen(email); i++)
        {
            if (email[i] == '@')
                cont++;
            if(cont > 1)
                break;
        }
        if (cont > 1)
        {
            v = 0;
            cout << "O e-mail s� pode conter um vez o caracter @" << endl;
        }
    }

    //Verificar se termina com @gmail.com
    if(v == 1)
    {
        cont = 0;
        int i, x = 0;
        //percorre at� encontrar o @
        for(i = 0; i < strlen(email); i++)
        {
            if (email[i] == '@')
                break;
        }

        //ap�s o @ verifica se os elementos s�o iguais aos solicitados
        //que est�o inclusos no vetor aux.
        for(int j = i + 1; j < strlen(email); j++)
        {
            if(email[j] != aux[x])
            {
                v = 0;
                cout << "O e-mail n�o termina com gmail.com" << endl;
                break;
            }
            x++;
        }
    }

    if(v)
        cout << "V�LIDO";
    else
        cout << "INV�LIDO";
}
