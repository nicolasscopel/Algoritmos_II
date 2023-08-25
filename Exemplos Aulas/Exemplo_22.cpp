/**/




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
    setlocale (LC_ALL, "Portuguese");

    int vet[5] = {5,6,7,8,9}, i = 0;
    int *pvet;
    pvet = vet;


    while(i < 5)
    {
        cout << "Endereço " << pvet << ", ";
        cout << "Valor " << *pvet << endl;

        pvet++;
        i++;



    }


    cout << "Endereço " << pvet << ", ";
    cout << "Valor " << *pvet << endl;
    cout << "i " << i << endl;
    cout << endl;


    // RESET DO VETOR NA POSIÇÃO 0
    /*
    pvet -= 5;
    cout << "Endereço " << pvet << ", ";
    cout << "Valor " << *pvet << endl;
    */

    while(i > 0)
    {
        pvet--;
        cout << "Endereço " << pvet << ", ";
        cout << "Valor " << *pvet << endl;
        i--;

    }











}
