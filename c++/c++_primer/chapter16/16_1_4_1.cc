/**************************************************************
 * 
 * Find out an element that occurs most frequently.
 *
 * Return the smallest result if more than one element found.
 *
 **************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
typename T::value_type mostFre(T first, T last)
{
    // get the container size
    size_t amount = 0;
    T start = first;
    while (start != last) {
        ++amount;
        ++start;
    }

    typedef vector<typename T::value_type> VecType;

    // copy the input array into a vector
    VecType vec(amount);
    typename VecType::iterator newFirst = vec.begin();
    typename VecType::iterator newLast = vec.end();

    std::uninitialized_copy(first, last, newFirst);
    std::sort(newFirst, newLast);

    size_t maxOccu = 0, occu = 0;
    typename VecType::iterator preIter = newFirst;
    typename VecType::iterator maxOccuElemIt = newFirst;

    while (newFirst != newLast) {
        if (*newFirst != *preIter) {
            if (occu > maxOccu) {
                maxOccu = occu;
                maxOccuElemIt = preIter;
            }
            occu = 0;
        }
        ++occu;
        preIter = newFirst;
        ++newFirst;
    }

    // Don't forget to count the last value
    if (occu > maxOccu) {
        maxOccu = occu;
        maxOccuElemIt = preIter;
    }

    return *maxOccuElemIt;
}

int main() 
{
    int ia[] = {1, 2, 3, 3, 3, 4, 4};
    string sa[] = {"hello", "it", "world", "it", "this"};
    vector<int> ivec(ia, ia+7);
    vector<string> svec(sa, sa+5);
    cout << "most frequent int: " << mostFre(ivec.begin(), ivec.end()) <<  endl;
    cout << "most frequent string: " << mostFre(svec.begin(), svec.end()) <<  endl;
    return 0;
}
