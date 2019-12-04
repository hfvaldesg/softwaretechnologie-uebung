#ifndef BROKER_H
#define BROKER_H

#include <vector>
#include <memory>
#include <subscriber.h>

class Broker {
    // Implementation of a Broker following the Singleton Pattern
    private:
        Broker(){};
        std::vector<Subscriber> subscribers;     
    public:        
        static std::shared_ptr<Broker> getInstance(){
            std::shared_ptr<Broker> instance;
            if(!instance){
                instance.reset(new Broker());
            }
            return instance;
        }
        void add_subscriber(Subscriber subscriber){
            subscribers.push_back(subscriber);
        }
        void publish(std::string message){
            for(auto subscriber : subscribers){
                subscriber.showMessage(message);
            }
        }
};

#endif