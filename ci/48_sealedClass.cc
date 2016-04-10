#include <iostream>
using namespace std;

// file description:
// design a class: SealedClass, sealedClass can not be inheritated.

// =====================solution 1=====================
// private constructor & destructor
// 但是我们要生成该类型的实例时，只能透过下面两个public成员函数
class SealedClass1 {
public:
    static SealedClass1* getInstance() {
        return new SealedClass1();
    }
    static void deleteInstance(SealedClass1* pInstance) {
        delete pInstance;
    }
private:
    SealedClass1() {}
    ~SealedClass1() {}
};

// 如果试图从SealedClass1继承出新的类型
// 将会导致编译错误
/*
class Try1: public SealedClass1 {
public:
    Try1() {}
    ~Try1() {}
};
*/

// =====================solution 2=====================
// 虚拟继承，只能由最底层的派生类初始化虚基类
// 将我们设计的类设成父类的友元（可访问private, protected），友元关系不能继承给下一代
// 这样我们设计的类可以不通过public成员函数调用构造、析构函数

template <typename T>
class HelpSealed {
    friend T;
private:
    HelpSealed() {}
    ~HelpSealed() {}
};

class SealedClass2: virtual public HelpSealed<SealedClass2>{
public:
    SealedClass2() {}
    ~SealedClass2() {}
};

// 如果试图从SealedClass1继承出新的类型
// 将会导致编译错误
class Try2: public SealedClass2 {
public:
    Try2() {}
    ~Try2() {}
};

int main() {

    return 0;
}
