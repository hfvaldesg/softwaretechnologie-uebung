#include "publisher.h"
#include "subscriber.h"
#include "topic.h"
#include "broker.h"
#include <memory>

int main(){
    // Define the shared pointers
    std::shared_ptr<Topic> topic_ptr = std::make_shared<Topic>();
    std::shared_ptr<Subscriber> sub_ptr = std::make_shared<Subscriber>();
    std::shared_ptr<Publisher> pub_ptr = std::make_shared<Publisher>();
    
    // Set pub-sub relationships
    topic_ptr->addSubscriber(sub_ptr);
    pub_ptr->setTopic(topic_ptr);

    pub_ptr->sendMessage("Hallo von Publisher!");
    return 0;
}