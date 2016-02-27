#include <iostream>
using namespace std;

void permutation(char* pStr, char* pBegin);

void permutation(char* pStr) {
    if (pStr == NULL)
        return;
    permutation(pStr, pStr);
}

void permutation(char* pStr, char* pBegin) {
    if (*pBegin == '\0') {
        cout << pStr << endl;
        return;
    }
    for (char* pCh = pBegin; *pCh != '\0'; ++pCh) {
        char tmp = *pCh;
        *pCh = *pBegin;
        *pBegin = tmp;

        permutation(pStr, pBegin+1);

        tmp = *pCh;
        *pCh = *pBegin;
        *pBegin = tmp;
    }
}

// =====================Test Code=====================
void test(char* pStr) {
    if (pStr == NULL)
        cout << "Test for NULL begins: " << endl;
    else
        cout << "Test for " << pStr << " begins: " << endl;
    permutation(pStr);
    cout << endl;
}

int main() {
    test(NULL);

    char str1[] = "";
    test(str1);

    char str2[] = "a";
    test(str2);

    char str3[] = "ab";
    test(str3);

    char str4[] = "abc";
    test(str4);

    return 0;
}
