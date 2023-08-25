/*38 - Crie um programa que manipule um vetor de dimensão variável (o usuário informa o
tamanho do vetor menor que 100) os valores para preencher o vetor devem ser gerados
dinamicamente, não sendo permitido números duplicados e devem ser menores que a 500.
Após os valores do vetor devem ser escritos em um arquivo texto chamado “valores.txt”
separando cada valor por uma virgula e colocando os valores em ordem crescente.
O programa deve permitir:
Excluir valores do vetor (o usuário informa o valor se existir no vetor deve ser eliminado,
ajustando os elementos na ordem novamente)
Mostrar vetor na tela.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>
#include <fstream>
#include<algorithm>

using namespace std;

void gerar (int *v, int **t);
void menu(int **escolha);
void escrever (int *v, int **t);
void excluir (int *v, int **t, int **igual);
void mostrar (int *v, int **t, int **igual);

int main()
{
    int *tam = new int;
    do
        {
    cout << "Informe o tamanho do vetor: ";
    cin >> *tam;


    }while(*tam >= 100);
    fflush(stdin);

    int *vet = new int[*tam];

    gerar(vet, &tam);

    sort(vet, vet + (*tam)); //ORDENAÇÃO

    escrever(vet, &tam);

    cout << "Vetor Gerado!";
    cout << "\n\nPressione 'ENTER' para prosseguir ...";
    getchar();
    system("cls");

    int *opcao = new int;
    int *remover = new int;

    do
    {
        menu(&opcao);
        switch(*opcao)
        {
        case 0:
            system("cls");
            cout << "Programa Finalizado!";
            break;
        case 1:
            system("cls");

            excluir(vet, &tam, &remover);
            break;
        case 2:
            system("cls");

            mostrar(vet, &tam, &remover);
            getchar();
            break;
        default:
            system("cls");
            cout << "Valor Invalido!";
            getchar();
        }
    }
    while(*opcao != 0);

}

void gerar (int *v, int **t)
{
    srand(time(NULL));

    int *i = new int;
    int *j = new int;
    int *aux = new int;
    int *flag = new int;
    int *pv = new int[**t];

    pv = v;

    for (*i = 0; *i < **t; (*i)++)
    {
        *aux = rand() % 500;
        if (*i == 0)
            *v = *aux;
        else
        {
            *flag = 0;
            for (*j = 0; *j < *i; (*j)++)
            {
                if (*pv == *aux)
                {
                    *flag = 1;
                    break;
                }
                pv++;
            }
            pv -= *j;
            if (*flag == 0)
                *v  = *aux;
            else
            {
                (*i)--;
                v--;
            }
        }
        v++;
    }
    delete i;
    delete j;
    delete aux;
    delete flag;
}

void escrever (int *v, int **t)
{
    int *i = new int;
    ofstream arquivo("valores.txt");
    if(arquivo.is_open())
    {
        for(*i = 0; *i < **t; (*i)++)
        {
            arquivo << *v << ", ";
            v++;
        }
        v -= *i;
    }
    arquivo.close();
}

void menu(int **escolha)
{
    system("cls");
    cout.width(28);
    cout << "=========== MENU DE OPÇÕES =========" << endl;
    cout << "- 0 Sair                           -" << endl;
    cout << "- 1 Remover Elemento               -" << endl;
    cout << "- 2 Mostrar                        -" << endl;
    cout << "====================================" << endl;
    cout << "\nSua Escolha: ";
    cin >> **escolha;
    fflush(stdin);
}

void excluir (int *v, int **t, int **igual)
{
    int *num = new int, *i = new int, *existe = new int;
    cout << "\nInforme o numero que deseja excluir: ";
    cin >> *num;
    fflush(stdin);

    *existe = 0;

    for (*i = 0; *i < **t; (*i)++)
    {
        if (*num == *v)
        {
            **igual = *i;
            (*existe)++;
            break;
        }
        v++;
    }
    v -= *i;
    if (*existe == 0)
    {
        cout << "\nO Valor nao consta no vetor.";
    }
    else
    {
        ofstream arquivo("valores.txt");
        for (*i = 0; *i < **t; (*i)++)
        {
            if (*i == **igual)
            {}
            else
            {
                arquivo << *v << ", ";
            }
            v++;
        }
        v -= *i;
        cout << "\nValor excluido com sucesso!";
    }
    getchar();
}

void mostrar (int *v, int **t, int **igual)
{
    int *i = new int;
    cout << "Vetor Gerado: {";
    for (*i = 0; *i < **t; (*i)++)
    {
        if (*i == **igual)
        {
        }
        else
            cout << *v << ", ";
        v++;
    }
    cout << "}";
}

