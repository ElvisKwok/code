#include "get.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string line;
    cout << "Enter a line of text: " << endl;
    getline(cin, line);
    line += " ";    // 避免最后一个有效数据无法输出, 行末加空格(与文件结束符隔开)
    istringstream isstr(line);  // 用line创建istringstream对象
    get(isstr);

    return 0;
}
