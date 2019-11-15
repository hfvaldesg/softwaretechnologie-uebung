#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point final{
    private:
        float x;
        float y;   
    public:
        Point(float _x, float _y): x(_x), y(_y){}
        Point(){}
        ~Point() = default;
        Point(const Point&) = default;  
        Point(Point&&) = default;
        Point& operator=(const Point&) = default;
        Point& operator=(Point&&) = default;

        void setX(float _x){
            x = _x;
        }
        float getX(){
            return x;
        }
        void setY(float _y){
            y = _y;
        }
        float getY(){
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