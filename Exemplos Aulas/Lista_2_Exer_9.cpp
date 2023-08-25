#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;

main()
{
    setlocale(LC_ALL,"portuguese");
    char texto[200], aux[200], alfabeto[] = "abcdefghijlmnopqrstuvxz";
    int cont = 0, x= -1;
    bool pangrama = 1;
    cout << "Informe um texto qualquer: ";
    gets(texto);
    fflush(stdin);

    //copia para o vetor aux somente os caracteres alfabéticos convertido para minúsculo
    for(int i = 0; i < strlen(texto); i++)
    {
        if(isalpha(texto[i]))
        {
            x++;
            aux[x] = tolower(texto[i]);
        }
    }

    //compara se cada caracter do alfabeto existe no texto lido
    for(int i = 0; i < strlen(alfabeto); i++)
    {
        cont = 0;
        for(int j = 0; j < strlen(aux); j++)
        {
            if(alfabeto[i] == aux[j])
                cont++;
        }
        if(cont == 0)
        {
            pangrama = 0;
            break;
        }
    }

    if(pangrama)
        cout << "S";
    else
        cout << "N";
}
