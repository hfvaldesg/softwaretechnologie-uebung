#ifndef TOPIC_H
#define TOPIC_H

#include <string>

class Topic{
    private:
        std::string name;
    public:
        Topic(std::string _name): name(_name){}

        void setName(std::string _name){
            name = _name;
        }

        std::string getName(){
            return name;
        }
};

#endif