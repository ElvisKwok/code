#include <iostream>
using namespace std;

// replace ' ' as "%20"

// length is the size of str[]
void replaceBlank(char str[], int length) {
    if (str==NULL && length<=0)         // note!
        return;
    int originalLength = 0;
    int numberOfBlank = 0;
    int i=0;
    while (str[i] != '\0') {
        if (str[i] == ' ')
            ++numberOfBlank;
        ++i;
    }
    originalLength = i;
    int newLength = originalLength + numberOfBlank*2;
    if (newLength > length)         // note!
        return;
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {         // note!
        if (str[indexOfOriginal] == ' ') {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        }
        else
            str[indexOfNew--] = str[indexOfOriginal];
        --indexOfOriginal;
    }
}

void test(char* testName, char str[], int length, char expected[]) {
    if (testName != NULL)
        cout << testName << " begins: ";
    replaceBlank(str, length);
    if (expected == NULL && str == NULL)
        cout << "passed." << endl;
    else if (expected == NULL && str != NULL)
        cout << "failed." << endl;
    else if (strcmp(expected, str)==0)
        cout << "passed." << endl;
    else
        cout << "failed." << endl;
}

// a blank at the mid
void test1() {
    const int length = 100;
    char str[length] = "hello world";
    test("test1", str, length, "hello%20world");
}

// a blank at the begin
void test2() {
    const int length = 100;
    char str[length] = " helloworld";
    test("test2", str, length, "%20helloworld");
}

// a blank at the end
void test3() {
    const int length = 100;
    char str[length] = "helloworld ";
    test("test4", str, length, "helloworld%20");
}

// continuous blanks
void test4() {
    const int length = 100;
    char str[length] = "hello  world";
    test("test3", str, length, "hello%20%20world");
}

// no blank
void test5() {
    const int length = 100;
    char str[length] = "helloworld";
    test("test8", str, length, "helloworld");
}

// str == NULL
void test6() {
    test("test5", NULL, 0, NULL);
}

// str is empty
void test7() {
    const int length = 100;
    char str[length] = "";
    test("test6", str, length, "");
}

// str is a blank
void test8() {
    const int length = 100;
    char str[length] = " ";
    test("test7", str, length, "%20");
}

// str is all continous blanks.
void test9() {
    const int length = 100;
    char str[length] = "   ";
    test("test9", str, length, "%20%20%20");
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    return 0;
}
