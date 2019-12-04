#ifndef HELPERS_H
#define HELPERS_H

#include "point.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
namespace helpers {
    Point lowest_point(std::vector<Point> points){
        // Find lowest point (y-axis) in a cloud of points
        // If there are 2 minimal points, choose the one with the minimal x coordinate (left-down corner)
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
        return lowest_point; 
    }

    std::vector<Point> sort_points_to_reference(Point reference, std::vector<Point> points){
        // Sort the points in the cloud depending of the angle to the reference. Lowest angle first
        std::map<double, std::pair<Point, double>> cloud;
        for(auto point : points){
            if(!(point == reference)){
            double angle = atan2(point.getY() - reference.getY(), 
                            point.getX() - reference.getX());
            double distance = sqrt(pow(point.getX() - reference.getX(), 2) 
                                + pow(point.getY() - reference.getY(), 2));
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
        std::vector <Point> sorted_points{reference};
        for(auto point : cloud){
            sorted_points.push_back(point.second.first); // Add point to vector
        }
        return sorted_points;
    }

    std::pair<double, std::vector<Point>> rotated_corners(std::vector<Point> points, double angle){
        // Obtain a pair composed by an area and a vector of corners, which form a rectangle
        double min_x, max_x, min_y, max_y;
        for(auto it = points.begin(); it != points.end(); ++it){
            //rotate the points
            double rotated_x = cos(angle) * it->getX() - sin(angle) * it->getY();
            double rotated_y = sin(angle) * it->getX() + cos(angle) * it->getY();
            if(it == points.begin()){
                min_x = rotated_x;
                max_x = rotated_x;
                min_y = rotated_y;
                max_y = rotated_y;
            } else {
                // Determine min/max x,y of rotated points
                if(rotated_x < min_x){
                    min_x = rotated_x;
                } else if(rotated_x > max_x){
                    max_x = rotated_x;
                }
                if(rotated_y < min_y){
                    min_y = rotated_y;
                }else if(rotated_y > max_y){
                    max_y = rotated_y;
                } 
            }
        }       
        double area{
            std::abs((max_x - min_x) * (max_y - min_x))
        };
        // Rotation in the other direction (negative)
        // Right - Up corner
        Point right_up_corner {
            cos(angle) * max_x + sin(angle) * max_y,
            -1 * sin(angle) * max_x + cos(angle) * max_y 
        };
        // Left - Up corner
        Point left_up_corner {
            cos(angle) * min_x + sin(angle) * max_y,
            -1 * sin(angle) * min_x + cos(angle) * max_y 
        };
        // Right - Down corner
        Point right_down_corner {
            cos(angle) * max_x + sin(angle) * min_y,
            -1 * sin(angle) * max_x + cos(angle) * min_y 
        };
        // Left - Down corner
        Point left_down_corner {
            cos(angle) * min_x + sin(angle) * min_y,
            -1 * sin(angle) * min_x + cos(angle) * min_y
        };

        std::vector<Point> minimal_points{
            right_up_corner, left_up_corner, right_down_corner, left_down_corner
        }; 
        
        std::pair<double, std::vector<Point>> pair_area_points {area, minimal_points};
        return pair_area_points;  
    }
}

#endif