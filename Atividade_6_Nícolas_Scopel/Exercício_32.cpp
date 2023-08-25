/*32 - Diz-se que um n�mero inteiro N � um quadrado perfeito se existirem M n�meros �mpares
consecutivos a partir do valor 1 cuja soma � igual a N. Neste caso N = M2

. Exemplo:

16=1+3+5+7 (16 � igual � soma dos quatro primeiros �mpares a partir de 1) e 16=42

. Logo 16
representa um quadrado perfeito. Escreva um algoritmo que utilizando fun��es, verifique se um
valor inteiro positivo fornecido pelo usu�rio � um quadrado perfeito ou n�o.*/




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
    cout << "Digite um n�mero inteiro positivo: ";
    cin >> num;
    if (quadradoperfeito(num))
    {
        cout << num << " � um quadrado perfeito." << endl;
    }
    else
    {
        cout << num << " n�o � um quadrado perfeito." << endl;
    }
    return 0;


}
