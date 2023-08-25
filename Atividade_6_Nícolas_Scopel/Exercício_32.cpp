/*32 - Diz-se que um número inteiro N é um quadrado perfeito se existirem M números ímpares
consecutivos a partir do valor 1 cuja soma é igual a N. Neste caso N = M2

. Exemplo:

16=1+3+5+7 (16 é igual à soma dos quatro primeiros ímpares a partir de 1) e 16=42

. Logo 16
representa um quadrado perfeito. Escreva um algoritmo que utilizando funções, verifique se um
valor inteiro positivo fornecido pelo usuário é um quadrado perfeito ou não.*/




#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

bool quadradoperfeito(int n)
{
    int i = 1;
    int soma = 0;
    while (soma < n)
    {
        soma += i;
        i += 2;
    }
    return soma == n;
}

main()
{
    setlocale (LC_ALL, "Portuguese");

    int num;
    cout << "Digite um número inteiro positivo: ";
    cin >> num;
    if (quadradoperfeito(num))
    {
        cout << num << " é um quadrado perfeito." << endl;
    }
    else
    {
        cout << num << " não é um quadrado perfeito." << endl;
    }
    return 0;


}
