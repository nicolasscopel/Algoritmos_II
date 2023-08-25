#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;
//protótipo da função
void leitura(int vet[], int qtd);
void mostra(int vet[], int qtd);

main()
{
    setlocale(LC_ALL,"portuguese");
    int a[50], b[10];
    leitura(a, 50);
    leitura(b, 10);
    cout << "Vetor A: " << endl;
    mostra(&a[0], 50);

    cout << "\n\nVetor B: " << endl;
    mostra(b, 10);

}

void leitura(int vet[], int qtd)
{
    int i;
    srand(time(NULL));
    for(i = 0; i < qtd; i++)
    {
        vet[i] = rand() % 100;
    }
}

void mostra(int vet[], int qtd)
{
    int i;
    for(i = 0; i < qtd; i++)
    {
        cout << vet[i] << ", ";
    }
}

