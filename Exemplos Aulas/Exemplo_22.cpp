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
        cout << "Endere�o " << pvet << ", ";
        cout << "Valor " << *pvet << endl;

        pvet++;
        i++;



    }


    cout << "Endere�o " << pvet << ", ";
    cout << "Valor " << *pvet << endl;
    cout << "i " << i << endl;
    cout << endl;


    // RESET DO VETOR NA POSI��O 0
    /*
    pvet -= 5;
    cout << "Endere�o " << pvet << ", ";
    cout << "Valor " << *pvet << endl;
    */

    while(i > 0)
    {
        pvet--;
        cout << "Endere�o " << pvet << ", ";
        cout << "Valor " << *pvet << endl;
        i--;

    }











}
