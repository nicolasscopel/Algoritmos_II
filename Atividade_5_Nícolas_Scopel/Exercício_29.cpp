/* 29 – Escreva um programa que manipule um cardápio de um restaurante, com as seguintes
estruturas:
struct prato
{
string ingredientes;
string preparo;
int calorias;
};
struct cardapio
{
int codigo;
string nome;
prato x;
float valor;
}
O sistema deverá permitir o cadastro de no máximo 20 itens no cardápio e deverá apresentar o
seguinte menu:
0 - Sair
1 – Incluir
2 – Mostrar cardápio (utilize um linha pontilhada entre um item e outro)
3 – Detalhar cardápio (recebe o código do cardápio e mostra os dados do referido cardápio)
4 – Mostrar cardápio mais caro;
5 – Mostrar cardápio com a menor quantidade de calorias;*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

struct prato
{
    string ingredientes;
    string preparo;
    int calorias;
};

struct cardapio
{
    int codigo;
    string nome;
    prato x;
    float valor;
};

void cadastro(cardapio v[], int &i);
void mostra(cardapio v[], int ind);
void especifica(cardapio v[], int ind);
void maiscaro(cardapio v[], int ind);
void menoscalorias(cardapio v[], int ind);




main()
{
	setlocale (LC_ALL, "Portuguese");


	 int i, x, menu = -1, indice = -1, ver;

    cardapio vet[20];



    do
    {
        system("cls");
        cout << "============================= MENU DE OPÇÕES ============================" << endl;
        cout << "- 0 - Sair                                                              -" << endl;
        cout << "- 1 - Incluir                                                           -" << endl;
        cout << "- 2 – Mostrar cardápio                                                  -" << endl;
        cout << "- 3 – Detalhar cardápio (Informe o código do alimento)                  -" << endl;
        cout << "- 4 – Mostrar cardápio mais caro                                        -" << endl;
        cout << "- 5 – Mostrar cardápio com a menor quantidade de calorias               -" << endl;
        cout << "=========================================================================" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {

        case 0:

            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;



        case 1 :

            system("cls");

            cadastro(vet,indice);


            getchar();
            break;


        case 2:

            system("cls");

            if(indice < 0)
                cout << "Nenhum item cadastrado!";
            else
            {
                mostra(vet,indice);


            }

            getchar();
            break;


        case 3 :
            system("cls");

            if(indice < 0)
               cout << "Nenhum item cadastrado!";
            else
            {
                especifica(vet,indice);

            }


            getchar();
            break;


        case 4 :
            system("cls");

            if(indice < 0)
                cout << "Nenhum item cadastrado!";
            else
            {
                maiscaro(vet,indice);

            }

            getchar();
            break;

        case 5 :
            system("cls");

            if(indice < 0)
               cout << "Nenhum item cadastrado!";
            else
            {
                menoscalorias(vet,indice);

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
    while(menu != 0);

}

void cadastro(cardapio v[], int &i)
{
    i++;

    if(i >= 20)
    {
        cout << "Não é possível cadastrar mais um item no cardápio! " << endl;
        return;
    }

    cout << "\nInforme o código do item a ser cadastrado [" << i << "]: ";
    cin >> v[i].codigo;
    fflush(stdin);

    for (int x = 0; x < i; x++)
    {

        if (v[x].codigo == v[i].codigo)
        {
            cout << "Ja existe um item com esse código." << endl;
            i--;
            return;
        }
    }

    cout << "Informe o nome do prato ou bebida [" << i << "]: ";
    getline(cin, v[i].nome);
    fflush(stdin);

    cout << "Informe os ingredientes [" << i << "]: ";
    getline(cin, v[i].x.ingredientes);
    fflush(stdin);

    cout << "Informe o modo de preparo [" << i << "]: ";
    getline(cin, v[i].x.preparo);
    fflush(stdin);

    cout << "Informe a quantidade de calorias [" << i << "]: ";
    cin >> v[i].x.calorias;
    fflush(stdin);

    cout << "Informe o valor [" << i << "]: ";
    cin >> v[i].valor;
    fflush(stdin);


}

void mostra(cardapio v[], int ind)
{


    cout << "Cardapio: " << endl;
    for (int i = 0; i <=ind; i++)
    {
        cout << "Código: " << v[i].codigo << endl;
        cout << "Nome: " << v[i].nome << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Valor: " << v[i].valor << endl;

        cout << "--------------------------------" << endl;
    }

}

void especifica(cardapio v[], int ind)
{
    int cod = 0, f = 0;
    cout << "\nInforme o código do item a ser consultado: ";
    cin >> cod;
    fflush(stdin);

    for(int i = 0; i <= ind; i++)
    {
        if(v[i].codigo == cod)
        {
            f = i;
            break;
        }
    }

        cout << "Codigo: " << v[f].codigo << endl;
        cout << "Nome: " << v[f].nome << endl;
        cout << "Ingredientes: " << v[f].x.ingredientes << endl;
        cout << "Modo de preparo: " << v[f].x.preparo << endl;
        cout << "Quantidade de calorias: " << v[f].x.calorias << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Valor: " << v[f].valor << endl;
        cout << "-----------------------------------------------------------------------------------" << endl;

}

void maiscaro(cardapio v[], int ind)
{

    float maiscaro = 0;


    for(int i = 0; i <= ind; i++)
    {
        if(v[i].valor > maiscaro)
        {
            maiscaro = v[i].valor;

        }
    }

    cout << fixed;
    cout.precision(2);
    cout << "O item mais caro do cardápio custa: R$" << maiscaro << endl;



}

void menoscalorias(cardapio v[], int ind)
{

    int menoscalorias = v[0].x.calorias;


    for(int i = 0; i <= ind; i++)
    {
        if(v[i].x.calorias < menoscalorias)
        {
            menoscalorias = v[i].x.calorias;

        }
    }

    cout << fixed;
    cout.precision(2);
    cout << "O item menos calórico do cardápio possui " << menoscalorias <<" calorias" <<endl;



}












