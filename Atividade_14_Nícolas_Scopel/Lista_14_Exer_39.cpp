/*39 – Escrever um programa que gere um vetor V[20] com valores no intervalo de 0 a 100,
mostre os valores gerados e escreva-os em um arquivo texto chamado “exer_39.txt”. Após o
usuário deve informar duas posições do vetor (validar para aceitar 0 a 19) e o programa deverá
trocar os elementos destas posições e escrever o vetor alterado no arquivo texto e mostrar na
tela.*/




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

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int vet[20], i, n1, n2, aux;

    for(i = 0; i < 20; i++)
    {
        vet[i] = rand() % 101;
    }
    cout << "\nVetor Gerado: [";

    for(i = 0; i < 20; i++)
    {
        cout << vet[i] << " ";
    }
    cout << "]";

    ofstream escreve("exer_39.txt");

    if(escreve.is_open())
    {
    for(int x = 0; x < 20; x++)
    {
        escreve << vet[x];
        escreve << " ";
    }
        escreve.close();
    }
    else
    {
        cout << "NAO FOI POSSIVEL ABRIR O ARQUIVO!\n";
    }

    do
    {
        cout << "\nInforme a primeira posicao para trocar: ";
        cin >> n1;

    }while(n1 < 0 || n1 > 19);

     do
    {
        cout << "\nInforme a segunda posicao para trocar: ";
        cin >> n2;

    }while(n2 < 0 || n2 > 19 || n2 == n1);

    aux = vet[n1];
    vet[n1] = vet[n2];
    vet[n2] = aux;

    cout << "\nVetor Trocado: [";

    for(i = 0; i < 20; i++)
    {
        cout << vet[i] << " ";
    }
    cout << "]";

    escreve.open("exer_39.txt");

    if(escreve.is_open())
    {
    for(int x = 0; x < 20; x++)
    {
        escreve << vet[x];
        escreve << " ";
    }
        escreve.close();
    }
    else
    {
        cout << "NAO FOI POSSIVEL ABRIR O ARQUIVO!\n";
    }

}
