#include <publisher.h>
#include <subscriber.h>
#include <topic.h>
#include <broker.h>
#include <pingpong.h>
#include <memory>

int main(){
    // Define the shared pointers
    std::shared_ptr<Topic> topic1 = std::make_shared<Topic>("topic1");
    std::shared_ptr<Subscriber> sub1 = std::make_shared<Subscriber>(topic1);
    std::shared_ptr<Subscriber> sub2 = std::make_shared<Subscriber>(topic1);
    std::shared_ptr<Publisher> pub1 = std::make_shared<Publisher>(topic1);

    std::shared_ptr<Broker> broker = Broker::getInstance();
    broker->add_subscriber(sub1);
    broker->add_subscriber(sub2);
    pub1->setBroker(broker);

    // Exercise 1: Hello World
    std::cout << "Exercise 1" << std::endl;
    int COUNT = 10;
    for(int i = 1; i <= COUNT; i++){
        pub1->sendMessage(std::to_string(i));
    }

    std::cout << "\n---- ----\n" << std::endl;

    // Exercise 2: Ping/Pong
    std::cout << "Exercise 2" << std::endl;
    std::shared_ptr<Topic> topicPingPong = std::make_shared<Topic>("pingpong");
    PingPong ping_pong{topicPingPong, broker};

    COUNT = 10;
    for(int i = 1; i <= COUNT; i++){
        ping_pong.sendPing();
    }    

    return 0;
}