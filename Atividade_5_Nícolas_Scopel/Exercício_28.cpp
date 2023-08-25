/* 28 - O IBGE realizou uma pesquisa entre habitantes de uma cidade. De cada habitante foram
coletados os dados: idade, sexo(M - Masculino, F- Feminino), salário e número de filhos. Crie a
estrutura de dados adequada para armazenar estas informações e faça uma função que
armazene as informações digitadas pelo usuário na estrutura de dados criada.
O programa deverá possibilitar a exibição dos seguintes dados a qualquer momento:
- Média de salário das pessoas do sexo Masculino;
- Média de salário das pessoas do sexo Feminino;
- Sexo e salário da pessoa com a maior idade;
- Sexo e salário da pessoa com menor idade;
- Salário da pessoa com o maior número de filhos;
Crie as opções necessárias no menu.
OBS: o programa deverá funcionar para qualquer quantia de cadastros realizados.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

struct dados
{
    int idade;
    char sexo;
    double salario;
    int qtdfilhos;
};

void cadastrar(dados v[], int &i);
void mediamasc(dados v[], int ind);
void mediafem(dados v[], int ind);
void maioridade(dados v[], int ind);
void menoridade(dados v[], int ind);
void maisfilhos(dados v[], int ind);

using namespace std;

main()
{
    setlocale (LC_ALL, "Portuguese");

    int i, x, menu = -1, indice = -1, ver;

    dados vet[100];



    do
    {
        system("cls");
        cout << "============================= MENU DE OPÇÕES ============================" << endl;
        cout << "- 0 - Sair                                                              -" << endl;
        cout << "- 1 - Cadastrar Pessoas                                                 -" << endl;
        cout << "- 2 - Média de salário das pessoas do sexo Masculino                    -" << endl;
        cout << "- 3 - Média de salário das pessoas do sexo Feminino                     -" << endl;
        cout << "- 4 - Sexo e salário da pessoa com a maior idade                        -" << endl;
        cout << "- 5 - Sexo e salário da pessoa com menor idade                          -" << endl;
        cout << "- 6 - Salário da pessoa com o maior número de filhos                    -" << endl;
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

            cadastrar(vet, indice);

            getchar();
            break;


        case 2:

            system("cls");

            if(indice < 0)
                cout << "Nenhuma pessoa cadastrada!";
            else
            {

                mediamasc(vet,indice);
            }

            getchar();
            break;


        case 3 :
            system("cls");

            if(indice < 0)
                cout << "Nenhuma pessoa cadastrada!";
            else
            {

                 mediafem(vet, indice);
            }


            getchar();
            break;


        case 4 :
            system("cls");

            if(indice < 0)
                cout << "Nenhuma pessoa cadastrada!";
            else
            {

                 maioridade(vet, indice);
            }


            getchar();
            break;

        case 5 :
            system("cls");

            if(indice < 0)
                cout << "Nenhuma pessoa cadastrada!";
            else
            {
                menoridade(vet,indice);


            }
            getchar();
            break;


        case 6 :
            system("cls");

            if(indice < 0)
                cout << "Nenhuma pessoa cadastrada!";
            else
            {
                maisfilhos(vet, indice);


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


void cadastrar(dados v[], int &i)
{
    i++;

    cout << "\nInforme a sua idade: [" << i << "]: ";
    cin >> v[i].idade;
    fflush(stdin);


    cout << "Informe o Sexo (M - Masculino  F - Feminino [" << i << "]: ";
    cin >> v[i].sexo;
    fflush(stdin);

    cout << "Informe o salário: [" << i << "]: ";
    cin >> v[i].salario;
    fflush(stdin);

    cout << "Informe a quantidade de filhos: [" << i << "]: ";
    cin >> v[i].qtdfilhos;
    fflush(stdin);

    cout << "Pessoa cadastrada com sucesso!\nPressione Enter para prosseguir";

}

void mediamasc(dados v[], int ind)
{
    float mediasal = 0, soma = 0, cont = 0;




    for(int x = 0; x <= ind; x++)
    {
        if(v[x].sexo == 'M')
        {
            cont++;
            soma += v[x].salario;

        }
    }

    mediasal = soma / cont;

    if(cont == 0)
    {
        cout << "Não foram cadastradas pessoas do sexo masculino." << endl;

        return;
    }

    cout << fixed;
    cout.precision(2);

    cout << "A média salarial masculina é de R$: " << mediasal << endl;


}

void mediafem(dados v[], int ind)
{
    float mediasal = 0, soma = 0, cont = 0;

    for(int x = 0; x <= ind; x++)
    {
        if(v[x].sexo == 'F')
        {
            cont++;
            soma += v[x].salario;

        }
    }

    mediasal = soma / cont;

    if(cont == 0)
    {
        cout << "Não foram cadastradas pessoas do sexo feminino." << endl;

        return;
    }

    cout << fixed;
    cout.precision(2);

    cout << "A média salarial feminina é de R$: " << mediasal << endl;


}

void maioridade(dados v[], int ind)
{
    int maior = 0;

    for(int x = 0; x <= ind; x++)
    {
        if(v[x].idade > v[maior].idade)
        {

            maior = x;

        }
    }

    cout << "Sexo da pessoa com maior idade é: " << v[maior].sexo << "\nSeu salário é de: R$" << v[maior].salario << endl;


}

void menoridade(dados v[], int ind)
{
    int menor = 0;

    for(int x = 0; x <= ind; x++)
    {
        if(v[x].idade < v[menor].idade)
        {

            menor = x;

        }
    }
    cout << fixed;
    cout.precision(2);

    cout << "Sexo da pessoa com maior idade é: " << v[menor].sexo << "\nSeu salário é de: R$" << v[menor].salario << endl;


}

void maisfilhos(dados v[], int ind)
{
    int mais = 0;


    for(int x = 0; x <= ind; x++)
    {
        if(v[x].qtdfilhos > v[mais].qtdfilhos)

        {
            mais = x;
        }
    }

    cout << fixed;
    cout.precision(2);

    cout << "O salario da pessoa com mais filhos é de: R$" << v[mais].salario << endl;

}











