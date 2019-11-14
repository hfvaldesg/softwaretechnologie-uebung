#include "punkt.h"
#include <vector>
#include <iostream>

class Polygon {
    protected:
        std::vector<Punkt> punkte;
    public:
        Polygon(){}
        Polygon(std::vector<Punkt> _punkte): punkte(_punkte){}
        // Rule of five: default
        Polygon(const Polygon&) = default;
        Polygon(Polygon&&) = default;
        Polygon& operator=(const Polygon&) = default;
        Polygon& operator=(Polygon&&) = default;
        virtual ~Polygon() = default;

        void setPunkte(std::vector<Punkt> _punkte){
            punkte = _punkte;
        }
        std::vector<Punkt> getPunkte(){
            return punkte;
        }
        void addPunkt(Punkt _punkt){
            punkte.push_back(_punkt);
        }
        void print(){
            std::cout <<"Liste aller Punkte: "<< std::endl;
            for(auto punkt : punkte){
                std::cout << punkt << ", ";
            }
            std::cout << std::endl;
        }

        // Convex Hull Polygon 
};