/*32 – Crie um programa que manipule um arquivo texto contendo em cada linha um número
inteiro qualquer, o programa deverá ler todos os números e apresentar os seguintes dados:
- Maior valor existente no arquivo
- Menor valor existente no arquivo
- Média aritmética dos valores no arquivo
- Quantidade de números pares e ímpares existentes no arquivo*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;

void leitura(int vet[], int qtd);
void maiorValor(int &maior, int vet[], int qtd);
void menorValor(int &menor, int vet[], int qtd);
float media(int vet[], int qtd);
void parImpar(int vet[], int qtd, int &p, int &i);


main()
{
    int i = 0, aux;
    ifstream doc("exer32.txt");
    if(doc.is_open())
    {
    while(!doc.fail())
    {
        doc >> aux;
        i++;
    }
        doc.close();
    }
    else
    {
        cout << "NAO FOI POSSIVEL ABRIR O ARQUIVO!\n";
    }
    i = i - 1;
    int X[i], M, m, pares = 0, impares = 0;
    leitura(X, i);
    maiorValor(M, X, i);
    cout << "MAIOR VALOR: " << M << endl;
    menorValor(m, X, i);
    cout << "MENOR VALOR: " << m << endl;
    cout << "MEDIA: " << media(X, i) << endl;
    parImpar(X, i, pares, impares);
    cout << "TOTAL DE PARES: " << pares << endl;
    cout << "TOTAL DE IMPARES: " << impares;
}

void leitura(int vet[], int qtd)
{
    ifstream doc("exer32.txt");
    if(doc.is_open())
    {
    for(int x = 0; x < qtd; x++)
    {
        doc >> vet[x];
    }
        doc.close();
    }
    else
    {
        cout << "NAO FOI POSSÍVEL ABRIR O ARQUIVO!\n";
    }
}

void maiorValor(int &maior, int vet[], int qtd)
{
    for (int x = 0; x < qtd; x++)
    {
        if (x == 0)
            maior = vet[x];
        else if (vet[x] > maior)
            maior = vet[x];
    }
}

void menorValor(int &menor, int vet[], int qtd)
{
    for (int x = 0; x < qtd; x++)
    {
        if (x == 0)
            menor = vet[x];
        else if (vet[x] < menor)
            menor = vet[x];
    }
}

float media(int vet[], int qtd)
{
    float soma = 0.0;
    for (int x = 0; x < qtd; x++)
    {
        soma += vet[x];
    }
    return (soma / qtd);
}

void parImpar(int vet[], int qtd, int &p, int &i)
{
    for (int x = 0; x < qtd; x++)
    {
        if (vet[x] % 2 == 0)
            p++;
        else if (vet[x] % 2 != 0)
            i++;
    }
}
