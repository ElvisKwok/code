#include "Sales_item.h"
#include <iostream>
using namespace std;

int main()
{
    Sales_item item;
    
    cout << "enter some transactions:(Ctrl+D to end) " << endl;
    while(item.input(cin)) {
        item.output(cout);
        cout << endl;
    }
    
    return 0;
}
