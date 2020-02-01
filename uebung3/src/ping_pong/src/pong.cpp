#include <memory>
#include <thread>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using std::placeholders::_1;

class Pong : public rclcpp::Node
{
  public:
    Pong()
    : Node("pong_node")
    {
      subscription_ = this->create_subscription<std_msgs::msg::String>(
      "ping", 10, std::bind(&Pong::topic_callback, this, _1));
      publisher_ = this->create_publisher<std_msgs::msg::String>("pong", 10);
    }

  private:
    void send_pong(){        
        auto message = std_msgs::msg::String();
        message.data = "Pong";
        RCLCPP_INFO(this->get_logger(), "%s", message.data.c_str());
        publisher_->publish(message);        
    }
    void topic_callback(const std_msgs::msg::String::SharedPtr msg)
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      send_pong();
    }
    
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Pong>());
  rclcpp::shutdown();
  return 0;
}