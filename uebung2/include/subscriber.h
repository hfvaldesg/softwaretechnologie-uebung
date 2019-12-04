#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Subscriber {
    public:
        Subscriber(){};
        void showMessage(std::string message){
            std::cout << "\033[1m\u001b[36mMessage in subscriber\u001b[0m: " << message << std::endl;
        }
};

#endif