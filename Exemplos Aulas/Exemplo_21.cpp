#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
void ajuste(int *x, int *i);

main()
{
    setlocale(LC_ALL, "Portuguese");
    int n1, n2;
    cout << "Informe o valor 1: ";
    cin >> n1;
    fflush(stdin);

    cout << "Informe o valor 2: ";
    cin >> n2;
    fflush(stdin);

    ajuste(&n1, &n2);

    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;

}

void ajuste(int *x, int *i)
{
    *x += 4;
    *i -= 2;
    cout << "Valores na fun��o ajuste: " << endl;
    cout << "*x = " << *x << endl;
    cout << "*i = " << *i << endl;
}
