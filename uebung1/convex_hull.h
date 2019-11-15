#ifndef CONVEX_HULL_H
#define CONVEX_HULL_H

#include "point.h"
#include "polygon.h"
#include "rectangle.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>


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
    std::map<double, std::pair<Point, double>> cloud;
    for(auto point : points){
        if(!(point == lowest_point)){
            double angle = atan2(point.getY() - lowest_point.getY(), 
                            point.getX() - lowest_point.getX());
            double distance = sqrt(pow(point.getX() - lowest_point.getX(), 2) 
                                + pow(point.getY() - lowest_point.getY(), 2));
            // Test if the angle already exists. If the angle exists, use the point with the bigger distance.
            std::pair<Point, double> point_and_radius{point, distance};
            if ( cloud.find(angle) == cloud.end() ) {                
                cloud.insert({angle, point_and_radius});
            } else {
                double actual_distance = cloud.at(angle).second;
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
    // Save the area and rectangle for every rotated possibility
    std::map<float, Rectangle> area_rectangle_dict;
    for(auto point : points){
        double angle = atan2(point.getY(), point.getX());
        std::pair<Point, double> min_x, max_x, min_y, max_y;
        for(auto it = points.begin(); it != points.end(); ++it){
            //rotate the points
            double rotated_x = cos(angle) * it->getX() - sin(angle) * it->getY();
            double rotated_y = sin(angle) * it->getX() + cos(angle) * it->getY();
            if(it == points.begin()){
                min_x = {*it, rotated_x};
                max_x = {*it, rotated_x};
                min_y = {*it, rotated_y};
                max_y = {*it, rotated_y};
            } else {
                // Determine min/max x,y of rotated points
                if(rotated_x < min_x.second){
                    min_x = {*it, rotated_x};
                } else if(rotated_x > max_x.second){
                    max_x = {*it, rotated_x};
                }
                if(rotated_y < min_y.second){
                    min_y = {*it, rotated_y};
                }else if(rotated_y > max_y.second){
                    max_y = {*it, rotated_y};
                } 
            }                   
        }
        double area{
            (max_x.second - min_x.second) * (max_y.second - min_x.second)
        };
        std::vector<Point> minimal_points{
            // Those are the original non-rotated points
            min_x.first, max_x.first, min_y.first, max_y.first
        };
        Rectangle minimal_rect{minimal_points};
        // Store the information
        area_rectangle_dict.insert({area, minimal_rect});        
    }

    // Sort the areas
    std::vector<double> areas;
    for(auto rect : area_rectangle_dict){
        areas.push_back(rect.first);
    }   
    sort(areas.begin(), areas.end());

    // Retrieve the minimal rectangle
    Rectangle rect;
    rect = area_rectangle_dict.at(areas.at(0));

    if(verbose == true){
        std::cout << "\n\033[1m\u001b[36m\033[4mPoints in minimal rectangle\u001b[0m" << std::endl << std::endl;
        for(auto point : rect.getPoints()){
            std::cout << point << std::endl;
        }
    }
    
    return rect;
}
#endif