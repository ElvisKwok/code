#include <iostream>
#include <set>

using namespace std;

//void recur(int N, set<int>* Set, int K, int k, int& count, int num)
//{
//    if (k == K - 1)
//    {
//        for (set<int>::iterator it = Set[k].begin(); it != Set[k].end(); it++)
//        {
//            if (num * 10 + *it <= N)
//                count++;
//            else
//                break;
//        }
//    }
//    else
//    {
//        for (set<int>::iterator it = Set[k].begin(); it != Set[k].end(); it++)
//            recur(N, Set, K, k + 1, count, num * 10 + *it);
//    }
//}

void recur(int N, set<int>* Set, int K, int k, int& count, int num)
{
    if (k == K)
    {
		if (num <= N)
			count++;
		return;
    }
    
	for (set<int>::iterator it = Set[k].begin(); it != Set[k].end(); it++)
            recur(N, Set, K, k + 1, count, num * 10 + *it);
}

int main()
{
    set<int> m[8];
    m[1] = { 1,4 };
    m[2] = { 1,2,3,7 };
    m[3] = { 5,6 };
    m[4] = { 0,1,7 };
    m[5] = { 1,3,4,5,7,9 };
    m[6] = { 2 };
    m[7] = { 1,4,7 };
    bool possible[10];
    
    int S;
    scanf("%d", &S);
    char buffer[100];
    
    for (int s = 0; s < S; s++)
    {
        int K, N;
        scanf("%d%d", &K, &N);
        set<int>* Set = new set<int>[K];
        
        gets(buffer);	// read '\n' (left by scanf)
        for (int k = 0; k < K; k++)	// k-th light
        {
            for (int p = 0; p < 10; p++)
                possible[p] = true;
            gets(buffer);// read a line to buffer
            for (char* cur = buffer; *cur != '\0'; cur++)
            {
                if (isdigit(*cur))
                {
                    int digit = *cur - '0';
                    for (set<int>::iterator it = m[digit].begin(); it != m[digit].end(); it++)
                    {
                        possible[*it] = false;
                    }
                }
            }			
            for (int p = 0; p < 10; p++)
            {
                if (possible[p] == true)
                {
                    Set[k].insert(p);				
                }
            }
            
        }
        int count = 0;
        recur(N, Set, K, 0, count, 0);
        cout << count << endl;
        delete[] Set;
    }
    
    return 0;
}

