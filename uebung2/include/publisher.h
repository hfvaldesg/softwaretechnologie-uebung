#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "topic.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Publisher {
    private:
        std::shared_ptr<Topic> topic;
    public:
        Publisher();
        Publisher(std::shared_ptr<Topic> _topic): topic(_topic){

        }

        void setTopic(std::shared_ptr<Topic> _topic){
            topic = _topic;
        }

        std::shared_ptr<Topic> getTopic(){
            return topic;
        };

        void sendMessage(std::string message){
            
        }
};

#endif