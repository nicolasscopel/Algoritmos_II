/*4 - Uma empresa possui ônibus com 40 lugares (20 nas janelas e 20 no corredor). Faça
um programa que, usando ponteiros, utilize dois vetores para controlar as poltronas
ocupadas no corredor e na janela. Considere que 0 representa poltrona desocupada e 1,
poltrona ocupada.

Janela
1 1 0 0 ... 1 0 0
0 1 2 3 ... 17 18 19

Corredor
1 0 0 1 ... 1 0 0
0 1 2 3 ... 17 18 19

Inicialmente, todas as poltronas estarão livres (0). Depois disso, o programa deverá
apresentar um menu com as seguintes opções:
1 - vender passagem.
2 - mostrar mapa de ocupação do ônibus.
3 - encerrar.
Quando a opção escolhida for Vender Passagem, deverá ser perguntado se o usuário
deseja janela ou corredor e o número da poltrona. O programa deverá, então, dar uma
das seguintes mensagens:
- Venda efetivada — se a poltrona solicitada estiver livre, marcando-a como ocupada.
- Poltrona ocupada — se a poltrona solicitada não estiver disponível para venda.
- Ônibus lotado — quando todas as poltronas já estiverem ocupadas.
Quando a opção escolhida for Mostrar Mapa de Ocupação do Ônibus, deverá ser
mostrada uma listagem conforme a seguir:


JANELA         CORREDOR

1- Ocupada    1- Ocupada
2- Ocupada    2- Livre
3- Livre      3- Livre
4- Livre      4- Ocupada
5- Ocupada    5- Livre
E assim sucessivamente...*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void venda(int *v, int num);
void mapa(int *j, int *c);

main()
{
    setlocale (LC_ALL, "Portuguese");

    int corredor[20] = {0}, janela[20] = {0};
    int poltrona, menu;
    char posicao;
    int *pontc, *pontj;
    pontc = corredor;
    pontj = janela;

    do
    {

         system("cls");
        cout << "=============== MENU DE OPÇÕES ===============" << endl;
        cout << "- 1 - Vender Passagem                        -" << endl;
        cout << "- 2 – Mostrar mapa de ocupação do ônibus     -" << endl;
        cout << "- 3 – Encerrar                               -" << endl;
        cout << "==============================================" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {



        case 1 :

            system("cls");

            cout << "O Sr(a). deseja poltrona no corredor ou janela? | J - Janela | C - Corredor |: ";
            cin >> posicao;

            cout << "Qual o numero da poltrona 1 - 20: ";
            cin >> poltrona;

            if((posicao != 'J' && posicao != 'C') || (poltrona < 1 || poltrona > 20))
            {
                cout << "Dados informados incorretamente! Tente novamente.";
                getchar();
            }

            else if(posicao == 'J')
            {
                venda(pontj, poltrona);

            }
            else if(posicao == 'C')
            {
                venda(pontc, poltrona);
            }


            getchar();
            break;


        case 2:

            system("cls");

            mapa(pontj, pontc);



            getchar();
            break;


        case 3 :

            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;




        default :
            system("cls");
            cout << "Opção inválida.";
            getchar();
            break;
        }


    }while(menu != 3);

}

void venda(int *v, int num)
{
    int cont = 0;

    if(v[num - 1] == 0)
    {
        v[num - 1] = 1;
        cout << "Venda efetivada com sucesso!" << endl;
        getchar();
        cont++;
        return;
    }
    if(v[num - 1] == 1)
    {
        cout << "Poltrona ocupada!" << endl;
        getchar();
        return;
    }

    if(cont >= 40)
    {
        cout << "Onibus lotado!" << endl;
        getchar();
        return;
    }


}



void mapa(int *j, int *c)
{

    int i;

    cout << "JANELA           CORREDOR" << endl;

    for(i = 0; i < 20; i++)
    {
        cout << i+1 << "- ";
        if(j[i] == 0)
        {
            cout.width(15);
            cout << left << "Livre";
        }

        else
        {
            cout.width(15);
            cout << left << "Ocupado";
        }




        cout << right << i+1 << "- ";
        if(c[i] == 0)
        {
            cout.width(12);
            cout << left << "Livre";
        }

        else
        {
            cout.width(12);
            cout << left << "Ocupado";
        }


        cout << endl;

    }

}
