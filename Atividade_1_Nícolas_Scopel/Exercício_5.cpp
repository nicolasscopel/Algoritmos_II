#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL, "Portuguese");


    int menu, x, y, num, cont, cod, qtd, folha = 0, caneta = 0, cad = 0, marca = 0, cola = 0, corre = 0, lapis = 0;
    int moch = 0, dese = 0;
    float valor1 = 0, valor2 = 0, valor3 = 0, valor4 = 0, valor5 = 0, valor6 = 0, valor7 = 0, valor8 = 0, valor9 = 0;
    float desc1 = 0, desc2 = 0, desc3 = 0, desc4 = 0, desc5 = 0, desc6 = 0, desc7 = 0, desc8 = 0, desc9 = 0;
    float total1 = 0, total2 = 0, total3 = 0, total4 = 0, total5 = 0, total6 = 0, total7 = 0, total8 = 0, total9 = 0;




    cout << fixed;
    cout.precision(2);

    do
    {
        system("cls");
        cout << "###### MENU DE OPÇÕES ######" << endl;
        cout << "# 0 - Incluir Mais um Item #" << endl;
        cout << "# 1 - Encerrar Compra      #" << endl;
        cout << "############################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        if(menu == 1)
        {
            system("cls");


            cout << "Encerrando compra. " << endl;

            cout << "\nDescrição \t\t\t";
            cout.width(9);
            cout << right <<  "QTD \t\t";
            cout.width(23);
            cout << right << "Valor do item \t";
            cout.width(18);
            cout << right << "Desconto\t";
            cout.width(14);
            cout << right << "Total Item" << endl;


            if(folha != 0)
            {
                cout.width(30);
                cout << left << "Folha branca A4 com 500";
                cout.width(7);
                cout << right << folha;
                cout.width(30);
                cout << right << valor1;
                cout.width(21);
                cout << right << desc1;
                cout.width(18);
                cout << right << total1;

            }

            if(caneta != 0)
            {
                cout.width(30);
                cout << left << "\nCaneta BIC ponta fina";
                cout.width(8);
                cout << right << caneta;
                cout.width(30);
                cout << right << valor2;
                cout.width(21);
                cout << right << desc2;
                cout.width(18);
                cout << right << total2;

            }

            if(cad != 0)
            {
                cout.width(30);
                cout << left << "\nCaderno 10 matérias";
                cout.width(8);
                cout << right << cad;
                cout.width(30);
                cout << right << valor3;
                cout.width(21);
                cout << right << desc3;
                cout.width(18);
                cout << right << total3;

            }


            if(marca != 0)
            {
                cout.width(30);
                cout << left << "\nCaneta marca texto";
                cout.width(8);
                cout << right << marca;
                cout.width(30);
                cout << right << valor4;
                cout.width(21);
                cout << right << desc4;
                cout.width(18);
                cout << right << total4;

            }

            if(cola != 0)
            {
                cout.width(30);
                cout << left << "\nCola Bastão";
                cout.width(8);
                cout << right << cola;
                cout.width(30);
                cout << right << valor5;
                cout.width(21);
                cout << right << desc5;
                cout.width(18);
                cout << right << total5;

            }

            if(corre != 0)
            {
                cout.width(30);
                cout << left << "\nCorretor ortográfico";
                cout.width(8);
                cout << right << corre;
                cout.width(30);
                cout << right << valor6;
                cout.width(21);
                cout << right << desc6;
                cout.width(18);
                cout << right << total6;

            }

            if(lapis != 0)
            {
                cout.width(30);
                cout << left << "\nLápis preto";
                cout.width(8);
                cout << right << lapis;
                cout.width(30);
                cout << right << valor7;
                cout.width(21);
                cout << right << desc7;
                cout.width(18);
                cout << right << total7;

            }

            if(moch != 0)
            {
                cout.width(30);
                cout << left << "\nMochila com repartimento";
                cout.width(8);
                cout << right << moch;
                cout.width(30);
                cout << right << valor8;
                cout.width(21);
                cout << right << desc8;
                cout.width(18);
                cout << right << total8;

            }

            if(dese != 0)
            {
                cout.width(30);
                cout << left << "\nCaderno de desenho";
                cout.width(8);
                cout << right << dese;
                cout.width(30);
                cout << right << valor9;
                cout.width(21);
                cout << right << desc9;
                cout.width(18);
                cout << right << total9;

            }

            cout << "\n\nTotal da compra:";
            cout.width(90);
            cout.fill('.');
            cout << right << total1 + total2 +total3 + total4 + total5 + total6 + total7 + total8 + total9;




            getchar();
            break;

        }

        if(menu == 0)
        {
            system("cls");


            cout << "Descrição \t\t\t";
            cout.width(10);
            cout << "Código \t\t";
            cout.width(20);
            cout << "Valor R$ \t\t";
            cout.width(10);
            cout << "Desconto %" << endl;

            cout.width(30);
            cout << left << "Folha branca A4 com 500";
            cout.width(6);
            cout << right << "1";
            cout.width(35);
            cout << right << "28.00";
            cout.width(21);
            cout << right << "7%" << endl;

            cout.width(30);
            cout << left << "Caneta BIC ponta fina";
            cout.width(6);
            cout << right << "2";
            cout.width(35);
            cout << right << "6.30";
            cout.width(21);
            cout << right << "5%" << endl;

            cout.width(30);
            cout << left << "Caderno 10 matérias";
            cout.width(6);
            cout << right << "3";
            cout.width(35);
            cout << right << "22.00";
            cout.width(21);
            cout << right << "5%" << endl;

            cout.width(30);
            cout << left << "Caneta marca texto";
            cout.width(6);
            cout << right << "4";
            cout.width(35);
            cout << right << "17.80";
            cout.width(21);
            cout << right << "6%" << endl;

            cout.width(30);
            cout << left << "Cola Bastão";
            cout.width(6);
            cout << right << "5";
            cout.width(35);
            cout << right << "5.50";
            cout.width(21);
            cout << right << "7%" << endl;

            cout.width(30);
            cout << left << "Corretor ortográfico";
            cout.width(6);
            cout << right << "6";
            cout.width(35);
            cout << right << "11.00";
            cout.width(21);
            cout << right << "10%" << endl;

            cout.width(30);
            cout << left << "Lápis preto";
            cout.width(6);
            cout << right << "7";
            cout.width(35);
            cout << right << "4.50";
            cout.width(21);
            cout << right << "2%" << endl;

            cout.width(30);
            cout << left << "Mochila com repartimento";
            cout.width(6);
            cout << right << "8";
            cout.width(35);
            cout << right << "138.00";
            cout.width(21);
            cout << right << "7%" << endl;

            cout.width(30);
            cout << left << "Caderno de desenho";
            cout.width(6);
            cout << right << "9";
            cout.width(35);
            cout << right << "8.00";
            cout.width(21);
            cout << right << "5%" << endl;



                cout << "\n\nInforme o código do produto: ";
                cin >> cod;

                cout << "\nInforme a quantidade do produto: ";
                cin >> qtd;

                if(cod < 1 || cod > 9)
                {
                    system("cls");
                    cout << "Código incorreto. Informe novamente." << endl;

                    system("PAUSE");
                    getchar();


                }

                else if(cod == 1)
                {
                    folha += qtd;
                    valor1 = 28.00;
                    desc1 = valor1 * folha * 0.07;
                    total1 = (folha * valor1) - desc1;
                    getchar();
                }

                else if(cod == 2)
                {
                    caneta += qtd;
                    valor2 = 6.30;
                    desc2 = valor2 * caneta * 0.05;
                    total2 = (caneta * valor2) - desc2;
                    getchar();

                }

                else if(cod == 3)
                {
                    cad += qtd;
                    valor3 = 22.00;
                    desc3 = valor3 * cad * 0.05;
                    total3 = (cad * valor3) - desc3;
                    getchar();

                }
                else if(cod == 4)
                {
                    marca += qtd;
                    valor4 = 17.80;
                    desc4 = valor4 * marca * 0.06;
                    total4 = (marca * valor4) - desc4;
                    getchar();

                }

                else if(cod == 5)
                {
                    cola += qtd;
                    valor5 = 5.50;
                    desc5 = valor5 * cola * 0.07;
                    total5 = (cola * valor5) - desc5;
                    getchar();

                }

                else if(cod == 6)
                {
                    corre += qtd;
                    valor6 = 11.00;
                    desc6 = valor6 * corre * 0.1;
                    total6 = (corre * valor6) - desc6;
                    getchar();

                }

                else if(cod == 7)
                {
                    lapis += qtd;
                    valor7 = 4.50;
                    desc7 = valor7 * lapis * 0.02;
                    total7 = (lapis * valor7) - desc7;
                    getchar();

                }

                else if(cod == 8)
                {
                    moch += qtd;
                    valor8 = 138.00;
                    desc8 = valor8 * moch * 0.07;
                    total8 = (moch * valor8) - desc8;
                    getchar();

                }

                else if(cod == 9)
                {
                    dese += qtd;
                    valor9 = 8.00;
                    desc9 = valor9 * dese * 0.05;
                    total9 = (dese * valor9) - desc9;
                    getchar();

                }


        }

        else
        {
            system("cls");
            cout << " Opcao invalida.";
            getchar();
        }



    }
    while(menu != 1);





}
