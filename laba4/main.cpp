#include <cstring>
#include <iostream>

using namespace std;

int _strrchr(const char *string, char c){
    int num = -1;
    for (int i = 0; string[i] != '\0'; ++i)
        if (string[i] == c){
            num = i;
        }
    return num;
}

int main()
{
    cout << "task A" << endl << "cin your word and cin your letter" << endl;
    char string1[256];
    cin >> string1;
    char c;
    cin >> c;
    if (_strrchr(string1, c) != -1)
        cout << "last position of " << c << " in " << string1 << " is " << _strrchr(string1, c);
    else
        cout << c << " is not in " << string1;
}
