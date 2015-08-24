#include <iostream>

using namespace std;

istream& get(istream& in)
{
    int ival;
    
    while (in >> ival, !in.eof()) {
        if (in.bad())
            throw runtime_error("IO stream corrupted");
        if (in.fail()) {
            cerr << "bad data, try again";
            in.clear();
            in.ignore(200, ' ');
            continue;
        }
        cout << ival << " ";
    }
    in.clear();

    return in;
}
