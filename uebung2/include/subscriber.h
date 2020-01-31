#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <topic.h>
#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Subscriber {
    private:
        std::shared_ptr<Topic> topic;
    public:
        Subscriber(std::shared_ptr<Topic> _topic):topic(_topic){};

        void setTopic(std::shared_ptr<Topic> _topic){
            topic = _topic;
        }

        std::shared_ptr<Topic> getTopic(){
            return topic;
        }

        void showMessage(std::string message){
            if(message != "Ping"){
                std::cout << "\033[1m\u001b[36mMessage in subscriber\u001b[0m: " 
                << message << std::endl;
            } else {
                std::cout << "\033[1m\u001b[36mMessage in subscriber\u001b[0m: " 
                << "Pong" << std::endl;
            }
            
        }
};

#endif