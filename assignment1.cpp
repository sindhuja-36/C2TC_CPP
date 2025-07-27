#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual void calculateArea() const = 0;
};

class Rectangle : public Shape {
    double length, breadth;
public:
    Rectangle(double l, double b) : Shape("Rectangle"), length(l), breadth(b) {}
    void calculateArea() const override {
        cout << name << " Area: " << length * breadth << endl;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    void calculateArea() const override {
        cout << name << " Area: " << M_PI * radius * radius << endl;
    }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : Shape("Triangle"), base(b), height(h) {}
    void calculateArea() const override {
        cout << name << " Area: " << 0.5 * base * height << endl;
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Rectangle(10, 5);
    shapes[1] = new Circle(7);
    shapes[2] = new Triangle(6, 4);

    for (int i = 0; i < 3; ++i) {
        shapes[i]->calculateArea();
    }

    return 0;
}
