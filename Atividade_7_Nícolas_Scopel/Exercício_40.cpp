/*40 - Escreva um programa que implemente as seguintes fun��es:
- Fun��o para ler um n�mero inteiro qualquer, maior que 10, considere que o d�gito 0 �zero� n�o
ser� informado na composi��o do valor lido.
- Fun��o para ler um n�mero verificador inteiro entre 1 e 9 (inclusive 1 e 9), valores fora deste
intervalo n�o ser�o aceitos, validar a entrada.
- Fun��o RECURSIVA que conta quantas vezes o n�mero verificador aparece no n�mero inteiro
lido e apresenta o resultado. Caso o n�mero verificador n�o aparecer deve apresentar 0 como
resposta.
Exemplo:
Informe um n�mero inteiro qualquer: 12345
Informe o n�mero verificador: 3
Resposta: 1
Informe um n�mero inteiro qualquer: 5347412
Informe o n�mero verificador: 4
Resposta: 2
Informe um n�mero inteiro qualquer: 4176
Informe o n�mero verificador: 2
Resposta: 0
OBS: Todas as fun��es devem ser acionadas na respectiva ordem no programa principal.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

int lernum(int &num);
int lerverificador(int &veri);
int procura(int num, int veri, int count);

main()
{
    setlocale (LC_ALL, "Portuguese");

    int numero, verif, contador = 0;

    lernum(numero);
    lerverificador(verif);

    cout << "O numero verificador aparece " << procura(numero, verif , 0) << " vezes no numero informado." << endl;


}


int lernum(int &num)
{
    do
    {
        cout << "Informe um numero inteiro maior que 10: ";
        cin >> num;
    }
    while(num <= 10);

}

int lerverificador(int &veri)
{
    do
    {
        cout << "Informe um numero verificador (1 - 9): ";
        cin >> veri;
    }
    while(veri < 1 || veri > 9);

}

int procura(int num, int veri, int count)
{
    int digi;

    if(num == 0)
    {
        return count;
    }


    else
    {
        digi = num % 10;
        if(digi == veri)
        {
             count++;
        }

        procura(num / 10, veri, count);
    }


}
