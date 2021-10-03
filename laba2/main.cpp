#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int ARRAY_SIZE = 100;

int main()
{
    cout << "Tatti's. 14 variant." << endl;
    int arr_size;
    cout << endl << "int array size < 100 && > 1: " << endl;
    cin >> arr_size;
    if (arr_size > ARRAY_SIZE && arr_size < 1)
    {
        cout << "error. one more time. right array size: " << endl;
        cin >> arr_size;
    }
    cout << "choose 1 variant" << endl << "enter 1 if you want to enter array" << endl << "enter 2 if you want random array" <<endl;
    int variant;
    cin >> variant;
    double* b = new double[arr_size];
    if (variant == 1)
    {
        cout << endl << "all elements of array B: " << endl;
        for (int i = 0; i < arr_size; i++)
        {
            cin >> b[i];
        }
    }
    else if (variant == 2)
    {
        cout << endl << "interval of array for array B: ";
        int first, last;
        cin >> first >> last;
        for (int i = 0; i < arr_size; i++)
        {
            b[i] = first + rand() % (last - first) + (float)1/((rand() % 10) + 0.1);
            if (i == 0)
            {
                cout << endl << "all elements of array B: " << endl;
            }
            cout << b[i] << "; ";
        }


    }
    else
    {
        cout << "you have chosen not 1 or 2";
        return 0;
    }

    double max_b = b[0];
    for (int i = 0; i < arr_size; i++)
    {
        if (b[i] > max_b)
        {
            max_b = b[i];
        }
    }
    cout << endl << "max element of array B: " << max_b;

    double last_pol_b = b[0];
    for (int i = 0; i < arr_size; i++)
    {
        if (b[i] > 0)
        {
            last_pol_b = i;
        }
    }
    double sum_b = 0;
    int i = 0;
    while (i < last_pol_b)
    {
        sum_b += b[i];
        i++;
    }
    cout << endl << "sum before max element of array B: " << sum_b;

    cout << endl << "interval of array for deleting elements: ";
    double left_interval, right_interval;
    cin >> left_interval >> right_interval;
    int new_size = arr_size;
    i = 0;
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
    delete[]b;

    return 0;
}
