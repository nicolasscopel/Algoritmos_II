#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
void leitura(int **px2);
void calcula(int ***px3);

main()
{
    setlocale(LC_ALL, "Portuguese");
    int x, *px;
    px = &x;
    cout << "Endere�o do ponteiro px: " << px << endl;
    leitura(&px);

    cout << endl << x << endl;
}

void leitura(int **px2)
{
    cout << "Informe um valor: ";
    cin >> **px2;
    fflush(stdin);
    calcula(&px2);
}

void calcula(int ***px3)
{
    ***px3 += 8;
    if(***px3 % 2 == 0)
        cout << "O resultado " << ***px3 << " � par;";
    else
        cout << "O resultado " << ***px3 << " � �mpar;";

    cout << "Endere�o do ponteiro original px: " << **px3 << endl;
}
