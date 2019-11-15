#ifndef POLYGON_H
#define POLYGON_H

#include "point.h"
#include <vector>
#include <iostream>

class Polygon {
    protected:
        std::vector<Point> points;
    public:
        Polygon(){}
        Polygon(std::vector<Point> _points): points(_points){}
        // Rule of five: default
        Polygon(const Polygon&) = default;
        Polygon(Polygon&&) = default;
        Polygon& operator=(const Polygon&) = default;
        Polygon& operator=(Polygon&&) = default;
        virtual ~Polygon() = default;

        void setPoins(std::vector<Point> _points){
            points = _points;
        }
        std::vector<Point> getPoints(){
            return points;
        }
        void addPunkt(Point _point){
            points.push_back(_point);
        }
        void print(){
            std::cout <<"Liste aller Punkte: "<< std::endl;
            for(auto point : points){
                std::cout << point << ", ";
            }
            std::cout << std::endl;
        }

        // Convex Hull Polygon 
};

#endif