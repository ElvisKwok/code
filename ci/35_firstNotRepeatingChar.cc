#include <iostream>
using namespace std;

char firstNotRepeatingChar(char* pStr) {
    if (pStr==NULL || *pStr == '\0')
        return '\0';
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for (int i=0; i<tableSize; ++i)
        hashTable[i] = 0;
    char* pHashKey = pStr;
    while (*pHashKey != '\0')
        ++hashTable[(unsigned char)(*pHashKey++)];
    pHashKey = pStr;
    while (*pHashKey != '\0') {
        if (hashTable[*pHashKey] == 1)
            return *pHashKey;
        ++pHashKey;
    }
    return '\0';
}

// =====================Test Code=====================
void test(char* pStr, char expected) {
    if (firstNotRepeatingChar(pStr) == expected)
        cout << "test passed." << endl;
    else
        cout << "test failed." << endl;
}

int main() {
    test("google", 'l');
    test("abcdefg", 'a');
    test("aabccdbd", '\0');

    test(NULL, '\0');

    return 0;
}
