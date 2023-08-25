/* 17 � Escreva um programa que gere dois vetores inteiros X e Y de 10 posi��es que devem ser
preenchidos de forma aleat�ria com valores entre 0 e 12, A seguir apresente um menu que proporcione
as seguintes funcionalidades:
A) A uni�o de X com Y (todos os elementos de X e de Y, sem repeti��o)
B) A diferen�a entre X e Y (todos os elementos de X que n�o existam em Y, sem repeti��o)
C) A soma entre X e Y (soma de cada elemento de X com o elemento da mesma posi��o em Y)
D) O produto entre X e Y (multiplica��o de cada elemento de X com o elemento da mesma posi��o
em Y)
E) A intersec��o entre X e Y (apenas os elementos que aparecem nos dois vetores, sem repeti��o)*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void gerar(int *p);
void exibe(int *p);
void uniao(int *x1, int *x2, int *x3);
void diferenca(int *x1, int *x2);
void soma (int *x, int *y);
void multi (int *x, int *y);
void intersec (int *x1, int *x2);


main()
{

    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int *i = new int (0);
    int *l = new int (0);
    int *x = new int[10];
    int *y = new int[10];
    int *u = new int [20];
    char *menu = new char;

    system("cls");

    gerar(x);
    gerar(y);
    cout << "Vetor X [";
    exibe(x);
    cout << "Vetor Y [";
    exibe(y);

    cout << "\n\n\n";




    do
    {
        system("cls");

        cout << "Vetor X [";
        exibe(x);
        cout << "Vetor Y [";
        exibe(y);

        cout << "\n\n\n";

        cout << "=============== MENU DE OP��ES =================" << endl;
        cout << "- A - A uni�o de X com Y                      -" << endl;
        cout << "- B - A diferen�a entre X e Y                 -" << endl;
        cout << "- C � A soma entre X e Y                      -" << endl;
        cout << "- D � O produto entre X e Y                   -" << endl;
        cout << "- E � A intersec��o entre X e Y               -" << endl;
        cout << "- F � Finalizar Programa                      -" << endl;
        cout << "===============================================" << endl;
        cout << "Sua escolha: ";
        cin >> *menu;
        fflush(stdin);

        switch(*menu)

        {

        case 'A':
            system("cls");

            cout << "Vetor X [";
            exibe(x);
            cout << "Vetor Y [";
            exibe(y);
            cout << "Vetor U [";

            uniao(u,x,y);
            cout << "]" << endl;

            getchar();
            break;



        case 'B' :

            system("cls");


            cout << "Vetor X [";
            exibe(x);
            cout << "Vetor Y [";
            exibe(y);
            cout << "Elementos que existem em X que n�o existem em Y: [";
            diferenca(x,y);


            getchar();
            break;


        case 'C':

            system("cls");
            cout << "Vetor X [";
            exibe(x);
            cout << "Vetor Y [";
            exibe(y);

            soma(x,y);



            getchar();
            break;


        case 'D' :
            system("cls");

            cout << "Vetor X [";
            exibe(x);
            cout << "Vetor Y [";
            exibe(y);

            multi(x,y);


            getchar();
            break;

        case 'E':

            system("cls");
            cout << "Vetor X [";
            exibe(x);
            cout << "Vetor Y [";
            exibe(y);
            cout << "Intersec��o de X e Y: [";

            intersec(x,y);



            getchar();
            break;

        case 'F':
            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;



        default :
            system("cls");
            cout << "Op��o inv�lida.";
            getchar();
            break;
        };

    }
    while(*menu != 'F');



}

void gerar(int *p)
{
    int *i = new int(0);

    while(*i < 10)
    {
        *p = rand() % 13;
        p++;
        (*i)++;
    }

    p -= *i;
    *i = 0;
}

void exibe(int *p)
{
    int *i = new int(0);


    while(*i < 10)
    {
        cout << *p << " ";
        p++;
        (*i)++;
    }

    cout << "]" << endl;
}

void uniao(int *x3, int *x1, int *x2)
{


    int *i = new int(0);
    int *j = new int(0);
    int *a = new int;
    int *b = new int;
    int *c = new int;

    while(*i < 20)
    {
        *x3 = *x1;
        x3++;
        *x3 = *x2;
        x3++;
        x2++;
        x1++;
        (*i)+= 2;
    }

    x3 -= *i;
    *i = 0;

     for(*i = 0; *i < 20; (*i)++)
    {
        for (*j = *i + 1; *j < 20; (*j)++)
        {
            if(x3[*i] == x3[*j])
            x3[*j] = -1;
        }
    }

    *i = 0;

    while(*i < 20)
    {
        if(*x3 != -1)
        {
            cout << *x3 << " ";
        }

        x3++;
        (*i)++;
    }
    x3 -= *i;
    *i = 0;

}

void diferenca(int *x1, int *x2)
{
    int *i = new int (0);
    int *j = new int (0);
    int *cont = new int (0);
    int *k = new int (0);
    int *v =  new int[12];
    int *aux = new int;


    while(*i < 10)
    {
        while(*j < 10)
        {
            if(*x1 == *x2)
            {
                (*cont)++;

            }
            x2++;
            (*j)++;
        }

        if (*cont == 0)
        {
            *v = *x1;
            v++;
            (*k)++;
        }

        x1++;
    (*i)++;
    x2 -= *j;
    *cont = 0;
    *j = 0;

    }
    *j = 0;
    *i = 0;
    v -= *k;

    for(*i = 0; *i < *k; (*i)++)
    {
        for (*j = *i + 1; *j < *k; (*j)++)
        {
            if(v[*i] == v[*j])
            v[*j] = -1;
        }
    }

    *i = 0;


    while(*i < *k)
    {

        if(*v != -1)
        {
            cout << *v << " ";
        }

        v++;
        (*i)++;
    }
    cout << "]";


}

void soma (int *x, int *y)
{
    int *i = new int;
    int *soma =  new int(0);


    for(*i = 0; *i < 10; (*i)++)
    {
        *soma += *x;
        *soma += *y;
        cout << "Posicao " << *i << " Soma =  " << *soma << endl;
        *soma = 0;
        x++;
        y++;

    }
    x -= 10;
    y -= 10;

}

void multi (int *x, int *y)
{
    int *i = new int;
    int *soma =  new int(0);


    for(*i = 0; *i < 10; (*i)++)
    {

        cout << "Posicao " << *i << " Produto =  " << (*x)*(*y) << endl;

        x++;
        y++;

    }
    x -= 10;
    y -= 10;

}

void intersec(int *x1, int *x2)
{
    int *i = new int (0);
    int *j = new int (0);
    int *cont = new int (0);
    int *k = new int (0);
    int *v =  new int[12];
    int *aux = new int;


    while(*i < 10)
    {
        while(*j < 10)
        {
            if(*x1 == *x2)
            {
                (*cont)++;

            }
            x2++;
            (*j)++;
        }

        if (*cont != 0)
        {
            *v = *x1;
            v++;
            (*k)++;
        }

        x1++;
    (*i)++;
    x2 -= *j;
    *cont = 0;
    *j = 0;

    }
    *j = 0;
    *i = 0;
    v -= *k;

    for(*i = 0; *i < *k; (*i)++)
    {
        for (*j = *i + 1; *j < *k; (*j)++)
        {
            if(v[*i] == v[*j])
            v[*j] = -1;
        }
    }

    *i = 0;


    while(*i < *k)
    {

        if(*v != -1)
        {
            cout << *v << " ";
        }

        v++;
        (*i)++;
    }
    cout << "]";


}


