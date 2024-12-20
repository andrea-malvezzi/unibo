//
// Created by andre on 17/12/2024.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cstdlib>

class Rectangle {
protected:
    double base;
    double altezza;
public:
    double area() { return base*altezza; }
    double perimeter() { return 2*base+2*altezza; }
    Rectangle(const int b=0, const int h=0) { base = abs(b); altezza = abs(h); }
};

#endif //RECTANGLE_H
