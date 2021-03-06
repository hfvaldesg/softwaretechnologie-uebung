#include "point.h"
#include "polygon.h"
#include "rectangle.h"
#include "convex_hull.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

int main(){    
    // Point p1 {1, 1};
    // Point p2 {3, 1};
    // Point p3 {6, 2};
    // Point p4 {3, 2};
    // Point p5 {2, 3};
    // Point p6 {6, 4};
    // Point p7 {1, 4};
    // std::vector <Point> points {p1, p2, p3, p4, p5, p6, p7};   


    // Point p1 {1, 2};
    // Point p2 {5, 1};
    // Point p3 {8, 3};
    // Point p4 {5, 4};
    // Point p5 {4, 6};
    // std::vector <Point> points {p1, p2, p3, p4, p5};   

    // Point p1 {3, 3};
    // Point p2 {-3, 3};
    // Point p3 {-3, -3};r
    // Point p4 {3, -3};
    // Point p5 {1, 1};
    // Point p6 {-1, 1};
    // Point p7 {-1, -1};
    // Point p8 {1, -1};
    // std::vector <Point> points {p1, p2, p3, p4, p5, p6, p7, p8};   

    // srand(time(NULL));
    // std::vector<Point> points{};
    // for(int i = 0; i <= 200 ; i++){
    //     double x = rand() % 200;
    //     double y = rand() % 200; 
    //     Point rand_point{x, y};
    //     points.push_back(rand_point);
    // }

    Point p1 {-1, 5};
    Point p2 {-1, 3};
    Point p3 {-3, 3};
    Point p4 {-2, 1};
    Point p5 {-1, -1};
    Point p6 {3, -2};
    Point p7 {2, -5};
    Point p8 {5, -1};
    Point p9 {6, 1};
    Point p10 {3, 1};
    Point p11 {1, 1};
    Point p12 {2, 3};
    Point p13 {4, 3};
    Point p14 {5, 5};
    Point p15 {7, 3};

    std::vector <Point> points {
        p1, p2, p3, p4, p5, 
        p6, p7, p8, p9, p10,
        p11, p12, p14, p15};   

    Polygon convex_hull_polygon{ch_polygon(points)};
    Rectangle minimal_rectangle{ch_rectangle(points)};

    std::cout << "\033[4m\033[1m\u001b[36mConvex Hull Polygon\u001b[0m" << std::endl;
    convex_hull_polygon.print();

    std::cout << std::endl;

    std::cout << "\033[4m\033[1m\u001b[36mMinimal Area Rectangle\u001b[0m" << std::endl;
    minimal_rectangle.print();

    // Save the cloud of points
    std::ofstream allPointsFile;
    allPointsFile.open("all-points.txt");
    for(auto point : points){
        allPointsFile << point.getX() << " " << point.getY() << std::endl;;
    }
    allPointsFile.close();
    
    // Save the polygon points
    convex_hull_polygon.writePoints("polygon-points.txt");

    // Save the rectangle points
    minimal_rectangle.writePoints("rectangle-points.txt");
    
    return 0;
}
