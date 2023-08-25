#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

main()
{
    setlocale(LC_ALL,"portuguese");
    string teste;
    cout << "Informe um texto qualquer: ";
    getline(cin, teste);
    fflush(stdin);

    cout << teste << endl;

    if(isalnum(teste[4]))
        cout << "Letra ou número";
    else
        cout << "Caracter especial";
}
