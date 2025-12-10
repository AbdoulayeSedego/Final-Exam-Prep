#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

// Abstract base class Shape
class Shape {
protected:
    string name;

public:
    // Constructor
    Shape(string shapeName) : name(shapeName) {}

    // Pure virtual functions (makes this class abstract)
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;

    // Virtual function to display shape info
    virtual void display() {
        cout << "Shape: " << name << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }

    // Virtual destructor (important for proper cleanup with polymorphism)
    virtual ~Shape() {
        cout << "Destroying " << name << endl;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double r) : Shape("Circle"), radius(r) {}

    // Implement calculateArea: À * r²
    double calculateArea() override {
        return PI * radius * radius;
    }

    // Implement calculatePerimeter: 2 * À * r
    double calculatePerimeter() override {
        return 2 * PI * radius;
    }

    // Override display to include radius
    void display() override {
        cout << "--- Circle ---" << endl;
        cout << "Radius: " << radius << endl;
        Shape::display();
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}

    // Implement calculateArea: width * height
    double calculateArea() override {
        return width * height;
    }

    // Implement calculatePerimeter: 2 * (width + height)
    double calculatePerimeter() override {
        return 2 * (width + height);
    }

    // Override display to include dimensions
    void display() override {
        cout << "--- Rectangle ---" << endl;
        cout << "Width: " << width << ", Height: " << height << endl;
        Shape::display();
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double side1;
    double side2;
    double side3;

public:
    // Constructor
    Triangle(double s1, double s2, double s3)
        : Shape("Triangle"), side1(s1), side2(s2), side3(s3) {}

    // Implement calculateArea using Heron's formula
    // Area = sqrt(s * (s-a) * (s-b) * (s-c)) where s = (a+b+c)/2
    double calculateArea() override {
        double s = (side1 + side2 + side3) / 2;  // semi-perimeter
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    // Implement calculatePerimeter: sum of all sides
    double calculatePerimeter() override {
        return side1 + side2 + side3;
    }

    // Override display to include sides
    void display() override {
        cout << "--- Triangle ---" << endl;
        cout << "Sides: " << side1 << ", " << side2 << ", " << side3 << endl;
        Shape::display();
    }
};

int main() {
    cout << "=== Shape Drawing System (Polymorphism Demo) ===" << endl << endl;

    // Create individual shape objects
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Triangle triangle(3.0, 4.0, 5.0);  // Right triangle (3-4-5)

    // Display each shape directly
    cout << "--- Direct Object Calls ---" << endl << endl;
    circle.display();
    cout << endl;
    rectangle.display();
    cout << endl;
    triangle.display();
    cout << endl;

    // Demonstrate polymorphism with base class pointers
    cout << "=== Polymorphism with Base Class Pointers ===" << endl << endl;

    Shape* shapes[3];
    shapes[0] = &circle;
    shapes[1] = &rectangle;
    shapes[2] = &triangle;

    for (int i = 0; i < 3; i++) {
        shapes[i]->display();
        cout << endl;
    }

    // Demonstrate polymorphism with dynamic allocation
    cout << "=== Polymorphism with Dynamic Allocation ===" << endl << endl;

    Shape* dynamicShapes[3];
    dynamicShapes[0] = new Circle(3.0);
    dynamicShapes[1] = new Rectangle(5.0, 3.0);
    dynamicShapes[2] = new Triangle(5.0, 5.0, 6.0);  // Isosceles triangle

    for (int i = 0; i < 3; i++) {
        dynamicShapes[i]->display();
        cout << endl;
    }

    // Clean up dynamic memory (demonstrates virtual destructor)
    cout << "=== Cleaning Up Dynamic Objects ===" << endl;
    for (int i = 0; i < 3; i++) {
        delete dynamicShapes[i];
    }

    cout << endl << "=== End of Program ===" << endl;
    // Note: Local objects (circle, rectangle, triangle) will be destroyed
    // automatically when main() ends

    return 0;
}
