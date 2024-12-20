//
// Created by andre on 17/12/2024.
//

#ifndef TRIANGLE_RECT_H
#define TRIANGLE_RECT_H
#include <math.h>
#include <valarray>

#include "Rectangle.h"


class Triangle_Rect : public Rectangle {
public:
    double area() { return Rectangle::area()/2; }
    double perimeter() { return base + altezza + sqrt(base*base + altezza*altezza); }
    Triangle_Rect() : Rectangle() {}
    Triangle_Rect(const int b, const int h) : Rectangle(b, h) {     // chiamo il costruttore di rectangle
        // qui potrei definire campi aggiuntivi rispetto a rectangle
    }
};



#endif //TRIANGLE_RECT_H
