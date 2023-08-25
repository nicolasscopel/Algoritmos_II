#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

main()
{
   setlocale(LC_ALL,"portuguese");
   string nome, aux;
   cout << "Informe o nome: ";
   getline(cin, nome);
   fflush(stdin);

   cout << nome << endl;

   aux = "Nome digitado: " + nome;

   //aux = nome;

   for(int i = 0; i < nome.size(); i++)
   {
       cout << nome[i] << ", ";
   }

   cout << "\nVariável auxiliar: " <<  aux << endl;

   if(nome == "Pedro")
      cout << "Nome correto";
   else
      cout << "Nome inválido";


}
