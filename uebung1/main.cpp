#include "point.h"
#include "polygon.h"
#include "rectangle.h"
#include "convex_hull.h"
#include <vector>


int main(){
    Point p1 {1, 1};
    Point p2 {3, 1};
    Point p3 {6, 2};
    Point p4 {3, 2};
    Point p5 {2, 3};
    Point p6 {6, 4};
    Point p7 {1, 4};
    
    std::vector <Point> points {p1, p2, p3, p4, p5, p6, p7};   
    ch_polygon(points, true);
    ch_rectangle(points, true);
    return 0;
}
