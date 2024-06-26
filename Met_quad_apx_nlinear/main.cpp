#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
   int N = 10, i = 0;
   double x[N], y[N], a0, a1, a , b ;
   double lnx[N], lny[N], ln2x[N], lnylnx[N];
   double sx = 0.0, sx2 = 0.0, sy = 0.0, syx = 0.0;

   x[0] = 1.0; y[0] = 0.829;
   x[1] = 2.0; y[1] = 3.206;
   x[2] = 3.0; y[2] = 10.13;
   x[3] = 4.0; y[3] = 23.7;
   x[4] = 5.0; y[4] = 42.2;
   x[5] = 6.0; y[5] = 69.16;
   x[6] = 7.0; y[6] = 106.5;
   x[7] = 8.0; y[7] = 153.2;
   x[8] = 9.0; y[8] = 209.2;
   x[9] = 10.0; y[9] = 281.3;

   for(i=0 ; i<N; i++ )
    {
    lnx[i] = log(x[i]);
    lny[i] = log(x[i]);
    ln2x[i] = lnx[i] * lnx[i];
    lnylnx[i] = lny[i] * lnx[i];
    }

    for (i=0 ; i<N ; i++)
    {
    sx = sx + lnx[i];
    sx2 = sx2 + ln2x[i];
    sy = sy + lny[i];
    syx = syx + lnylnx[i];
    }




    a0 = (sx2*sy-syx*sx)/(N*sx2-sx*sx);
    a1 = (N*syx-sx*sy)/(N*sx2-sx*sx);

    a = exp(a0);
    b = a1;


    cout << "x\t\ty\tlnx\tlny\tln2x\t\t\tlnylnx" << endl;
    for(i=0;i<N; i++)
    {
    cout << lnx[i] << "\t\t" << lny[i] << "\t\t" << ln2x[i] << lnylnx[i] << endl;
    }

    cout << "---------------------------------------------------------------------------------------------------------------\n";
    cout << sx << "\t\t" << sy <<"\t\t" << syx << "\t\t" << syx2 << endl;

     cout << "------------------------------------------------------------------------------\n";
    cout << "a0 = " << a0 <<  "\t\ta1 = " << a1 << "a = " << a <<  "\t\tb = " << b << endl;

}
