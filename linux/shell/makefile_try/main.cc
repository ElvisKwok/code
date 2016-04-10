#include <iostream>
#include <cstdlib>
#include "pub.h"
using namespace std;

int main(int argc, char **argv) {
	if (argc < 4) {
		cerr << "error" << endl;
		return -1;
	}
	cout << argv[1] << ' ' << argv[2] << ' ' << argv[3] << " = "
	     << pub(atoi(argv[1]), argv[2], atoi(argv[3])) << endl;
	return 0;
}
