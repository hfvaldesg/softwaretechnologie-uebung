#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "topic.h"
#include "broker.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Publisher {
    private:
        std::shared_ptr<Topic> topic;
        std::shared_ptr<Broker> broker;
    public:
        Publisher(){};
        Publisher(std::shared_ptr<Topic> _topic): topic(_topic){

        }

        void setTopic(std::shared_ptr<Topic> _topic){
            topic = _topic;
        }

        std::shared_ptr<Topic> getTopic(){
            return topic;
        };

        void setBroker(std::shared_ptr<Broker> _broker){
            broker = _broker;
        }

        std::shared_ptr<Broker> getBroker(){
            return broker;
        }

        void sendMessage(std::string message){
            broker->publish(message);
        }
};

#endif