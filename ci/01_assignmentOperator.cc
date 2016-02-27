#include <iostream>
#include <string>
using namespace std;

// implement the assign operator in the class CMyString

class CMyString {
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& other);
    ~CMyString();

    CMyString& operator=(const CMyString& rhs);
    
    void print();
private:
    char* m_pData;
};

CMyString::CMyString(char* pData) {
    if (pData == NULL) {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else {
        int length = strlen(pData);
        m_pData = new char[length+1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString& other) {
    int length = strlen(other.m_pData);
    m_pData = new char[length+1];
    strcpy(m_pData, other.m_pData);
}

CMyString::~CMyString() {
    delete []m_pData;
}

CMyString& CMyString::operator=(const CMyString& rhs) {
    if (this == &rhs)
        return *this;
    delete []m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(rhs.m_pData)+1];
    strcpy(m_pData, rhs.m_pData);

    return *this;
}

void CMyString::print() {
    cout << m_pData << endl;
}

// =====================Test Code=====================
void test1() {
    cout << "test1 begins: " << endl;
    char text[] = "hello world";
    CMyString str1(text);
    CMyString str2;
    str2 = str1;
    cout << "the expected result is: " << text << endl;
    cout << "the actual result is: ";
    str2.print();
}

// 自我赋值
void test2() {
    cout << "test2 begins: " << endl;
    char text[] = "hello world";
    CMyString str1(text);
    str1 = str1;
    cout << "the expected result is: " << text << endl;
    cout << "the actual result is: ";
    str1.print();
}

// 连续赋值
void test3() {
    cout << "test3 begins: " << endl;
    char text[] = "hello world";
    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;
    cout << "the expected result is: " << text << endl;
    cout << "the actual result is: ";
    str2.print();
    cout << "the expected result is: " << text << endl;
    cout << "the actual result is: ";
    str3.print();
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}
