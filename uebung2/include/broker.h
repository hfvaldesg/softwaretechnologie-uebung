#ifndef BROKER_H
#define BROKER_H

#include <vector>
#include <memory>
#include <topic.h>
#include <subscriber.h>

class Broker {
    // Implementation of a Broker following the Singleton Pattern
    private:
        Broker(){};
        std::vector<std::shared_ptr<Subscriber>> subscribers;     
    public:        
        static std::shared_ptr<Broker> getInstance(){
            std::shared_ptr<Broker> instance;
            if(!instance){
                instance.reset(new Broker());
            }
            return instance;
        }
        
        void add_subscriber(std::shared_ptr<Subscriber> subscriber){
            subscribers.push_back(subscriber);
        }

        void publish(std::string message, std::shared_ptr<Topic> topic){
            for(auto subscriber : subscribers){
                if(subscriber->getTopic() == topic){
                    subscriber->showMessage(message);
                }                
            }
        }
};

#endif