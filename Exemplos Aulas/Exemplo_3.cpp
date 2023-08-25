#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

main()
{
   setlocale(LC_ALL,"portuguese");
   char nome[50], aux[50]="variavel aux";
   cout << "Informe o nome: ";
   gets(nome);
   fflush(stdin);

   cout << nome << endl;

   cout << "Antes: " << aux << endl;

   strcpy(aux, nome);

   cout << "Após: " << aux << endl;

}
