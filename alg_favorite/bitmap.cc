#include <iostream>
using namespace std;

const int SIZE = sizeof(int) * 8;

class Bitmap {
public:
	Bitmap(int size = SIZE): N(size) {	
		bits = new int[N/SIZE + 1];
	}
	~Bitmap() {
		delete[] bits;
	}
	bool test(int i) {
		int pos = i / SIZE;		// i/32 = i >> 5
		int off = i % SIZE;		// i%32 = i & 0x1F
		return (bits[pos] & (1 << off)) != 0;
	}
	void set(int i) {
		int pos = i / SIZE;
		int off = i % SIZE;
		bits[pos] |= (1 << off);
	}
private:
	int *bits;
	int N;
};

void print_duplicates(int a[], int n, int bitsize) {
	Bitmap bm(bitsize);
	for (int i = 0; i < n; ++i) {
		if (bm.test(a[i]-1))			// a[i]-1 !!!!
			cout << a[i] << " ";
		else
			bm.set(a[i]-1);
	}
	cout << endl;
}

int main() {
	int a[14] = {1, 2, 3, 4, 5, 32000, 7, 8, 9, 1, 2, 5, 8, 32000};
	print_duplicates(a, 14, 32000);
	return 0;
}
