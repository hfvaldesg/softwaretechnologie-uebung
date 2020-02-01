#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class Ping: public rclcpp::Node {
    public:
        Ping(): Node("ping_node"){
            publisher_ = this->create_publisher<std_msgs::msg::String>("ping", 10);
            send_ping();
            subscription_ = this->create_subscription<std_msgs::msg::String>(
            "pong", 10, std::bind(&Ping::topic_callback, this, _1));
        }
    private:
        void send_ping(){
            auto message = std_msgs::msg::String();
            message.data = "Ping";
            RCLCPP_INFO(this->get_logger(), "%s", message.data.c_str());
            publisher_->publish(message);
        }
        void topic_callback(const std_msgs::msg::String::SharedPtr msg){
            RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
            send_ping();
        }
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Ping>());
    rclcpp::shutdown();
    return 0;
}