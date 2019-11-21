#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "polygon.h"
#include <vector>
#include <iostream>

class Rectangle: public Polygon{
    public:
        Rectangle(){}
        Rectangle(std::vector<Point> _points): Polygon(_points){
        }
        // Rule of five: default
        Rectangle(const Rectangle&) = default;
        Rectangle(Rectangle&&) = default;
        Rectangle& operator=(const Rectangle&) = default;
        Rectangle& operator=(Rectangle&&) = default;
        virtual ~Rectangle() = default;
};

#endif