#include "polygon.h"
#include <vector>
#include <iostream>

class Rechteck: public Polygon{
    public:
        Rechteck(){}
        Rechteck(std::vector<Point> _points): Polygon(_points){
        }
        // Rule of five: default
        Rechteck(const Rechteck&) = default;
        Rechteck(Rechteck&&) = default;
        Rechteck& operator=(const Rechteck&) = default;
        Rechteck& operator=(Rechteck&&) = default;
        virtual ~Rechteck() = default;
};