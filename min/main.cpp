#include <iostream>
#include <cmath>
#include <iomanip> // Para std::fixed e std::setprecision

using namespace std;

int main()
{
    const int N = 10;
    double x[N], y[N], x2[N];
    double lny[N], lnyx[N];
    double a0, a1, a, b;
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

    for (int i = 0; i < N; i++)
    {
        lny[i] = log(y[i]);
        x2[i] = x[i] * x[i];
        lnyx[i] = x[i] * lny[i];
    }

    for (int i = 0; i < N; i++)
    {
        sx = sx + x[i];
        sx2 = sx2 + x2[i];
        sy = sy + lny[i];
        syx = syx + lnyx[i];
    }

    a0 = (sx2 * sy - syx * sx) / (N * sx2 - sx * sx);
    a1 = (N * syx - sx * sy) / (N * sx2 - sx * sx);
    a = exp(a0);
    b = exp(a1);


    cout << fixed << setprecision(6);

    cout << "x\t\ty\t\t\tlny\t\t\tx2\t\t\tlnyx" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << x[i] << "\t" << y[i] << "\t\t" << lny[i] << "\t\t" << x2[i] << "\t\t" << lnyx[i] << endl;
    }

    cout << "-----------------------------------------------------------------------\n";
    cout << sx << "\t\t-\t\t" << sy << "\t\t" << sx2 << "\t\t" << syx << endl;

    cout << "-----------------------------------------------------------------------\n";
    cout << "a0 = " << a0 << "\t\ta1 = " << a1 << endl;
    cout << "a = " << a << "\t\tb = " << b << endl;

    return 0;
}
