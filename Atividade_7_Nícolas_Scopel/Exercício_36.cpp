/*36 – Crie um programa para manipular uma estrutura chamada "pessoa" com os campos
"nome" e "idade". Em seguida, o programa deverá apresentar um menu com as seguintes
opções:
0 – Sair
1 – Cadastrar Pessoa
2 – Pessoa de maior e menor idade
3 – Média das idades
OBS: Utilize funções e passagem de parâmetro para resolver este exercício, as opções 2 e 3 só
poderão ser executadas se existir ao menos uma pessoa cadastrada, o programa deverá
funcionar para qualquer quantidade de pessoa cadastrada, sendo no máximo 20.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

struct pessoa
{
    int idade;
    string nome;
};

void cadastro(pessoa v[] ,int &i);
void maioridade(pessoa v[], int ind);
void menoridade(pessoa v[], int ind);
void mediaidades(pessoa v[], int ind);

main()
{
	setlocale (LC_ALL, "Portuguese");

	int i, x, menu = -1, indice = -1, ver;

	pessoa vet[20];

	 do
    {
        system("cls");
        cout << "================ MENU DE OPÇÕES ================" << endl;
        cout << "- 0 - Sair                                     -" << endl;
        cout << "- 1 - Cadastrar pessoa                         -" << endl;
        cout << "- 2 – Pessoa de maior e menor idade            -" << endl;
        cout << "- 3 – Média das idades                         -" << endl;
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

            cadastro(vet,indice);

            getchar();
            break;


        case 2:

            system("cls");

            if(indice < 0)
                cout << "Nenhum aluno cadastrado!";
            else
            {
                maioridade(vet,indice);
                menoridade(vet,indice);
            }

            getchar();
            break;


        case 3 :
            system("cls");

            if(indice < 0)
                cout << "Nenhum aluno cadastrado!";
            else
            {
                mediaidades(vet,indice);
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

void cadastro(pessoa v[] , int &i)
{
    i++;

    if(i >= 20)
    {
        cout << "\nNao e possivel cadastrar mais pessoas!" << endl;
        i--;
        return;
    }

    cout << "\nInforme a idade da pessoa [" << i << "]: ";
    cin >> v[i].idade;
    fflush(stdin);

    cout << "Informe o nome da pessoa [" << i << "]: ";
    getline(cin, v[i].nome);
    fflush(stdin);

}

void maioridade(pessoa v[], int ind)
{

    int maior = 0, posi = 0;

    for(int x = 0; x <= ind; x++)
    {
        if(v[x].idade > maior)
        {
            maior = v[x].idade;
            posi = x;
        }
    }

    cout << "\nNome da pessoa com maior idade: " << v[posi].nome;
    cout << "\nIdade dela: " << maior << endl;
    cout << "----------------------------------------" << endl;



}


void menoridade(pessoa v[], int ind)
{

    int menor = 10000, posi = 0;

    for(int x = 0; x <= ind; x++)
    {
        if(v[x].idade < menor)
        {
            menor = v[x].idade;
            posi = x;
        }
    }

    cout << "\nNome da pessoa com menor idade: " << v[posi].nome;
    cout << "\nIdade dela: " << menor << endl;
    cout << "----------------------------------------" << endl;

}
void mediaidades(pessoa v[], int ind)
{

    float media = 0, cont = 0;

    for(int x = 0; x <= ind; x++)
    {
        media += v[x].idade;
        cont++;
    }
    cout << fixed;
    cout.precision(2);

    cout << "\nMedia das idades é: " << media / cont << endl;

}


