#include <iostream>

class Punkt final{
    private:
        float x;
        float y;   
    public:
        Punkt(float _x, float _y): x(_x), y(_y){}
        Punkt(){}
        ~Punkt() = default;
        Punkt(const Punkt&) = default;  
        Punkt(Punkt&&) = default;
        Punkt& operator=(const Punkt&) = default;
        Punkt& operator=(Punkt&&) = default;

        void setX(float _x){
            x = _x;
        }
        float getX(){
            return x;
        }
        void setY(float _y){
            y = _y;
        }
        float getY(){
            return y;
        }
        friend std::ostream& operator<<(std::ostream& os, 
                                        const Punkt& pkt){
            os << "(" << pkt.x 
            << ", " << pkt.y << ")";
            return os;
        }
        bool operator==(const Punkt& other ){
            return (this->getX() == other.x) && (this->getY() == other.y);
        }
};