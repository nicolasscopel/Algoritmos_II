/*40 – Escreva um programa para cadastrar uma turma de alunos, de cada aluno será fornecido o
nome, nota 1, nota 2 e nota 3, os dados devem ser mantidos em um arquivo texto, colocando
os dados de cada aluno em uma linha diferente, o sistema deverá apresentar um menu com as
seguintes opções:
0 – Sair
1 – Cadastrar aluno
2 – Mostrar todos os cadastrados exibindo a média aritmética de cada aluno
3 – Mostrar a maior, menor e a média da turma
4 – Calcular o percentual de alunos aprovados (média >= 6) e reprovados (média < 6)*/




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

struct alunos
{
    char nome[100];
    float n1;
    float n2;
    float n3;
};

void carregar_dados (alunos x[], int &i);
void gravar_dados (alunos x[], int &i);
void cadastro(alunos x[], int &i);
void mostra (alunos x[], int i);
void media (alunos x[], int &i);
void aprovados(alunos x[], int i);


main()
{
    //setlocale (LC_ALL, "Portuguese");
    int menu, indice = -1;
    alunos turma[30];

    carregar_dados(turma, indice);



    do
    {
        system("cls");
        cout.width(30);
        cout << right << "MENU DE OPCOES" << endl;
        cout << "0  Sair " << endl;
        cout << "1  Cadastrar Aluno " << endl;
        cout << "2  Mostrar todos os cadastrados exibindo a media aritmetica de cada aluno " << endl;
        cout << "3  Mostrar a maior, menor e a media da turma" << endl;
        cout << "4  Calcular o percentual de alunos aprovados (media >= 6) e reprovados (media < 6) " << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
        case 0:
        {
            gravar_dados(turma, indice);
            system("cls");
            cout << "\nPrograma Finalizado!";
            cout << "\nPressione ENTER para prosseguir ......";

            getchar();
            break;
        }
        case 1:
        {
            system("cls");

            cadastro(turma,indice);
            gravar_dados(turma, indice);

            getchar();
            break;
        }
        case 2:
        {
            system("cls");

            if(indice < 0)
            {
                cout << "\nNenhum aluno cadastrado!";
                getchar();
                break;
            }
            else
            {
                mostra(turma, indice);
            }


            getchar();
            break;
        }
        case 3:
        {
            system("cls");
            if(indice < 0)
            {
                cout << "\nNenhum aluno cadastrado!";
                getchar();
                break;
            }
            else
            {
                media(turma, indice);
            }

            getchar();
            break;
        }
        case 4:
        {
            if(indice < 0)
            {
                cout << "\nNenhum aluno cadastrado!";
                getchar();
                break;
            }
            else
            {
                aprovados(turma, indice);
            }
        }
        getchar();
        break;
        };
    }
    while(menu != 0);



}

void carregar_dados (alunos x[], int &i)
{
    char aux[100], aux2[100];
    int cont = 0, tam;
    ifstream ler("turma.txt");
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
                x[i].n1 = atof(aux);
            }
            else if(cont == 3)
            {
                x[i].n2 = atof(aux);

            }
            else if(cont == 4)
            {
                x[i].n3 = atof(aux);
                cont = 0;
            }
            ler.getline(aux, 100, ';');
        }
    }
    ler.close();
}
void gravar_dados (alunos x[], int &i)
{
    ofstream escreve;
    escreve.open("turma.txt", ios::out);
    if(escreve.is_open())
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)
                escreve << x[j].nome << ";" << x[j].n1 << ";" << x[j].n2 << ";" << x[j].n3 << ";";
            else
                escreve << "\n" << x[j].nome << ";" << x[j].n1 << ";" << x[j].n2 << ";" << x[j].n3 << ";";
        }
    }
    escreve.close();
}

void cadastro(alunos x[], int &i)
{
    i++;

    cout << "\nInforme o Nome do Aluno: ";
    gets(x[i].nome);
    fflush(stdin);

    cout << "\nInforme a nota 1 do Aluno: ";
    cin >> x[i].n1;
    fflush(stdin);

    cout << "\nInforme a nota 2 do Aluno: ";
    cin >> x[i].n2;
    fflush(stdin);

    cout << "\nInforme a nota 3 do Aluno: ";
    cin >> x[i].n3;
    fflush(stdin);

}

void mostra (alunos x[], int i)
{
    float media;
    cout << "\nAlunos cadastrados: " << endl;

    for(int j = 0; j <= i; j++)
    {
        media = x[j].n1 + x[j].n2 + x[j].n3;
        media = media / 3.0;
        cout << "Nome: " << x[j].nome << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Media: " << media << endl;

        cout << "..................................." << endl;
    }
}
void media (alunos x[], int &i)
{
    float media, mediaturma = 0, maior, menor;

    for(int j = 0; j <= i; j++)
    {
        media = x[j].n1 + x[j].n2 + x[j].n3;
        media = media / 3.0;
        if(j == 0)
        {
            maior = media;
            menor = media;

        }
        else
        {
            if(media > maior)
            {
                maior = media;
            }
            if(media < menor)
            {
                menor = media;
            }
        }
        mediaturma += media;

    }


    cout.precision(2);
    cout << fixed;
    cout << "\nMaior media: " << maior;
    cout.precision(2);
    cout << fixed;
    cout << "\nMenor media: " << menor;
    cout.precision(2);
    cout << fixed;
    cout << "\nMedia da Turma: " << mediaturma / (i + 1);



}

void aprovados(alunos x[], int i)
{
    float media, percenta, percentr;
    float conta = 0, contr = 0;

    for(int j = 0; j <= i; j++)
    {
        media = x[j].n1 + x[j].n2 + x[j].n3;
        media = media / 3.0;
        if(media >= 6)
        {
            conta++;
        }
        else
        {
            contr++;
        }

    }

    percenta = (conta * 100) / (i+1);
    percentr = 100 - percenta;

    cout.precision(2);
    cout << fixed;
    cout << "\nPercentual de Aprovados: " << percenta << "%";
    cout.precision(2);
    cout << fixed;
    cout << "\nPercentual de Reprovados: " << percentr << "%";


}









