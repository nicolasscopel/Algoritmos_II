/* 1 – Pedro comprou um saco de ração com peso em quilos. Ele possui dois gatos, para
os quais fornece a quantidade de ração em gramas. A quantidade diária de ração
fornecida para cada gato é sempre a mesma. Faça um programa que receba o peso do
saco de ração e a quantidade de ração fornecida para cada gato, calcule e mostre
quanto restará de ração no saco após cinco dias. Este exercício deverá ser resolvido com
a utilização de ponteiros.*/


#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

void calcula(int *peso, int *gato1, int *gato2);

main()
{
    setlocale (LC_ALL, "Portuguese");

    int peso, gato1, gato2;

    fflush(stdin);

    cout << "Informe o peso em quilos do saco de racao : ";
    cin >> peso;
    fflush(stdin);

    cout << "Informe a quantidade em gramas de racao que o gato 1 come: ";
    cin >> gato1;
    fflush(stdin);

    cout << "Informe a quantidade em gramas de racao que o gato 2 come: ";
    cin >> gato2;
    fflush(stdin);


    calcula(&peso, &gato1, &gato2);



}


void calcula(int *peso, int *gato1, int *gato2)
{
    int i;
    *peso = *peso * 1000;

    for(i = 1; i <= 5; i++ )
    {
        *peso = *peso - *gato1 - *gato2;
    }


    cout << "O peso apos cinco dias será de " << *peso << " gramas" <<  endl;

}
