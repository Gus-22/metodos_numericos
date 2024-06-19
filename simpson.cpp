#include <iostream>
#include <cmath>
#include <iomanip>
//método do trapézio
using namespace std;

double f(double x);

int main ()
{   int i, j, nmax=20;
    int n;   // quantidade de subintervalos
    double A[nmax], ER[nmax];
    double a, b, h, eps = 0.000001, auxi;

    a = 0.0;
    b = 1.0;
    n = 2;
    h = 0.5*(b-a);
    A[0] = h*(f(a) + f(b) +4.0*f(0.5*(a+b)))/3.0;

    ER[0] = 1.0;
    i = 0;
    while ( ER[i] > eps && i < nmax)
    {   i++;
        n = 2*n;
        double x[n+1];
        h = 0.5*h;
        x[0] = a;
        for ( j=1; j<=n; j++)
        {
            x[j] = x[j-1] + h;
        }

        auxi = f(x[2]);
        j = 4;
        while(j < n)
        {
            auxi = auxi + f(x[j]);
            j = j + 2;
        }

        A[i] = 2.0*auxi;


        auxi = f(x[1]);
        j = 3;
        while(j < n)
        {
            auxi = auxi + f(x[j]);
            j = j + 2;
        }

        A[i] = A[i] + 4.0*auxi +f(x[0])+ f(x[n]);
        A[i] = h*A[i]/3.0;
        ER[i] = abs(A[i]-A[i-1])/abs(A[i]);
    }

    cout << "k\t\tA[k]\t\tER[k]" << endl;
    for ( j=0; j<=i; j++)
    {   cout << setprecision(10) << j << "\t\t" << A[j] << "\t\t" << ER[j] << endl;

    }

}

double f(double x)
{
    double aux, pi = 3.14159265359;
    aux = pi*x;
    return 2*exp(-x*x) + 4.0 +sin(2.0*aux) + sin(3.0*aux) + cos(4.0*aux);
}
