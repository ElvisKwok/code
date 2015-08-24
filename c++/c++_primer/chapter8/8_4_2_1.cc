#include "get.h"
#include "open_file.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream& open_file(ifstream &in, const string &file);

int main()
{
    string fileName;
    cout << "Enter filename: " << endl;
    cin >> fileName;

    ifstream inFile;
    if (!open_file(inFile, fileName.c_str())) {
        cout << "error: can not open file: "
             << fileName << endl;
        return -1;
    }
    get(inFile);
    inFile.close();
    return 0;
}
