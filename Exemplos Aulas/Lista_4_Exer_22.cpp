#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void fibonacci(int valor, int ultValor, int cont, int fim){
    if(cont > fim){
        return;
    } else {
        cout << valor << endl;
        fibonacci(valor + ultValor, valor, cont+1, fim);
    }
}

main()
{
    fibonacci(0, 1, 1, 20);

}
