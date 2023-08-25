/* 30 - Em diferentes modalidades esportivas a tecnologia está sendo utilizada para monitorar o
desempenho dos atletas, no futebol não tem sido diferente, a maioria dos grandes clubes utiliza
de uma espécie de colete ou cinta que os jogadores utilizam embaixo da camiseta, este colete
está equipado com sensores e um dispositivo de GPS, capaz de coletar as seguintes
informações:
Tempo da atividade (em horas), Distância percorrida (em km), Frequência cardíaca.
Tudo isso é um “prato cheio” para os departamentos de análises científicas dos clubes, que, em
uma integração com o departamento médico, de fisiologia e técnico, conseguem saber qual
atleta está melhor em vários aspectos.
Para facilitar a análise dos dados você foi contratado para desenvolver um programa
informatizado, que poderá receber os dados mencionados acima de cada um dos jogadores,
cada jogador é identificado pelo número da sua camisa e deve ter a informação da sua idade e
seu peso corporal também.
O sistema deverá realizar e exibir os seguintes cálculos:
- Velocidade média de cada jogador
- Distância percorrida por cada jogador em ordem decrescente
- Jogador que consumiu o maior e o menor número de calorias, o cálculo do consumo de
calorias deverá seguir conforme este exemplo: um indivíduo de 78 Kg, correndo à uma
velocidade média de 8 Km/h estará gastando: 8 x 78 x 0,0175 = 10,92 Calorias por minuto.
Uma corrida de uma hora nesta velocidade terá, portanto, gastado 10,92 x 60 min = 655,2
Calorias.
O sistema deverá apresentar um menu com as seguintes alternativas:
0 – Sair
1 – Cadastrar atleta (O sistema deve funcionar com qualquer quantidade de atletas
cadastrados)
2 – Mostrar todos os cadastrados (exibir todos os dados separando cada atleta por uma linha
pontilhada)
3 – Velocidade média de cada jogador
4 – Distância percorrida em ordem decrescente
5 – Maior e menor consumo de calorias

OBS:
- As ações 2, 3, 4 e 5 só poderão ser acionadas se a opção 1 já foi executada.
- Ao escolher opção inválida no menu deverá exibir mensagem com tal informação.
- Utilize struct, funções e passagem de parâmetro para resolver este exercício, não sendo
permitido o uso de variáveis globais.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

struct dados
{
    int camisa;
    int idade;
    float peso;
    float horas;
    float distancia;
    int frequencia;
};

void cadastro(dados v[], int &i);
void mostra(dados v[], int ind);
void velmedia(dados v[], int ind);
void ordemdecresdist(dados v[], int ind);
void consumocalorias(dados v[], int ind);

main()
{
    setlocale (LC_ALL, "Portuguese");

    int i, x, menu = -1, indice = -1, ver;

    dados vet[100];

    do
    {
        system("cls");
        cout << "====================== MENU DE OPÇÕES =====================" << endl;
        cout << "- 0 - Sair                                                -" << endl;
        cout << "- 1 - Cadastrar atleta                                    -" << endl;
        cout << "- 2 – Mostrar todos os cadastrados                        -" << endl;
        cout << "- 3 – Velocidade média de cada jogador                    -" << endl;
        cout << "- 4 – Distância percorrida em ordem decrescente           -" << endl;
        cout << "- 5 – Maior e menor consumo de calorias                   -" << endl;
        cout << "===========================================================" << endl;
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
                cout << "Nenhum jogador cadastrado!";
            else
            {
                mostra(vet,indice);
            }

            getchar();
            break;


        case 3 :
            system("cls");

            if(indice < 0)
                cout << "Nenhum jogador cadastrado!";
            else
            {
                velmedia(vet,indice);

            }


            getchar();
            break;


        case 4 :
            system("cls");

            if(indice < 0)
                cout << "Nenhum jogador cadastrado!";
            else
            {
                ordemdecresdist(vet,indice);
            }

            getchar();
            break;

        case 5 :
            system("cls");

            if(indice < 0)
                cout << "Nenhum jogador cadastrado!";
            else
            {
                consumocalorias(vet,indice);

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

void cadastro(dados v[], int &i)
{
    i++;

    cout << "\nInforme o numero da camiseta [" << i << "]: ";
    cin >> v[i].camisa;
    fflush(stdin);

    for (int x = 0; x < i; x++)
    {

        if (v[x].camisa == v[i].camisa)
        {
            cout << "Ja existe um jogador com esse número." << endl;
            i--;
            return;
        }
    }

    cout << "Informe a idade [" << i << "]: ";
    cin >> v[i].idade;
    fflush(stdin);

    cout << "Informe o peso [" << i << "]: ";
    cin >> v[i].peso;
    fflush(stdin);

    cout << "Informe o tempo de atividade em horas [" << i << "]: ";
    cin >> v[i].horas;
    fflush(stdin);

    cout << "Informe a distancia em quilometros [" << i << "]: ";
    cin >> v[i].distancia;
    fflush(stdin);

    cout << "Informe a frequencia cardiaca [" << i << "]: ";
    cin >> v[i].frequencia;
    fflush(stdin);

    cout << "\n\nJogador cadastrado com sucesso!! Pressione Enter para continuar." << endl;


}
void mostra(dados v[], int ind)
{


    cout << "Jogadores cadastrados no sistema: " << endl << endl;
    for (int i = 0; i <=ind; i++)
    {
        cout << "Número da camiseta: " << v[i].camisa << endl;
        cout << "Idade: " << v[i].idade << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Peso: " << v[i].peso << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Tempo de atividade: " << v[i].horas << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Distância percorrida: " << v[i].distancia << endl;
        cout << "Frequencia Cardiaca: " << v[i].frequencia << endl;


        cout << "\n\n--------------------------------" << endl;
    }

}
void velmedia(dados v[], int ind)
{
    float media, tempo, dist;
    cout << "Velocidade média de cada jogador: ";
    cout << "\n--------------------------------" << endl;
    for (int i = 0; i <=ind; i++)
    {
        tempo = v[i].horas;
        dist = v[i].distancia;
        media = dist/tempo;


        cout << "Número da camiseta: " << v[i].camisa << endl;
        cout << "Velocidade média é de: " << media << " km/h" << endl;



        cout << "\n--------------------------------" << endl;
    }

}
void ordemdecresdist(dados v[], int ind)
{

    int vet[ind], aux;

    for(int i = 0; i <= ind; i++)
    {
        vet[i] = v[i].distancia;
    }

    for(int i = 0; i < ind; i++)
    {
        for( int x = i + 1; x < ind+1; x++)
        {
            if(vet[i] < vet[x])
            {
                aux = vet[i];
                vet[i] = vet[x];
                vet[x] = aux;
            }
        }
    }



    cout << "\nDistância percorrida em ordem descrescente";
    for(int i = 0; i <= ind; i++)
    {

        cout << endl;
        cout << fixed;
        cout.precision(2);
        cout << vet[i] << " km";
        cout << endl;
    }


    return;


}

/*- Jogador que consumiu o maior e o menor número de calorias, o cálculo do consumo de
calorias deverá seguir conforme este exemplo: um indivíduo de 78 Kg, correndo à uma
velocidade média de 8 Km/h estará gastando: 8 x 78 x 0,0175 = 10,92 Calorias por minuto.
Uma corrida de uma hora nesta velocidade terá, portanto, gastado 10,92 x 60 min = 655,2
Calorias.*/

void consumocalorias(dados v[], int ind)
{
    float peso, tempo, dist, media, calorias, vet[ind], maior = -1, menor = 9999, camisa;
    int f, h;


    for (int i = 0; i <=ind; i++)
    {
        camisa = v[i].camisa;
        tempo = v[i].horas;
        dist = v[i].distancia;
        media = dist/tempo;

        peso = v[i].peso;

        vet[i] = peso * media * 0.0175 * tempo * 60;


    }

     for (int i = 0; i <= ind; i++)
    {
        if(vet[i] < vet[i+1])
        {
            menor = vet[i];
            f = i;

        }

    }

    for (int i = 0; i <= ind; i++)
    {
        if(vet[i] > vet[i+1])
        {
            maior = vet[i];
            h = i ;

        }

    }

    cout << fixed;
    cout.precision(2);
    cout << "O maior consumo de calorias foi de: " << maior << " cal " << endl;

    cout << fixed;
    cout.precision(2);
    cout << "O menor consumo de calorias foi de: " << menor << " cal" << endl;



}









