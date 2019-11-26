#ifndef HELPERS_H
#define HELPERS_H

#include "point.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>

Point lowestPoint(std::vector<Point> points){
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

#endif