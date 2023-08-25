/*34 – Escreva um programa que leia uma sequência de valores de um arquivo texto, separados
por um espaço, a seguir ordene esses valores em ordem crescente e escreva novamente no
arquivo os valores ordenados.*/




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

void ordemCrescente(int vetor[], int tamanho){

    for(int i=0; i<tamanho; i++){

         for(int j=0; j<tamanho-1; j++){

            if(vetor[j] > vetor[i])
            {
                int aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
         }
    }
}

main()
{
    string nomeArquivo;

    cout << "Informe o nome do arquivo texto a ser lido (completo, com .txt no final): ";
    getline(cin, nomeArquivo);

    ifstream ler(nomeArquivo); // ios::in --> default


    char numeroTexto[20];
    int cont=0;

    if(ler.is_open()){

            while(ler.getline(numeroTexto, 20, ' '))
                cont++;

            int numerosLidos[cont];

            ler.close();
            ler.open(nomeArquivo, ios::in);

            int j=0;
            while(ler.getline(numeroTexto, 20, ' ')){
                numerosLidos[j++] = atoi(numeroTexto);

            }

             ofstream escrever(nomeArquivo); //ios::out --> default

            ordemCrescente(numerosLidos, cont);

            for(int i=0; i<cont; i++)
                escrever << numerosLidos[i] << " ";

            escrever.close();

            cout << "\nArquivo modificado com sucesso!\n\n";

    }else
        cout << "\nErro ao abrir o arquivo\n";


    ler.close();








}
