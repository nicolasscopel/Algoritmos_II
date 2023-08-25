/*35 - Em ano de Copa do Mundo de Futebol, o álbum de figurinhas oficial é sempre um grande
sucesso entre crianças e também entre adultos. Para quem não conhece, o álbum contém
espaços numerados de 1 a N para colar as figurinhas; cada figurinha, também numerada de 1 a
N, é uma pequena foto de um jogador de uma das seleções que jogará a Copa do Mundo. O
objetivo é colar todas as figurinhas nos respectivos espaços no álbum, de modo a completar o
álbum (ou seja, não deixar nenhum espaço sem a correspondente figurinha).
As figurinhas são vendidas em envelopes fechados, de forma que o comprador não sabe quais
figurinhas está comprando, e pode ocorrer de comprar uma figurinha que ele já tenha colado no
álbum.
Para ajudar os usuários, a empresa responsável pela venda do álbum e das figurinhas quer criar
um aplicativo que permita gerenciar facilmente as figurinhas que faltam para completar o álbum
e está solicitando a sua ajuda.
Dados o número total de espaços e figurinhas do álbum, e uma lista das figurinhas já
compradas (que pode conter figurinhas repetidas), sua tarefa é determinar quantas figurinhas
faltam para completar o álbum.
Entrada
A primeira linha contém um inteiro N indicando o número total de figurinhas e espaços no
álbum. A segunda linha contém um inteiro M indicando o número de figurinhas já compradas.
Cada uma das M linhas seguintes contém um número inteiro X indicando uma figurinha já
comprada.
Saída
Seu programa deve produzir uma única linha contendo um inteiro, o número de figurinhas que
falta para completar o álbum.
Restrições
1 ≤ N ≤ 100
1 ≤ M ≤ 300
1 ≤ X ≤ N*/

void receberdados(int total, int compra);




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

main()
{
    srand(time(NULL));
    setlocale (LC_ALL, "Portuguese");

    int n, m;

    do
    {
        cout << "\nInforme quantos espacos existem no album  1 - 100: ";
        cin >> n;

        cout << "Informe quantas figuirinhas foram compradas  1 - 300: ";
        cin >> m;

        if(n > 100 || n < 1 || m > 300 || m < 1)
        {
            cout << "Valores informados incorretamente!" << endl;
        }

    }
    while(n > 100 || n < 1 || m > 300 || m < 1);

    receberdados(n,m);


}

void receberdados(int x, int compra)
{

    int v[compra], i = 0, j = 0, cont = 0, valor, total;
    total = x;

    for(i = 0; i < compra; i++)
    {
        v[i] = rand() % x + 1;

    }

    for(i = 0; i < compra; i++)
    {
        cout << v[i] << " ";

    }
    cout << endl;

    for (i = 0; i < compra; i++)
    {
        for (j = i + 1; j < compra; j++)
        {
            if (v[i] == v[j])
            {
                cont++;
            }
        }

    }

    compra -= cont;


    x = x - compra;


    if(x < 1)
    {
        cout << "COMPLETOU" << endl;
    }
    else
    {
        cout << "Figurinhas faltantes: " << x;
    }


}
