#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
//protótipo da função
int leitura(char texto[50]);
int soma(int &x, int &y);

main()
{
    setlocale(LC_ALL,"portuguese");
    int a, b, res;

    a = leitura("Informe o valor A: ");
    b = leitura("Informe o valor B: ");

    cout << "Valor de A: " << a << endl;
    cout << "Valor de B: " << b << endl;

    res = soma(a,b);
    cout << "A soma de " << a << " + " << b << ": " << res << endl;

    cout << "Valor de A atualizado: " << a << endl;
    cout << "Valor de B atualizado: " << b << endl;
}

int leitura(char texto[50])
{
    int v;
    cout << texto;
    cin >> v;
    fflush(stdin);
    return v;
}

int soma(int &x, int &y)
{
    if(x % 2 == 0)
        x *= 2;
    else
        x -= 3;
    y += 5;
    return (x + y);
}
