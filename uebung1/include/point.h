#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point final{
    private:
        double x;
        double y;   
    public:
        Point(double _x, double _y): x(_x), y(_y){}
        Point(){}
        ~Point() = default;
        Point(const Point&) = default;  
        Point(Point&&) = default;
        Point& operator=(const Point&) = default;
        Point& operator=(Point&&) = default;

        void setX(double _x){
            x = _x;
        }
        double getX(){
            return x;
        }
        void setY(double _y){
            y = _y;
        }
        double getY(){
            return y;
        }
        friend std::ostream& operator<<(std::ostream& os, 
                                        const Point& point){
            os << "(" << point.x 
            << ", " << point.y << ")";
            return os;
        }
        bool operator==(const Point& other ){
            return (this->getX() == other.x) && (this->getY() == other.y);
        }
};

#endif