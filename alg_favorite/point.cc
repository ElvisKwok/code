#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

struct Point {
	double x;
	double y;
	Point(int ix, int iy): x(ix), y(iy) { }
};

double distance(const Point &p1, const Point &p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

Point pos(Point &start, Point &end, double len) {	// 直线上距离start len长度的点
	Point p(0, 0);
	if (len > distance(start, end))
		return p;
	double k = (end.y - start.y) / (end.x - start.x);
	double b = start.y - k * start.x;
	p.x = len / (sqrt(1+k*k)) + start.x;
	p.y = k * p.x + b;
	return p;
}

int main() {
	Point p1(1, 1), p2(7, 7);
	Point p3(-1, 0), p4(8, 0);
	double len = 2.0;

	cout << "distance of p1, p2: ";
	cout << "(" << p1.x << ", " << p1.y << ")\t";
	cout << "(" << p2.x << ", " << p2.y << ")" << endl;
	cout << distance(p1, p2) << endl;
	cout << "len start from p1" << endl;
	Point p = pos(p1, p2, len);
	cout << "(" << p.x << ", " << p.y << ")" << endl;


	cout << "distance of p3, p4: ";
	cout << "(" << p3.x << ", " << p3.y << ")\t";
	cout << "(" << p4.x << ", " << p4.y << ")" << endl;
	cout << distance(p3, p4) << endl;
	cout << "len start from p1" << endl;
	p = pos(p3, p4, len);
	cout << "(" << p.x << ", " << p.y << ")" << endl;

	return 0;	
}
