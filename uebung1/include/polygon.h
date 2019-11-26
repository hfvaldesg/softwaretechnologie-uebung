#ifndef POLYGON_H
#define POLYGON_H

#include "point.h"
#include "helpers.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>

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

    void addPoint(Point _point){
      points.push_back(_point);
    }

    void print(){
      for(auto point : points){
        std::cout << point << ", ";
      }
      std::cout << std::endl;
    }  

    Point getCenter(){
      // Obtain center of polygon
      // Order the points
      Point lowest_point{helpers::lowestPoint(points)};
      std::vector <Point> sorted_points{helpers::sort_points_to_reference(lowest_point, points)};
      double total_area{0};
      double x_weight{0};
      double y_weight{0};
      if(sorted_points.size() > 3){
        // Not a triangle
        Point p1{sorted_points.front()};
        for(int x = 1; x < sorted_points.size() - 1; x++){
          Point p2{sorted_points.at(x)};
          Point p3{sorted_points.at(x+1)};
          double cross_product = (p2.getX() - p1.getX()) * (p3.getY() - p1.getY())
                                - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
          double sub_area{cross_product / 2};
          double sub_center_x{(p1.getX() + p2.getX() + p3.getX()) / 3};
          double sub_center_y{(p1.getY() + p2.getY() + p3.getY()) / 3};
          total_area += sub_area;
          x_weight += sub_center_x * sub_area;
          y_weight += sub_center_y * sub_area;
        }
      } 
      
      Point center{
        x_weight / total_area,
        y_weight / total_area
      };
      return center;
    }
};

#endif