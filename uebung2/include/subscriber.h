#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Subscriber {
    public:
        Subscriber();
        void showMessage(std::string message){
            std::cout << "New message: " << message << std::endl;
        }
};

#endif