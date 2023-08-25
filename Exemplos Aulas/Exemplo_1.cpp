/* */


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>


using namespace std;

main()
{
    cout << fixed;
    cout.precision(2);
    float num;
    cout << "Informe um valor: ";
    cin >> num;

    fflush(stdin); //limpar buffer do teclado


    for(int i = 1; i <= 10; i++)
    {
        cout.width(6);
        cout.fill(' ');
        cout << left << i;
        cout.width(50);
        cout.fill('-');
        cout << right << num << endl;

        num += num * (5.00 / 100.00);



    }

}

