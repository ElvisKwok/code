#include <iostream>

using namespace std;

class HasPtr {
public:
    HasPtr(int *p, int i): ptr(p), val(i) { }
    
    int *get_ptr() const { return ptr; }
    int get_val() const { return val; }

    void set_ptr(int *p) { ptr = p; }
    void set_int(int i) { val = i; }

    int get_ptr_val() const { return *ptr; }
    void set_ptr_val(int i) const { *ptr = i; } 

private:
    int *ptr;
    int val;
};

int main()
{
    int obj = 0;
    HasPtr ptr1(&obj, 42);
    HasPtr ptr2(ptr1);

    cout << ptr1.get_val() << endl;
    cout << ptr1.get_ptr_val() << endl;
    cout << ptr2.get_val() << endl;
    cout << ptr2.get_ptr_val() << endl;

    ptr1.set_int(100);
    cout << ptr1.get_val() << endl;
    cout << ptr1.get_ptr_val() << endl;
    cout << ptr2.get_val() << endl;
    cout << ptr2.get_ptr_val() << endl;

    ptr1.set_ptr_val(1234);
    cout << ptr1.get_val() << endl;
    cout << ptr1.get_ptr_val() << endl;
    cout << ptr2.get_val() << endl;
    cout << ptr2.get_ptr_val() << endl;
     
    return 0;
}
