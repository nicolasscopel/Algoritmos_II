/* 27 – Faça um programa que realize o cadastro de contas bancárias com as seguintes
informações: número da conta, nome do cliente e saldo. O banco permite o cadastramento de
10 contas e não poderá haver mais que uma conta com o mesmo número. O sistema deverá
apresentar um menu com as seguintes opções:
1 – Cadastrar contas;
2 – Visualizar dados da conta; (deve ser informado o número da conta)
3 – Depositar; (deve ser informado o número da conta e o valor a ser depositado)
4 – Sacar; (deve ser informado o número da conta e o valor a ser sacado, validar se o saque
pode ser realizado ou não)
5 – Pix; (deve ser informado o número da conta de origem, o número da conta de destino e o
valor, existindo saldo na conta de origem o programa deve realizar a transferência, atualizando
o saldo nas duas contas)
5 – Sair;*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>



using namespace std;

struct cadastro
{
    int conta;
    string nome;
    int saldo;

};

void ler(cadastro v[], int &i);
void mostra(cadastro v[], int ind);
void deposito(cadastro v[], int ind);
void sacar(cadastro v[], int ind);
void pix(cadastro v[], int ind);


main()
{


    setlocale (LC_ALL, "Portuguese");

    cadastro vet[10];
    int i, x, menu = -1, indice = -1, ver;

    srand(time(NULL));

    do
    {
        system("cls");
        cout << "=========== MENU DE OPÇÕES ==========" << endl;
        cout << "- 1 - Cadastrar Contas              -" << endl;
        cout << "- 2 - Visualizar dados da Conta     -" << endl;
        cout << "- 3 - Depositar                     -" << endl;
        cout << "- 4 - Sacar                         -" << endl;
        cout << "- 5 - Pix                           -" << endl;
        cout << "- 6 - Sair                          -" << endl;
        cout << "=====================================" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {


        case 1 :

            system("cls");
            ler(vet, indice);


            getchar();
            break;


        case 2:
            system("cls");
            if(indice < 0)
                cout << "Nenhuma conta cadastrada!";
            else
            {

                mostra(vet, indice);
            }


            getchar();
            break;


        case 3 :
            system("cls");

            if(indice < 0)
                cout << "Nenhuma conta cadastrada!";
            else
            {

                deposito(vet, indice);
            }



            getchar();
            break;




        case 4 :
            system("cls");

            if(indice < 0)
                cout << "Nenhuma conta cadastrada!";
            else
            {

                sacar(vet, indice);
            }


            getchar();
            break;

        case 5 :
            system("cls");

            if(indice < 0)
                cout << "Nenhuma conta cadastrada!";
            else
            {

                pix(vet, indice);
            }



            getchar();
            break;

        case 6 :

            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;


        default :
            system("cls");
            cout << "Opção inválida.";
            getchar();
            break;
        };

    }
    while(menu != 6);

}

void ler(cadastro v[], int &i)
{
    i++;

    if(i == 10)
    {
        cout << "Não é possível cadastras mais contas: " << endl;
        return;
    }

    cout << "\nInforme o número da conta [" << i << "]: ";
    cin >> v[i].conta;
    fflush(stdin);

    for (int x = 0; x < i; x++)
    {

        if (v[x].conta == v[i].conta)
        {
            cout << "Ja existe uma conta com este numero." << endl;
            i--;
            return;
        }
    }

    cout << "Informe o nome do proprietário [" << i << "]: ";
    getline(cin, v[i].nome);
    fflush(stdin);

    cout << "Informe o saldo da conta [" << i << "]: ";
    cin >> v[i].saldo;
    fflush(stdin);

    cout << "Conta cadastrada com sucesso!\nPressione Enter para prosseguir";


}

void mostra(cadastro v[], int ind)
{
    int ver, i = -1;

    cout << "Informe a conta para consulta: ";
    cin >> ver;

    for(int x = 0; x <= ind; x++)
    {
        if(v[x].conta == ver )
        {
            i = x;
        }
    }

    if(i > -1)
    {
        cout << "Dados da Conta: " << endl;
        cout << "Conta: " << v[i].conta << endl;
        cout << "Nome: " << v[i].nome << endl;
        cout << "Saldo: " << v[i].saldo << endl;
        cout << "--------------------------------" << endl;

    }
    else
    {
        cout << "Essa conta não existe." << endl;
    }
    getchar();



}

void deposito(cadastro v[], int ind)
{
    int ver, i = -1, valor;

    cout << "Informe a conta para realizar a operação: ";
    cin >> ver;
    cout << "\nInforme o valor de deposito: ";
    cin >> valor;

    for(int x = 0; x <= ind; x++)
    {
        if(v[x].conta == ver )
        {
            i = x;
        }
    }

    if(i > -1)
    {

        v[i].saldo += valor;

        cout << "Valor depositado com sucesso! " << endl;


    }
    else
    {
        cout << "Essa conta não existe. " << endl;
    }
    getchar();


}
void sacar(cadastro v[], int ind)
{
    int ver, i = -1, valor;

    cout << "Informe a conta para realizar a operação: ";
    cin >> ver;
    cout << "\nInforme o valor que deseja sacar: ";
    cin >> valor;

    for(int x = 0; x <= ind; x++)
    {
        if(v[x].conta == ver )
        {
            i = x;
        }
    }


    if(v[i].saldo < valor )
    {
        cout << "Não é possível sacar um valor maior que o disponível em sua conta!" << endl;
        getchar();
        return;

    }

    if(i > -1)
    {

        v[i].saldo -= valor;

        cout << "Valor sacado com sucesso! " << endl;

    }
    else
    {
        cout << "Essa conta não existe. " << endl;
    }
    getchar();

}
void pix(cadastro v[], int ind)
{

    int ver, p = -1, r = -1, valor;

    cout << "\nInforme a conta que realizará o pagamento: ";
    cin >> ver;

    for(int x = 0; x <= ind; x++)
    {
        if(v[x].conta == ver )
        {
            p = x;
        }
    }

    cout << "\nInforme a conta que receberá o pagamento: ";
    cin >> ver;

    for(int x = 0; x <= ind; x++)
    {
        if(v[x].conta == ver )
        {
            r = x;
        }
    }

    cout << "\nInforme o valor que deseja pagar: ";
    cin >> valor;

    if(v[p].saldo < valor )
    {
        cout << "Não é possível realizar o pagamento maior que o saldo disponível em sua conta!" << endl;
        getchar();
        return;

    }


    if(p > -1 && r > -1)
    {

        v[p].saldo -= valor;
        v[r].saldo += valor;

        cout << "Pagamento realizado com sucesso! " << endl;
        getchar();


}

else
{
    cout << "Alguma conta não foi cadastrada!" << endl;
    getchar();
}




}
