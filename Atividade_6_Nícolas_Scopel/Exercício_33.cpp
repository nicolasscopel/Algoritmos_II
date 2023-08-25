/* 33 - Crie um programa para controlar o estoque de uma empresa, sabendo que serão no
máximo 50 produtos (mas o sistema deve funcionar para qualquer quantidade inferior ao
máximo permitido), o sistema deverá manipular o código do produto, nome, unidade (kg, dz, m,
un, cx, tn, etc...), valor de venda e quantidade em estoque.
0 – Sair
1 – Cadastrar produto
2 – Listar produtos cadastrados
3 – Consultar produto pelo código
4 – Vender produto (fornece o código e a quantidade de venda, o sistema verifica se existe
estoque suficiente e executa a venda atualizando a quantidade em estoque).*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

struct produto
{
    int codigo;
    string nome;
    string unidade;
    float valor;
    int quantidade;


};

void cadastro(produto v[], int &i);
void mostra(produto v[], int ind);
void especifica(produto v[], int ind);
void venda(produto v[], int ind);

main()
{
   setlocale (LC_ALL, "Portuguese");

    int i, x, menu = -1, indice = -1, ver;

    produto vet[50];

    do
    {
        system("cls");
        cout << "================ MENU DE OPÇÕES ================" << endl;
        cout << "- 0 - Sair                                     -" << endl;
        cout << "- 1 - Cadastrar produto                        -" << endl;
        cout << "- 2 – Listar produtos cadastrados              -" << endl;
        cout << "- 3 – Consultar produto pelo código            -" << endl;
        cout << "- 4 – Vender produto                           -" << endl;
        cout << "================================================" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        case 0:
        {


            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;



        case 1 :

            system("cls");

            cadastro(vet, indice);

            getchar();
            break;


        case 2:

            system("cls");

            if(indice < 0)
                cout << "Nenhum produto cadastrado!";
            else
            {
                mostra(vet,indice);
            }

            getchar();
            break;


        case 3 :
            system("cls");

            if(indice < 0)
                cout << "Nenhum produto cadastrado!";
            else
            {
                especifica(vet,indice);
            }

            getchar();
            break;


        case 4 :
            system("cls");

            if(indice < 0)
                cout << "Nenhum produto cadastrado!";
            else
            {
                venda(vet,indice);
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


void cadastro(produto v[], int &i)
{
    i++;

    if(i >= 50)
    {
        cout << "Não é possível cadastrar mais produtos! " << endl;
        return;
    }

    cout << "\nInforme o código do produto [" << i << "]: ";
    cin >> v[i].codigo;
    fflush(stdin);

    for (int x = 0; x < i; x++)
    {

        if (v[x].codigo == v[i].codigo)
        {
            cout << "Ja existe um produto com esse codigo." << endl;
            i--;
            return;
        }
    }

    cout << "\nInforme o nome do produto [" << i << "]: ";
    getline(cin,v[i].nome);
    fflush(stdin);

    cout << "\nInforme a unidade de armazenamento do produto (kg, l, g, ...) [" << i << "]: ";
    getline(cin, v[i].unidade);
    fflush(stdin);

    cout << "\nInforme o valor do produto [" << i << "]: ";
    cin >> v[i].valor;
    fflush(stdin);

    cout << "\nInforme o quantidade em estoque do produto [" << i << "]: ";
    cin >> v[i].quantidade;
    fflush(stdin);

}

void mostra(produto v[], int ind)
{

    cout << "Produtos em estoque: " << endl;
    for (int i = 0; i <=ind; i++)
    {
        cout << "Código: " << v[i].codigo << endl;
        cout << "Nome: " << v[i].nome << endl;
        cout << "Unidade de armazenamento: " << v[i].unidade << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Valor: " << v[i].valor << endl;
         cout << fixed;
        cout.precision(2);
        cout << "Quantidade em estoque: " << v[i].quantidade << endl;

        cout << "--------------------------------" << endl;
    }

}


void especifica(produto v[], int ind)
{
    int cod = 0, f = -1;
    cout << "\nInforme o código do produto a ser consultado: ";
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

    if(f == -1)
    {
        cout << "Código Inexistente!" << endl;
        return;
    }

       cout << "Código: " << v[f].codigo << endl;
        cout << "Nome: " << v[f].nome << endl;
        cout << "Unidade de armazenamento: " << v[f].unidade << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Valor: " << v[f].valor << endl;
         cout << fixed;
        cout.precision(2);
        cout << "Quantidade em estoque: " << v[f].quantidade << endl;

        cout << "--------------------------------" << endl;

}

void venda(produto v[], int ind)
{

    int cod = 0, f = -1;
    float qtd;

    cout << "\nInforme o código do produto: ";
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

    if(f == -1)
    {
        cout << "Código Inexistente!" << endl;
        return;
    }

    cout << "Nome do produto: " << v[f].nome << endl;
    cout << "Vendido em: " << v[f].unidade << endl;
    cout << "Quantidade em estoque " << v[f].quantidade << " " << v[f].unidade << endl;
    cout << "Preço por unidade: " << v[f].valor << endl;


    cout << "Informe a quantidade que deseja comprar: ";
    cin >> qtd;

    if(qtd > v[f].quantidade)
    {
        cout << "Impossível comprar mais que o disponível em estoque! " << endl;
        getchar();
        return;
    }
    else
    {
        v[f].quantidade -= qtd;
        cout << "Compra realizada com sucesso!" << endl;
        getchar();
    }


}
