#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int fibonacci(int termo);

main()
{
   setlocale(LC_ALL,"portuguese");
   cout << "Os primeiros 20 termos de fibonacci são: " << endl;
   for (int i = 0; i < 20; i++)
   {
      cout << fibonacci(i) << ", ";
   }
}

int fibonacci(int termo)
{
    if (termo == 0 || termo == 1)
    {
        return termo;
    }

    return fibonacci(termo-1) + fibonacci(termo-2);
}



