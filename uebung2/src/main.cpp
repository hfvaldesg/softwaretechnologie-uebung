#include "publisher.h"
#include "subscriber.h"
#include "topic.h"
#include "broker.h"
#include <memory>

int main(){
    // Define the shared pointers
    // std::shared_ptr<Topic> topic_ptr = std::make_shared<Topic>();
    std::shared_ptr<Subscriber> sub_ptr = std::make_shared<Subscriber>();
    std::shared_ptr<Publisher> pub_ptr = std::make_shared<Publisher>();
    
    // Set pub-sub relationships
    // topic_ptr->addSubscriber(sub_ptr);
    // pub_ptr->setTopic(topic_ptr);

    std::shared_ptr<Broker> broker = Broker::getInstance();
    broker->add_subscriber(sub_ptr);
    pub_ptr->setBroker(broker);

    // Exercise 1: Hello World
    std::cout << "Exercise 1" << std::endl;
    int COUNT = 10;
    for(int i = 1; i <= COUNT; i++){
        pub_ptr->sendMessage(std::to_string(i));
    }
    

    return 0;
}