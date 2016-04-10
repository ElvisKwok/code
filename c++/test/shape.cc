#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415926;

class Shape {
public:
    Shape() {}
    ~Shape() {}
    virtual double area() { return 0; }
    virtual double girth() { return 0; }
    virtual void show() { cout << "Shape Object: " << endl; }
};

class Circle: public Shape {
public:
    Circle(): m_radius(0.0) { }
    Circle(double radius=0.0): m_radius(radius) { }
    ~Circle() { }
    double area() { return PI * m_radius * m_radius; }
    double girth() { return 2 * PI * m_radius; }
    void show() { cout << "Circle Object: " << endl; }
private:
    double m_radius;
};

class Triangle: public Shape {
public:
    Triangle(): a(0.0), b(0.0), c(0.0) { }
    Triangle(double x=0.0, double y=0.0, double z=0.0): a(x), b(y), c(z) { }
    ~Triangle() { }
    double area() { 
        double s = girth() / 2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    double girth() { return a+b+c; }
    void show() { cout << "Triangle Object: " << endl; }
private:
    double a, b, c;
};

int main() {
    Shape *p1 = new Circle(2);
    Shape *p2 = new Triangle(3, 4, 5);
    cout << "Area: " << endl;
    cout << "p1 = " << p1->area() << endl;
    cout << "p2 = " << p2->area() << endl;
    cout << "girth: " << endl;
    cout << "p1 = " << p1->girth() << endl;
    cout << "p2 = " << p2->girth() << endl;
    cout << "type: " << endl;
    p1->show();
    p2->show();
    delete p1;
    delete p2;
    return 0;
}
