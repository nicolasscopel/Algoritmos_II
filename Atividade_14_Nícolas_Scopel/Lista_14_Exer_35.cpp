/*35 – Escreva um programa para controlar uma agenda telefônica, os dados da agenda devem
ser carregados e atualizados em um arquivo texto chamado “agenda.txt”, onde em cada linha
deve estar o nome e o número do telefone separados por um ponto e virgula. O programa
deverá apresentar um menu com as seguintes informações:
0 – Sair
1 – Cadastrar contato (não deve permitir números de telefone repetido)
2 – Mostrar contatos
3 – Consultar (informa o nome e apresenta os contatos do referido nome, pode haver mais de
um)
4 – Excluir (informa o número do telefone, caso exista, exclui do cadastro, caso contrário exibe
mensagem de contato inexistente)*/




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


struct cadastro
{
    char nome[100];
    int telefone;
};

void ler(cadastro x[], int &i);
void carregar_dados (cadastro x[], int &i);
void gravar_dados (cadastro x[], int &i);
void mostrar (cadastro x[], int i);
void consultanome(cadastro x[], int i);
void excluir (cadastro x[], int &i);

main()
{
    setlocale (LC_ALL, "Portuguese");

    cadastro cad[30];
    int menu = -1, indice = -1;
    carregar_dados(cad, indice);

    do
    {
        system("cls");
        cout << "MENU DE OPCOES" << endl;
        cout << "0 - Sair " << endl;
        cout << "1 - Cadastrar Contato " << endl;
        cout << "2 - Mostrar Contatos " << endl;
        cout << "3 - Consultar" << endl;
        cout << "4 - Excluir " << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
        case 0:
        {
            system("cls");
            cout << "\nPrograma Finalizado!";
            cout << "\nPressione ENTER para prosseguir ......";

            getchar();
            break;
        }
        case 1:
        {
            system("cls");

            ler(cad,indice);
            gravar_dados(cad,indice);


            getchar();
            break;
        }
        case 2:
        {
            system("cls");
            mostrar(cad,indice);

            getchar();
            break;
        }
        case 3:
        {
            system("cls");
            consultanome(cad,indice);

            getchar();
            break;
        }
        case 4:
        {
            system("cls");
            excluir(cad,indice);

            getchar();
            break;
        }

        };
    }
    while(menu != 0);



}

void carregar_dados (cadastro x[], int &i)
{
    char aux[100], aux2[100];
    int cont = 0, tam;
    ifstream ler("agenda.txt");
    if(ler.is_open())
    {
        ler.getline(aux, 100, ';');
        while(!ler.eof())
        {
            tam = strlen(aux);
            if(aux[0] == '\n')
            {
               cout << "quebra de linha no inicio" << endl;
               for(int i = 0; i < tam; i++)
                  aux2[i] = aux[i + 1];
               cout << aux2 << ", ";
               strcpy(aux,aux2);
            }

            if(cont == 0)
                i++;
            cont++;
            if(cont == 1)
            {
                strcpy(x[i].nome, aux);
            }
            else if(cont == 2)
            {
                x[i].telefone = atoi(aux);
                cont = 0;
            }

            ler.getline(aux, 100, ';');
        }
    }
    ler.close();
}

void ler (cadastro x[], int &i)
{
    int num, cont = 0;
    char nom[100];
    bool repetido;
    repetido = false;

    i++;
    cout << "Informe o nome: ";
    gets(nom);
    fflush(stdin);

    cout << "Digite o numero: ";
    cin >> num;
    fflush(stdin);

    for(int j= 0; j<=i; j++)
    {
        if(num == x[j].telefone)
        {
            cont++;
        }

    }
    if(cont == 0)
    {
        cout << "\nContato cadastrado.";
        strcpy(x[i].nome,nom);
        x[i].telefone = num;
    }
    else
    {
        i--;
        cout << "\nNumero repetido!";
    }


}
void mostrar (cadastro x[], int i)
{
    cout << "DADOS INFORMADOS: " << endl << endl;
    for(int j = 0; j <= i; j++)
    {
        cout << "Nome: " << x[j].nome << endl;
        cout << "Telefone: " << x[j].telefone << endl;
        cout << "..................................." << endl;
    }
}

void consultanome(cadastro x[], int i)
{
    char procura[100];
    int cont = 0;
    int pos = 0;

    cout << "\nInforme o nome para procurar: ";
    gets(procura);

    for (int j = 0; j <= i; j++)
    {
        if (strcmp(procura, x[j].nome) == 0)
        {
            cout << "Nome: " << x[j].nome << endl;
            cout << "Telefone: " << x[j].telefone << endl;
            cout << "..............................." << endl;
            cont++;
        }
    }

    if(cont == 0)
    {
        cout << "\nNao existe nenhum contato com esse nome!";
    }



}
void gravar_dados (cadastro x[], int &i)
{
    ofstream escreve;
    escreve.open("agenda.txt", ios::out);
    if(escreve.is_open())
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)
                escreve << x[j].nome << ";" << x[j].telefone << ";";
            else
                escreve << "\n" << x[j].nome << ";" << x[j].telefone << ";";

        }
    }
    escreve.close();
}

void excluir(cadastro x[], int &i)
{
    int num, cont = 0;
    cout << "Informe o numero para exluir da agenda: ";
    cin >> num;

    ofstream escreve ("agenda.txt", ios::out);

    for(int j = 0; j <= i; j++)
    {
        if (num == x[j].telefone)
        {
             i--;
             cont++;
        }

        else
            escreve << x[j].nome << ";" << x[j].telefone << ";";
    }
    escreve.close();

    if(cont == 0)
    {
        cout << "\nNumero nao existe na agenda!";
    }
    else
    {
        cout << "\nNumero deletado com sucesso!";
    }
    getchar();
}







