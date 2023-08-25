/*34 - Na papelaria �Livro e Cia� a volta as aulas � um momento de realizar promo��es, os itens
descritos abaixo est�o com o respectivo desconto e percentual

Descri��o                C�digo    ValorR$    Desconto%
Folha branca A4 com 500     1      28.00     7%
Caneta Bic ponta fina       2      6.30      5%
Caderno 10 mat�rias         3      22.00     5%
Caneta marca texto          4      17.80     6%
Cola bast�o                 5       5.50     7%
Corretor ortogr�fico        6      11.00    10%
L�pis preto                 7      4.50      2%
Mochila comrepartimento     8     138.00     7%
Caderno de desenho          9      8.00      5%

Escreva um programa que auxilie o dono da papelaria a realizar as compras dos clientes, sendo
poss�vel registrar at� 10 compras, onde deve ser armazenado o c�digo do cliente e seu nome e
o total da venda, cada venda poder� ter v�rios itens, em rela��o aos itens deve ser armazenado
o c�digo do item e a quantidade, para tanto o sistema dever� apresentar um menu com as
seguintes possibilidades:
0 � Sair do programa
1 � Registrar venda
2 � Mostrar todas as vendas
3 � Consultar venda pelo c�digo do cliente
4 � Mostrar o valor total das vendas realizadas.
Para exibir as vendas dever� seguir este padr�o
Cliente: 1 � Fulano de tal
Descri��o QTD Valor do Item Desconto Total Item
Folha branca A4 com 500 1 28.00 1.96 26.04
Caderno 10 mat�rias 2 44.00 2.20 41.80
Cola bast�o 1 5.50 0.38 5.12
Total da compra:....................................................................................................72.96
OBS:
- Validar para aceitar somente itens pertencentes � lista apresentada.
- Exibir a compra com os alinhamentos e os valores num�ricos formatados conforme no
exemplo.
- Aplicar o desconto em cada item, conforme a tabela de promo��es*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

struct itens
{
    int codigo;
    float valor, desconto;
    string nome;
};
struct vendido
{
    int codigo;
    int qtd;
};
struct vendas
{
    int codigoCl;
    string nomeCl;
    vendido compraCl[9];
    int qtdCompras;
};

void line();
void tabelaProdutos(itens item[], int n), invalido();
int checkCod(vendas v[], int n, int codigo);
void mostrarUm(itens item[], vendas v[], int n);
void mostrarTodos(itens item[], vendas v[], int n);
void somaTot(itens item[], vendas v[], int n, float &somaVendas);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct itens item[9];
    struct vendas v[10];
    item[0] = {.codigo=1, .valor=28, .desconto=0.07, .nome = "Folha branca A4 com 500"};
    item[1] = {.codigo=2, .valor=6.3, .desconto=0.05, .nome = "Caneta Bic ponta fina"};
    item[2] = {.codigo=3, .valor=22, .desconto=0.05, .nome = "Caderno 10 mat�rias"};
    item[3] = {.codigo=4, .valor=17.8, .desconto=0.06, .nome = "Caneta marca texto"};
    item[4] = {.codigo=5, .valor=5.5, .desconto=0.07, .nome = "Cola Bast�o"};
    item[5] = {.codigo=6, .valor=11, .desconto=0.1, .nome = "Corretor ortogr�fico"};
    item[6] = {.codigo=7, .valor=4.5, .desconto=0.02, .nome = "L�pis preto"};
    item[7] = {.codigo=8, .valor=138, .desconto=0.07, .nome = "Mochila com repartimento"};
    item[8] = {.codigo=9, .valor=8, .desconto=0.05, .nome = "Caderno de desenho"};

    int op, n=-1;
    bool ok=0;
    float somaVendas = 0;

    do
    {
        system("cls");
        tabelaProdutos(item, 8);

        cout << "\n0 � Sair do programa\n1 � Registrar venda\n2 � Mostrar todas as vendas\n3 � Consultar venda pelo c�digo do cliente\n4 � Mostrar o valor total das vendas realizadas\n\nOp��o: ";
        cin >> op;

        if(op<0 || op>4)
        {
            invalido();
        }
        else if(op==0)
        {
            cout << "\nVoc� sair� do programa!\n";
        }
        else if(op==1)
        {
            if(n>=9)
            {
                cout << "\nQuantidade m�xima de vendas alcan�ada! N�o � poss�vel vender mais!\n";
                system("pause");
            }
            else
            {
                int cCl, numCl, c, qtd;
                bool segue=1;

                cout << "\nC�digo do cliente: ";
                cin >> cCl;

                for(int i=0; i<=n; i++)
                {
                    if(cCl == v[i].codigoCl)
                    {
                        cout << "\nPor quest�es de organiza��o das vendas, n�o � poss�vel registrar mais de uma venda com o mesmo c�digo do cliente! Inicie a venda com outro c�digo ou fa�a v�rias compras com o mesmo cliente em uma venda s�!\n";
                        system("pause");
                        segue=0;
                    }
                }

                if(segue == 1)
                {
                    n++;
                    int x=-1;

                    v[n].codigoCl = cCl;

                    cout << "\nNome do cliente: ";
                    fflush(stdin);
                    getline(cin, v[n].nomeCl);

                    int interromper; //coloquei como int para n�o dar bug no programa se o usu�rio digitar algo que nao seja 0 ou 1
                    do
                    {
                        interromper=1;

                        do
                        {
                            cout << "\nC�digo do produto: ";
                            cin >> c;

                            if(c<1 || c>9)
                            {
                                cout << "\nC�digo inv�lido! Digite novamente!\n";
                                system("pause");
                            }
                            else
                            {
                                x++;
                                if(x==0)
                                    v[n].qtdCompras=0;
                                v[n].qtdCompras++;
                                v[n].compraCl[x].codigo = c - 1;
                            }
                        }
                        while(c<1 || c>9);

                        do
                        {
                            cout << "\nQuantidade: ";
                            cin >> qtd;

                            if(qtd<=0)
                            {
                                cout << "\nQuantidade inv�lida! Digite novamente!\n";
                                system("pause");
                            }
                            else
                            {
                                v[n].compraCl[x].qtd = qtd;
                            }

                        }
                        while(qtd<=0);

                        do
                        {
                            cout << "\nDigite 0 para continuar comprando. Digite 1 para sair.\n";
                            cin >> interromper;

                            if(interromper!=0 && interromper!=1)
                                cout << "\nInv�lido! Digite novamente!\n";

                        }
                        while(interromper!=0 && interromper!=1);


                    }
                    while(interromper==0);
                }
            }
            ok=1;
        }
        else if(ok==1)
        {
            if(op==2)
            {
                mostrarTodos(item, v, n);
                cout << endl;
                system("pause");
            }
            else if(op==3)
            {
                int x, check;
                do
                {
                    cout << "\nC�digo do cliente: ";
                    cin >> x;

                    check = checkCod(v, n, x);

                    if(check == -1)
                    {
                        cout << "\nC�digo Inv�lido! Digite novamente!\n";
                        system("pause");
                    }

                }
                while(check == -1);

                mostrarUm(item, v, check);
                cout << endl;
                system("pause");
            }
            else if(op==4)
            {
                somaVendas=0;
                for(int i=0; i<=n; i++)
                    somaTot(item, v, i, somaVendas);

                printf("\nSoma de todas as vendas: %.2f\n\n", somaVendas);
                system("pause");
            }
        }
        else
        {
            cout << "\nN�o h� nenhuma venda cadastrada! Venda para realizar opera��es!\n";
            system("pause");
        }
    }
    while(op!=0);


    return 0;
}
void line()
{
    for(int i=0; i<90; i++)
        cout << "-";
}
void tabelaProdutos(itens item[], int n)
{
    cout << "\t\tPAPELARIA LIVRO E CIA\n\n";
    printf("|%18s        |%7s |%8s |%10s |\n", "DESCRI��O", "C�DIGO", "VALOR R$", "DESCONTO %");
    for(int i=0; i<=n; i++)
    {
        printf("|%25s |%7d |%8.2f |%10.2f |\n", item[i].nome.c_str(), item[i].codigo, item[i].valor, item[i].desconto*100 );
    }
}
void invalido()
{
    printf("\nValor inv�lido!\n\n");
    system("pause");
}
int checkCod(vendas v[], int n, int codigo)
{
    for(int i=0; i<=n; i++)
    {
        if(v[i].codigoCl == codigo)
            return i;
    }
    return -1;
}
void mostrarUm(itens item[], vendas v[], int n)//n sera obtido pelo checkcod
{
    line();
    printf("\nCliente: %d - %s\n\n", v[n].codigoCl, v[n].nomeCl.c_str());
    printf("\n|%18s        |%3s |%8s\t|%10s\t |%10s \n", "DESCRI��O", "QTD", "VALOR ITEM", "DESCONTO R$", "TOTAL ITEM");


    int q = v[n].qtdCompras;
    float parcial, total=0, descontoRS;

    for(int i=0; i<q; i++)
    {
        int c = v[n].compraCl[i].codigo;
        int qtd = v[n].compraCl[i].qtd;

        descontoRS  = item[c].valor*item[c].desconto*qtd;
        parcial = (item[c].valor * qtd) - descontoRS;
        total += parcial;

        printf("|%25s |%d \t|%.2f\t\t|%.2f \t\t |%.2f\t \n", item[c].nome.c_str(), qtd, item[c].valor, descontoRS, parcial);

    }

    printf("\n\nTotal:....................................................................%.2f\n\n", total);


}
void mostrarTodos(itens item[], vendas v[], int n)
{
    for(int i=0; i<=n; i++)
        mostrarUm(item, v, i);
    line();
}

void somaTot(itens item[], vendas v[], int n, float &somaVendas)
{
    int q = v[n].qtdCompras;
    float parcial, total=0, descontoRS;

    for(int i=0; i<q; i++)
    {
        int c = v[n].compraCl[i].codigo;
        int qtd = v[n].compraCl[i].qtd;

        descontoRS  = item[c].valor*item[c].desconto*qtd;
        parcial = (item[c].valor * qtd) - descontoRS;
        total += parcial;

    }

    somaVendas+=total;
}
