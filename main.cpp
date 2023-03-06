#include "dot.h"
#include <iostream>

class Triangle {
private:
    Dot vertex1;
    Dot vertex2;
    Dot vertex3;
public:
    Triangle(const Dot& v1, const Dot& v2, const Dot& v3) {
        double side1 = v1.distanceTo(v2);
        double side2 = v2.distanceTo(v3);
        double side3 = v3.distanceTo(v1);
        if (side1 + side2 <= side3 
            || side2 + side3 <= side1 
            || side3 + side1 <= side2) {
            throw std::invalid_argument("Invalid triangle vertices");
        }
        vertex1 = v1;
        vertex2 = v2;
        vertex3 = v3;
    }
    void printSidesLength() {
        double side1 = vertex1.distanceTo(vertex2);
        double side2 = vertex2.distanceTo(vertex3);
        double side3 = vertex3.distanceTo(vertex1);
        std::cout << "Side 1 length: " << side1 << std::endl;
        std::cout << "Side 2 length: " << side2 << std::endl;
        std::cout << "Side 3 length: " << side3 << std::endl;
    }
    double perimeter() {
        double side1 = vertex1.distanceTo(vertex2);
        double side2 = vertex2.distanceTo(vertex3);
        double side3 = vertex3.distanceTo(vertex1);
        return side1 + side2 + side3;
    }
    double area() {
        double side1 = vertex1.distanceTo(vertex2);
        double side2 = vertex2.distanceTo(vertex3);
        double side3 = vertex3.distanceTo(vertex1);
        double p = (side1 + side2 + side3) / 2;
        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }
};

int main() {
    Dot vertex1(0, 0);
    Dot vertex2(3, 0);
    Dot vertex3(0, 4);
    Triangle triangle(vertex1, vertex2, vertex3);
    triangle.printSidesLength();
    std::cout << "Perimeter: " << triangle.perimeter() << std::endl;
    std::cout << "Area: " << triangle.area() << std::endl;
    return 0;
}
