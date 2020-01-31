#ifndef PINGPONG_H
#define PINGPONG_H

#include <topic.h>
#include <subscriber.h>
#include <publisher.h>
#include <broker.h>
#include <memory>
#include <iostream>
#include <string>

class PingPong {
    private:
        std::shared_ptr<Topic> topic;
        std::shared_ptr<Broker> broker;
        std::shared_ptr<Subscriber> subscriber;
        std::shared_ptr<Publisher> publisher;
    public:
        PingPong(std::shared_ptr<Topic> _topic, 
            std::shared_ptr<Broker> _broker): topic(_topic), broker(_broker){
                subscriber = std::make_shared<Subscriber>(topic);
                publisher = std::make_shared<Publisher>(topic);
                publisher->setBroker(broker);
                broker->add_subscriber(subscriber);
        }

        void sendPing(){
            std::string message{"Ping"};
            std::cout << message << std::endl;
            publisher->sendMessage(message);
        }
};

#endif