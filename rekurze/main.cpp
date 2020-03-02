#include <iostream>

using namespace std;

int pocet = 0;
void funkce()
{
    cout << ++pocet << endl;
    if (pocet<100) funkce();
}

double mocnina(double x, double n)
{
    if(n==0) return 1;
    else return x*mocnina(x,n-1);
}

double faktorial(int x)
{
    if(x==0) return 1;
    else return x*faktorial(x-1);
}

double fib(int n)
{
    if(n<2) return n;
    int novy=0, predchozi=1, predpredchozi=0;
    for(int i=2;i<=n;i++)
    {
        novy = predchozi + predpredchozi;
        predpredchozi = predchozi;
        predchozi = novy;
    }
    return novy;
}

long fibRek(int n)
{
    if(n<2) return n;
    else return fibRek(n-1)+fibRek(n-2);
}

int main()
{
    cout << mocnina(2,3) << endl;
    cout << faktorial(8) << endl;
    cout << fib(8) << endl;
    cout << fibRek(8) << endl;
    return 0;
}