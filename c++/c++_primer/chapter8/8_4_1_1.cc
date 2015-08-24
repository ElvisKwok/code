#include <iostream>
#include <fstream>
#include <string>
#include "get.h"

using namespace std;

int main()
{
    string fileName;
    cout << "enter file namme: " << endl;
    cin >> fileName;
    // 创建ifstream对象并绑定到名为fileName的文件
    ifstream inFile(fileName.c_str());
    if (!inFile) {
        cerr << "error: can not open input file: "
             << fileName << endl;
        return -1;
    }
    get(inFile);

    return 0;
}
