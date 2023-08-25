#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void ler(int v[], int posicao);

main()
{
   setlocale(LC_ALL,"portuguese");
   int vet[10];
   srand(time(NULL));
   ler(vet,0);
   for(int i = 0; i < 10; i++)
       cout << vet[i] << ", ";
}

void ler(int v[], int posicao)
{
   if(posicao == 10)
       return; //ponto de parada
   else
   {
       v[posicao] = rand() % 50;
       ler(v, posicao + 1);
   }
}

