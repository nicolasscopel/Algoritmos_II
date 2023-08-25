/*27 – Implemente um programa utilizando ponteiros, que manipule um vetor vet[20] de números inteiros, o programa deverá ter um menu com as seguintes opções:
0 – Sair
1 – Gerar vetor (gera valores para preencher o vetor com números menores que 50 sem valores repetidos)
2 – Acha Maior e Menor (crie uma função que receba por parâmetro o vetor vet e os endereços de duas variáveis inteiras (que podemos chamar de min e max).
    Ao passar essas variáveis para a função seu programa deverá analisar qual é o maior e o menor elemento do vetor e depositar esses elementos nas respectivas variáveis)
3 – Mostra (Exibe o vetor na tela e os valores de min e max)
4 – Calcula (Exibe o percentual de valores pares e ímpares no vetor)*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

void gerar(int *pvet);
void acha(int *p, int *men, int *mai);
void mostra(int *pvet);
void calcula(int *pvet);

main()
{
	srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int *i = new int (0);
    int *l = new int (0);
    int *x = new int(0);
    int *j = new int(0);
    int *vet = new int[20];
    int *menu = new int (-1);
    int *indice = new int (-1);
    int *men = new int;
    int *mai = new int;



    do
    {
        system("cls");
        cout << "=========== MENU DE OPÇÕES ===========" << endl;
        cout << "- 0 - Sair                           -" << endl;
        cout << "- 1 - Gerar Vetor                    -" << endl;
        cout << "- 2 – Acha Maior e Menor             -" << endl;
        cout << "- 3 – Mostra                         -" << endl;
        cout << "- 4 – Calcula                        -" << endl;
        cout << "======================================" << endl;
        cout << "Sua escolha: ";
        cin >> *menu;
        fflush(stdin);

        switch(*menu)

        {

        case 0:
            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;



        case 1 :

            system("cls");

            gerar(vet);

            (*indice)++;

            cout << "\nVetor Gerado!";



            getchar();
            break;


        case 2:

            system("cls");

            if(*indice < 0)
                cout << "Necessario gerar o vetor primeiro!";
            else
            {
                acha(vet,men,mai);
                cout << "\nValores menor e maior achados.";


            }

            getchar();
            break;


        case 3 :
            system("cls");

            if(*indice < 0)
            {
                cout << "Necessario gerar o vetor primeiro!";

            }

            else
            {
                mostra(vet);
                cout << "\nValor Menor: " << *men << endl;
                cout << "Valor Maior: " << *mai << endl;

            }

            getchar();
            break;

        case 4:

            system("cls");

            if(*indice < 0)
                cout << "Necessario gerar o vetor primeiro!";
            else
            {
                mostra(vet);
                calcula(vet);

            }

            getchar();
            break;



        default :
            system("cls");
            cout << "Opção inválida.";
            getchar();
            break;
        };

    }
    while(*menu != 0);


}

void gerar(int *pvet)
{

    int *valor = new int(0);
    int *contV = new int(0);
    int *j = new int(0);
    int *i = new int(0);
    bool *repetido = new bool(0);

    for( *i = 0; *i < 20; (*i)++)
    {
        do
        {
            *valor = rand()% 50;
            *repetido = false;

            for( *j = 0; *j < *contV; (*j)++)//loop de 0 até (i-1) -> o vetor foi preenchidocom valores não repetidos até (i-1)
            {
                if(pvet[*j] == *valor)
                    *repetido = true;
            }
            if(*repetido == false)
            {
                pvet[*i] = *valor;
                (*contV)++;
            }
        }
        while(*repetido == true);
    }


}

void acha(int *p, int *men, int *mai)
{
    int *i = new int;

    *mai = *p;
    *men = *p;

    for(*i = 0; *i < 20; (*i)++)
    {
        if(p[*i] > *mai)
        {
            *mai = p[*i];
        }
    }

    for(*i = 0; *i < 20; (*i)++)
    {
        if(p[*i] < *men)
        {
            *men = p[*i];
        }
    }





}


void mostra(int *pvet)
{
    int *i = new int;
    cout << "Vetor Vet: [ ";

    *i = 0;
    while(*i < 20)
    {
        cout << *pvet << " ";
        pvet++;
        (*i)++;
    }
    cout << "]";
    pvet -= *i;
    *i = 0;

}

void calcula(int *pvet)
{
    int *i = new int;
    int *contpar = new int(0);
    float *percentpar = new float(0);
    int *contimp = new int(0);
    float *percentimp = new float(0);


    for(*i = 0; *i < 20; (*i)++)
    {
        if(pvet[*i] % 2 == 0)
        {
            (*contpar)++;
        }
        else
        {
            (*contimp)++;
        }
    }

    *percentpar = (20 - *contpar);
    *percentpar = (*percentpar / 20) * 100;

    *percentimp = (20 - *contimp);
    *percentimp = (*percentimp / 20) * 100;

    cout.precision(2);
    cout << fixed;
    cout << "\nPercentual de valores Pares: " << *percentpar << "%.";
    cout.precision(2);
    cout << fixed;
    cout << "\nPercentual de valores Ímpares: " << *percentimp << "%.";
}
