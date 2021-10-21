#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CloseFiles(ifstream& in, ofstream& out_round, ofstream& out_square)
{
    out_round.close();
    out_square.close();
    in.close();
    if (in.is_open() || out_square.is_open() || out_round.is_open())
    {
        cout << "Something is wrong";
    }
    cout << "Program is alright" << endl;
}

void Round(ifstream& in, ofstream& out_round) {
    string s;
    while (getline(in, s)) {
        int first = s.find('(', 0);
        int last = s.rfind(')', s.size());
        if (first + last > 1 && first + 1 < last) {
            out_round << s << endl;
        }
        else {
            out_round << "I'm sorry, but there's nothing to see";
        }
    }
}

void Square(ifstream& in, ofstream& out_square) {
    string s;
    while (getline(in, s)) {
        int first = s.find('[', 0);
        int last = s.rfind(']', s.size());
        if (first + last > 1 && first + 1 < last) {
            out_square << s;
        }
        else {
            out_square << "I'm sorry, but there's nothing to see";
        }
    }
}

void ReOpen(ifstream &in, const string &name) {
    in.close();
    in.open(name);
}

int main()
{
    ifstream in("input.txt");
    ofstream out_round("output_round.txt");
    ofstream out_square("output_square.txt");

    Round(in, out_round);
    ReOpen(in, "input.txt");
    Square(in, out_square);

    CloseFiles(in, out_round, out_square);
    return 0;
}
