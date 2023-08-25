/**/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void gerarnum(int *p, int *tam);
void exibe(int *p, int *tam);
void ordem(int *p, int *paux, int *tam);
void ordemaux(int *p, int *tam);
void sorteio(int *p, int *tam, int *aux, int *tamaux);

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int *i = new int (0);
    int *l = new int (0);
    int *x = new int(0);
    int *j = new int(0);
    int *menu = new int (-1);
    int *indice = new int (-1);
    int *tamanho = new int;
    int *vet = new int[*tamanho];
    int *aux = new int[5];
    int *tamaux = new int (0);
    int *vetaux = new int[*tamanho];




    do
    {
        system("cls");
        cout << "================ MENU DE OPÇÕES ================" << endl;
        cout << "- 0 - Sair                                     -" << endl;
        cout << "- 1 - Gerar Valores para o Vetor               -" << endl;
        cout << "- 2 – Sorteio                                  -" << endl;
        cout << "- 3 – Exibir Vetores                           -" << endl;
        cout << "================================================" << endl;
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


            do
            {
                cout << "Informe o número de elementos do vetor: ";
                cin >> *tamanho;


            }
            while(*tamanho < 5 || *tamanho > 50);

            vet = new int[*tamanho];

            gerarnum(vet, tamanho);



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
                cout << "Vet: [";
                exibe (vet, tamanho);
                cout << "]";

                sorteio(vet, tamanho, aux, tamaux);



            }

            getchar();
            break;


        case 3:
            system("cls");

            if(*indice < 0)
            {
                cout << "Necessario gerar o vetor primeiro!";

            }
            else
            {
                cout << "Vet: [";
                ordem(vet, vetaux, tamanho);
                exibe (vetaux, tamanho);
                cout << "]";

                if(*tamaux == 0)
                {
                    cout << "\nVetor auxiliar está vazio.";
                }
                else
                {
                    cout << "\nAux: [";
                ordemaux(aux, tamaux);
                exibe (aux, tamaux);
                cout << "]";

                }

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


void gerarnum(int *p, int *tam)
{
    int *valor = new int(0);
    int *contV = new int(0);
    int *j = new int(0);
    int *i = new int(0);
    bool *repetido = new bool(0);

    for( *i = 0; *i < *tam; (*i)++)
    {
        do
        {
            *valor = rand()% 50 + 1;
            *repetido = false;

            for( *j = 0; *j < *contV; (*j)++)//loop de 0 até (i-1) -> o vetor foi preenchidocom valores não repetidos até (i-1)
            {
                if(p[*j] == *valor)
                    *repetido = true;
            }
            if(*repetido == false)
            {
                p[*i] = *valor;
                (*contV)++;
            }
        }
        while(*repetido == true);
    }


}

void exibe(int *p, int *tam)
{

    int *i = new int(0);


    while(*i < *tam)
    {
        if(*p != -1)
        {
             cout << *p << " ";
        }

        p++;
        (*i)++;
    }
    p -= *i;
    *i = 0;

}

void ordem(int *p, int *paux, int *tam)
{
    int *i = new int(0);
    int *j = new int(0);
    int *aux = new int(0);
    int *prox =  new int(0);


    for(*i = 0; *i < *tam; (*i)++)
    {
        paux[*i] = p[*i];

    }

    prox = paux;




    for(*i = 0; *i < *tam; (*i)++)
    {
        for(*j = 0; *j <= *tam -1; (*j)++)
        {
            if(*paux > *prox)
            {
                *aux = *paux;
                *paux = *prox;
                *prox = *aux;

            }
            prox++;
        }
        prox -= *j;
        paux++;
    }
    paux -= *i;
    prox -=*j;

}

void ordemaux(int *p, int *tam)
{
    int *i = new int(0);
    int *j = new int(0);
    int *aux = new int(0);
    int *prox =  new int(0);

    prox = p;



    for(*i = 0; *i < *tam; (*i)++)
    {
        for(*j = 0; *j <= *tam -1; (*j)++)
        {
            if(*p > *prox)
            {
                *aux = *p;
                *p = *prox;
                *prox = *aux;

            }
            prox++;
        }
        p++;
        prox -= *j;
    }

    p -= *i;
    prox -=*j;


}

void sorteio(int *p, int *tam, int *aux, int *tamaux)
{
    int *n = new int;
    int *i = new int;
    int *cont = new int (0);



    do
    {
        cout << "\nInforme um numero: ";
        cin >> *n;

    }while(*n <1 || *n > 50);

    for(*i = 0; *i < *tam; (*i)++)
    {
        if(*n == p[*i])
        {
            cout << "\nValor " << *n << " está na posição " << *i << " e seu endereço na memória é " << &p[*i];
            (*cont)++;
            p[*i] = -1;


            getchar();

        }


    }



    if(*cont == 0)
        {
            cout << "\nO valor " << *n << " nao existe no vetor VET, será inserido no vetor auxiliar. " << endl;
            if(*tamaux == 5)
            {
                cout << "Vetor auxiliar cheio.";
                *tamaux = 0;
                int *aux = new int[5];
            }

            aux[*tamaux] = *n;
            (*tamaux)++;
            getchar();

        }





}
