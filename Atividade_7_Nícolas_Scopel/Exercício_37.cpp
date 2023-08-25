/*37 – Crie um programa para manipular uma estrutura chamada "hora" com os campos "horas",
"minutos" e “segundos”. Em seguida, escreva uma função que receba como parâmetro dois
valores inteiros expresso em segundos a função calcular e apresentar a diferença entre esses
dois valores em Horas:Minutos:Segundo. Após apresentar o resultado o programa deve solicitar
se o usuário deseja verificar outros valores (S) ou encerrar o programa (N).*/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

struct hora
{
    int horas;
    int minutos;
    int segundos;

};

void calcula(hora valor1, hora valor2);

main()
{
	setlocale (LC_ALL, "Portuguese");

	char res;
	hora hora1, hora2;


	do
    {
        system("cls");

        cout << "Esse programa calcula a diferença de tempo entre dois valores em segundos!" << endl;

        cout << "\nInforme um valor inteiro que deseja em segundos: ";
        cin >> hora1.segundos;

        cout << "Informe outro valor inteiro que deseja em segundos: ";
        cin >> hora2.segundos;

        calcula(hora1, hora2);



        cout << "\n\nDeseja informar novos valores? S - SIM / N - NAO: ";
        cin >> res;


    }while(res != 'N');

}

void calcula(hora hora1, hora hora2)
{

    int diferencaSegundos = hora1.segundos - hora2.segundos;

    int horas = diferencaSegundos / 3600;
    int minutos = (diferencaSegundos % 3600) / 60;
    int segundos = diferencaSegundos % 60;

    cout << "Diferença: " << horas << ":" << minutos << ":" << segundos << endl;



}

