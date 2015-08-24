#include <fstream>

ifstream& open_file(ifstream &in, const string &file)
{
    in.close();     // close in case it was already open
    in.clear();     // clear any existing errors
    in.open(file.c_str());
    return in;
}
