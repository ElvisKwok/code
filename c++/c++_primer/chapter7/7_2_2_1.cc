#include <iostream>

using namespace std;

void ptr_swap(int *&v1, int *&v2)
{
    int *tmp = v1;
    v1 = v2;
    v2 = tmp;
}

int main()
{
    int i = 1, j = 2;
    int *pi = &i, *pj = &j;
    cout << "before: " << *pi << '\t' << *pj << endl;
    ptr_swap(pi, pj);
    cout << "after: " << *pi << '\t' << *pj << endl;
    
    return 0;
}
