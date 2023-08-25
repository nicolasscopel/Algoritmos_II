#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    int *tamanho = new int;
    cout << "Informe o tamanho do vetor: ";
    cin >> *tamanho;
    fflush(stdin);

    int *pvet = new int[*tamanho];
    int *i = new int(0);
    srand(time(NULL));
    while(*i < *tamanho)
    {
        *pvet = rand() % 100;
        pvet++;
        (*i)++;
    }

    pvet -= *i;


    for(int *x = new int(0); *x < *tamanho; (*x)++)
    {
        cout << *pvet << ", ";
        pvet++;
    }

    delete []pvet;
    delete i;
}
