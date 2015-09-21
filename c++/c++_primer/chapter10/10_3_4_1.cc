#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, int> word_count;
    string word;

    while (cin >> word)
        ++word_count[word];
    
    map<string, int>::iterator map_it = word_count.begin();
    for ( ; map_it != word_count.end(); ++map_it)
        cout << map_it->first << '\t' << map_it->second << endl;

    return 0;
}
