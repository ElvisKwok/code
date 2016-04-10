#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

void path(vector<string>& svec, int &cnt, int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2) {
		cout << cnt << endl;
		return ;
	}
	if (x1 > x2 && y1 == y2) {
		string s("L");
		svec.push_back(s);
		cnt++;
		x1--;
	}
	else if (x1 > x2 && y1 > y2) {
		string s("LD");
		svec.push_back(s);
		cnt++;
		x1--;
		y1--;
	}
	else if (x1 == x2 && y1 > y2) {
		string s("D");
		svec.push_back(s);
		cnt++;
		y1--;
	}
	else if (x1 < x2 && y1 > y2) {
		string s("RD");
		svec.push_back(s);
		cnt++;
		x1++;
		y1--;
	}
	else if (x1 < x2 && y1 == y2) {
		string s("R");
		svec.push_back(s);
		cnt++;
		x1++;
	}
	else if (x1 < x2 && y1 < y2) {
		string s("RU");
		svec.push_back(s);
		cnt++;
		x1++;
		y1++;
	}
	else if (x1 == x2 && y1 < y2) {
		string s("U");
		svec.push_back(s);
		cnt++;
		y1++;
	}
	else if (x1 > x2 && y1 < y2) {
		string s("LU");
		svec.push_back(s);
		cnt++;
		x1--;
		y1++;
	}
	path(svec, cnt, x1, y1, x2, y2);
}
    
int main() {
	freopen("input.txt", "r", stdin);

    int cnt, x1, y1, x2, y2;
    string from, to;
	while (cin >> from >> to) {
		vector<string> svec;
		cnt = 0;
		x1 = from[0]-'1';
		y1 = from[1]-'a';
		x2 = to[0]-'1';
		y2 = to[1]-'a';
		path(svec, cnt, x1, y1, x2, y2);
		for (int i=0; i < svec.size(); ++i) {
			cout << svec[i] << endl;
		}
	}

	fclose(stdin);
    return 0;
}
