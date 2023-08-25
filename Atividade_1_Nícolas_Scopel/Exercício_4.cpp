/* 4 - Crie um programa que manipule um vetor V[10] que deve ser preenchido randomicamente com valores inteiros entre 15 e 50, sem números repetidos.
Após gerar o vetor o programa deverá:
- Exibir o vetor na tela
- Exibir o vetor em ordem crescente
- Exibir a quantidade de valores pares e ímpares existentes no vetor
- Exibir o percentual de valores pares e o percentual de valores ímpares no vetor
- Exibir a média dos valores do vetor com duas casas decimais.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

main()
{
    setlocale (LC_ALL, "Portuguese");

    int vet[10], contV=0, contGerador=0, valor, i = 0, j = 0, aux = 0 ;
    float percentp = 0, percenti = 0, contp = 0, contimp = 0, soma = 0, media = 0;


    bool repetido;

    srand(time(NULL));




    for(int i=0; i < 10; i++)
    {
        do
        {
            valor = rand()% 49 + 1;
            contGerador++;
            repetido = false;
            for(int j=0; j<contV; j++)//loop de 0 até (i-1) -> o vetor foi preenchidocom valores não repetidos até (i-1)
            {
                if(vet[j] == valor)
                    repetido = true;
            }
            if(repetido == false)
            {
                vet[i] = valor;
                contV++;
            }
        }
        while(repetido == true);
    }

    cout << " Vetor Gerado: ";
    cout << "[";


    for(int i=0; i < 10; i++)
    {
        //mostra
        cout << vet[i]<< " ";

    }
    cout << "]";
    cout << endl;


    cout << " Vetor em ordem crescente: ";
    cout << "[";

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j <=9; j++)
        {
            if(vet[i] < vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;

            }
        }
    }

    for(i = 0; i < 10; i++)
    {
        cout << vet[i] << " ";
    }
    cout << "]";

    for(i = 0; i < 10; i++)
    {
        if(vet[i] % 2 == 0)
        {
            contp++;
        }
        else
        {
            contimp++;
        }

    }

    cout << " \n A quantidade de pares e: " << contp << endl;
    cout << " A quantidade de impares e: " << contimp << endl;



    cout << " O percentual de pares e: " << (contp / 10) * 100<< "%" << endl;
    cout << " O percentual de impares e: " << (contimp / 10) * 100 << "%" << endl;

    for(i = 0; i < 10; i++)
    {
        soma += vet[i];

    }

    media = soma / 10;

    cout << fixed;
    cout.precision(2);

    cout << " Media dos valores: " << media << endl;




}
