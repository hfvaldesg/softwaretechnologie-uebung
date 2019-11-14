#include "polygon.h"
#include <vector>
#include <iostream>

class Rechteck: public Polygon{
    public:
        Rechteck(){}
        Rechteck(std::vector<Punkt> _punkte): Polygon(_punkte){
        }
        // Rule of five: default
        Rechteck(const Rechteck&) = default;
        Rechteck(Rechteck&&) = default;
        Rechteck& operator=(const Rechteck&) = default;
        Rechteck& operator=(Rechteck&&) = default;
        virtual ~Rechteck() = default;
};