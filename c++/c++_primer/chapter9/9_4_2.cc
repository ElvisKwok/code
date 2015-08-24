#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec;
    cout << "empty state: " << endl;
    cout << "size(): " << ivec.size() << endl;
    cout << "capacity(): " << ivec.capacity() << endl;
    
    cout << "after assigning 24 values: " << endl;
    for (vector<int>::size_type ix = 0; ix != 24; ++ix) 
        ivec.push_back(ix);
    cout << "size(): " << ivec.size() << endl;
    cout << "capacity(): " << ivec.capacity() << endl;

    cout << "reserving 50 space: " << endl;
    ivec.reserve(50);
    cout << "size(): " << ivec.size() << endl;
    cout << "capacity(): " << ivec.capacity() << endl;
    
    cout << "use up all reserved space: " << endl;
    while (ivec.size() != ivec.capacity())
        ivec.push_back(0);
    cout << "size(): " << ivec.size() << endl;
    cout << "capacity(): " << ivec.capacity() << endl;

    cout << "push one more..." << endl;
    ivec.push_back(51);
    cout << "size(): " << ivec.size() << endl;
    cout << "capacity(): " << ivec.capacity() << endl;

    vector<double> dvec;
    for (vector<double>::size_type ix = 0; ix != 11; ++ix) {
        dvec.push_back(ix);
        cout << "dvec\tsize(): " << dvec.size() << "\tcapacity(): " << dvec.capacity() << endl;
    }

    return 0;
}
