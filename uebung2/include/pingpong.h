#ifndef PINGPONG_H
#define PINGPONG_H

#include <topic.h>
#include <subscriber.h>
#include <publisher.h>
#include <broker.h>
#include <memory>

class PingPong {
    private:
        std::shared_ptr<Topic> topic;
        std::shared_ptr<Broker> broker;
        std::shared_ptr<Subscriber> subscriber;
        std::shared_ptr<Publisher> publisher;
    public:
        PingPong(std::shared_ptr<Topic> _topic, 
            std::shared_ptr<Broker> _broker): topic(_topic), broker(_broker){
        }
};

#endif