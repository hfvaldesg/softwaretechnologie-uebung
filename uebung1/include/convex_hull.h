#ifndef CONVEX_HULL_H
#define CONVEX_HULL_H

#include "point.h"
#include "polygon.h"
#include "rectangle.h"
#include "helpers.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>


Polygon ch_polygon(std::vector<Point> points, bool verbose=false){
    // Using Graham Scan Algorithm    

    // Find lowest y of the cloud of points
    Point lowest_point{helpers::lowestPoint(points)};

    // Create a new empty vector only with sorted points 
    std::vector <Point> sorted_points{helpers::sort_points_to_reference(lowest_point, points)};
    
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

    Polygon pol{polygon_points};    
    return pol;
}   

Rectangle ch_rectangle(std::vector<Point> _points, bool verbose=false){
    Polygon convex_hull{ch_polygon(_points)};
    std::vector<Point> points{convex_hull.getPoints()};
    Point center{convex_hull.getCenter()};
    // Obtain angle for every point and create new rotated vector
    // Save the area and rectangle for every rotated possibility
    std::map<float, Rectangle> area_rectangle_dict;

    // For the original position (non rotated)
    {
        double angle{0};
        std::pair<double, std::vector<Point>> pair_area_points {helpers::rotated_corners(points, angle)};
        Rectangle minimal_rect{pair_area_points.second};
        // Store the information
        area_rectangle_dict.insert({pair_area_points.first, minimal_rect});  
    }    

    for(auto point : points){
        // For the rotated vertices
        double angle = atan2(point.getY() - center.getY(), 
                            point.getX() - center.getX());
        std::pair<double, std::vector<Point>> pair_area_points {helpers::rotated_corners(points, angle)};
        Rectangle minimal_rect{pair_area_points.second};
        // Store the information
        area_rectangle_dict.insert({pair_area_points.first, minimal_rect});        
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

    return rect;
}
#endif