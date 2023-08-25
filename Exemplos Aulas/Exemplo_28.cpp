#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL, "Portuguese");
    int *tamanho = new int;
    cout << "Informe o número de linhas da matriz: ";
    cin >> *tamanho;
    fflush(stdin);

    int (*pmat)[5] = new int[*tamanho][5];

    for(int *i = new int(0); *i < *tamanho; (*i)++)
    {
        for(int *j = new int(0); *j < 5; (*j)++)
        {
            pmat[*i][*j] = rand() % 100;
        }
    }

    for(int *i = new int(0); *i < *tamanho; (*i)++)
    {
        for(int *j = new int(0); *j < 5; (*j)++)
        {
            cout << pmat[*i][*j] << "\t";
        }
        cout << endl;
    }

}
