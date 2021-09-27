#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int ARRAY_SIZE = 100;

int main()
{
    ///0
    cout << "Tatti's. 14 variant." << endl;
    int arr_size;
    cout << endl << "int array size < 100 && > 1: " << endl;
    cin >> arr_size;
    if (arr_size > ARRAY_SIZE && arr_size < 1)
    {
        cout << "error. one more time. right array size: " << endl;
        cin >> arr_size;
    }

    cout << endl << "interval of array for array B: " << endl;
    int first, last;
    cin >> first >> last;

    double a[arr_size], b[arr_size];
    cout << endl << "all elements of array A: " << endl;
    for (int i = 0; i < arr_size; i++)
    {
        cin >> a[i];
        b[i] = first + rand() % (last - first) + (float)1/((rand() % 10) + 0.1);
        if (i == 0)
        {
            cout << endl << "all elements of array B: " << endl;
        }
        cout << b[i] << "; ";
    }
    cout << endl;

    ///1 a
    double max_a = a[0], max_b = b[0];
    for (int i = 0; i < arr_size; i++)
    {
        if (a[i] > max_a)
        {
            max_a = a[i];
        }
    }
    cout << endl << "max element of array A: " << max_a;
    /// 1 b
    for (int i = 0; i < arr_size; i++)
    {
        if (b[i] > max_b)
        {
            max_b = b[i];
        }
    }
    cout << endl << "max element of array B: " << max_b;

    /// 2 a
    double last_pol_a = a[0], last_pol_b = b[0];
    for (int i = 0; i < arr_size; i++)
    {
        if (a[i] > 0)
        {
            last_pol_a = i;
        }
    }
    double sum_a = 0, sum_b = 0;
    int i = 0;

    while (i < last_pol_a)
    {
        sum_a += a[i];
        i++;
    }
    cout << endl << "sum before max element of array A: " << endl << sum_a;

    /// 2 b
    for (int i = 0; i < arr_size; i++)
    {
        if (b[i] > 0)
        {
            last_pol_b = i;
        }
    }
    i = 0;
    while (i < last_pol_b)
    {
        sum_b += b[i];
        i++;
    }
    cout << endl << "sum before max element of array B: " << endl << sum_b;

    ///3 a
    cout << endl << "interval of array for deleting elements: " << endl;
    double left_interval, right_interval;
    cin >> left_interval >> right_interval;

    int new_size = arr_size;
    i = 0;
    while (i < new_size)
    {
        if ( (fabs(a[i]) >= left_interval) && (fabs(a[i]) <= right_interval))
        {
            for (int j = i; j < arr_size - 1; j++)
            {
                a[j] = a[j + 1];
            }
            new_size --;
            i--;
        }
        i++;
    }

    for (int i = new_size; i < arr_size; i++)
    {
        a[i] = 0;
    }
    cout << endl << "array A without elements from interval: " << endl;
    for (int i = 0; i < arr_size; i++)
    {
        cout << a[i] << "; ";
    }

    /// 3 b
    new_size = arr_size, i = 0;
    while (i < new_size)
    {
        if ( (fabs(b[i]) >= left_interval) && (fabs(b[i]) <= right_interval))
        {
            for (int j = i; j < arr_size - 1; j++)
            {
                b[j] = b[j + 1];
            }
            new_size --;
            i--;
        }
        i++;
    }
    for (int i = new_size; i < arr_size; i++)
    {
        b[i] = 0;
    }
    cout << endl << "array B without elements from interval: " << endl;
    for (int i = 0; i < arr_size; i++)
    {
        cout << b[i] << "; ";
    }
    return 0;
}
