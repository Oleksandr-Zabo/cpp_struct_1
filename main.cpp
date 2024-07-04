#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
private:
    double _x;
    double _y;
public:
    Point()
    {
        _x = 0;
        _y = 0;
    }

    Point(double x) : Point()
    {
        setX(x);
    }
    Point(double x, double y) : Point(x)
    {
        setY(y);
    }


    //Getters
    int getX() { return _x; }
    int getY() { return _y; }

    //Setters
    void setX(double x) {
        _x = x;
    }
    void setY(double y) {
        _y = y;
    }
};

double Distance(Point& p1, Point& p2) {
    return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
}



int main()
{
    double x;
    cout << "Enter x_1: ";
    cin >> x;

    double y;
    cout << "Enter y_1: ";
    cin >> y;

    Point point_1 = Point(x, y);

    cout << "Enter x_2: ";
    cin >> x;

    cout << "Enter y_2: ";
    cin >> y;

    Point point_2 = Point(x, y);

    double distance = Distance(point_1, point_2);

    cout << "Distance between points: " << distance << endl;

    cout << "End of program" << endl;


    return 0;
}