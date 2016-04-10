#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	float x;
	float y;
	bool visited;
};

bool compare(const point &p1, const point &p2) {
	return p1.x < p2.x;
}

int main() {
	point p[3];
	p[0].x = 1;
	p[0].y = 1;
	p[1].x = 20;
	p[1].y = 0;
	p[2].x = 3;
	p[2].y = 5;
	sort(p, p+3, compare);
	for (int i=0; i<3; ++i) 
		cout << p[i].x << ", " << p[i].y << endl;
	

	return 0;
}
