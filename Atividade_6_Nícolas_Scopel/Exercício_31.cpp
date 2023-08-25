/*31 � A professora de matem�tica do IFSUL, necessita elaborar um controle para registro das
suas turmas de alunos, para cada registro � necess�rio saber o n�mero da matricula, nome,
turma, curso, m�dia e frequ�ncia.
Conforme ocorre os fechamentos dos di�rios a professora registra os resultados dos alunos no
cadastro, ap�s ela poder� usufruir dos relat�rios emitidos pelo sistema, conforme apresentados.
O sistema deve permitir as seguintes a��es:
0 - Sair
1 - Cadastrar aluno (n�o permitir cadastro com matr�cula duplicada)
2 - Listar aluno por turma (Recebe o n�mero da turma e lista todos os alunos (todos os dados)
que pertencem a referida turma, separando cada aluno com uma linha pontilhada, caso n�o
tenha alunos na turma dever� exibir uma mensagem com tal informa��o).
3 � Listar aprovados por curso (Recebe o nome do curso e lista todos os alunos pertencentes ao
curso que obtiveram m�dia igual ou superior a 6.0 e frequ�ncia igual ou superior � 75).
4 � M�dia por turma (lista a maior, menor e a m�dia das notas de cada turma, juntamente com
o n�mero da turma, separando cada turma com uma linha pontilhada)
Obs: as a��es devem funcionar para qualquer quantidade de pessoas cadastradas e ser�o no
m�ximo 50.
OBS:
- As a��es 2, 3, 4 s� poder�o ser acionadas se a op��o 1 j� foi executada.
- Ao escolher op��o inv�lida no menu dever� exibir mensagem com tal informa��o.
- Utilize struct, fun��es e passagem de par�metro para resolver este exerc�cio, n�o sendo
permitido o uso de vari�veis globais.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

struct aluno
{
    int matricula;
    string nome;
    int turma;
    string curso;
    float media;
    float frequencia;
};

void cadastro(aluno v[], int &i);
void mostraturma(aluno v[], int ind);
void aprovadoscurso(aluno v[], int ind);
void mediaturma(aluno v[], int ind);

main()
{
    setlocale (LC_ALL, "Portuguese");

    int i, x, menu = -1, indice = -1, ver;

    aluno vet[50];

    do
    {
        system("cls");
        cout << "================ MENU DE OP��ES ================" << endl;
        cout << "- 0 - Sair                                     -" << endl;
        cout << "- 1 - Cadastrar aluno                          -" << endl;
        cout << "- 2 � Listar aluno por turma                   -" << endl;
        cout << "- 3 � Listar aprovados por curso               -" << endl;
        cout << "- 4 � M�dia por turma                          -" << endl;
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
                mostraturma(vet,indice);

            }

            getchar();
            break;


        case 3 :
            system("cls");

            if(indice < 0)
                cout << "Nenhum aluno cadastrado!";
            else
            {

                aprovadoscurso(vet, indice);

            }


            getchar();
            break;


        case 4 :
            system("cls");

            if(indice < 0)
                cout << "Nenhum aluno cadastrado!";
            else
            {
                mediaturma(vet, indice);
            }

            getchar();
            break;




        default :
            system("cls");
            cout << "Op��o inv�lida.";
            getchar();
            break;
        };

    }
    while(menu != 0);

}

void cadastro(aluno v[], int &i)
{
    i++;

    if(i >= 50)
    {
        cout << "N�o � poss�vel cadastrar mais alunos! " << endl;
        return;
    }

    cout << "\nInforme a matr�cula do aluno [" << i << "]: ";
    cin >> v[i].matricula;
    fflush(stdin);

    for (int x = 0; x < i; x++)
    {

        if (v[x].matricula == v[i].matricula)
        {
            cout << "Ja existe um aluno com essa matricula." << endl;
            i--;
            return;
        }
    }

    cout << "Informe o nome do aluno [" << i << "]: ";
    getline(cin, v[i].nome);
    fflush(stdin);

    cout << "Informe a turma do aluno [" << i << "]: ";
    cin >> v[i].turma;
    fflush(stdin);

    cout << "Informe o curso do aluno (CC - EC - EM) [" << i << "]: ";
    getline(cin, v[i].curso);
    fflush(stdin);

    cout << "Informe a m�dia do aluno (0 - 10) [" << i << "]: ";
    cin >> v[i].media;
    fflush(stdin);

    cout << "Informe a frequencia do aluno (0 - 100%) [" << i << "]: ";
    cin >> v[i].frequencia;
    fflush(stdin);


}

void mostraturma(aluno v[], int ind)
{
    int ver, cont = 0;

    cout << "Informe a turma para consulta: ";
    cin >> ver;

    for(int i = 0; i <= ind; i++)
    {
        if(v[i].turma == ver )
        {
            cont++;
            cout << "N�mero da matr�cula: " << v[i].matricula << endl;
            cout << "Nome: " << v[i].nome << endl;
            cout << "Turma: " << v[i].turma << endl;
            cout << "Curso: " << v[i].curso << endl;
            cout << fixed;
            cout.precision(2);
            cout << "M�dia: " << v[i].media << endl;
            cout << "Frequencia: " << v[i].frequencia << "%" << endl;
            cout << "------------------------------------------------" << endl;

        }
    }
    getchar();

    if(cont == 0)
    {
        cout << "N�o exsitem alunos nessa turma!" << endl;
        getchar();
    }

}


void aprovadoscurso(aluno v[], int ind)
{
    char tipo[2];
    int i = 0, cont = 0;

    cout << "Informe o curso que deseja consultar: ";
    gets(tipo);

    if(strcmp(tipo,"CC") == 1 && strcmp(tipo,"EC") == 1 && strcmp(tipo,"EM") == 1)
    {
        cout << "Curso Inexistente!" << endl;
        return;

    }


    for(i = 0; i <= ind; i++)
    {
        if(strcmp(tipo,"CC") == 0 && v[i].curso == "CC")
        {
            if(v[i].frequencia >= 75 && v[i].media >= 6.00)
            {
                cout << "N�mero da matr�cula: " << v[i].matricula << endl;
                cout << "Nome: " << v[i].nome << endl;
                cout << fixed;
                cout.precision(2);
                cout << "M�dia: " << v[i].media << endl;
                cout << "Frequencia: " << v[i].frequencia << "%" << endl;
                cout << "------------------------------------------------" << endl;

            }
        }

    }


     for(i = 0; i <= ind; i++)
    {
        if(strcmp(tipo,"EM") == 0 && v[i].curso == "EM")
        {
            if(v[i].frequencia >= 75 && v[i].media >= 6.00)
            {
                cout << "N�mero da matr�cula: " << v[i].matricula << endl;
                cout << "Nome: " << v[i].nome << endl;
                cout << fixed;
                cout.precision(2);
                cout << "M�dia: " << v[i].media << endl;
                cout << "Frequencia: " << v[i].frequencia << "%" << endl;
                cout << "------------------------------------------------" << endl;

            }
        }
    }


    for(i = 0; i <= ind; i++)
    {
        if(strcmp(tipo,"EC") == 0 && v[i].curso == "EC")
        {
            if(v[i].frequencia >= 75 && v[i].media >= 6.00)
            {
                cout << "N�mero da matr�cula: " << v[i].matricula << endl;
                cout << "Nome: " << v[i].nome << endl;
                cout << fixed;
                cout.precision(2);
                cout << "M�dia: " << v[i].media << endl;
                cout << "Frequencia: " << v[i].frequencia << "%" << endl;
                cout << "------------------------------------------------" << endl;

            }
        }
    }

}

/*M�dia por turma (lista a maior, menor e a m�dia das notas de cada turma, juntamente com
o n�mero da turma, separando cada turma com uma linha pontilhada)*/

void mediaturma(aluno v[], int ind)
{
    int x = 1, i = 0, cont, k = 0;
    int turma[x];
    float maior[cont] , menor[cont], media[cont];

    for(i = 0; i <= ind; i++)
    {
        if(v[i].turma != turma[i])
        {
            turma[x] = v[i].turma;
            x++;
            cont++;


        }

    }

     for(x = 1; x <= cont; x++)
    {
            cout << turma[x] << "   ";
    }



    for(x = 1; x <= cont; x++)
    {
        maior[x] = 0;
        menor[x] = 100;
        media[x] = 0;



        for(i = 0; i< ind; i++)
        {
            if(turma[x] == v[i].turma )
            {
                if(v[i].media > maior[x])
                {
                    maior[x] = v[i].media;
                }
                if(v[i].media < menor[x])
                {
                    menor[x] = v[i].media;
                }

                media[x] += v[i].media;
                k++;


            }
        }


    }

    for(x = 1; x <= cont; x++)
    {

    cout << "\nTurma: " << turma[x] << endl;
        cout << "Maior nota: " << maior[x] << endl;
        cout << "Menor nota: " << menor[x] << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Media da turma: " << media[x] / k  << endl;
        cout << "--------------------" << endl;

    }



}
