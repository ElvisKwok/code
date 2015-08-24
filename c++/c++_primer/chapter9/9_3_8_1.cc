#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main()
{
    char* sa[] = {"Alice", "bob", "Cindy", "David"};
    list<char*> slst(sa, sa+4);
    vector<string> svec;
    
    svec.assign(slst.begin(), slst.end());

    cout << "slst: ";
    for (list<char*>::iterator liter = slst.begin(); liter != slst.end(); ++liter)
        cout << *liter << " ";
    cout << "\nsvec: ";

    for (vector<string>::iterator viter = svec.begin(); viter != svec.end(); ++viter)
        cout << *viter << " ";
    cout << endl;

    return 0;
}
