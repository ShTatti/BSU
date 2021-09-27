#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int k, kol, ch = 1;
    double x0, res1, res2 = 0, x;

    cout << " k = ";
    cin >> k;
    if (k <= 1)
    {
        cout << "wrong";
        return 1;
    }
    cout << " x = ";
    cin >> x0;
    x = x0;

    cout << "int precision = ";
    cin >> kol;

    res1 = (exp(x) - exp(-x))/2;

     while (fabs(x) > 1 / pow(10, k))
     {
        res2 += x;
        x *= x0;
        x *= x0;
        ch++;
        x/= ch;
        ch++;
        x/=ch;
    }

    res2 += x;
    cout << fixed << setprecision(kol) << " 1 formula: " << res1 << endl << " 2 formula: " << res2 << endl;
    return 0;
}
