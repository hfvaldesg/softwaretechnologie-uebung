#ifndef TOPIC_H
#define TOPIC_H

#include "subscriber.h"
#include <vector>
#include <iostream>
#include <memory>

class Topic{
    private:
        std::vector<std::shared_ptr<Subscriber>> subscribers;
    public:
        Topic();
        void addSubscriber(std::shared_ptr<Subscriber> new_subscriber){
            subscribers.push_back(new_subscriber);
        }
        void publish(std::string message){
            for(auto subscriber : subscribers){
                subscriber->showMessage(message);
            }
        }
};

#endif