#ifndef BROKER_H
#define BROKER_H

#include <vector>
#include <memory>
#include <subscriber.h>

class Broker {
    // Implementation of a Broker following the Singleton Pattern
    private:
        Broker();
        std::vector<Subscriber> subscribers;
        
    public:
        virtual ~Broker() = default;
        static std::shared_ptr<Broker> getInstance(){
            static std::shared_ptr<Broker> instance(new Broker);
            return instance;
        }
};

#endif