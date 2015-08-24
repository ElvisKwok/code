#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void process(string);

int main()
{
    vector<string> files;
    string fileName, s;

    cout << "Enter filenams: (Ctrl-Z to end)" << endl;
    while (cin >> fileName)
        files.push_back(fileName);
    ifstream input;
    vector<string>::const_iterator it = files.begin();

    while (it != files.end()) {
        input.open(it->c_str());
        if (!input) {
            cerr << "error: can not open files: "
                 << *it << endl;
            input.clear();
            ++it;
        }
        else {
            while (input >> s)
                process(s);
            cout << endl;
            input.close();
            input.clear();
            ++it;
        }
    }
    
    return 0;
}

void process(string s) 
{
    cout << s << ' ';
}
