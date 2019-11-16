#include "point.h"
#include "polygon.h"
#include "rectangle.h"
#include "convex_hull.h"
#include <vector>


int main(){
    // Point p1 {1, 1};
    // Point p2 {3, 1};
    // Point p3 {6, 2};
    // Point p4 {3, 2};
    // Point p5 {2, 3};
    // Point p6 {6, 4};
    // Point p7 {1, 4};
    
    // std::vector <Point> points {p1, p2, p3, p4, p5, p6, p7};   
    // ch_polygon(points, true);
    // ch_rectangle(points, true);

    // Point p1 {1, 2};
    // Point p2 {5, 1};
    // Point p3 {8, 3};
    // Point p4 {5, 4};
    // Point p5 {4, 6};
    
    // std::vector <Point> points2 {p1, p2, p3, p4, p5};   
    // ch_polygon(points2, true);
    // ch_rectangle(points2, true);

    // Point p1 {3, 3};
    // Point p2 {-3, 3};
    // Point p3 {-3, -3};
    // Point p4 {3, -3};
    // Point p5 {1, 1};
    // Point p6 {-1, 1};
    // Point p7 {-1, -1};
    // Point p8 {1, -1};
    
    // std::vector <Point> points {p1, p2, p3, p4, p5, p6, p7, p8};   
    // ch_polygon(points, true);
    // ch_rectangle(points, true);

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
    ch_polygon(points, true);
    ch_rectangle(points, true);

    return 0;
}
