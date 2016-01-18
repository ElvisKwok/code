// Source : https://leetcode.com/problems/simplify-path/
// Author : Elvis Kwok
// Date   : 2016-01-16

/********************************************************************************** 
 * 
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * 
 * click to show corner cases.
 * 
 * Corner Cases:
 * 
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as 
 * "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/*
 * general case:
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * 
 * corner case:
 * "/../" => "/"
 * "/home//foo" => "/home/foo"
 * "/." => "/"
 * 
 */

class Solution {
public:
    string simplifyPath(string path) {
        string result;
        for (int i=0; i<path.size(); ) {
            int left = i, right = i;
            while ((++right)<path.size() && path[right] != '/');
            string section(path.begin()+left, path.begin()+right);
            // cout << left << ", " << right << endl;
            // cout << "section: " << section << endl;
            if (section == "/.")
                ;
            else if (section == "/..") {
                if (result.empty())
                    if (right < path.size()) ;
                    else return "/";    // path = "/../"
                else {
                    int j;
                    for (j=result.size()-1; j>=0 && result[j]!='/'; --j);
                    result.erase(j, result.size());
                }
            }
            else if (section == "/") {
                if (right < path.size());   // ignore redundant '/' like "/home//foo/"
                else if (result.empty()) return "/";    // path = "/" => "/"
                else return result;
            }
            else
                result.append(section.begin(), section.end());
            i = right;      // !! jump to next section
            // cout << "result: " << result << endl;
        }
        if (result.empty()) return "/";     // "/." => "/"
        return result;
    }

    // haoel solution:
    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim))
            elems.push_back(item);
        return elems;
    }
    string simplifyPath2(string path) {
        string result;
        vector<string> elems = split(path, '/');
        int ignore = 0;
        for (int i=elems.size()-1; i>=0; --i) {
            if (elems[i]=="" || elems[i]==".")
                continue;
            if (elems[i]=="..") {
                ++ignore;
                continue;
            }
            if (ignore>0) {
                --ignore;
                continue;
            }

            if (result.size()==0) {
                result = "/" + elems[i];
            } else {
                result = "/" + elems[i] + result;
            }
        }
        
        return result.size() ? result : "/";
    }
    
    // soulmachine solution: stack
    string simplifyPath3(string path) {
        vector<string> dirs;    // stack
        for (auto i=path.begin(); i!=path.end();) {
            ++i;
            auto j = find(i, path.end(), '/');
            auto dir = string(i, j);
            if (!dir.empty() && dir!=".") {     // continuous '///', dir is empty
                if (dir == "..") {
                    if (!dirs.empty())
                        dirs.pop_back();
                }
                else
                    dirs.push_back(dir);
            }
            i = j;
        }
        
        stringstream out;
        if (dirs.empty()) {
            out << "/";
        } else {
            for (auto dir : dirs)
                out << '/' << dir;
        }

        return out.str();

    }
};

int main(int argc, char **argv)
{
    Solution s;
    string path("/home/desktop");
    string path2("/a/./b/../../c/");
    //cout << s.simplifyPath(path) << endl;
    cout << s.simplifyPath(path2) << endl;
    cout << s.simplifyPath2(path2) << endl;
    cout << s.simplifyPath3(path2) << endl;

    if (argc == 2) {
        cout << s.simplifyPath(argv[1]) << endl;
        cout << s.simplifyPath2(argv[1]) << endl;
        cout << s.simplifyPath3(argv[1]) << endl;
    }

    return 0;
}
