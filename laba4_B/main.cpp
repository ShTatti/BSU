#include <iostream>

using namespace std;

bool check_letters(char *now, const char *end){
    for (char *i = now; i <= end; i++){
        for (char *j = now; j < i; j++){
            if (*i == *j)
                return false;
        }
    }
    return true;
}

int main()
{
    cout << "task B" << endl;
    cout << "cin your line and enter in the end:" << endl;
    int counter = 0;
    char *string = new char[300];
    char text;
    do{
        cin.get(text);
        string[counter++] = text;
    }
    while (text != '\n');

    string[counter - 1] = '\0';
    char *t_end;
    char *t_begin = string;
    char *end = string;
    char *begin = string + 1;
    for (int i = 0; i < counter; i++){
        if (string[i] == '\0' || string[i] == ' ' ){
            t_end = string + i - 1;
            if ((t_end >= t_begin) && (check_letters(t_begin, t_end))){
                end = t_end;
                begin = t_begin;
                break;
            }
            t_begin = string + i + 1;
        }
    }
    if (end - begin >= 0)
        for (; begin <= end; ++begin)
            cout << *begin;
    else
        cout << "there is no such word";
    delete[] string;

    return 0;
}
