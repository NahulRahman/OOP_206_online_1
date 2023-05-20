/*
Solve the problem using Object Oriented Paradigm.
A line consists of two points. The length is given by: √((x1−x2)^2 + (y1−y2)^2)
The midpoint is given by:(( x1 + x2 ) / 2 , (y1 + y2 ) / 2 )
*/
#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x, y;
public:
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double _x) { x = _x; }
    void setY(double _y) { y = _y; }
};

class Line {
private:
    Point p1, p2;
public:
    Line(const Point& _p1 = Point(), const Point& _p2 = Point()) : p1(_p1), p2(_p2) {}
    double length() const {
        double dx = p1.getX() - p2.getX();
        double dy = p1.getY() - p2.getY();
        return sqrt(dx * dx + dy * dy);
    }
    Point midpoint() const {
        double x = (p1.getX() + p2.getX()) / 2;
        double y = (p1.getY() + p2.getY()) / 2;
        return Point(x, y);
    }
};

int main() {
    Point p1(0, 0);
    Point p2(3, 4);
    Line l(p1, p2);
    cout << "Length: " << l.length() << endl;
    Point mid = l.midpoint();
    cout << "Midpoint: (" << mid.getX() << ", " << mid.getY() << ")" << endl;
    return 0;
}
