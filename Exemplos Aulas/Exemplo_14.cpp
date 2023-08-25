#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

void fibonacci(int cont, int t1, int t2);

main()
{
   setlocale(LC_ALL,"portuguese");
   cout << "Os primeiros 20 termos de fibonacci são: " << endl;
   fibonacci(2,0,1);
}


void fibonacci(int cont, int t1, int t2)
{
    if(cont > 20)
        return;
    else
    {
        if(cont == 2)
        {
            cout << t1 << ", " << t2 << ", ";
            cont++;
            fibonacci(cont, t1, t2);
        }
        else
        {
            cout << t1 + t2 << ", ";
            cont++;
            fibonacci(cont, t2, t1 + t2);
        }
    }
}

