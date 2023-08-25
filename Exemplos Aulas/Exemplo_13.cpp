#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;
//protótipo da função
void leitura(int mat[][5]);
void mostra(int mat[][5]);

main()
{
    setlocale(LC_ALL,"portuguese");
    int a[10][5];
    leitura(a);
    cout << "MATRIZ A: " << endl;
    mostra(a);
}


void leitura(int mat[][5])
{
    int i, x;
    srand(time(NULL));
    for(i = 0; i < 10; i++)
    {
        for(x = 0; x < 5; x++)
        {
            mat[i][x] = rand() % 100;
        }
    }
}


void mostra(int mat[][5])
{
    int i, x;
    for(i = 0; i < 10; i++)
    {
        for(x = 0; x < 5; x++)
        {
            cout << mat[i][x] << "\t\t";
        }
        cout << "\n";
    }
}

