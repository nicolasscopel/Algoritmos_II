#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
//protótipo da função
int leitura(char texto[50]);
//void soma(int a, int b);
int soma(int a, int b);

main()
{
    setlocale(LC_ALL,"portuguese");
    int a, b;

    a = leitura("Informe o valor A: ");
    b = leitura("Informe o valor B: ");

    cout << "Valor de A: " << a << endl;
    cout << "Valor de B: " << b << endl;

    //soma(a, b);

    cout << "A soma de " << a << " + " << b << ": " << soma(a,b) << endl;
}

int leitura(char texto[50])
{
    int v;
    cout << texto;
    cin >> v;
    fflush(stdin);
    return v;
}

/*
void soma(int a, int b)
{
    int s;
    s = a + b;
    cout << "A soma de " << a << " + " << b << ": " << s << endl;
}
*/

int soma(int vet[10])
{
    return (a + b);
}
