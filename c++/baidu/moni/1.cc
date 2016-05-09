#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printSVEC(vector<string> svec) {
	string s(30, '*');
	cout << s << endl;
	for (int i = 0; i < svec.size(); ++i) {
		cout << svec[i] << endl;
	}
}

int canArrangeWords(int num, vector<string> &svec);
int canArrangeWords(int num, char **arr) {
	vector<string> svec;
	for (int i = 0; i < num; ++i) {
		string s(arr[i]);
		svec.push_back(s);
	}

	return canArrangeWords(num, svec);
}


int canArrangeWords(int num, vector<string> &svec) {
	while (1) {
		if (svec.size() == 1)
			return 1;
		for (int i=0; i < svec.size()-1; ++i) {
			//printSVEC(svec);
			bool found = false;
			for (int j = 1; j < svec.size(); ++j) {
				int ilen = svec[i].size();
				int jlen = svec[j].size();
				if (svec[i][0] == svec[j][jlen-1]) {
					string s = svec[j] + svec[i];
					svec.erase(svec.begin()+i);
					svec.erase(svec.begin()+j-1);
					svec.push_back(s);
					found = true;
				}
				else if (svec[j][0] == svec[i][ilen-1]) {
					string s = svec[i] + svec[j];
					svec.erase(svec.begin()+i);
					svec.erase(svec.begin()+j-1);
					svec.push_back(s);
					found = true;
				}
			}
			if (found == false)
				return -1;
		}
	}	
}

int main(int argc, char **argv) {
	cout << canArrangeWords(argc-1, argv+1) << endl;

	return 0;
}
