#include <iostream>
#include <cmath>
#include <iomanip>
//método do trapézio
using namespace std;

double f(double x);

int main ()
{   int i, j, nmax=50;
    int n;   // quantidade de subintervalos
    double A[nmax], ER[nmax];
    double a, b, h, eps = 0.000001;

    a = -0.981;
    b = 2.91;
    n = 1;
    h = (b-a) / double(n);
    A[0] = 0.5*h*(f(a)+f(b));

    ER[0] = 1.0;
    i = 0;
    while ( ER[i] > eps && i < nmax)
    {   i++;
        n = 2*n;
        double x[n+1];
        h = 0.5*h;
        x[0] = a;
        for ( j=1; j<=n; j++)
        {   x[j] = x[j-1] + h;

        }
        A[i] = f(x[0]) + f(x[n]);
        for ( j=1; j<n; j++)
        {   A[i] = A[i] + 2.0*f(x[j]);

        }
        A[i] = 0.5*h*A[i];
        ER[i] = abs(A[i]-A[i-1])/abs(A[i]);
    }

    cout << "k\t\tA[k]\t\tER[k]" << endl;
    for ( j=0; j<=i; j++)
    {   cout << setprecision(10) << j << "\t\t" << A[j] << "\t\t" << ER[j] << endl;

    }

}

double f(double x)
{ return sin(3.003*x*x) + sin(6.974*x)*sin(6.974*x);
}