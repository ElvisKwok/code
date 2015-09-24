#include <iostream>
#include <vector>

using namespace std;

struct Exmpl {
    // default constructor
    Exmpl() { std::cout << "Exmpl()" << std::endl; }
    // copy constructor
    Exmpl(const Exmpl &)
    { std::cout << "Exmpl(const Exmpl &)" << std::endl; }
    // assign operator
    Exmpl & operator= (const Exmpl &rhe)
    {
        std::cout << "operator= (const Exmpl&)" << std::endl;
        return *this;
    }
    // deconstructor
    ~Exmpl() { std::cout << "~Exmpl()" << std::endl; }
};

void func1(Exmpl obj) { }

void func2(Exmpl &obj) { }

Exmpl func3()
{
    Exmpl obj;
    return obj;
}

int main()
{
    Exmpl eobj;
    cout << "----------------" << endl;
    
    func1(eobj);
    cout << "----------------" << endl;

    func2(eobj);
    cout << "----------------" << endl;

    eobj = func3();
    cout << "----------------" << endl;

    Exmpl *p = new Exmpl;
    cout << "----------------" << endl;

    vector<Exmpl> evec(3);
    cout << "----------------" << endl;

    delete p; 
    cout << "----------------" << endl;

    return 0;
}
