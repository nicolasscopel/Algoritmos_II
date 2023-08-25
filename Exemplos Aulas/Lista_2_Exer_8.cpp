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
    cout << "Informe o endereço de e-mail que deseja validar: ";
    gets(email);
    fflush(stdin);

    //Verificar se contém a quantidade mínima de caracteres
    //sabendo que @gmail.com ocupa 10 posições

    if((strlen(email)) < 11)
    {
        v = 0;
        cout << "O e-mail informado não possui a quantidade mínima de caracteres" << endl;
    }

    //Verificar se o primeiro caracter é um número
    if(v == 1)
    {
        if (isdigit(email[0]))
        {
            v = 0;
            cout << "O e-mail não pode iniciar por um número" << endl;
        }
    }


    //Verificar se existe espaço em branco
    if(v == 1)
    {
        for(int i = 0; i < strlen(email); i++)
        {
            if(isspace(email[i]))
            {
                v = 0;
                cout << "O e-mail não pode ter espaços em branco" << endl;
                break;
            }
        }
    }

    //Verificar se é um alfanumérico ou underline ou ponto
    if(v == 1)
    {
        for(int i = 0; i < strlen(email); i++)
        {
            if(!isalnum(email[i]))
            {
                if(email[i] != '@' && email[i] != '_' && email[i] != '.')
                {
                    v = 0;
                    cout << "O e-mail contém caracteres inválidos" << endl;
                    break;
                }
            }
        }
    }

    //Verificar se todos os caracteres são minúsculos
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
            cout << "O e-mail não pode ter caracteres maiúsculos" << endl;
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
            cout << "O e-mail só pode conter um vez o caracter @" << endl;
        }
    }

    //Verificar se termina com @gmail.com
    if(v == 1)
    {
        cont = 0;
        int i, x = 0;
        //percorre até encontrar o @
        for(i = 0; i < strlen(email); i++)
        {
            if (email[i] == '@')
                break;
        }

        //após o @ verifica se os elementos são iguais aos solicitados
        //que estão inclusos no vetor aux.
        for(int j = i + 1; j < strlen(email); j++)
        {
            if(email[j] != aux[x])
            {
                v = 0;
                cout << "O e-mail não termina com gmail.com" << endl;
                break;
            }
            x++;
        }
    }

    if(v)
        cout << "VÁLIDO";
    else
        cout << "INVÁLIDO";
}
