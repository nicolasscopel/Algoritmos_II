/*39 - Escreva uma fun��o recursiva que determine quantas vezes um d�gito K ocorre em um
n�mero natural N. Por exemplo, o d�gito 2 ocorre 3 vezes em 342021892.
O n�mero K e o valor N devem ser informados pelo usu�rio
Validar para que o d�gito K seja >=0 e <= 9*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

int procura(int N, int K);

main()
{
	setlocale (LC_ALL, "Portuguese");

	int K, N;

	do
    {
        cout << "Informe um numero inteiro: ";
	cin >> N;

	cout << "Informe um �nico digito inteiro: ";
	cin >> K;


    }while(K < 0 || K > 9);

    cout << "Esse numero aparece " << procura(N,K) << " vezes! " << endl;


}

int procura(int N, int K)
{
    int cont = 0;

    if(N == 0)
    {
        return 0;
    }
    if(N % 10 == K)
    {
        return 1 + procura(N/10, K);
    }

    else
    {
        return procura(N / 10, K);
    }
}
