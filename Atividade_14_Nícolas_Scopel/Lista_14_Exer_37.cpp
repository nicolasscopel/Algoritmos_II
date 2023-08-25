/*37 - Crie um programa para controlar o estoque de mercadorias de uma pequena mercearia,
para cada produto é necessário armazenar as seguintes informações: código, nome, preço e
quantidade, os dados devem ser lidos do arquivo “produtos.txt”, sempre que o programa iniciar
e mantidos neste mesmo arquivo, sempre que o programa for encerrado. No arquivo os
produtos devem estar em uma linha contínua, separando as informações com um “#” sustenido.
O sistema deve possibilitar as seguintes ações:
0 - Sair
1 - Incluir um novo produto (não permitir código duplicado)
2 - Vender produto (validar se existe quantidade suficiente e atualizar a quantidade vendida)
3 - Listar produto com estoque zerado
4 - Consultar produto (informar o nome e o sistema lista os dados do produto)
5 - Listar todos os produtos (separando cada registro por uma linha pontilhada)*/




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

struct estoque
{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

void carregar_dados (estoque x[], int &i);
void cadastrar (estoque x[], int &i);
void gravar_dados (estoque x[], int &i);
void vender(estoque x[], int &i);
void zerado(estoque x[], int &i);
void consultar(estoque x[], int &i);
void listar(estoque x[], int &i);






main()
{
    setlocale (LC_ALL, "Portuguese");

    int menu = -1, indice = -1;
    estoque cad[30];
    carregar_dados(cad, indice);



    do
    {
        system("cls");
        cout << "MENU DE OPCOES" << endl;
        cout << "0 - Sair " << endl;
        cout << "1 - Incluir um novo produto " << endl;
        cout << "2 - Vender produto " << endl;
        cout << "3 - Listar produto com estoque zerado" << endl;
        cout << "4 - Consultar produto" << endl;
        cout << "5 - Listar todos os produtos" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
        case 0:
        {
            system("cls");
            gravar_dados(cad,indice);
            cout << "\nPrograma Finalizado!";
            cout << "\nPressione ENTER para prosseguir ......";

            getchar();
            break;
        }
        case 1:
        {
            system("cls");

            cadastrar(cad,indice);
            gravar_dados(cad,indice);

            getchar();
            break;
        }
        case 2:
        {
            system("cls");

            vender(cad,indice);



            getchar();
            break;
        }
        case 3:
        {
            system("cls");

            zerado(cad,indice);

            getchar();
            break;
        }
        case 4:
        {
            system("cls");

            consultar(cad,indice);

            getchar();
            break;
        }
         case 5:
        {
            system("cls");

            listar(cad,indice);

            getchar();
            break;
        }

        };
    }
    while(menu != 0);



}

void carregar_dados (estoque x[], int &i)
{
    char aux[50];
    int cont = 0;
    ifstream ler("produtos.txt");
    if(ler.is_open())
    {
        ler.getline(aux, 50, '#');
        while(!ler.fail())
        {
            if(cont == 0)
               i++;
            cont++;
            if(cont == 1)
            {
                 x[i].codigo = atoi(aux);
            }
            else if(cont == 2)
            {
                strcpy(x[i].nome, aux);
            }
            else if(cont == 3)
            {
                x[i].preco = atof(aux);

            }
            else if(cont == 4)
            {
                x[i].quantidade = atoi(aux);
                cont = 0;
            }
            ler.getline(aux, 50, '#');
        }
    }
    ler.close();
}

void cadastrar (estoque x[], int &i)
{
    i++;
    int cod;
    cout << "Informe o codigo do produto: ";
    cin >> cod;
    fflush(stdin);

    for(int j = 0; j <= i; j++)
    {
        if(cod == x[j].codigo)
        {
            cout << "\nCódigo Repetido;";
            i--;
            return;
        }
    }
     x[i].codigo = cod;


    cout << "Informe o nome do produto: ";
    gets(x[i].nome);
    fflush(stdin);

    cout << "Informe o preço: ";
    cin >> x[i].preco;
    fflush(stdin);

    cout << "Informe a quantidade em estoque: ";
    cin >> x[i].quantidade;
    fflush(stdin);


}
void gravar_dados (estoque x[], int &i)
{
    ofstream escreve;
    escreve.open("produtos.txt", ios::out);
    if(escreve.is_open())
    {
        for(int j = 0; j <= i; j++)
        {
            escreve << x[j].codigo << "#" << x[j].nome << "#" << x[j].preco << "#" << x[j].quantidade << "#";
        }
    }
    escreve.close();
}
void vender(estoque x[], int &i)
{
    int cod, qtd,j, cont = 0, pos;

    cout << "Informe o codigo do produto que deseja comprar: ";
    cin >> cod;
    cout << "\nInforme a quantidade do produto: ";
    cin >> qtd;

     for(int j = 0; j <= i; j++)
    {
        if(cod == x[j].codigo)
        {
            cout << "\nProduto: " << x[j].nome;
            pos = j;
            cont++;
            getchar();

        }
    }
    if(cont == 0)
    {
        cout << "\nCodigo não encontrado.";
        getchar();

        return;
    }
    cont = 0;

    for(int j = 0; j <= i; j++)
    {
            if(qtd > x[j].quantidade)
            {
                cout << "\nQuantidade indisponível.";
                getchar();
                return;
            }

    }

    x[pos].quantidade -= qtd;
    cout << "\nVenda realizada com sucesso.";
    getchar();


}
void zerado(estoque x[], int &i)
{
    cout << "\nProdutos sem estoque" << endl;

    for(int j = 0; j <= i; j++)
    {
            if(x[j].quantidade == 0)
            {
                cout << "\nProduto: " << x[j].nome << endl;


            }

    }


}

void consultar(estoque x[], int &i)
{
    char procura[100];
    int cont = 0;
    int pos = 0;

    cout << "\nInforme o nome do produto para procurar: ";
    gets(procura);

    for (int j = 0; j <= i; j++)
    {
        if (strcmp(procura, x[j].nome) == 0)
        {
            cout << "Nome: " << x[j].nome << endl;
            cout << "Codigo: " << x[j].codigo << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Preco: " << x[j].preco << endl;
            cout << "Quantidade: " << x[j].quantidade << endl;
            cout << "..............................." << endl;
            cont++;
        }
    }

    if(cont == 0)
    {
        cout << "\nNao existe nenhum produto com esse nome!";
    }


}

void listar (estoque x[], int &i)
{
    cout << "PRODUTOS CADASTRADOS: " << endl;
    for(int j = 0; j <= i; j++)
    {
            cout << "Nome: " << x[j].nome << endl;
            cout << "Codigo: " << x[j].codigo << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Preco: " << x[j].preco << endl;
            cout << "Quantidade: " << x[j].quantidade << endl;
            cout << "..............................." << endl;
    }
}







