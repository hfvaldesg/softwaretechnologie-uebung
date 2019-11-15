#ifndef CONVEX_HULL_H
#define CONVEX_HULL_H

#include "point.h"
#include "polygon.h"
#include "rectangle.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <map>


Polygon ch_polygon(std::vector<Point> points, bool verbose=false){
    // Using Graham Scan Algorithm    

    // Find lowest y of the cloud of points
    Point lowest_point;
    for(auto it = points.begin(); it != points.end(); ++it){
        if(it == points.begin()){
            lowest_point = *it;
        } else {
            if(it->getY() < lowest_point.getY()){
                lowest_point = *it;
            } else if( (it->getY() == lowest_point.getY()) && (it->getX() < lowest_point.getX())){
                lowest_point = *it;
            }
        }
    }
    if(verbose == true){
        std::cout << "\033[1m\u001b[36m\033[4mLowest point in the cloud\u001b[0m" << std::endl << std::endl;
        std::cout << lowest_point <<std::endl;
    }    

    // Create map of points, using angle as key and <Point, distance> as value
    // Map automatically sort the keys in increasing order
    std::map<float, std::pair<Point, float>> cloud;
    for(auto point : points){
        if(!(point == lowest_point)){
            float angle = atan2(point.getY() - lowest_point.getY(), 
                            point.getX() - lowest_point.getX());
            float distance = sqrt(pow(point.getX() - lowest_point.getX(), 2) 
                                + pow(point.getY() - lowest_point.getY(), 2));
            // Test if the angle already exists. If the angle exists, use the point with the bigger distance.
            std::pair<Point, float> point_and_radius{point, distance};
            if ( cloud.find(angle) == cloud.end() ) {                
                cloud.insert({angle, point_and_radius});
            } else {
                float actual_distance = cloud.at(angle).second;
                if(actual_distance < distance){
                    cloud.at(angle) = point_and_radius;
                }
            }            
        }        
    } 

    // Create a new empty vector only with sorted points 
    std::vector <Point> sorted_points{lowest_point};
    if(verbose == true){
        std::cout << "\033[1m\u001b[36m\033[4mSorted cloud of points (without lowest point)\u001b[0m" << std::endl << std::endl;
    }
    for(auto point : cloud){
        if(verbose == true){
            std::cout << point.second.first << ", angle: " << point.first << ", r: " << point.second.second << std::endl;
        }
        sorted_points.push_back(point.second.first); // Add point to vector
    }
    if(verbose == true){
        std::cout << "\033[1m\u001b[36m\033[4mDetermine left and right turns\u001b[0m" << std::endl << std::endl;
    }
    
    // Iterate sorted points to discard the sequence of points that generate a right (negative) turn.
    // The turn is calculated using the cross product between last 2 points and actual point
    std::vector <Point> polygon_points; // lowest point is the first point
    for(auto it = sorted_points.begin(); it != sorted_points.end(); ++it){
        int index = it - sorted_points.begin();
        if(index < 2){
            polygon_points.push_back(*it);
        } else {
            Point p1 = polygon_points.at(polygon_points.size() - 2);
            Point p2 = polygon_points.at(polygon_points.size() - 1);
            Point p3 = *it;
            double cross_product = (p2.getX() - p1.getX()) * (p3.getY() - p2.getY())
                                - (p2.getY() - p1.getY()) * (p3.getX() - p2.getX());
            if(verbose == true){
                std::cout << "p1: " << p1 << std::endl;
                std::cout << "p2: " << p2 << std::endl;
                std::cout << "p3: " << p3 << std::endl;
                std::cout << "cross product: " << cross_product << std::endl << std::endl;
            }
            
            if(cross_product < 0){
                // Right turn (negative)
                polygon_points.pop_back();
                polygon_points.push_back(*it);
            } else {
                // Left turn (positive) and collinear points (cross product = 0)
                polygon_points.push_back(*it);
            }  
        }
    }
    if(verbose == true){
        std::cout << "\033[1m\u001b[36m\033[4mPoints in the Convex Hull\u001b[0m" << std::endl << std::endl;
        for(auto point : polygon_points){
            std::cout << point << std::endl;
        }
    }
    Polygon pol{polygon_points};    
    return pol;
}   

Rectangle ch_rectangle(std::vector<Point> _points, bool verbose=false){
    Polygon convex_hull{ch_polygon(_points)};
    std::vector<Point> points{convex_hull.getPoints()};

    // Obtain angle for every point and create new rotated vector
    for(auto point : points){
        float angle = atan2(point.getY(), point.getX());
        std::vector<Point> rotated_points;
        std::pair<Point, float> min_x, max_x, min_y, max_y;
        for(auto p : points){
            //rotate the points
            double rotated_x = cos(angle) * p.getX() - sin(angle) * p.getY();
            double rotated_y = sin(angle) * p.getX() + cos(angle) * p.getY();
            Point rotated_point{(float) rotated_x,(float) rotated_y};
            // Determine min/max x,y of rotated points
            if(rotated_point.getX() < min_x.first.getX()){
                min_x = {rotated_point, rotated_point.getX()};
            }
            if(rotated_point.getX() > min_x.first.getX()){
                max_x = {rotated_point, rotated_point.getX()};
            }
            if(rotated_point.getY() < min_x.first.getY()){
                min_y = {rotated_point, rotated_point.getY()};
            }
            if(rotated_point.getY() > min_x.first.getY()){
                max_y = {rotated_point, rotated_point.getY()};
            }
        }
        float area{
            (max_x.second - min_x.second) * (max_y.second - min_x.second)
        };
    }   

    Rectangle rect;
    return rect;
}
#endif