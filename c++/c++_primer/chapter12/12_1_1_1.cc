#include <iostream>

using namespace std;

class Person {
public:
    Person(const std::string &nm, const std::string &addr): name(nm), address(addr) { }
    std::string getName() const
    {
        return name;
    }
    std::string getAddress() const
    {
        return address;
    }
private:
    std::string name;
    std::string address;
};

int main()
{
    Person me("Elvis Kwok", "SYSU");
    cout << me.getName() << '\t' << me.getAddress() << endl;
     
    return 0;
}
