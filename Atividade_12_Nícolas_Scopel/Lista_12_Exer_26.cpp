/*26 - Implemente uma função em C++ que receba dois ponteiros para strings e concatene o conteúdo das duas strings em uma terceira string.
A terceira string deve ser alocada dinamicamente, apresente o conteúdo das três strings.*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

void agrupastrings(char *a, char *b, int *tam);

main()
{
	setlocale (LC_ALL, "Portuguese");

	char *a = new char [50];
	char *b = new char [50];
	int *tam = new int(0);
	int *i = new int(0);



	cout << "Digite o texto A: ";
	cin.getline(a,50);

	cout << "Digite o texto B: ";
	cin.getline(b,50);

	*tam += strlen(a);
	*tam += strlen(b);

	agrupastrings(a,b,tam);


}

void agrupastrings(char *a, char *b, int *tam)
{
    char *c = new char[*tam];
    int *i = new int(0);
    char *e = new char (' ');

    strcat(c,a);
    strcat(c,e);
	strcat(c,b);


	*tam = strlen(c);
	cout << "Strings Concatenadas com um espaço entre elas: ";

	while(*i < *tam)
    {
        cout << *c;
        c++;
        (*i)++;
    }

    c -= *i;
    *i = 0;


}
